#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int ** init_matrix (int row, int col) {
    assert((row > 0) && (col > 0));
    int ** matrix = (int **) malloc(sizeof(int *) * row);
    assert(matrix != NULL);
    for (int i = 0; i < row; ++i) {
        matrix[i] = (int *) malloc(sizeof(int) * col);
        assert(matrix[i] != NULL);
    }
    return matrix;
}

int ** transpose(int ** matrix, int row, int col) {
    int ** transposed_matrix = init_matrix(col, row);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            transposed_matrix[j][i] = matrix[i][j];
        }
    }
    return transposed_matrix;
}

void destroy(int *** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        free((*matrix)[i]);
    }
    free(*matrix);
    *matrix = NULL;
}

int main() {
    int row = 0;
    int col = 0;
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter col: ");
    scanf("%d", &col);
    int ** matrix = init_matrix(row, col);
    printf("Enter elements:\n");
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int ** transposed_matrix = transpose(matrix, row, col);
    printf("\nResult:\n");
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            printf("%d ", transposed_matrix[i][j]);
        }
        printf("\n");
    }
    destroy(&matrix, row);
    destroy(&transposed_matrix, col);
    return 0;
}