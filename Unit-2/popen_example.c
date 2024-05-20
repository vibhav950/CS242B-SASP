#include <stdio.h>
#include <stdlib.h>

#define MAXSTRS 5

int main(void)
{
    /* Pointer to an open stream used to write/read to the pipe */
    FILE *pipe_fd;
    /* We will sort these strings by invoking the sort process, and
       writing to it using a pipe. */
    char *strings[MAXSTRS] = {"a", "d", "b", "c", "e"};

    /* Open the process by calling popen(), that creates a pipe, forks
       and then invokes the shell.

       NOTE: Since a pipe is by definition unidirectional, the type
       argument may specify only reading or writing, not both; the
       resulting stream is correspondingly read-only or write-only.
    */
    if ((pipe_fd = popen("sort", "w")) == NULL)
    {
        perror("popen");
        exit(1);
    }

    /* Processing loop */
    for (int i = 0; i < MAXSTRS; i++)
    {
        fputs(strings[i], pipe_fd);
        fputc('\n', pipe_fd);
    }

    /* Close the pipe. On success, it returns the exit status
       of the command; otherwise returns -1 and errno is set. */
    int status = pclose(pipe_fd);

    print("Exit status of sort: %d", status);

    return (0);
}