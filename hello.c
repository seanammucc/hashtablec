#include <stdio.h>
#include <stdlib.h>

void write_record(const char *filename, const char *record){
    FILE *file = fopen(filename, "a");
    if (file == NULL){
        printf("Error opening file!\n");
        return;
    }
    fwrite(record, sizeof(char), strlen(record), file);
    fclose(file);
}

void read_record(const char *filename){
    FILE *file = fopen(filename, "rb");
    if (file == NULL){
        printf("Error opening file!\n");
        return;
    }
    char buffer[256];
    while(fgets(buffer, sizeof(buffer), file) != NULL){
        printf("%s", buffer);
    }
    fclose(file);
}