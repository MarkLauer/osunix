#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[]) {
    
    printf("Arguments: ");
    for (int i = 0; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("\n");
    
    int envc = 0;
    while (envp[envc] != NULL) envc++;
    printf("Environment variables:\n");
    for (int i = 0; i < envc; i++) {
        printf("%s\n", envp[i]);
    }
    
    return 0;
}
