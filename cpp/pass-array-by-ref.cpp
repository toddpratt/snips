
#include <iostream>

#define ARRAY_SIZE 100

void print(int (&a)[ARRAY_SIZE]) {
    for(int i=0; i<ARRAY_SIZE; i++)
        std::cout << a[i] << std::endl;
}

void init(int (&a)[ARRAY_SIZE]) {
    for(int i=0; i<ARRAY_SIZE; i++)
        a[i] = i*2;
}

int main(void) {
    int a[ARRAY_SIZE];
    init(a);
    print(a);
    return 0;
}
