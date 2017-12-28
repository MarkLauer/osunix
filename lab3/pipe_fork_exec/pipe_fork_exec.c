#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
    int fd[2], result;
    size_t size;
    char resstring[14];
    if (pipe(fd) < 0) {
        printf("Can\'t create pipe\n");
        exit(-1);
    }
    result = fork();
    if (result < 0) {
        printf("Can\'t fork child\n");
        exit(-1);
    } else if (result > 0) {
        (void)execle("writer", "writer", &fd[1], 0, envp);
    } else {
        (void)execle("reader", "reader", &fd[0], 0, envp);
    }
    return 0;
}