#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
	int input = *argv[1];
    size_t size;
    size = write(input, "Hello, world!", 14);
    if (size != 14) {
        printf("Can\'t write all string\n"); 
        exit(-1);
    }
    close(input);
    return 0;
}