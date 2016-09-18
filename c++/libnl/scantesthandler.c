#include<assert.h>
#include<errno.h>
#include<ifaddrs.h>
#include<netdb.h>
#include<stddef.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <asm/types.h>
#include <linux/rtnetlink.h>
#include <netlink/netlink.h>
#include <netlink/msg.h>
#include <netlink/cache.h>
#include <netlink/socket.h>
#include <netlink/genl/genl.h>
#include <netlink/genl/ctrl.h>
#include <stdlib.h>
#include <netlink/genl/genl.h>
#include <netlink/genl/ctrl.h>
#include <netlink/route/link.h>
#include <linux/nl80211.h>
#include <net/if.h>

static int expectedId;
static int ifIndex;
struct wpa_scan_res 
{
  unsigned char bssid[6]; 
  int freq;
};

static int error_handler(struct sockaddr_nl *nla, struct nlmsgerr *err, void *arg) 
{

  int *ret = arg;
  *ret = err->error;
  printf("\nError error!\n");
  return NL_SKIP;
}

static int finish_handler(struct nl_msg *msg, void *arg) 
{

  int *ret = arg;
  *ret = 0;
  printf("finish_handler\n");
  return NL_SKIP;
}
static int ack_handler(struct nl_msg *msg, void *arg)
{
  int *err = arg;
  *err = 0;
  printf("ack_handler\n");
  return NL_STOP;
}

static int bss_info_handler(struct nl_msg *msg, void *arg)
{

  struct nlattr *tb[NL80211_ATTR_MAX + 1];
  struct genlmsghdr *gnlh = nlmsg_data(nlmsg_hdr(msg));
  struct nlattr *bss[NL80211_BSS_MAX + 1];
  static struct nla_policy bss_policy[NL80211_BSS_MAX + 1] = {
    [NL80211_BSS_BSSID] = { .type = NLA_UNSPEC },
    [NL80211_BSS_FREQUENCY] = { .type = NLA_U32 },
    [NL80211_BSS_TSF] = { .type = NLA_U64 },
    [NL80211_BSS_BEACON_INTERVAL] = { .type = NLA_U16 },
    [NL80211_BSS_CAPABILITY] = { .type = NLA_U16 },
    [NL80211_BSS_INFORMATION_ELEMENTS] = { .type = NLA_UNSPEC },
    [NL80211_BSS_SIGNAL_MBM] = { .type = NLA_U32 },
    [NL80211_BSS_SIGNAL_UNSPEC] = { .type = NLA_U8 },
    [NL80211_BSS_STATUS] = { .type = NLA_U32 },
    [NL80211_BSS_SEEN_MS_AGO] = { .type = NLA_U32 },
    [NL80211_BSS_BEACON_IES] = { .type = NLA_UNSPEC },
  };
  struct wpa_scan_res *r = NULL;

  printf("扫描结果：\n");

  r = (struct wpa_scan_res*)malloc(sizeof(struct wpa_scan_res));

  nla_parse(tb, NL80211_ATTR_MAX, genlmsg_attrdata(gnlh, 0),
            genlmsg_attrlen(gnlh, 0), NULL);
  if (!tb[NL80211_ATTR_BSS])
    return NL_SKIP;
  if (nla_parse_nested(bss, NL80211_BSS_MAX, tb[NL80211_ATTR_BSS],
                       bss_policy))
    return NL_SKIP;
  if (bss[NL80211_BSS_BSSID])
    memcpy(r->bssid, nla_data(bss[NL80211_BSS_BSSID]),6);
  if (bss[NL80211_BSS_FREQUENCY])
    r->freq = nla_get_u32(bss[NL80211_BSS_FREQUENCY]);


  printf("\nFrequency: %d ,BSSID: %02x:%02x:%02x:%02x:%02x:%02x\n",r->freq,r->bssid[0],r->bssid[1],r->bssid[2],r->bssid[3],r->bssid[4],r->bssid[5]);
  return NL_SKIP;
}


static struct nl_msg* nl80211_scan_common(uint8_t cmd, int expectedId)
{
  const char* ssid = "";

  int ret;

  struct nl_msg *msg;
  int err;
  size_t i;
  int flags = 0,ifIndex;

  msg = nlmsg_alloc();
  if (!msg)
    return NULL;

  // setup the message
  if(NULL==genlmsg_put(msg, 0, 0, expectedId, 0, flags, cmd, 0))
    {
      printf("\nError return genlMsg_put\n");
    }
  else
    {
      printf("\nSuccess genlMsg_put\n");
    }

