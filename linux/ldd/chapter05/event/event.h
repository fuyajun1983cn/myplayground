#ifndef EVENT_H
#define EVENT_H


#include <linux/module.h>
#include <linux/wait.h>


#define EVENT_NAME_LEN  16


#define R_ERR_OK 0
#define R_ERR_INVALID_ARG -1
#define R_ERR_INVALID_INIT_VALUE -2
#define R_ERR_INVALID_OPTION_VALUE -3
#define R_ERR_MAY_BLOCK -4
#define R_ERR_TIMEOUT  -5
#define R_ERR_OUT_OF_MEMORY -6
#define R_ERR_FAILED -7
#define R_ERR_INVALID_OPERATION -8
#define R_ERR_WOULD_BLOCK -9
#define R_ERR_EXIST -10
#define R_ERR_NO_RESOURCE -11


typedef int errcode_t;


typedef unsigned int event_val;
typedef unsigned char BOOL;


#define TRUE 1
#define FALSE 0


typedef enum
{
  EV_OP_CLEAR,
  EV_OP_AND,
  EV_OP_OR,
  EV_OP_AND_CONSUME,
  EV_OP_OR_CONSUME,
} ev_grp_op;


typedef struct _event
{
  struct _event *previous;
  struct _event *next;


  wait_queue_head_t wq;
  event_val events;
  unsigned char name[EVENT_NAME_LEN + 1];
} event;


errcode_t event_group_create (event ** evt_grp, unsigned char *name,
			      event_val vals);
errcode_t event_group_delete (event * evt_grp, unsigned char *name,
			      event_val vals);
errcode_t event_group_set_event (event * evt_grp, event_val events,
				 ev_grp_op op);


errcode_t event_group_wait_event_timeout (event * evt_grp,
					  event_val event_req,
					  event_val * event_got,
					  ev_grp_op op, unsigned int timeout);
errcode_t event_group_wait_event (event * evt_grp,
				  event_val event_req,
				  event_val * event_got, ev_grp_op op);




#endif
