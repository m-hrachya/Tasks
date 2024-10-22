#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define SIZE 5

float get_avg(int * arr, int size) {
    float avg = 0;
    for (int i = 0; i < size; ++i) {
        avg += *(arr + i);
    }
    return avg / size;
}

int get_sum(int * arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += *(arr + i);
    }
    return sum;
}

int main() {
    int arr[SIZE] = {0};
    printf("Enter elements: ");
    for (int i = 0; i < SIZE; ++i) {
        scanf("%d", arr + i);
    }
    printf("Avg: %.1f, Sum: %d\n", get_avg(arr, SIZE), get_sum(arr, SIZE));
    return 0;
}