  ifIndex = if_nametoindex("wlp6s0");

  printf("\n interface index: %d\n", ifIndex);


  if(nla_put_u32(msg, NL80211_ATTR_IFINDEX, ifIndex) < 0)
    {
      printf("\n setting interface index failed \n");
      goto fail;
    }

  struct nl_msg *ssids = nlmsg_alloc();
  if(nla_put(ssids, 1,strlen(ssid) ,ssid) <0)
    {

      nlmsg_free(ssids);
      goto fail;
    }

  err =   nla_put_nested(msg,  NL80211_ATTR_SCAN_SSIDS,ssids);
  nlmsg_free(ssids);
  if (err < 0)
    goto fail;

  struct nl_msg *freqs = nlmsg_alloc();

  if( nla_put_u32(freqs,1 ,2442) < 0) //amitssid
    {
      printf("\nnla_put_fail\n");
      goto fail;
    }
  else
    {
      printf("\nnla_put_u32 pass\n");
    }

  //add message attributes
  if(nla_put_nested(msg, NL80211_FREQUENCY_ATTR_FREQ,freqs) < 0)
    {
      printf("\nnla_put_nested failing:\n");
    }
  else
    {
      printf("\nnla_put_nested pass\n");
    }

  nlmsg_free(freqs);
  if (err < 0)
    goto fail;

  return msg;

 nla_put_failure:
  printf("\nnla_put_failure\n");
  nlmsg_free(msg);
  return NULL;


 fail:
  nlmsg_free(msg);
  return NULL;

}
int main(int argc, char** argv)
{

  struct nl_msg *msg= NULL;
  int ret = -1;
  struct nl_cb *cb = NULL;
  int err = -ENOMEM;
  int returnvalue,getret;
  int ifIndex, callbackret=-1;
  struct nl_sock* sk = (void*)nl_socket_alloc();
  if(sk == NULL)
    {
      printf("\n分配netlink失败\n");
      return -1;
    }

  cb = nl_cb_alloc(NL_CB_CUSTOM);
  if(cb == NULL)
    {
      printf("\nfailed to allocate netlink callback\n");
      return -1;
    }

  enum nl80211_commands cmd;
  if(genl_connect((void*)sk))
    {
      printf("\n连接netlink失败\n");
      return -1;
    }

  //find the nl80211 driverID
  expectedId = genl_ctrl_resolve((void*)sk, "nl80211");

  if(expectedId < 0)
    {
      printf("\nnl80211未找到\n");
      return -1;
    }


  msg = nl80211_scan_common(NL80211_CMD_TRIGGER_SCAN, expectedId);
  if (!msg)
    {
      printf("\nmsgbal:\n");
      return -1;
    }

  err = nl_send_auto_complete((void*)sk, msg);
  if (err < 0)
    goto out;
  else
    {
      printf("发送扫描");
    }
  err = 1;
  nl_cb_err(cb,NL_CB_CUSTOM,error_handler,&err);
  nl_cb_set(cb,NL_CB_FINISH,NL_CB_CUSTOM,finish_handler,&err);
  nl_cb_set(cb,NL_CB_ACK,NL_CB_CUSTOM,ack_handler,&err);
  callbackret = nl_cb_set(cb,NL_CB_VALID,NL_CB_CUSTOM,bss_info_handler,&err);

   while (err > 0)
     nl_recvmsgs((void*)sk,cb);

  nlmsg_free(msg);
  msg = NULL;
  msg = nlmsg_alloc();
  if (!msg)
    return -1;

  if(NULL==genlmsg_put(msg, 0, 0, expectedId, 0, NLM_F_DUMP, NL80211_CMD_GET_SCAN, 0))
    {
      printf("\nError return genlMsg_put\n");
    }
  else
    {
      printf("\nSuccess genlMsg_put\n");
    }

  ifIndex = if_nametoindex("wlp6s0");
  printf("\nGet Scaninterface returned :%d\n",ifIndex);

  nla_put_u32(msg,NL80211_ATTR_IFINDEX,ifIndex);  

  err = nl_send_auto_complete((void*)sk,msg);
  if(err < 0) goto out;

  err = 1;
  printf("\n扫描结果: \n");
  while (err > 0)
    nl_recvmsgs((void*)sk,cb);

 out:
  nlmsg_free(msg);
  return err;

 nla_put_failure:
  printf("\nnla_put_failure\n");
  nlmsg_free(msg);
  return err;
}
