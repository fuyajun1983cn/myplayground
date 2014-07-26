#include "event.h"
#include <linux/string.h>	//for memset
#include <linux/module.h>
#include <linux/spinlock.h>
#include <linux/slab.h>
#include <linux/sched.h>


static event *evt_grp_list = NULL;


static DEFINE_SPINLOCK (evt_grp_list_lock);


static void
event_group_list_add (event * e)
{
  if (evt_grp_list != NULL)
    {
      e->previous = evt_grp_list->previous;
      e->next = evt_grp_list;
      evt_grp_list->previous->next = e;
      evt_grp_list->previous = e;
    }
  else
    {
      evt_grp_list = evt_grp_list->previous = evt_grp_list->next = e;
    }
}


static void
event_group_list_remove (event * e)
{
  if (e->previous == e)
    {
      evt_grp_list = NULL;
    }
  else
    {
      e->previous->next = e->next;
      e->next->previous = e->previous;
      if (e == evt_grp_list)
	evt_grp_list = e->next;
    }
}


static event *
find_event_obj_in_event_group (unsigned char *name)
{
  event *item = evt_grp_list;
  if (item == NULL)
    {
      return NULL;
    }
  else
    {
      do
	{
	  if (!strncmp (name, item->name, EVENT_NAME_LEN))
	    return item;
	  item = item->next;
	}
      while (evt_grp_list != item);
    }
  return NULL;
}


errcode_t
event_group_create (event ** evt_grp, unsigned char *name, event_val vals)
{
  event *tmp = NULL;
  unsigned long flags;


  if (name == NULL || name[0] == '\0' || evt_grp == NULL)
    return R_ERR_INVALID_ARG;

  tmp = kcalloc (1, sizeof (event), GFP_KERNEL);
  if (tmp == NULL)
    return R_ERR_NO_RESOURCE;


  tmp->events = vals;
  strncpy (tmp->name, name, EVENT_NAME_LEN);
  init_waitqueue_head (&tmp->wq);

  spin_lock_irqsave (&evt_grp_list_lock, flags);
  if (find_event_obj_in_event_group (name) != NULL)
    {
      spin_unlock_irqrestore (&evt_grp_list_lock, flags);
      kfree (tmp);
      return R_ERR_EXIST;
    }


  event_group_list_add (tmp);
  spin_unlock_irqrestore (&evt_grp_list_lock, flags);

  *evt_grp = tmp;


  return R_ERR_OK;
}


errcode_t
event_group_delete (event * evt_grp, unsigned char *name, event_val vals)
{
  unsigned long flags;
  event *tmp = NULL;


  if (name == NULL || name[0] == '\0' || evt_grp == NULL)
    return R_ERR_INVALID_ARG;

  tmp = (event *) evt_grp;

  spin_lock_irqsave (&evt_grp_list_lock, flags);
  event_group_list_remove (tmp);
  spin_unlock_irqrestore (&evt_grp_list_lock, flags);

  kfree (tmp);


  return R_ERR_OK;
}


errcode_t
event_group_set_event (event * evt_grp, event_val events, ev_grp_op op)
{
  event *p_evt_grp = NULL;
  unsigned long flags;


  if (op == EV_OP_CLEAR)
    {
      events = (event_val) 0;
      op = EV_OP_AND;
    }
  else if (op != EV_OP_AND || op != EV_OP_OR)
    {
      return R_ERR_INVALID_ARG;
    }
  p_evt_grp = evt_grp;
  spin_lock_irqsave (&evt_grp_list_lock, flags);
  if (op == EV_OP_AND)
    {
      p_evt_grp->events &= events;
    }
  else
    {
      p_evt_grp->events |= events;
    }
  wake_up_all (&p_evt_grp->wq);
  spin_unlock_irqrestore (&evt_grp_list_lock, flags);


  return R_ERR_OK;

}


