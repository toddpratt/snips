
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "ord.dat"

typedef struct {
    char lname[50];
    char fname[50];
} rec_t;

bail(char *msg) {
    fprintf(stderr, "ERROR: %s\n", msg);
    exit(EXIT_FAILURE);
}

FILE *db_open(char *mode) {
    FILE *fp;
    if((fp=fopen(FILENAME, mode))==NULL)
        bail("unable to open data file");
    return fp;
}

db_seek(FILE *fp, unsigned long long pos) {
    if(fseek(fp, pos * sizeof(rec_t), SEEK_SET) != 0)
        bail("read_next_id(): seek failed");
}

unsigned long long read_next_id(FILE *fp) {
    unsigned long long next_id;
    db_seek(fp, 0);
    if(fread(&next_id, sizeof next_id, 1, fp) != 1)
        bail("unable to read next_id");
    return next_id;
}

write_next_id(FILE *fp, unsigned long long next_id) {
    db_seek(fp, 0);
    if(fwrite(&next_id, sizeof next_id, 1, fp) != 1)
        bail("unable to write next_id");
    fflush(fp);
    printf("Updated next_id 1: %llu\n", next_id);
    next_id = read_next_id(fp);
    printf("Updated next_id 2: %llu\n", next_id);
}

init_file() {
    FILE *fp;
    fp = db_open("wb+");
    write_next_id(fp, 1);
    fclose(fp);
}

show_count() {
    FILE *fp;
    unsigned long long id;
    fp = db_open("rb");
    id = read_next_id(fp);
    printf("Record count: %llu\n", id - 1);
    close(fp);
}

write_record(char *first, char*last) {
    FILE *fp;
    rec_t record;
    unsigned long long id;
    printf("writing...");
    fp = db_open("rb+");
    strcpy(&record.fname, first);
    strcpy(&record.lname, last);
    id = read_next_id(fp);
    db_seek(fp, id);
    if(fwrite(&record, sizeof record, 1, fp) != 1)
        bail("unable to save record!");
    write_next_id(fp, id + 1);
    fclose(fp);
    printf("OK\n\n");
}

read_record(unsigned long long id) {
    FILE *fp;
    unsigned long long next_id;
    rec_t record;
    fp = db_open("rb");
    next_id = read_next_id(fp);
    if(id < 1 || id >= next_id)
        bail("specified record does not exist");
    db_seek(fp, id);
    if(fread(&record, sizeof record, 1, fp) != 1)
        bail("unable to read record!");
    printf("First: %s\n", record.fname);
    printf("Last: %s\n", record.lname);
    fclose(fp);
}

print_record(rec_t *record) {
    printf("First: %s\n", record->fname);
    printf("Last: %s\n", record->lname);
}

list_all() {
    FILE *fp;
    unsigned long long next_id, i;
    rec_t record;
    fp = db_open("rb");
    next_id = read_next_id(fp);
    for(i=1; i<next_id; i++) {
        db_seek(fp, i);
        if(fread(&record, sizeof record, 1, fp) != 1)
            bail("unable to read record!");
        print_record(&record);
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if(argc == 2) {
        if(strcmp(argv[1], "init") == 0)
            init_file();
        else
        if(strcmp(argv[1], "count") == 0)
            show_count();
        else
        if(strcmp(argv[1], "list") == 0)
            list_all();
        else
            read_record(strtoull(argv[1], NULL, 10));
    } else if(argc == 3) {
        printf("new...\n");
        write_record(argv[1], argv[2]);
        printf("done..\n");
    }
    return 0;
}

