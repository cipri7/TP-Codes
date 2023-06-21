#include<stdio.h>
#include<stdlib.h>
// copiaza ditr-un fisier in altul utilizand argumente in linia de comanda

void copy(char *source, char *dest) {
    FILE *in, *out;
    char buffer[512];
    int nr_bytes;
    in = fopen(source, "r");
    if(in == NULL) {
        perror("Error while opening file.");
        exit(EXIT_FAILURE);
    }
    
    out = fopen(dest, "w");
    if(dest == NULL) {
        perror("Error opening file.");
        fclose(in);
        exit(EXIT_FAILURE);
    }
    
    //while(!feof(in)) {
        nr_bytes = fread(buffer, 1, 512, in);
        fwrite(buffer, 1, nr_bytes, out);
    //}
    fclose(in);
    fclose(out);

}


int main(int argc, char **argv)
{
    if(argc != 3) {
        printf("Usage ./copy_files file_source file_dest");
        return 0;
    }
    copy(argv[1], argv[2]);




    return 0;
}