#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <scsi/sg.h>
#include <sys/ioctl.h>
#include <string.h>

#define BUF_SIZE 4096

char buf[BUF_SIZE];

int main(int argc, char * argv[]) {

	if (argc < 3) {
		fprintf(stderr, "Usage: %s device command [file]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int fd = open(argv[1], O_RDONLY);

	if(fd < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	
	int cmd = atoi(argv[2]);

	if (argc == 4) {
		int fd = open(argv[1], O_RDONLY);

		if(fd < 0) {
			perror("open");
			exit(EXIT_FAILURE);
		}

		int ret = read(0, buf, sizeof(buf));

		if (ret < 0) {
			perror("read");
			exit(EXIT_FAILURE);
		}
	}
	
	

	int ret = ioctl(fd, cmd, buf);
	if (ret < 0) {
		perror("ioctl");
		exit(EXIT_FAILURE);
	}

	close(fd);

	return EXIT_SUCCESS;
}
