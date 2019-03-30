#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(void) {
    static_test();
    pid_t pid = getpid();
    printf("mypid = %d \n", pid);
    static_test();

    extern char etext, edata, end;
    printf("%d, %c, %c\n", etext, edata, end);

    int page_size = sysconf(_SC_PAGESIZE);
    printf("page size = %ld\n", page_size);
    return 0;
}

int static_test() {
    static int i;
    i ++;
    printf("i is %d\n", i);
}