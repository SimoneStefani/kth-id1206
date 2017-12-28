#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

    unsigned long *heap = (unsigned long*)calloc(40, sizeof(unsigned long));

    printf("heap[2]: 0x%lx\n", heap[2]);          
    printf("heap[1]: 0x%lx\n", heap[1]);        
    printf("heap[0]: 0x%lx\n", heap[0]);      
    printf("heap[-1]: 0x%lx\n", heap[-1]);      
    printf("heap[-2]: 0x%lx\n", heap[-2]);

    free(heap);

    printf("heap[2]: 0x%lx\n", heap[2]);          
    printf("heap[1]: 0x%lx\n", heap[1]);        
    printf("heap[0]: 0x%lx\n", heap[0]);      
    printf("heap[-1]: 0x%lx\n", heap[-1]);      
    printf("heap[-2]: 0x%lx\n", heap[-2]);


    int pid = getpid();

    printf("\n\n /usr/bin/vmmap %d\n\n", pid);
    char command[50];
    sprintf(command, "vmmap %d", pid);
    system(command);  

    return 0;
}