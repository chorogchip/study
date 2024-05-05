#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main(void) {
    syscall(SYS_write, 1, "asd", 3);
    write(1, "asd", 3);
    fwrite("asd", 1, 3, stdout);
    printf("asd");
}