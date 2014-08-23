#include "lock.h"
#include <linux/module.h>


lock_t *
lock_init (lock_flags_t flags)
{
  lock_t *lock = NULL;


/* Validate parameters: */
/* Flags acceptable */
  if (0 != (flags & ~(LOCKFLAG_SPINLOCK
		      | LOCKFLAG_SPINLOCK_IRQ
		      | LOCKFLAG_NONINTERRUPTABLE
		      | LOCKFLAG_READERWRITER
		      | LOCKFLAG_ORDERED | LOCKFLAG_ONELOCK)))
    {
      Printf ("Invalid Flags!\n");
      return NULL;
    }
/* Spinlocks are always non-interruptable */
  if ((((flags & LOCKFLAG_SPINLOCK) || (flags & LOCKFLAG_SPINLOCK_IRQ))
       && (flags & LOCKFLAG_NONINTERRUPTABLE))
      || !(flags & LOCKFLAG_SPINLOCK))
    {
    }
  else
    {
      Printf ("Spinlocks are always non-interruptable\n");
      return NULL;
    }




  lock = kmalloc (sizeof (lock_t), GFP_KERNEL);


  if (NULL == lock)
    {
      return lock;
    }


/* Determine type of mutex: */
  /* defaults to interruptable mutex if no flags are specified */


  if ((flags & LOCKFLAG_SPINLOCK))
    {
/* Non-interruptable Spinlocks override all others */
      lock->type = LOCKTYPE_SPIN;
      spin_lock_init (&lock->obj.spinlock);
    }
  else if ((flags & LOCKFLAG_SPINLOCK_IRQ))
    {
      lock->type = LOCKTYPE_SPIN_IRQ;
      lock->flags = 0;
      spin_lock_init (&lock->obj.spinlock);
    }
  else if ((flags & LOCKFLAG_NONINTERRUPTABLE)
	   && (flags & LOCKFLAG_READERWRITER))
    {
      lock->type = LOCKTYPE_MUTEX_NONINT_RW;
      init_rwsem (&lock->obj.rw_sema);
    }
  else
    {
/* Usual mutex types */
      if ((flags & LOCKFLAG_NONINTERRUPTABLE))
	{
	  lock->type = LOCKTYPE_MUTEX_NONINT;
	}
      else
	{
	  lock->type = LOCKTYPE_MUTEX;
	}


/* Initially unlocked */
      sema_init (&lock->obj.sema, 1);
    }


  return lock;
}


errcode_t
lock_wait (lock_t * lock, lock_mode_t mode)
{
  errcode_t err = R_ERR_OK;


/* Parameter validation */
  if (lock == NULL)
    {
      Printf ("invalide handle parameter!\n");
      err = R_ERR_INVALID_HANDLE;
      return err;
    }


  if (!(LOCKMODE_RW == mode || LOCKMODE_RO == mode))
    {
      Printf ("invalide lock mode parameter!\n");
      err = R_ERR_INVALID_LOCKMODE;
      return err;
    }


  switch (lock->type)
    {
    case LOCKTYPE_SPIN:
      spin_lock (&lock->obj.spinlock);
      break;
    case LOCKTYPE_SPIN_IRQ:
      spin_lock_irqsave (&lock->obj.spinlock, lock->flags);
      break;


    case LOCKTYPE_MUTEX:
      if (down_interruptible (&lock->obj.sema))
	{
	  err = R_ERR_RESTARTSYSCALL;
	}
      break;


    case LOCKTYPE_MUTEX_NONINT:
      down (&lock->obj.sema);
      break;


    case LOCKTYPE_MUTEX_NONINT_RW:
      if (mode == LOCKMODE_RO)
	{
	  down_read (&lock->obj.rw_sema);
	}
      else
	{
	  down_write (&lock->obj.rw_sema);
	}
      break;


    default:
      Printf ("Invalid internal lock type: %.8X", lock->type);
      break;
    }


  return err;
}


void
lock_signal (lock_t * lock, lock_mode_t mode)
{
/* Parameter validation */
  if (lock == NULL)
    {
      Printf ("invalide handle parameter!\n");
      return;
    }


  if (!(LOCKMODE_RW == mode || LOCKMODE_RO == mode))
    {
      Printf ("invalide lock mode parameter!\n");
      return;
    }


  switch (lock->type)
    {
    case LOCKTYPE_SPIN:
      spin_unlock (&lock->obj.spinlock);
      break;
    case LOCKTYPE_SPIN_IRQ:
      spin_unlock_irqrestore (&lock->obj.spinlock, lock->flags);
      break;


    case LOCKTYPE_MUTEX:
/* FALLTHROUGH */
    case LOCKTYPE_MUTEX_NONINT:
      up (&lock->obj.sema);
      break;


    case LOCKTYPE_MUTEX_NONINT_RW:
      if (mode == LOCKMODE_RO)
	{
	  up_read (&lock->obj.rw_sema);
	}
      else
	{
	  up_write (&lock->obj.rw_sema);
	}
      break;


    default:
      Printf ("Invalid internal lock type: %.8X", lock->type);
      break;
    }
}


void
lock_term (lock_t * lock)
{
/* Linux requires no explicit termination of spinlocks, semaphores, or rw_semaphores */
  kfree (lock);
}


EXPORT_SYMBOL (lock_init);
EXPORT_SYMBOL (lock_wait);
EXPORT_SYMBOL (lock_signal);
EXPORT_SYMBOL (lock_term);
