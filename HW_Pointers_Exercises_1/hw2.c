#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 10

void copy_array(const int * src, int * dest, int size) {
    for (int i = 0; i < size; ++i) {
        dest[i] = src[i];
    }
    return;
}

int main() {
    int src[SIZE] = {0};
    int dest[SIZE] = {0};
    printf("Enter src elements (%d elements): ", SIZE);
    for (int i = 0; i < SIZE; ++i) {
        scanf("%d", &src[i]);
    }
    copy_array(src, dest, SIZE);
    printf("Dest array elements: ");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", dest[i]);
    } 
    printf("\n");
    return 0;
}