/*
a)sa se scrie o functie care utilizand operatorii pe biti
afiseaza reprezentarea interna a unui numar intreg fara semn
primit ca si parametru
b)sa se scrie o functie care contorizeaza nr de biti de 1
a unui numar
c)sa se citeasca mai multe nr intregi fara semn, terminate cu CTRL + Z
sa se afiseze pentru fiecare reprezentarea interna utlizand
functile a) si b)
d)numerel care contin un nr impar de biti de 1 sa se salveze
intt un fisier binar. numele fisierului se va citii de la tastaura
e)sa se afiseze continutul fisierului creat
*/

#include <stdio.h>
#include <stdlib.h>

void print_bits(unsigned int n) {
    for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int sum_bits(unsigned int n) {
    int suma = 0;
    for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--) {
        suma += (n >> i) & 1;
    }

    return suma;
}

void process_input(char *filename) {
    FILE *output = fopen(filename, "ab");
    if (output == NULL) {
        perror("Could not open file!");
        exit(EXIT_FAILURE);
    }

    int number, sum;

    // basically, we'll read while we still have data in the stdin stream.
    // we can stop the stream by pressing CTRL+Z on Windows, or CTRL+D on Linux.
    while (scanf("%d", &number) == 1) {
        print_bits(number);
        sum = sum_bits(number);
        printf("Suma biti: %d\n", sum);

        if (sum % 2)
            fwrite(&number, sizeof(int), 1, output);
    }

    printf("Finished processing input!\n");
    fclose(output);
}

void print_binary_file(char *filename) {
    FILE *input = fopen(filename, "rb");
    if (input == NULL) {
        perror("Could not open file!");
        exit(EXIT_FAILURE);
    }
    
    printf("%s binary file contents:\n", filename);
    int number;
    while(!feof(input)) {
        fread(&number, sizeof(int), 1, input);
        printf("%08X ", number);
    }

    fclose(input);
}

int main()
{
    char filename[100];
    printf("Output file: ");
    scanf("%99s", filename);
    
    process_input(filename);
    print_binary_file(filename);

    return 0;
}