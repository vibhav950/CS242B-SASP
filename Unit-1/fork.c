#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t child;
    
    /* the fork system call is a little different
       it returns 0 in the child process and the
       PID of the child to the parent process, if
       successful, else it returns -1 and no child
       is created */
    child = fork();

    if (child == -1) {
        /* although system calls rarely fail under
           normal conditions, it is always good 
           practice to check */
        printf("Fork failed!\n");
        exit(1);
    }

    if (child == 0) {
        /* this is code to be run in the child process */
        printf("Hello, I'm the child process\n");
    } else {
        printf("Hello, I'm the parent process\n"
               "The child PID is %d\n", child);
        /* Wait for the child to avoid the creation of a zombie
           Note: you can just use wait() but in most cases it is
           better to use waitpid(), especially when a process
           has multiple children, you can read more about it at
           https://manpages.ubuntu.com/manpages/trusty/en/man2/wait.2.html */
        
        // wait(NULL);

        waitpid(child, NULL, 0);
    }
}