#include <stdio.h>

#define SIZE 31250000

int is_set (int v[], int id) {
    int i, o, m;
    i = id / 8;
    o = id % 8;
    m = 1 << o;
    return v[i] & m;
}

void do_set (int v[], int id) {
    int i, o, m;
    i = id / 8;
    o = id % 8;
    m = 1 << o;
    v[i] = v[i] | m;
}

void initialize (int v[]) {
    int i;
    for(i=0; i<SIZE; i++) {
        v[i] = 0;
    }
}

int main (void) {
    int id_status[SIZE], i;
    initialize(id_status);
    do_set(id_status, 23432);
    do_set(id_status, 23436);
    do_set(id_status, 23434);
    for(i=23430; i<23437; i++) {
        if (is_set(id_status, i))
            printf("%d is set\n", i);
        else
            printf("%d is not set\n", i);
    }
    return 0;
}

