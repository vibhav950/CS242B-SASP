#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* A process whose parent process no more exists i.e. either
   finished or terminated without waiting for its child process
   to terminate is called an orphan process.*/

int main(void)
{
    pid_t child;

    if (-1 == (child = fork()))
        exit(1);
    
    if (child == 0) {
        /* Use the command `ps -Af` to check the PPID of this child 
           process after it has become an orphan (i.e., immediately
           after running this program).
           1. Who is the parent of the orphaned process?
           Do this twice, the second time after waiting for about 10 s.
           2. Where does the orphan process go? */
        printf("PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(10);
    } else {
        exit(0);
    }
}