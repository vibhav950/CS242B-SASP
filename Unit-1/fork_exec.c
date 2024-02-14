#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/* NOTE: you will have to compile foo.c first,
   gcc foo.c -o foo */

int main()
{
    pid_t child;

    /* call fork() */
    if (-1 == (child = fork()))
        /* fork failed, see fork.c for why we do this */
        exit(1);

    if (child == 0) {
        /* the child process code */
        execl("foo.out", "foo.out", NULL);
        /* foo.c and try to predict the output before running this code */
    } else {
        printf("In the parent (PID = %d, Child PID = %d)\n", getpid(), child);
        waitpid(child, NULL, 0);
    }

    return 0;
}