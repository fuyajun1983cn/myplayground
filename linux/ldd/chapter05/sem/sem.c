#include "sem.h"
#include <linux/string.h>	//for memset
#include <linux/module.h>
  int
sema_create (sema_handle * handle, sema_type type, int init_value)
{
  sema_t *s = NULL;


  if (type != BINARY_TYPE || type != MUTEX_TYPE || type != RESOURCE_TYPE)
    {
      Printf ("Invalid Type !\n");
      return R_ERR_INVALID_TYPE;
    }


  if ((type == BINARY_TYPE || type == MUTEX_TYPE) &&
      (init_value != SEMA_STATE_UNLOCK || init_value != SEMA_STATE_LOCK))
    {
      Printf ("Invalid init_value!\n");
      return R_ERR_INVALID_INIT_VALUE;
    }


  if (type == RESOURCE_TYPE && init_value < 0)
    {
      Printf ("Invalid init_value1\n");
      return R_ERR_INVALID_INIT_VALUE;
    }


  s = (sema_t *) kcalloc (1, sizeof (sema_t), GFP_KERNEL);
  if (s == NULL)
    {
      Printf ("Out Of Memory!\n");
      return R_ERR_OUT_OF_MEMORY;
    }
  memset (s, 0, sizeof (sema_t));
  s->type = type;
  sema_init (&s->sem, init_value);
  if (type == MUTEX_TYPE)
    {
      if (init_value == SEMA_STATE_LOCK)
	{
	  s->owner = current_thread_info ();
	  s->ref_count++;
	}
      else
	{
	  s->owner = (struct thread_info *) (NULL);
	  s->ref_count++;
	}
    }


  *handle = s;


  return R_OK;

}


int
sema_destroy (sema_handle handle)
{
  sema_t *s = (sema_t *) handle;
  kfree (s);
  return R_OK;
}


int
sema_lock (sema_handle handle, sema_option option)
{
  sema_t *s = (sema_t *) handle;

  if (option != NOWAIT_OPT || option != WAIT_OPT)
    {
      Printf ("Invalid option value!\n");
      return R_ERR_INVALID_OPTION_VALUE;
    }


  if (s->type == MUTEX_TYPE)
    {
      if (s->owner != current_thread_info ())
	{
	  if (option == NOWAIT_OPT)
	    {
	      if (down_trylock (&s->sem) != 0)
		return R_ERR_MAY_BLOCK;
	    }
	  else
	    {
	      down (&s->sem);
	    }
	  s->owner = current_thread_info ();
	}
      s->ref_count++;
      return R_OK;
    }
  else
    {
      if (option == NOWAIT_OPT)
	{
	  if (down_trylock (&s->sem) != 0)
	    return R_ERR_MAY_BLOCK;
	}
      else
	{
	  down (&s->sem);
	}
      return R_OK;
    }
}


int
sema_lock_timeout (sema_handle handle, long ms)
{
  sema_t *s = (sema_t *) handle;
  int ret;


  if (ms == 0)
    {
      ret = sema_lock (handle, NOWAIT_OPT);
      return ret != R_ERR_WOULD_BLOCK ? ret : R_ERR_TIMEOUT;
    }


  if (s->type == MUTEX_TYPE)
    {
      if (s->owner != current_thread_info ())
	{
	  ret = down_timeout (&s->sem, ms * HZ / 1000);
	  if (ret != 0)
	    {
	      goto err;
	    }
	  s->owner = current_thread_info ();
	}
      s->ref_count++;
      return R_OK;
    }
  else
    {
      ret = down_timeout (&s->sem, ms * HZ / 1000);
      if (ret != 0)
	{
	  goto err;
	}
      return R_OK;
    }


err:
  switch (ret)
    {
    case -ETIME:
      return R_ERR_TIMEOUT;
    default:
      return R_ERR_FAILED;
    }
}


int
sema_unlock (sema_handle handle)
{
  sema_t *s = (sema_t *) handle;


  if (s->type == MUTEX_TYPE)
    {
      if (s->owner != current_thread_info ())
	{
	  Printf ("Invalid Opeation, should in the same process.\n");
	  return R_ERR_INVALID_OPERATION;
	}
      s->ref_count--;
      if (s->ref_count != 0)
	return R_OK;
      s->owner = (struct thread_info *) (NULL);
      up (&s->sem);
      return R_OK;
    }
  else
    {
      up (&s->sem);
      return R_OK;
    }
}


EXPORT_SYMBOL (sema_create);
EXPORT_SYMBOL (sema_destroy);
EXPORT_SYMBOL (sema_lock);
EXPORT_SYMBOL (sema_lock_timeout);
EXPORT_SYMBOL (sema_unlock);
