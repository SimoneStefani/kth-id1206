#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

char global[] = "This is a global string";

int main() {

    int pid = getpid();

    const int read_only = 123456;

    foo:
        printf("process id: %d\n", pid);
        printf("global string: %p\n", &global);
        printf("read only:  %p\n", &read_only);
        printf("the code: %p\n", &&foo);

        printf("\n\n /usr/bin/vmmap %d\n\n", pid);
        char command[50];
        sprintf(command, "vmmap %d", pid);
        system(command);

        return 0;
        
}