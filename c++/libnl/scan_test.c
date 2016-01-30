
#include "common.h"
extern int nl80211_init(struct nl80211_state *state);
extern void nl80211_cleanup(struct nl80211_state *state);
extern int get_device_index(const char *);

static int prepare_scan_req(struct nl80211_state *state, struct nl_cb *cb, struct nl_msg *msg)
{
  struct nl_msg *ssids = NULL;
  struct nl_msg *freqs = NULL;

  int err = -ENOBUFS;
  int flags = 0;

  ssids = nlmsg_alloc();
  if (!ssids) {
    return -ENOMEM;
  }

  freqs = nlmsg_alloc();
  if (!freqs) {
    nlmsg_free(ssids);
    return -ENOMEM;
  }

  //Freq 5220 MHz
  NLA_PUT_U32(freqs, 0, 5220);
  //SSID
  NLA_PUT(ssids, 1, strlen("MiBox_5G"), "MiBox_5G");

  //主动扫描
  nla_put_nested(msg, NL80211_ATTR_SCAN_SSIDS, ssids);

  //扫描指定的频率
  nla_put_nested(msg, NL80211_ATTR_SCAN_FREQUENCIES, freqs);

  //设置扫描标记
  flags |= NL80211_SCAN_FLAG_FLUSH;
  NLA_PUT_U32(msg, NL80211_ATTR_SCAN_FLAGS, flags);

  err = 0;

nla_put_failure:
  nlmsg_free(ssids);
  nlmsg_free(freqs);
  return err;
}

static struct cmd scan_req = {
  .cmd = NL80211_CMD_TRIGGER_SCAN,
  .nl_flags = 0,
  .handler = prepare_scan_req,
};

static int print_bss_handler(struct nl_msg *msg, void *arg)
{
  struct nlattr *tb[NL80211_ATTR_MAX + 1];
  struct genlmsghdr *gnlh = nlmsg_data(nlmsg_hdr(msg));
  struct nlattr *bss[NL80211_BSS_MAX + 1];
  char mac_addr[20], dev[20];
  static struct nla_policy bss_policy[NL80211_BSS_MAX + 1] = {
        [NL80211_BSS_TSF] = { .type = NLA_U64 },
        [NL80211_BSS_FREQUENCY] = { .type = NLA_U32 },
        [NL80211_BSS_BSSID] = { },
        [NL80211_BSS_BEACON_INTERVAL] = { .type = NLA_U16 },
        [NL80211_BSS_CAPABILITY] = { .type = NLA_U16 },
        [NL80211_BSS_INFORMATION_ELEMENTS] = { },
        [NL80211_BSS_SIGNAL_MBM] = { .type = NLA_U32 },
        [NL80211_BSS_SIGNAL_UNSPEC] = { .type = NLA_U8 },
        [NL80211_BSS_STATUS] = { .type = NLA_U32 },
        [NL80211_BSS_SEEN_MS_AGO] = { .type = NLA_U32 },
        [NL80211_BSS_BEACON_IES] = { },
  };

  nla_parse(tb, NL80211_ATTR_MAX, genlmsg_attrdata(gnlh, 0),
                  genlmsg_attrlen(gnlh, 0), NULL);

  if (!tb[NL80211_ATTR_BSS]) {
    fprintf(stderr, "bss info missing!\n");
    return NL_SKIP;
  }

  if (nla_parse_nested(bss, NL80211_BSS_MAX,
                       tb[NL80211_ATTR_BSS],
                       bss_policy)) {
    fprintf(stderr, "failed to parse nested attributes!\n");
    return NL_SKIP;
  }

  if (!bss[NL80211_BSS_BSSID])
    return NL_SKIP;

  mac_addr_n2a(mac_addr, nla_data(bss[NL80211_BSS_BSSID]));
  printf("BSS %s", mac_addr);
  if (tb[NL80211_ATTR_IFINDEX]) {
    if_indextoname(nla_get_u32(tb[NL80211_ATTR_IFINDEX]), dev);
    printf("(on %s)", dev);
  }

  if (bss[NL80211_BSS_STATUS]) {
    switch (nla_get_u32(bss[NL80211_BSS_STATUS])) {
      case NL80211_BSS_STATUS_AUTHENTICATED:
        printf(" -- authenticated");
        break;
      case NL80211_BSS_STATUS_ASSOCIATED:
        printf(" -- associated");
        break;
      case NL80211_BSS_STATUS_IBSS_JOINED:
        printf(" -- joined");
        break;
      default:
        printf(" -- unknown status: %d",
                nla_get_u32(bss[NL80211_BSS_STATUS]));
        break;
      }
   }
   printf("\n");

   return NL_SKIP;
}

static int prepare_scan_result_req(struct nl80211_state *state, struct nl_cb *cb, struct nl_msg *msg)
{
  nl_cb_set(cb, NL_CB_VALID, NL_CB_CUSTOM, print_bss_handler,
            NULL);
}

static struct cmd scan_result_req = {
  .cmd = NL80211_CMD_GET_SCAN,
  .nl_flags = 0,
  .handler = prepare_scan_result_req,
};

static void send_scan_request(struct nl80211_state *nlstate)
{
  send_command(nlstate, &scan_req);
}

static void get_scan_results(struct nl80211_state *nlstate)
{
  printf("get scan results\n");
  send_command(nlstate, &scan_result_req);
}

int main(int argc, char *argv[])
{
  struct nl80211_state nlstate;
  int err;

  err = nl80211_init(&nlstate);
  if (err) {
    printf("nl80211_init failed\n");
  }

  send_scan_request(&nlstate);

  //sleep(10);
  
  //get_scan_results(&nlstate);
  nl80211_cleanup(&nlstate);
  return err;
}
