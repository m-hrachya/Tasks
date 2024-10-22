#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int get_count(int * arr, int element, int index, int size) {
    int count = 1;
    for (int i = 0; i < size; ++i) {
        if (i == index) continue;
        if (arr[i] == element) ++count;
    }
    return count;
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
    int * elem_counts = (int *) calloc(sizeof(int), size);
    assert(elem_counts != NULL);
    printf("Input %d elements of array: ", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size; ++i) {
        elem_counts[i] = get_count(arr, arr[i], i, size);
    }
    for (int i = 0; i < size; ++i) {
        printf("Element: %d, Count: %d\n", arr[i], elem_counts[i]);
    }
    free(arr);
    free(elem_counts);
    arr = NULL;
    elem_counts = NULL;
    return 0;
}