
#include "common.h"

int main(int argc, char *argv[])
{
  int err;
  struct nl_sock *sock = nl_socket_alloc();
  if (!sock) {
        fprintf(stderr, "Failed to allocate netlink socket.\n");
        return -ENOMEM;
  }
  nl_socket_set_buffer_size(sock, 8192, 8192);

  if (genl_connect(sock)) {
        fprintf(stderr, "Failed to connect to generic netlink.\n");
        err = -ENOLINK;
        goto out_handle_destroy;
  }

  int nl80211_id = genl_ctrl_resolve(sock, "nl80211");
  if (nl80211_id < 0) {
        fprintf(stderr, "nl80211 not found.\n");
        err = -ENOENT;
        goto out_handle_destroy;
  }

  printf("NL802.11 family id: %d\n", nl80211_id);

  return 0;

 out_handle_destroy:
  nl_socket_free(sock);
  return err;
}
