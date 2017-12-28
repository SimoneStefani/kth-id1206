#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

char global[] = "This is a global string";

void zot(unsigned long *stop) {
    
    unsigned long r = 0x3;
    
    unsigned long *i;
    for (i = &r; i <= stop; i++) {
        printf(" %p      0x%lx\n", i, *i);
    }
}

void foo(unsigned long *stop) {
    unsigned long q = 0x2;
  
    zot(stop);
}

int main() {

    int pid = getpid();
    
    unsigned long p = 0x1;

    foo(&p);

    back:
        printf("  p: %p \n", &p);
        printf("  back: %p \n",  &&back);

        printf("\n\n /usr/bin/vmmap %d\n\n", pid);
        char command[50];
        sprintf(command, "vmmap %d", pid);
        system(command);

        return 0;
}