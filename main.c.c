#include <stdio.h>
char board[3][3];
char currentPlayer = 'X';
void initializeBoard() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = '1' + (i * 3 + j);
        }
    }
}
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}
int checkWin() {
    // Rows, Columns, and Diagonals Check
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0;
}
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
void playerMove() {
    int move;
    printf("Player %c, enter your move (1-9): ", currentPlayer);
    scanf("%d", &move);

    if (move < 1 || move > 9) {
        printf("Invalid move. Try again.\n");
        playerMove();
    } else {
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Spot already taken. Try again.\n");
            playerMove();
        } else {
            board[row][col] = currentPlayer;
        }
    }
}
int main() {
    initializeBoard();
    int game_over = 0;

    while (!game_over) {
        printBoard();
        playerMove();
        
        if (checkWin()) {
            printBoard();
            printf("Player %c wins!\n", currentPlayer);
            game_over = 1;
        } else if (checkDraw()) {
            printBoard();
            printf("It's a draw!\n");
            game_over = 1;
        } else {
            switchPlayer();
        }
    }

    return 0;
}