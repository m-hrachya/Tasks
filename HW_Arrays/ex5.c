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
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int size = 0;
    int count = 0;
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
    if (size < 2) {
        printf("Total number of duplicate elements found in the array is: 0\n");
        free(arr);
        arr = NULL;
        exit(EXIT_SUCCESS);
    }
    bubble_sort(arr, size);
    int * start = arr;
    int * check = arr + 1;
    int * end = &arr[size - 1];
    while (check <= end) {
        if (*check == *start) {
            ++count;
            while ((*check == *start) && (check != end + 1)) {
                ++check;
            }
            start = check;
            ++check;
        } else {
            ++start;
            ++check;
        }
    }
    printf("Total number of duplicate elements found in the array is: %d\n", count);
    free(arr);
    arr = NULL;
    return 0;
}