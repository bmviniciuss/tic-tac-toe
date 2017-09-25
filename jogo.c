#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tam = 3; // board size. DO NOT CHANGE

//functions
void printBoard(char board[tam][tam], int tam);
void resetBoard(char board[tam][tam], int tam);
char playerLetterInput(void);
char playerType(void);
char otherPlayerType(char p1Type);
int checkFull(char board[tam][tam], int tam);
int playerInput(int player);
int validPlay(char board[tam][tam], int tam, int number);
int inputLin(int number);
int inputCol(int number);
int checkWin(char board[tam][tam], int tam, char type);
void clearScreen(void); //have to ajust for WINDOWS AND LINUX

//main
int main(){
    char board[tam][tam], p1Type, p2Type;
    int lin, col, turn;
    int gameOn, pInput;

    p1Type = playerType(); //p1 type
    p2Type = otherPlayerType(p1Type); //p2 type

    srand(time( NULL )); //randomize turn
    turn = 1 + rand()%2; // random turn
    /*
    turn == 1 - player 1 turn
    turn == 2 - player 2 turn
    */

    gameOn = 1;//set games on to 1 - True
    resetBoard(board, tam);

    while(gameOn){ //game begins
        if(turn == 1){ // player 1 turn
            clearScreen();
            printf("Player's 1 Turn\n");
            printBoard(board, tam);

            if(!checkFull(board, tam)){ // board not full
                while(1){

                    pInput = playerInput(turn); //player's input

                    if(validPlay(board, tam, pInput)){ //check if local is valid
                        board[inputLin(pInput)][inputCol(pInput)] = p1Type;
                        clearScreen();
                        break;
                    }
                    else{
                        printf("This position is not a valid one. Try Again\n");
                        continue;
                    }
                }

                clearScreen();
                printBoard(board, tam);

                //check win
                if(!checkFull(board, tam)){ //board not full
                    if(checkWin(board, tam, p1Type)){ //player 1 won
                        printf("Congratulations Player 1!!! You WON!!!\n");
                        gameOn = 0; //game finished
                    }
                    else{
                        turn = 2; // turn 2
                    }
                }

            }
            else{ // board full
                printf("GAME TIE.\n");
                gameOn = 0;
            }
        }
        else{ /*player 2 turn*/

            clearScreen(); // clear screen

            printf("Player's 2 Turn\n");
            printBoard(board, tam); //print board

            if(!checkFull(board, tam)){ // board not full
                while(1){

                    pInput = playerInput(turn); //player's input

                    if(validPlay(board, tam, pInput)){ //check if local is valid
                        board[inputLin(pInput)][inputCol(pInput)] = p2Type;
                        clearScreen();
                        break;
                    }
                    else{
                        printf("This position is not a valid one. Try Again\n");
                        continue;
                    }
                }

                printBoard(board, tam);

                //check win
                if(!checkFull(board, tam)){ //board not full
                    if(checkWin(board, tam, p2Type)){ //player 2 won
                        printf("Congratulations Player 2!!! You WON!!!\n");
                        gameOn = 0; //game finished
                    }
                    else{
                        turn = 1; // turn 1
                    }
                }

            }
            else{ // board full
                printf("GAME TIE.\n");
                gameOn = 0; //end game
            }

        }
    }

    //system("pause"); //use on WINDOWS
    return 0;
}

//clear screen
void clearScreen(void){
    system("clear"); //use on linux
    // system("cls"); //use on windows
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
    }
}

//gets player input
char playerLetterInput(void){
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
        pInput = playerLetterInput();
        if(pInput == 'X' || pInput == 'O'){
            return pInput;
            break;
        }
        else{
            break;
        }
    }
}

//second player type
char otherPlayerType(char p1Type){
    char p2Type;
    switch(p1Type){
        case 'X':
            p2Type = 'O';
            break;
        case 'O':
            p2Type = 'X';
            break;
    }
    return p2Type;
}

