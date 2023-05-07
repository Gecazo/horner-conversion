#include <stdio.h>
#include <stdio.h>

int main() {    

    FILE *file_to_read  = fopen("file.in","r");
    FILE *file_to_write = fopen("file.out","w+");

    if (file_to_read == NULL || file_to_write == NULL){
        printf("File would not be open!\n");
        return -1;
    };

    char c;
    while ((c=fgetc(file_to_read)) != EOF){
        
        // TODO: Implement converting to the binary

        fputc(c, file_to_write);
    };


    fclose(file_to_read);
    fclose(file_to_write)
    return 0;   

};
