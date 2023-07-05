/*Given a NxM chess-board and a value K, fill the board with alternating
KxK squares made of 0s and 1s.
*/

/*
Input: N=6 M=8 K=2

Output: 00110011
        00110011
        11001100
        11001100
        00110011
        00110011

*/

#include<stdio.h>
#include<stdlib.h>

//Set n, m, k
void init_board(int *n, int *m, int *k) {
    int lin, col, dim;

    printf("Give number of lines: \n");
    scanf("%d",&lin);

    printf("Give number of coloumns: \n");
    scanf("%d",&col);

    do{
        printf("Give square dimension: \n");
        scanf("%d",&dim);

    //K dimension must be a divider of N and M
    }while((lin % dim != 0)  || (col % dim != 0));

    (*n)=lin;
    (*m)=col;
    (*k)=dim;
    

}

//Create board
int **create(int n, int m) {
    int **matrix;
    matrix = (int**)malloc(sizeof(int*)*n);
    if(matrix == NULL) {
        perror("Error when allocating memory!\n");
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<n; i++) {
        matrix[i] = malloc(sizeof(int)*m);

        if(matrix[i] == NULL) {
        perror("Error when allocating memory!\n");
        exit(EXIT_FAILURE);
        }
    }

    return matrix;
}

//Free board
void free_board(int **matrix, int n ,int m) {
    for(int i=0; i<n; i++)
        free(matrix[i]);
    free(matrix);
}

//Populate table
int **populate(int n, int m, int k) {
    int **board = create(n,m);
    int x, y, idx_sum;
    int val = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            //Get square number
            x = i/k;
            y = j/k;
            idx_sum = x+y;

            //Check if the square is even
            if(idx_sum % 2 == 0)
                val = 0;
            else
                val = 1;

            board[i][j] = val;
        }
    }
    return board;
}


//Print board
void print_board(int **board, int n, int m) {
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d",board[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int n,m,k;
    int **board;
    init_board(&n, &m, &k);
    board = populate(n, m, k);
    print_board(board, n, m);

    free_board(board, n, m);

    return 0;
}