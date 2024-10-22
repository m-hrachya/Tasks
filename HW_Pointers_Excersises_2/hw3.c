#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void swap(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void reverse(char * str, int start, int end) {
    if (start >= end) return;
    swap(&str[start++], &str[end--]);
    reverse(str, start, end);
    return;
}

int main() {
    char * str = (char *) malloc(sizeof(char) * (strlen("Hello, World!") + 1));
    assert(str != NULL);
    strcpy(str, "Hello, World!");
    reverse(str, 0, strlen(str) - 1);
    printf("%s\n", str);
    free(str);
    return 0;
}