#include <stdio.h>

main(int argc, char **argv)
{
    int i;
    for(i=1; i<argc; i++)
        printf("%2d. %s\n", i, argv[i]);
}