//checks if the board is FULL
int checkFull(char board[tam][tam], int tam){
    int lin,col, nNull = tam*tam, n = 0;
    for(lin = 0; lin < tam; lin++){
        for(col = 0; col < tam; col++){
            if(board[lin][col] == 'X' || board[lin][col] == 'O'){
                n++;
            }
        }
    }
    if(n == nNull){
        return 1;
    }
    else{
        return 0;
    }
}

//gets player input(number)
int playerInput(int player){
    int pInput;
    while(1){
        printf("Player %d play(1-9): ", player);
        scanf("%d", &pInput);
        printf("\n");
        if(pInput >= 1 && pInput <= 9){
            return pInput;
            break;
        }
        else{
            printf("Number out of range. Try again\n");
            continue;
        }
    }
}

//check if local is empty
int validPlay(char board[tam][tam], int tam, int number){
    int lin, col;
    switch (number) {
        case 1:
            lin = 2;
            col = 0;
            if(board[lin][col] == 'X' || board[lin][col] == 'O'){
                return 0;
            }
            else{
                return 1;
            }
            break;
        case 2:
            lin = 2;
            col = 1;
            if(board[lin][col] == 'X' || board[lin][col] == 'O'){
                return 0;
            }
            else{
                return 1;
            }
            break;
        case 3:
            lin = 2;
            col = 2;
            if(board[lin][col] == 'X' || board[lin][col] == 'O'){
                return 0;
            }
            else{
                return 1;
            }
            break;
        case 4:
            lin = 1;
            col = 0;
            if(board[lin][col] == 'X' || board[lin][col] == 'O'){
                return 0;
            }
            else{
                return 1;
            }
            break;
        case 5:
            lin = 1;
            col = 1;
            if(board[lin][col] == 'X' || board[lin][col] == 'O'){
                return 0;
            }
            else{
                return 1;
            }
            break;
        case 6:
            lin = 1;
            col = 2;
            if(board[lin][col] == 'X' || board[lin][col] == 'O'){
                return 0;
            }
            else{
                return 1;
            }
            break;
        case 7:
            lin = 0;
            col = 0;
            if(board[lin][col] == 'X' || board[lin][col] == 'O'){
                return 0;
            }
            else{
                return 1;
            }
            break;
        case 8:
            lin = 0;
            col = 1;
            if(board[lin][col] == 'X' || board[lin][col] == 'O'){
                return 0;
            }
            else{
                return 1;
            }
            break;
        case 9:
            lin = 0;
            col = 2;
            if(board[lin][col] == 'X' || board[lin][col] == 'O'){
                return 0;
            }
            else{
                return 1;
            }
            break;
    }
}

//give input lin
int inputLin(int number){
    if(number == 7 || number == 8 ||number == 9){
        return 0;
    }
    else if(number == 4 || number == 5 ||number == 6){
        return 1;
    }
    else if(number == 1 || number == 2 ||number == 3){
        return 2;
    }
}

//give input col
int inputCol(int number){
    if(number == 7 || number == 4 ||number == 1){
        return 0;
    }
    else if(number == 8 || number == 5 ||number == 2){
        return 1;
    }
    else if(number == 9 || number == 6 ||number == 3){
        return 2;
    }
}

//check if its a win by type
int checkWin(char board[tam][tam], int tam, char type){
    //horizontals
    if(board[0][0] == type && board[0][1] == type && board[0][2] == type){
        return 1;
    }
    else if(board[1][0] == type && board[1][1] == type && board[1][2] == type){
        return 1;
    }
    else if(board[2][0] == type && board[2][1] == type && board[2][2] == type){
        return 1;
    }
    //verticals
    else if(board[0][0] == type && board[1][0] == type && board[2][0] == type){
        return 1;
    }
    else if(board[0][1] == type && board[1][1] == type && board[2][1] == type){
        return 1;
    }
    else if(board[0][2] == type && board[1][2] == type && board[2][2] == type){
        return 1;
    }
    else if(board[0][0] == type && board[1][1] == type && board[2][2] == type){
        return 1;
    }
    else if(board[2][0] == type && board[1][1] == type && board[0][2] == type){
        return 1;
    }
    else{
        return 0;
    }
}
