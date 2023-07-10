//SUDOKU SOLVER
//4x4 board
//Cipri7
#include<stdio.h>
#include<stdlib.h>
#define N 4

//Print board
void print_board(int **matrix) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//Read board from file
int **read(char *nume_fis) {
    FILE *f = NULL;
    int **board;
    f = fopen(nume_fis, "rt");
    if(f == NULL) {
        perror("Eroare deschidere fisier!\n");
        exit(EXIT_FAILURE);
    }

    //Allocate memory for the board
    board = (int**)malloc(sizeof(int*) * N);
    for(int i=0; i<N; i++)
        board[i] = malloc(sizeof(int) * N);

    //Read elements from file
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            fscanf(f, "%d", &board[i][j]);
        }
    }
    fclose(f);
    return board;
}

//Compare if a value is already present on the same line
int compare_line(int **matrix, int value, int j) {
        for(int i=0; i<N; i++) {
            if(matrix[i][j] == value)
                return 0;
        }
    return 1;
}

//Compare if a value is already present on the same coloumn
int compare_col(int **matrix, int value, int i) {
        for(int j=0; j<N; j++) {
            if(matrix[i][j] == value)
                return 0;
        }
    return 1;
}

//Solver function
int **solve(int **matrix) {
    int value;

    for(int i=0; i<N; i++) {
        value = 1;
        for(int j=0; j<N; j++) {
            if(matrix[i][j] == 0) {
                if(compare_col(matrix, value, i) && compare_line(matrix, value, j)) {
                    matrix[i][j] = value;
                    value = 1;
                }
                else {
                    value++;
                    j--;
                }
            }
        }
    }
}

int main()
{
    int **sudoku= read("sudoku_file.txt");
    print_board(sudoku);
    sudoku = solve(sudoku);
    printf("\n");
    print_board(sudoku);

return 0;
}