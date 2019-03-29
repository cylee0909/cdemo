#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(void) {
    pid_t pid = getpid();
    printf("mypid = %d \n", pid);
    return 0;
}