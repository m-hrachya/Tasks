#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void multiply_matrixes(int ** first_matrix, int ** second_matrix, int ** result_matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result_matrix[i][j] += first_matrix[i][k] * second_matrix[k][j]; 
            }
        }
    }
}

void print_matrix(int ** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(int ** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    return;
}

int main() {
    int size;
    printf("Input matrix size: ");
    scanf("%d", &size);
    if (size < 1) {
        printf("Invalid size!\n");
        exit(EXIT_FAILURE);
    }
    int ** first_matrix = (int **) malloc(sizeof(int *) * size);
    int ** second_matrix = (int **) malloc(sizeof(int *) * size);
    assert(first_matrix != NULL && second_matrix != NULL);
    for (int i = 0; i < size; ++i) {
        first_matrix[i] = (int *) malloc(sizeof(int) * size);
        assert(first_matrix[i] != NULL);
        second_matrix[i] = (int *) malloc(sizeof(int) * size);
        assert(second_matrix[i] != NULL);
    }
    printf("Enter first matrix elements:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            scanf("%d", &first_matrix[i][j]);
        }
    }
    printf("Enter second matrix elements:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            scanf("%d", &second_matrix[i][j]);
        }
    }
    int ** result_matrix = (int **) malloc(sizeof(int *) * size);
    assert(result_matrix != NULL);
    for (int i = 0; i < size; ++i) {
        result_matrix[i] = (int *) calloc(sizeof(int), size);
        assert(result_matrix[i] != NULL);
    }
    multiply_matrixes(first_matrix, second_matrix, result_matrix, size);
    printf("The First matrix is:\n");
    print_matrix(first_matrix, size);
    printf("The Second matrix is:\n");
    print_matrix(second_matrix, size);
    printf("The multiplication of two matrix is:\n");
    print_matrix(result_matrix, size);
    free_matrix(first_matrix, size);
    free_matrix(second_matrix, size);
    free_matrix(result_matrix, size);
    return 0;
}