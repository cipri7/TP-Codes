/*
sa se creeze o strucura utilizand struct si union in care memorizam urmatoarele date:
Tip figura (S sfera, C con)
Dimensiuni
    petru sfera -raza
    pentru con -raza si inaltimea
Volum
-Sa se citeasca datele pentru n<=10 figuri geometrice, sa se memoreze si sa se calculeze
volumul fiecarei figuri
-Sa se afiseze informatiile in ordine crescatoare a volumelor
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10

typedef enum {Sfera, Con}Tip_figura;

typedef struct Dimensiuni_Con {
    float raza, inaltime;
}D_C;

typedef union{
    float raza;
    D_C Dim_Con;
}Dim;


typedef struct Figuri {
    Tip_figura Tip;
    Dim Dimensiuni;
    float Volum;
}Fig;

Fig *create(int n) {
    Fig *figuri;
    figuri = malloc(sizeof(Fig)*n);
    if(figuri == NULL) {
        perror("Eroare alcoare memorie!\n");
        exit(EXIT_FAILURE);
    }
    return figuri;
}

float calculate_volum_con(float raza, float inaltime) {
    float volum = (inaltime/3)*M_PI*(raza*raza);
    return volum;
}

float calculate_vol_sfera(float raza) {
    float volum = (4/3)*M_PI*(raza*raza*raza);
    return volum;
}

Fig init_figuri() {
    Fig Figura;
    printf("Tipul Figurii: Sfera(0) sau Con(1)\n");
    scanf("%d", &Figura.Tip);
    
    switch(Figura.Tip) {
        case Con:
            printf("Dati raza Conului: \n");
            scanf("%f",&Figura.Dimensiuni.Dim_Con.raza);
            printf("Dati inaltimea Conului: \n");
            scanf("%f",&Figura.Dimensiuni.Dim_Con.inaltime);
            Figura.Volum = calculate_volum_con(Figura.Dimensiuni.Dim_Con.raza,Figura.Dimensiuni.Dim_Con.inaltime);
            break;

        case Sfera:
            printf("Dati raza Sferei: \n");
            scanf("%f",&Figura.Dimensiuni.raza);
            Figura.Volum = calculate_vol_sfera(Figura.Dimensiuni.raza);
            break;
    }
    return Figura;
}

void print_fig(Fig *Figuri, int n) {
    Fig aux;
    int sort;
    do{
        sort = 1;
        for(int i=0; i<n-1; i++) {
            if(Figuri[i].Volum < Figuri[i+1].Volum) {
                aux = Figuri[i];
                Figuri[i] = Figuri[i+1];
                Figuri[i+1] = aux;
                sort = 0;
            }
        }
    }while(!sort);

    for(int i=0; i<n; i++) {
        printf("Tip: %d\n", Figuri[i].Tip);
        printf("Volum: %f\n", Figuri[i].Volum);
    }
}

int main()
{
    Fig *Figuri; 
    int i, n;

    do
    {
        printf("Dati n:\n");
        scanf("%d", &n);
    } while (n<0 || n>MAX);

    Figuri = create(n);

    for(i=0; i<n; i++){
        Figuri[i] = init_figuri();
    }
    //     for(int i=0; i<n; i++) {
    //     printf("Tip: %d\n", Figuri[i].Tip);
    //     printf("Volum: %f\n", Figuri[i].Volum);
    // }
    print_fig(Figuri, n);


    free(Figuri);
    return 0;
}