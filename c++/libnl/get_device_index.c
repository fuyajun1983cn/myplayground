
#include "common.h"

static int get_device_index1(char *name)
{
  char buf[200];
  int fd, pos;

  snprintf(buf, sizeof(buf), "/sys/class/ieee80211/%s/index", name);
  fd = open(buf, O_RDONLY);
  if (fd < 0) {
    printf("文件打开失败！！！\n");
    return -1;
  }
  pos = read(fd, buf, sizeof(buf) - 1);
  if (pos < 0) {
    printf("读取文件失败!!!\n");
    close(fd);
    return -1;
  }
  buf[pos] = '\0';
  close(fd);
  return atoi(buf);
}

static int get_device_index2(const char *ifname)
{
  unsigned int index = if_nametoindex(ifname);
  if (index == 0)
    index = -1;
  return index;
}

int main(int argc, char *argv[])
{
  printf(" Phy0 Index: %d\n", get_device_index1("phy0"));
  printf(" Device Index: %d\n", get_device_index2("wlp6s0"));
  return 0;
}
