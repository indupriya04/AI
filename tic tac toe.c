#include <stdio.h>

#define SIZE 9

int sum(int a, int b, int c) {
    return a + b + c;
}

void printBoard(int xState[], int zState[]) {
    char board[SIZE];
    for (int i = 0; i < SIZE; i++) {
        if (xState[i]) {
            board[i] = 'X';
        } else if (zState[i]) {
            board[i] = 'O';
        } else {
            board[i] = '0' + i;
        }
    }

    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}

int checkWin(int xState[], int zState[]) {
    int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (int i = 0; i < 8; i++) {
        if (sum(xState[wins[i][0]], xState[wins[i][1]], xState[wins[i][2]]) == 3) {
            printf("X won the game\n");
            return 1;
        }
        if (sum(zState[wins[i][0]], zState[wins[i][1]], zState[wins[i][2]]) == 3) {
            printf("O won the game\n");
            return 0;
        }
    }
    return -1;
}

int main() {
    int total_turns = 9;
    int xState[SIZE] = {0};
    int zState[SIZE] = {0};
    int turn = 1; // 1 for X and 0 for O
    int value;

    printf("Welcome to TIC-TAC-TOE\n");
    while (1) {
        printBoard(xState, zState);
        if (turn == 1) {
            printf("X's Chance\n");
        } else {
            printf("O's Chance\n");
        }
        printf("Please enter a value (0-8): ");
        scanf("%d", &value);

        if (turn == 1) {
            xState[value] = 1;
        } else {
            zState[value] = 1;
        }

        total_turns--;

        if (checkWin(xState, zState) != -1 || total_turns == 0) {
            printf("GAME OVER\n");
            printBoard(xState, zState);
            break;
        }
        turn = 1 - turn; // Switch turn
    }

    return 0;
}
