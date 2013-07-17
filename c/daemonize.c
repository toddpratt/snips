#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

the_loop() {
    while(1) {
        printf(".");
        sleep(2);
    }
}

fail() {
    fprintf(stderr, "fork() or setsid() failed\n");
    exit(1);
} 

daemonize() {
    int s;
    if((s=fork()) == -1)
        fail();
    else if(s == 0 && (s=setsid()) == -1)
        fail();
    else if(s=fork() == -1)
        fail();
    else if(s==0)
        the_loop();
}

int main() {
    daemonize();
    return 0;
}

