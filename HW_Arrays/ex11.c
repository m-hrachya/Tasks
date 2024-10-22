#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int * num1, int * num2) {
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

void bubble_sort(int * arr, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int size = 0;
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
    bubble_sort(arr, size);
    printf("Elements of array in sorted ascending order:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    arr = NULL;
    return 0;
}