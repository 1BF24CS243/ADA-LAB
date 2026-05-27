#include <stdio.h>

int N;
int board[20][20];

// Function to print solution
void printSolution() {
    int i, j;

    printf("\nSolution:\n");

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check safe position
int isSafe(int row, int col) {
    int i, j;

    // Check left side row
    for(i = 0; i < col; i++) {
        if(board[row][i] == 1)
            return 0;
    }

    // Check upper diagonal
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 1)
            return 0;
    }

    // Check lower diagonal
    for(i = row, j = col; i < N && j >= 0; i++, j--) {
        if(board[i][j] == 1)
            return 0;
    }

    return 1;
}

// Backtracking function
int solveNQueens(int col) {
    int i;

    // All queens placed
    if(col >= N)
        return 1;

    // Try every row
    for(i = 0; i < N; i++) {

        if(isSafe(i, col)) {

            board[i][col] = 1;

            // Recur for next column
            if(solveNQueens(col + 1))
                return 1;

            // Backtrack
            board[i][col] = 0;
        }
    }

    return 0;
}

int main() {

    int i, j;

    // Input from user
    printf("Enter number of queens: ");
    scanf("%d", &N);

    // Initialize board with 0
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    // Solve problem
    if(solveNQueens(0))
        printSolution();
    else
        printf("No solution exists");

    return 0;
}