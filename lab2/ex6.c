#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    pid_t pid = (pid_t)fork();

    if (pid == -1) {
        printf("Error\n");
    } else if (pid == 0) {
        (void)execle("/bin/cat", "bin/cat", "ex6.c", 0, envp);
    } else {
        printf("I'm a parent! My pid: %d, my ppid: %d\n", (int)getpid(), (int)getppid());
    }
    
    return 0;
}