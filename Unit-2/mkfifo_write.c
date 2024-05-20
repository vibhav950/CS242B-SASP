/*
    1. mkfifo() makes a FIFO special file with name pathname.  mode
    specifies the FIFO's permissions.

    2. A FIFO special file is similar to a pipe, except that it is
    created in a different way.  Instead of being an anonymous
    communications channel, a FIFO special file is entered into the
    filesystem by calling mkfifo().

    3. Once you have created a FIFO special file in this way, any
    process can open it for reading or writing, in the same way as an
    ordinary file.
    
    4. The FIFO has to be open at both ends simultaneously before you can
    proceed to do any input or output operations on it.  Opening a FIFO
    for reading normally blocks until some other process opens the same
    FIFO for writing, and vice versa.
*/

/*
    Program to write to the FIFO; must be run with its read counterpart
    mkfifo_read.c for the demonstration.

    1. Open two split terminals.
    2. Run this exe.
    3. Wait for a few seconds to see what happens.
    4. Run the read exe.
*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int fd;
    const char *myfifo = "/tmp/myfifo";

    char buf[] = "Hello World\0";

    mkfifo(myfifo, 0666);

    /* This blocks the current process till the read end opens */
    fd = open(myfifo, O_WRONLY);

    /* The FIFO must be opened at both ends before data can be passed */
    /* The read end must be opened before the below code can execute */
    printf("Writing now...\n");
    write(fd, buf, strlen(buf) + 1);

    close(fd);
    printf("Closed\n");

    return 0;
}
