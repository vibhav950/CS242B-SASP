#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* A process that finishes execution but has not been
   waited for by its parent becomes a "zombie". */

int main(void)
{
    pid_t child = 0;

    if (-1 == (child = fork()))
        exit(1);
    
    if (child == 0) {
        /* Use the command `ps -Af | grep "defunct"` to see the
           the newly created zombie process. 
           Note: You might have to run this command in another
           terminal before the main program exits, since it can
           be tricky to catch the zombie process before it has
           been reaped by init or a subreaper process. */
        printf("Child process (PID = %d, PPID = %d)\n", getpid(), getppid());
        exit(0);
    } else {
        /* Notice the absence of wait() */
        
        sleep(2);
    }

    return 0;
}