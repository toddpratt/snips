#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char **argv) {
    int c, p, s, n = 0;
    while((c = getopt(argc, argv, "f:")) > -1) {
        n++;
        if((p = fork()) > -1) {
            if(p == 0) {
                sleep(n);
                printf("%s\n", optarg);
                exit(n);
            } else
                printf("forked number %d pid %d\n", n, p);
        }
    }
    printf("waiting...\n");

    while(p = wait(&s) > -1)
        if(WIFEXITED(s))
            printf("completed: %d (%d)", p, WEXITSTATUS(s));
        else
            printf("%d did not terminate normally\n", p);

    printf("done.\n");
    return 0;
}

