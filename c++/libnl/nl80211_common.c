
#include "common.h"


int nl80211_init(struct nl80211_state *state)
{
        int err;

        state->nl_sock = nl_socket_alloc();
        if (!state->nl_sock) {
                fprintf(stderr, "Failed to allocate netlink socket.\n");
                return -ENOMEM;
        }

        nl_socket_set_buffer_size(state->nl_sock, 8192, 8192);

        if (genl_connect(state->nl_sock)) {
                fprintf(stderr, "Failed to connect to generic netlink.\n");
                err = -ENOLINK;
                goto out_handle_destroy;
        }

        state->nl80211_id = genl_ctrl_resolve(state->nl_sock, "nl80211");
        if (state->nl80211_id < 0) {
                fprintf(stderr, "nl80211 not found.\n");
                err = -ENOENT;
                goto out_handle_destroy;
        }

        return 0;

 out_handle_destroy:
        nl_socket_free(state->nl_sock);
        return err;
}

void nl80211_cleanup(struct nl80211_state *state)
{
        nl_socket_free(state->nl_sock);
}

int get_device_index(const char *ifname)
{
  unsigned int index = if_nametoindex(ifname);
  if (index == 0)
    index = -1;
  return index;
}

static int error_handler(struct sockaddr_nl *nla, struct nlmsgerr *err,
                         void *arg)
{
        int *ret = arg;
        *ret = err->error;
        return NL_STOP;
}

static int finish_handler(struct nl_msg *msg, void *arg)
{
        int *ret = arg;
        *ret = 0;
        return NL_SKIP;
}

static int ack_handler(struct nl_msg *msg, void *arg)
{
        int *ret = arg;
        *ret = 0;
        return NL_STOP;
}

int send_command(struct nl80211_state *state, struct cmd *cmd)
{
  struct nl_cb *cb;
  struct nl_cb *s_cb;
  struct nl_msg *msg;
  int err;

  msg = nlmsg_alloc();
  if (!msg) {
    fprintf(stderr, "failed to allocate netlink message\n");
    return 2;
  }
  #if _DEBUG
  cb = nl_cb_alloc(NL_CB_DEBUG);
  s_cb = nl_cb_alloc(NL_CB_DEBUG);
  #else
  cb = nl_cb_alloc(NL_CB_DEFAULT);
  s_cb = nl_cb_alloc(NL_CB_DEFAULT);
  #endif
  if (!cb || !s_cb) {
    fprintf(stderr, "failed to allocate netlink callbacks\n");
    err = 2;
    goto out_free_msg;
  }

  /*
   
    void* genlmsg_put(
                     struct nl_msg *         msg,
                     uint32_t        port,
                     uint32_t        seq,
                     int     family,
                     int     hdrlen,
                     int     flags,
                     uint8_t         cmd,
                     uint8_t         version 
    )     
    Parameters
    msg     Netlink message object
    port    Netlink port or NL_AUTO_PORT
    seq     Sequence number of message or NL_AUTO_SEQ
    family  Numeric family identifier
    hdrlen  Length of user header
    flags   Additional Netlink message flags (optional)
    cmd     Numeric command identifier
    version Interface version
  */
  genlmsg_put(msg, 0, 0, state->nl80211_id, 0,
                    cmd->nl_flags, cmd->cmd, 0);


  NLA_PUT_U32(msg, NL80211_ATTR_IFINDEX, get_device_index("wlan0"));

  err = cmd->handler(state, cb, msg);
  if (err)
    goto out;

  nl_socket_set_cb(state->nl_sock, s_cb);
  err = nl_send_auto_complete(state->nl_sock, msg);
  if (err < 0)
    goto out;

  err = 1;

  nl_cb_err(cb, NL_CB_CUSTOM, error_handler, &err);
  nl_cb_set(cb, NL_CB_FINISH, NL_CB_CUSTOM, finish_handler, &err);
  nl_cb_set(cb, NL_CB_ACK, NL_CB_CUSTOM, ack_handler, &err);

  while (err > 0) {
    nl_recvmsgs(state->nl_sock, cb);
  }

 out:
  nl_cb_put(cb);
 out_free_msg:
  nlmsg_free(msg);
  return err;
 nla_put_failure:
  fprintf(stderr, "building message failed\n");
  return 2;
}
