#include <stdio.h>
#include <unistd.h>

int main(void)
{
    sleep(2);
    printf("Hello from foo.exe (PPID = %d, PID = %d)\n", getppid(), getpid());
    return 0;
}