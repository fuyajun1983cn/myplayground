#ifndef LOCK_H
#define LOCK_H


#include <linux/version.h>


#include <linux/spinlock.h>
#include <linux/rwsem.h>


#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,26)
#include <linux/semaphore.h>
#else /* pre 2.6.26 the file was in the arch specific location */
#include <asm/semaphore.h>
#endif


#include <linux/slab.h>


#define Printf(fmt, args...) printk( KERN_DEBUG "lock: " fmt, ## args)


typedef enum
{
  R_ERR_OK = 0,
  R_ERR_INVALID_HANDLE = -1,
  R_ERR_INVALID_LOCKMODE = -2,
  R_ERR_RESTARTSYSCALL = -3
} errcode_t;


typedef enum
{
  LOCKMODE_UNDEF = -1,/**< Undefined lock mode. For internal use only */
  LOCKMODE_RW = 0x0,  /**< Read-write mode, default. All readers and writers are mutually-exclusive */
  LOCKMODE_RO,	      /**< Read-only mode, to support multiple concurrent readers, but mutual exclusion in the presence of writers. */
} lock_mode_t;


typedef enum
{
  LOCKFLAG_SPINLOCK = 0x1,
  LOCKFLAG_NONINTERRUPTABLE = 0x2,
  LOCKFLAG_READERWRITER = 0x4,
  LOCKFLAG_ORDERED = 0x8,
  LOCKFLAG_ONELOCK = 0x10,
  LOCKFLAG_SPINLOCK_IRQ = 0x20,


} lock_flags_t;


typedef enum
{
  LOCKTYPE_SPIN,		/* Mutex, implicitly non-interruptable, use spin_lock/spin_unlock */
  LOCKTYPE_SPIN_IRQ,		/* Mutex, IRQ version of spinlock, use spin_lock_irqsave/spin_unlock_irqrestore */
  LOCKTYPE_MUTEX,		/* Interruptable, use up()/down_interruptable() */
  LOCKTYPE_MUTEX_NONINT,	/* Non-Interruptable, use up()/down() */
  LOCKTYPE_MUTEX_NONINT_RW,	/* Non-interruptable, Reader/Writer, use {up,down}{read,write}() */
} lock_type;


typedef struct lock_t_struct
{
  lock_type type;
  unsigned long flags;		//for IRQ SPIN LOCK
  union
  {
    spinlock_t spinlock;
    struct semaphore sema;
    struct rw_semaphore rw_sema;
  } obj;
} lock_t;


lock_t *lock_init (lock_flags_t flags);
errcode_t lock_wait (lock_t * lock, lock_mode_t mode);
void lock_signal (lock_t * lock, lock_mode_t mode);
void lock_term (lock_t * lock);


#endif
