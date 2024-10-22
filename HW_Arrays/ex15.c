#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void delete_from_array(int * arr, int position, int * size) {
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        free(arr);
        arr = NULL;
        exit(EXIT_FAILURE);
    }
    for (int i = position; i < *size - 1; ++i) {
        arr[i] = arr[i+1];
    }
    --(*size);
    return;
}

int main() {
    int size = 0;
    int position = 0;
    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &size);
    if (size < 0) {
        printf("Invalid size!\n");
        exit(EXIT_FAILURE);
    }
    int * arr = (int *) calloc(sizeof(int), size);
    assert(arr != NULL);
    printf("Input %d elements of array: ", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }
    printf("Input the position where to delete: ");
    scanf("%d", &position);
    delete_from_array(arr, position, &size);
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    } printf("\n");
    free(arr);
    arr = NULL;
    return 0;
}