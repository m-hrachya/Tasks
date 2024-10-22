#include <stdio.h>
#include <string.h>


void swap(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}


void permute(char* str, int left, int right) {
    if (left == right) {
        printf("%s\n", str);
    } else {
        for (int i = left; i <= right; i++) {
            swap(&str[left], &str[i]);
            permute(str, left + 1, right);
            swap(&str[left], &str[i]);
        }
    }
}

int main() {
    char str[] = "ABCD";
    int n = strlen(str);
    printf("All permutations of the string \"%s\" are:\n", str);
    permute(str, 0, n - 1);
    return 0;
}
