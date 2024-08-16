#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int board[MAX][MAX];

bool canPlace(int row, int col, int N) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

bool solveNQueens(int row, int N) {
    if (row >= N) {
        return true;
    }
    for (int col = 0; col < N; col++) {
        if (canPlace(row, col, N)) {
            board[row][col] = 1;
            if (solveNQueens(row + 1, N)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

void printBoard(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    printf("Enter the number of queens: ");
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }
    if (solveNQueens(0, N)) {
        printBoard(N);
    } else {
        printf("No solution exists\n");
    }
    return 0;
}
