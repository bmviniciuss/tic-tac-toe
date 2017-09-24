#include <stdio.h>

int tam = 3; // board size
enum status{CONTINUE, WON, LOST}; //game status

//functions
void printBoard(char board[tam][tam], int tam);
void resetBoard(char board[tam][tam], int tam);
char playerInput(void);
char playerType(void);

int main(){
    char board[tam][tam], p1Type, p2Type;
    int lin, col, turn;

    // printf("Player 1, 'X' or 'O'? ");

    p1Type = playerType();
    switch(p1Type){
        case 'X':
            p2Type = 'O';
            break;
        case 'O':
            p2Type = 'X';
            break;
    }

    printf("P1 = %c\n", p1Type);
    printf("P2 = %c\n", p2Type);
    // printBoard(board, tam);

    return 0;
}

//print the board
void printBoard(char board[tam][tam], int tam){
    int lin, col;
    for(lin = 0; lin < tam; lin++){
        for(col =0; col < tam; col++){
            printf("%2c", board[lin][col]);
        }
        printf("\n");
    }
}

//populate the board with defaults values
void resetBoard(char board[tam][tam], int tam){
    int lin, col;
    for(lin = 0; lin < tam; lin++){
        for(col =0; col < tam; col++){
            board[lin][col]= '-';
        }
        printf("\n");
    }
}

//gets player input
char playerInput(void){
    char pInput;
    while(1){
        scanf("%c", &pInput);
        if(pInput == 'x' || pInput == 'X'){
            return 'X';
        }
        else if(pInput == 'o' || pInput == 'O'){
            return 'O';
        }
        else{
            continue;
        }
    }
}
//gets player type
char playerType(void){
    char pInput;
    while(1){
        printf("Player 1, 'X' or 'O': ");
        pInput = playerInput();
        if(pInput == 'X' || pInput == 'O'){
            return pInput;
            break;
        }
        else{
            break;
        }
    }
}
