#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid = (pid_t)fork();

    if (pid == -1) {
        printf("Error\n");
    } else if (pid == 0) {
        printf("I'm a child! My pid: %d, my ppid: %d\n", (int)getpid(), (int)getppid());
    } else {
        printf("I'm a parent! My pid: %d, my ppid: %d\n", (int)getpid(), (int)getppid());
    }
    
    return 0;
}
