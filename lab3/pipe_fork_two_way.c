#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int fd1[2], fd2[2], result;
    size_t size;
    char resstring1[6], resstring2[7];
    (void)pipe(fd1);
    (void)pipe(fd2);
    result = fork();
    if (result > 0) {
        close(fd1[0]);
        close(fd2[1]);
        size = write(fd1[1], "parent", 7);
        if (size != 7) {
            printf("can\'t write parent string\n"); 
            exit(-1);
        }
        close(fd1[1]);
        size = read(fd2[0], resstring1, 6);
        if (size < 0) {
            printf("can\'t read child string\n"); 
            exit(-1);
        }
        close(fd2[0]);
        printf("%s\n", resstring1);
    } else {
        close(fd1[1]);
        close(fd2[0]);
        size = write(fd2[1], "child", 6);
        if (size != 6) {
            printf("can\'t write child string\n"); 
            exit(-1);
        }
        close(fd2[1]);
        size = read(fd1[0], resstring2, 7);
        if (size < 0) {
            printf("can\'t read parent string\n"); 
            exit(-1);
        }
        close(fd1[0]);
        printf("%s\n", resstring2);
    }
    return 0;
}