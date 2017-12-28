#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    
    int pid = getpid();
    
    unsigned long p = 0x1;
    
    printf("  p (0x%lx): %p \n",p, &p);
    
    printf("\n\n /usr/bin/vmmap %d\n\n", pid);
    char command[50];
    sprintf(command, "vmmap %d", pid);
    system(command);
    
    return 0;
}