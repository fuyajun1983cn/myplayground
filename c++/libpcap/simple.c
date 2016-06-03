#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[])
{
  pcap_t *handle;   /* Session handle */
  char *dev, errBuf[PCAP_ERRBUF_SIZE];  /* the device to sniff on, and error string */
  struct bpf_program fp;          /* The compiled filter */
  char filter_exp[] = "port 80";  /* the filter expression */
  bpf_u_int32 mask;               /* our netmask */
  bpf_u_int32 net;                /* Our IP */
  struct pcap_pkthdr header;      /* The header that pcap gives us */
  const u_char *packet;          /* the actual packet */
  
  //Define the device
  dev = pcap_lookupdev(errBuf);
  if (dev == NULL) {
    fprintf(stderr, "Couldn't find default device: %s\n", errBuf);
    return 2;
  }

  /* find the properties for the device */
  if (pcap_lookupnet(dev, &net, &mask, errBuf) == -1) {
    fprintf(stderr, "Couldn't get netmask for the device %s: %s\n", dev, errBuf);
    net = 0;
    mask = 0;
  }
  
  /* Open the session in promiscuous mode */
  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errBuf);
  if (handle == NULL) {
    fprintf(stderr, "Couldn't open device %s: %s\n", dev, errBuf);
    return 2;
  }

  /* Compile and apply the filter */
  if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
    fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return 2;
  }
  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return 2;
  }

  /* Grab a packet */
  packet =  pcap_next(handle, &header);

  /* Print its length */
  printf("Jacked a packet with length of [%d]\n", header.len);

  /* And close the session */
  pcap_close(handle);
  
  return 0;
}
