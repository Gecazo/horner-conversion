#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {    

    FILE *file_to_read  = fopen("file.in","r");
    FILE *file_to_write = fopen("file.out","w+");

    if (file_to_read == NULL || file_to_write == NULL){
        printf("File would not be open!\n");
        return -1;
    };

    char chunk[128];

    // Store the chunks of text into a line buffer
    size_t len = sizeof(chunk);
    char *line = malloc(len);

    if (line == NULL){
        printf("Unable to allocate memmory!\n");
        return -1;
    };

    line[0] = '\0';

    while (fgets(chunk, sizeof(chunk), file_to_read) != NULL){
        size_t len_used = strlen(line);
        size_t chunk_used = strlen(chunk);

        if (len - len_used < chunk_used){
            len *= 2;
            if((line = realloc(line, len)) == NULL){
                printf("Unable to reallocate memory!\n");
                free(line);
                return(-1);
            };
        };

        strncpy(line + len_used, chunk, len - len_used);
        len_used += chunk_used;

        if(line[len_used - 1] == '\n'){
            // TODO: Implement converting to the binary
            fputs(line, file_to_write);
            line[0] = '\0';
        };
    };

    free(line);

    fclose(file_to_read);
    fclose(file_to_write);
    return 0;   

};
