#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2
#define DIAGONAL_WIN 5

int current_player = PLAYER_X;

char * init_board() {
    char * board = (char *) malloc(sizeof(char) * SIZE * SIZE);
    assert(board != NULL);
    for (int i = 0; i < SIZE * SIZE; ++i) {
        board[i] = ' ';
    }
    return board;
}

void print_board(char * board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("\"%c\" ", board[SIZE * i + j]);
        }
        printf("\n\n");
    }
}

void destroy_board(char * board) {
    free(board);
    return;
}

int win_in_row(char * board, int index) {
    return (board[SIZE * index] != ' ') && (board[SIZE * index] == board[SIZE * index + 1]) && (board[SIZE * index] == board[SIZE * index + 2]) ? 1 : 0;
}

int win_in_col(char * board, int index) {
    int column_number = index % SIZE;
    return (board[column_number] != ' ') && (board[column_number] == board[SIZE + column_number]) && (board[column_number] == board[2 * SIZE + column_number]) ? 1 : 0;
}

int win_in_diagonals(char * board) {
    if ((board[0] != ' ') && (board[0] == board[SIZE + SIZE / 2]) && (board[0] == board[SIZE * SIZE - 1])) return 1;
    if ((board[SIZE - 1] != ' ') && (board[SIZE - 1] == board[SIZE + SIZE / 2]) && (board[SIZE - 1] == board[SIZE * SIZE - SIZE])) return 1;
    return 0;
}

void anonce_winner(char * board, int index) {
    int winner = board[index * SIZE + index] == 'O' ? PLAYER_O : PLAYER_X;
    print_board(board);
    if (winner == PLAYER_O) printf("Player O wins!\n");
    else printf("Player X wins!\n");
    return;
}

void check_for_win(char * board) {
    for (int i = 0; i < SIZE; ++i) {
        if (win_in_row(board, i) || win_in_col(board, i)) {
            anonce_winner(board, i);
            destroy_board(board);
            exit(EXIT_SUCCESS);
        }
    }
    if (win_in_diagonals(board)) {
        anonce_winner(board, DIAGONAL_WIN);
        destroy_board(board);
        exit(EXIT_SUCCESS);
    }
}

void check_for_draw(char * board) {
    for (int i = 0; i < SIZE * SIZE; ++i) {
        if (board[i] == ' ') return;
    }
    printf("Draw!\n");
    destroy_board(board);
    exit(EXIT_SUCCESS);
}

void play(char * board) {
    int row = 0;
    int col = 0;
    int success = 0;
    if (current_player == PLAYER_X) printf("Player X (x, y): ");
    else printf("Player O (x, y): ");
    do {
        scanf("%d %d", &row, &col);
        if (row < 0 || col < 0 || row > 3 || col > 3) {
            printf("Invalid row or column entered!\n");
            continue;
        }
        if (board[SIZE * row + col] == ' ') {
            board[SIZE * row + col] = current_player == PLAYER_O ? 'O' : 'X';
            success = 1;
        } else {
            printf("That place is not available! Try again: ");
            continue;
        }
    } while (success == 0);
    current_player = current_player == PLAYER_O ? PLAYER_X : PLAYER_O;
    printf("\n");
    check_for_win(board);
    check_for_draw(board);
}

int main() {
    char * board = init_board();
    print_board(board);
    while (1) {
        play(board);
        print_board(board);
    }
}