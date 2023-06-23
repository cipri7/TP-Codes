#include <stdio.h>
#define PI 3.14

typedef enum {
    TipSfera,
    TipCon,
} TipFigura;

typedef struct {
    unsigned int raza;
} Sfera;

typedef struct {
    unsigned int raza;
    unsigned int inaltime;
} Con;

typedef struct {
    double volum;
    TipFigura tip;
    
    union {
        Sfera sfera;
        Con con;
    } data;
} Figura;

double compute_volume(Figura f) {
    if (f.tip == TipSfera) {
        int raza = f.data.sfera.raza;
        return (4/3) * PI * raza * raza * raza;
    } else if (f.tip == TipCon) {
        int raza = f.data.con.raza;
        return PI * raza * raza * f.data.con.inaltime / 3;
    }
    return -1;
}

void read_figures(Figura *figures, int n) {
    int tip;
    for (int i = 0; i < n; i++) {
        printf("Tip: 0 - Sfera, 1 - Con: ");
        scanf("%d", &tip);
        if (tip == TipSfera) {
            printf("Raza: ");
            scanf("%u", &figures[i].data.sfera.raza);
        } else if (tip == TipCon) {
            printf("Raza: ");
            scanf("%u", &figures[i].data.con.raza);
            printf("Inaltimea: ");
            scanf("%u", &figures[i].data.con.inaltime);
        } else {
            printf("Invalid input!\n");
            i--;
            continue;
        }
        
        figures[i].tip = tip;
        figures[i].volum = compute_volume(figures[i]);
    }
}

void sort_by_volume(Figura *figures, int n) {
    Figura aux;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n ; j++) {
            if (figures[i].volum > figures[j].volum) {
                aux = figures[i];
                figures[i] = figures[j];
                figures[j] = aux;
            }
        }
    }
}

void print_figures(Figura *figures, int n) {
    for (int i = 0; i < n; i++) {
        if (figures[i].tip == TipSfera) {
            printf("Figura %d: Sfera, Raza: %d, Volum: %g\n",
                i, figures[i].data.sfera.raza, figures[i].volum);
        } else if (figures[i].tip == TipCon) {
            printf("Figura %d: Con, Raza: %d, Inaltime: %d, Volum: %g\n",
                i, figures[i].data.con.raza, figures[i].data.con.inaltime,
                figures[i].volum);
        }
    }
}

int main()
{
    Figura figuri[10];
    unsigned int n;
    
    do {
        printf("Nr figuri geometrice: ");
        scanf("%d", &n);
    } while (n > 10);

    read_figures(figuri, n);
    sort_by_volume(figuri, n);
    print_figures(figuri, n);

    return 0;
}