#include<stdio.h>
#include<stdlib.h>

int my_strlen(char *s) {
    int i=0;
    while(*s++){
        i++;
    }
    return i-1;
}
void my_strcpy(char *dest, char *src) {
    int i=0;
    while((dest[i] = src[i]) != '\0'){
        i++;
    }
}

int main()
{
char s1[20  ], *s2;
char buffer[256];
fgets(buffer,256, stdin);
printf("%s\n", buffer);
printf("%d\n", my_strlen(buffer));
my_strcpy(s1, buffer);
printf("Copiat: %s\n", s1);



    return 0;
}