#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
    int output = *argv[1];
    size_t size;
    char resstring[14];
    size = read(output, resstring, 14);
    if (size < 0) {
        printf("Can\'t read string\n"); 
        exit(-1);
    }
    printf("%s\n", resstring);
    close(output);
    return 0;
}