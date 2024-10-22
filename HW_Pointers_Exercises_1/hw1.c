#include <stdio.h>

void foo(int * num) { *num *= 2; }

int main() {
    int num = 0;
    printf("Enter number: ");
    scanf("%d", &num);
    foo(&num);
    printf("Result: %d\n", num);
    return 0;
}