
#ifndef __COMMON_H__
#define __COMMON_H__

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

#include <ctype.h>
#include <netlink/attr.h>

#include <netlink/genl/genl.h>
#include <netlink/genl/family.h>
#include <netlink/genl/ctrl.h>
#include <netlink/msg.h>
#include <netlink/attr.h>

#include "nl80211.h"
#include "ieee80211.h"

#define ETH_ALEN 6

#if 0
#if !defined(CONFIG_LIBNL20) && !defined(CONFIG_LIBNL30)

#define nl_sock nl_handle

static inline struct nl_handle *nl_socket_alloc(void)
{
        return nl_handle_alloc();
}

static inline void nl_socket_free(struct nl_sock *h)
{
        nl_handle_destroy(h);
}

static inline int nl_socket_set_buffer_size(struct nl_sock *sk,
                                            int rxbuf, int txbuf)
{
        return nl_set_buffer_size(sk, rxbuf, txbuf);
}
#endif /* CONFIG_LIBNL20 && CONFIG_LIBNL30 */
#endif

struct nl80211_state {
         struct nl_sock *nl_sock;
         int nl80211_id; //family id
       };

 struct cmd {
   uint8_t cmd;
   int nl_flags; //netlink flags
   int (*handler)(struct nl80211_state *state,
                  struct nl_cb *cb,
                  struct nl_msg *msg);
 };

static inline void mac_addr_n2a(char *mac_addr, unsigned char *arg)
{
        int i, l;

        l = 0;
        for (i = 0; i < ETH_ALEN ; i++) {
                if (i == 0) {
                        sprintf(mac_addr+l, "%02x", arg[i]);
                        l += 2;
                } else {
                        sprintf(mac_addr+l, ":%02x", arg[i]);
                        l += 3;
                }
        }
}

static inline int mac_addr_a2n(unsigned char *mac_addr, char *arg)
{
        int i;

        for (i = 0; i < ETH_ALEN ; i++) {
                int temp;
                char *cp = strchr(arg, ':');
                if (cp) {
                        *cp = 0;
                        cp++;
                }
                if (sscanf(arg, "%x", &temp) != 1)
                        return -1;
                if (temp < 0 || temp > 255)
                        return -1;

                mac_addr[i] = temp;
                if (!cp)
                        break;
                arg = cp;
        }
        if (i < ETH_ALEN - 1)
                return -1;

        return 0;
}

int nl80211_init(struct nl80211_state *state);
void nl80211_cleanup(struct nl80211_state *state);
int send_command(struct nl80211_state *state, struct cmd *cmd);
int get_device_index(const char *);

#endif
