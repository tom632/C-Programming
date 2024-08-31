#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    int i = 0;
    int player = 0;
    int turn = 0;
    int row = 0;
    int column = 0;
    int line = 0;
    int victor = 0;
    char input[3];
    char board[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}  
    };

    for (i = 0; i < 9 && victor == 0; i++) {
        printf("\n");
        printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
        printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
        printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

        player = i % 2 + 1;

        do {
            printf("\nPlayer %d, select the number of the square where you want to place your %c: ", player, (player == 1) ? 'X' : 'O');
            scanf("%s", input);

            // Check if input is a number
            int isNumber = 1;
            for (int j = 0; j < strlen(input); j++) {
                if (!isdigit(input[j])) {
                    isNumber = 0;
                    break;
                }
            }

            // Convert to number if it is a valid digit
            if (isNumber && strlen(input) == 1) {
                turn = input[0] - '0'; // Convert char to int
            } else {
                turn = -1; // Invalid input
            }

            row = --turn / 3;
            column = turn % 3;

        } 
        while(turn < 0 || turn > 8 || board[row][column] > '9');

        board[row][column] = (player == 1) ? 'X' : 'O';

        if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0])) {
            victor = player;
        } 
        else {
            for(line = 0; line <= 2; line++) {
                if ((board[line][0] == board[line][1] && board[line][0] == board[line][2]) || (board[0][line] == board[1][line] && board[0][line] == board[2][line])) {
                    victor = player;
                }
            }
        }
    }

    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

    if(victor == 0) {
        printf("\nIt's a draw\n");
    } 
    else {
        printf("\nWinner, Player %d, YOU ARE THE WINNER!\n", victor);
    }

    return 0;
}
