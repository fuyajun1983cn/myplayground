#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_INOTIFY_H
#include <sys/inotify.h>
#endif


int main(int argc, const char *argv[])
{
#ifdef HAVE_INOTIFY_H
        printf("Here is a \n");
	int fd = inotify_init();
        int res = inotify_add_watch(fd, "/home/fuyajun/", IN_OPEN | IN_CREATE);
	if (res > 0) {
	    printf("inotify_add_watch successfully\n");
	    char event_buf[512];
	    struct inotify_event* event;

	    while (1) {
		int event_pos = 0;
		int num_bytes = read(fd, event_buf, sizeof(event_buf));

		if (num_bytes < (int)sizeof(*event)) {
		    if (errno == EINTR)
			continue;
		    printf("ERROR! got a short event!\n");
		    return -1;
		}

		while (num_bytes >= (int)sizeof(*event)) {
		    int event_size;
		    event = (struct inotify_event*)(event_buf + event_pos);
		    if (event->len > 0) {
			if (event->mask & IN_OPEN) {
			    printf("file %s is opened\n", event->name);
			}
			if (event->mask & IN_CREATE) {
			    printf("file %s is created\n", event->name);
			}
		    }

		    event_size = sizeof(*event) + event->len;
		    num_bytes -= event_size;
		    event_pos += event_size;
		}
	    }
	} else {
	    printf("Error: %s\n", strerror(errno));
	}
	return 0;
#else
	return -1;
#endif
}
