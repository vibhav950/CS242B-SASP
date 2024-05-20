/* Program to read from the FIFO. */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int fd;
    const char *myfifo = "/tmp/myfifo";

    char buf[30];

    fd = open(myfifo, O_RDONLY);
    read(fd, buf, sizeof(buf));
    printf("In reader process\n%s\n", buf);
    close(fd);

    return 0;
}
