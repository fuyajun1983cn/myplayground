#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netlink/netlink.h>
#include <netlink/socket.h>
#include <netlink/msg.h>

#include "config.h"

/* libnl 1.x compatibility code */
#if !defined(CONFIG_LIBNL20) && !defined(CONFIG_LIBNL30)

int main(int argc, char *argv[])
{
  return 0;
}

#else

struct nl_sock *sk;

struct rtgenmsg rt_hdr = {
  .rtgen_family = AF_UNSPEC,
};


/*

 * This function will be called for each valid netlink message received

 * in nl_recvmsgs_default()

 */

static int my_func(struct nl_msg *msg, void *arg)
{

   printf("a msg recived!\n");

   return 0;

}



struct nl_sock *sk;


int main(int argc, char *argv[])
{

    /* Allocate a new socket */

    sk = nl_socket_alloc();

    /*

    * Define a callback function, which will be called for each notification

    * received

    */

    nl_socket_modify_cb(sk, NL_CB_VALID, NL_CB_CUSTOM, my_func, NULL);



    /* Connect to routing netlink protocol */

    nl_connect(sk, NETLINK_ROUTE);


    nl_send_simple(sk, RTM_GETLINK, NLM_F_DUMP, &rt_hdr, sizeof(rt_hdr));


    /*

    * Start receiving messages. The function nl_recvmsgs_default() will block

    * until one or more netlink messages (notification) are received which

    * will be passed on to my_func().

    */

    while (1)

	    nl_recvmsgs_default(sk);

    return 0;
}

#endif
