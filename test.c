#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <gnu/libc-version.h>
#include <errno.h>
#include <string.h>

int main(void) {
    static_test();
    pid_t pid = getpid();
    printf("mypid = %d \n", pid);
    static_test();

    extern char etext, edata, end;
    printf("%d, %c, %c\n", etext, edata, end);

    int page_size = sysconf(_SC_PAGESIZE);
    printf("page size = %ld\n", page_size);
    
    char* libc_v = gnu_get_libc_version();
    printf("libc version is %s\n", libc_v);
    printf("error no is %d\n", errno);
    errno = EBFONT;
    perror("an error occured");
    printf("error msg = %s\n", strerror(errno));

    return 0;
}

int static_test() {
    static int i;
    i ++;
    printf("i is %d\n", i);
}