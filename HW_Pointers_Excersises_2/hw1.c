#include <stdio.h>
#include <stdlib.h>
#define LEAK_SIZE 128
void mem_leak() {
    int * ptr = (int *) malloc(sizeof(int) * 128);
    return; // Memory leaked
}

int main() {
    mem_leak();
    return;
}