static errcode_t
event_group_wait_impl (event * evt_grp,
		       event_val event_req,
		       event_val * event_got, ev_grp_op op, BOOL wait)
{
  event *p_evt_grp = evt_grp;
  event_val events;
  unsigned long flags;


  if (event_got == NULL ||
      (op != EV_OP_AND &&
       op != EV_OP_OR && op != EV_OP_AND_CONSUME && op != EV_OP_OR_CONSUME))
    {
      return R_ERR_INVALID_ARG;
    }


  *event_got = 0;


  if (wait)
    {
      while (TRUE)
	{
	  if (op == EV_OP_AND || op == EV_OP_AND_CONSUME)
	    wait_event (p_evt_grp->wq,
			(p_evt_grp->events & event_req) == event_req);
	  else
	    wait_event (p_evt_grp->wq,
			(p_evt_grp->events & event_req) != (event_val) 0);


	  spin_lock_irqsave (&evt_grp_list_lock, flags);
	  events = p_evt_grp->events & event_req;
	  if (op == EV_OP_AND || op == EV_OP_AND_CONSUME)
	    {
	      if (events == event_req)
		{
		  if (op == EV_OP_AND_CONSUME)
		    p_evt_grp->events &= ~event_req;
		  spin_unlock_irqrestore (&evt_grp_list_lock, flags);
		  break;
		}
	    }
	  else
	    {
	      if (events != (event_val) 0)
		{
		  if (op == EV_OP_OR_CONSUME)
		    p_evt_grp->events &= ~event_req;
		  spin_unlock_irqrestore (&evt_grp_list_lock, flags);
		  break;
		}
	    }
	  spin_unlock_irqrestore (&evt_grp_list_lock, flags);
	}
    }
  else
    {
      spin_lock_irqsave (&evt_grp_list_lock, flags);
      events = p_evt_grp->events & event_req;
      if (op == EV_OP_AND || op == EV_OP_AND_CONSUME)
	{
	  if (events == event_req)
	    {
	      if (op == EV_OP_AND_CONSUME)
		p_evt_grp->events &= ~event_req;
	      spin_unlock_irqrestore (&evt_grp_list_lock, flags);
	      return R_ERR_TIMEOUT;
	    }
	}
      else
	{
	  if (events != (event_val) 0)
	    {
	      if (op == EV_OP_OR_CONSUME)
		p_evt_grp->events &= ~event_req;
	      spin_unlock_irqrestore (&evt_grp_list_lock, flags);
	      return R_ERR_TIMEOUT;
	    }
	}
      spin_unlock_irqrestore (&evt_grp_list_lock, flags);
    }


  *event_got = events;


  return R_ERR_OK;
}


errcode_t
event_group_wait_event (event * evt_grp,
			event_val event_req,
			event_val * event_got, ev_grp_op op)
{
  return event_group_wait_impl (evt_grp, event_req, event_got, op, TRUE);
}


errcode_t
event_group_wait_event_timeout (event * evt_grp,
				event_val event_req,
				event_val * event_got,
				ev_grp_op op, unsigned int timeout)
{
  event *p_evt_grp = NULL;
  event_val events;
  unsigned long flags;
  int ret;
  static const int quantum_ms = 1000 / HZ;


  if (timeout == 0)
    return event_group_wait_impl (evt_grp, event_req, event_got, op, FALSE);
  else if (timeout == 0xFFFFFFFFU)
    return event_group_wait_impl (evt_grp, event_req, event_got, op, TRUE);


  p_evt_grp = evt_grp;


  if (event_got == NULL ||
      (op != EV_OP_AND &&
       op != EV_OP_OR && op != EV_OP_AND_CONSUME && op != EV_OP_OR_CONSUME))
    {
      return R_ERR_INVALID_ARG;
    }


  *event_got = 0;




  while (TRUE)
    {
      if (op == EV_OP_AND || op == EV_OP_AND_CONSUME)
	ret =
	  wait_event_timeout (p_evt_grp->wq,
			      (p_evt_grp->events & event_req) == event_req,
			      timeout / quantum_ms);
      else
	ret =
	  wait_event_timeout (p_evt_grp->wq,
			      (p_evt_grp->events & event_req) !=
			      (event_val) 0, timeout / quantum_ms);


      if (ret == 0)
	return R_ERR_TIMEOUT;


      spin_lock_irqsave (&evt_grp_list_lock, flags);
      events = p_evt_grp->events & event_req;
      if (op == EV_OP_AND || op == EV_OP_AND_CONSUME)
	{
	  if (events == event_req)
	    {
	      if (op == EV_OP_AND_CONSUME)
		p_evt_grp->events &= ~event_req;
	      spin_unlock_irqrestore (&evt_grp_list_lock, flags);
	      break;
	    }
	}
      else
	{
	  if (events != (event_val) 0)
	    {
	      if (op == EV_OP_OR_CONSUME)
		p_evt_grp->events &= ~event_req;
	      spin_unlock_irqrestore (&evt_grp_list_lock, flags);
	      break;
	    }
	}
      spin_unlock_irqrestore (&evt_grp_list_lock, flags);
    }




  *event_got = events;


  return R_ERR_OK;
}
