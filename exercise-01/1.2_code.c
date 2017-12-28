#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

char global[] = "This is a global string";

int main() {
    
    int pid = getpid();
    
    foo:
        printf("process id: %d\n", pid);
        printf("global string: %p\n", &global);
        printf("the code: %p\n", &&foo);    
        
        printf("\n\n /usr/bin/vmmap %d\n\n", pid);
        char command[50];
        sprintf(command, "vmmap %d", pid);
        system(command);
        
        return 0;
}