#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* NOTE: you will have to compile foo.c first,
   gcc foo.c -o foo */

int main(void)
{
    printf("Before exec(), PID = %d\n", getpid());

    /* visit foo.c and try to predict the output before running this code */
    execl("foo.out", "foo.out", NULL);

    // =====================================================

    printf("This will not get printed!\n");
    return 0;
}