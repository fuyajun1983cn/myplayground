#ifndef SEM_H
#define SEM_H


#include <linux/version.h>
#include <linux/slab.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,26)
#include <linux/semaphore.h>
#else /* pre 2.6.26 the file was in the arch specific location */
#include <asm/semaphore.h>
#endif


#define Printf(fmt, args...) printk( KERN_DEBUG "sema: " fmt, ## args)


#define SEMA_STATE_UNLOCK 1
#define SEMA_STATE_LOCK 0


#define R_OK 0
#define R_ERR_INVALID_TYPE -1
#define R_ERR_INVALID_INIT_VALUE -2
#define R_ERR_INVALID_OPTION_VALUE -3
#define R_ERR_MAY_BLOCK -4
#define R_ERR_TIMEOUT  -5
#define R_ERR_OUT_OF_MEMORY -6
#define R_ERR_FAILED -7
#define R_ERR_INVALID_OPERATION -8
#define R_ERR_WOULD_BLOCK -9


typedef enum
{
  BINARY_TYPE,
  MUTEX_TYPE,			//mutex use between process
  RESOURCE_TYPE
} sema_type;


typedef enum
{
  NOWAIT_OPT,
  WAIT_OPT
} sema_option;


typedef struct
{
  sema_type type;
  struct semaphore sem;
  struct thread_info *owner;
  int ref_count;
} sema_t, *sema_handle;




int sema_create (sema_handle * handle, sema_type type, int init_value);
int sema_destroy (sema_handle handle);
int sema_lock (sema_handle handle, sema_option option);
int sema_lock_timeout (sema_handle handle, long ms);
int sema_unlock (sema_handle handle);


#endif
