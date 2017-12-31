#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int volatile count;

void handler(int sig) {
    printf("signal %d was caught\n", sig);
    printf("Is this not a strange signal for this exception?!\n");
    
    exit(1);
    return;
}

int not_so_good() {
    int  x = 0;
    return 1 % x;
}

int main() {

    struct sigaction sa;

    printf("Ok, let's go - I'll catch my own error.\n");

    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGFPE, &sa, NULL) != 0) {
        fprintf(stderr, "something happend\n");
        return(1);
    }

    not_so_good();
    printf("Will probably not write this.\n");

    return(0);
}