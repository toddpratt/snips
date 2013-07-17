
#include <stdio.h>

int main() {
    FILE *fp;
    long n;

    n = 91;
    fp = fopen("junk.dat", "rb+");
    rewind(fp);
    fwrite(&n, sizeof n, 1, fp);
    rewind(fp);
    fread(&n, sizeof n, 1, fp);
    printf("n is %ld\n", n);

    n = 2;
    rewind(fp);
    fwrite(&n, sizeof n, 1, fp);
    rewind(fp);
    fread(&n, sizeof n, 1, fp);
    printf("n is %ld\n", n);

    n = 23;
    rewind(fp);
    fwrite(&n, sizeof n, 1, fp);
    rewind(fp);
    fread(&n, sizeof n, 1, fp);
    printf("n is %ld\n", n);
}

