#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_STACK_SIZE 10

void push(int * arr, int elem, int * size) {
    if (*size == MAX_STACK_SIZE) {
        printf("Stack is full!\n");
        return;
    }
    arr[(*size)++] = elem;
}

int pop(int * arr, int * size) {
    if (*size == 0) {
        printf("No elements to pop!\n");
        return -1;
    }
    return arr[--(*size)];
    
}

void print_arr(int * arr, int size) {
    for (int i = size - 1; i >= 0; --i) {
        printf("%d ", arr[i]);
    } printf("\n");
    return;
}

int main() {
    int arr [MAX_STACK_SIZE] = {0};
    int size = 0;
    push(arr, 128, &size);
    push(arr, 11, &size);
    push(arr, 128, &size);
    push(arr, 11, &size);
    push(arr, 128, &size);
    push(arr, 11, &size);
    push(arr, 128, &size);
    push(arr, 11, &size);
    push(arr, 128, &size);
    push(arr, 11, &size);
    push(arr, 128, &size);
    push(arr, 11, &size);
    printf("After pushing:\n");
    print_arr(arr, size);
    printf("Poped: %d\n", pop(arr, &size));
    printf("Poped: %d\n", pop(arr, &size));
    printf("After popping 2 times:\n");
    print_arr(arr, size);
    return 0;    
}