#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define DEF_STR_SIZE 16

int low_to_high(char * str1, char * str2) { return (strcmp(str1, str2) > 0) ? 1 : 0; }
int high_to_low(char * str1, char * str2) { return (strcmp(str1, str2) < 0) ? 1 : 0; }

void swap_strings(char * str1, char * str2) {
    char tmp[DEF_STR_SIZE];
    strcpy(tmp, str1);
    strcpy(str1, str2);
    strcpy(str2, tmp);
    return;
}

char ** init_strings(int count) {
    char ** strings = (char **) malloc(sizeof(char *) * count);
    assert(strings != NULL);
    for (int i = 0; i < count; ++i) {
        strings[i] = (char *) malloc(sizeof(char) * DEF_STR_SIZE);
        assert(strings[i] != NULL);
    }
    return strings;
}

void assign_strings(char ** strings, int count) {
    printf("Enter strings: ");
    for (int i = 0; i < count; ++i) {
        scanf("%s", strings[i]);
    }
    return;
}

void print_strings(char ** strings, int count) {
    for(int i = 0; i < count; ++i) {
        printf(":%s: ", strings[i]);
    } printf("\n");
    return;
}

void sort_strings(char ** strings, int count, int (*sort_logic)(char *, char *)) {
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (sort_logic(strings[j], strings[j + 1])) {
                swap_strings(strings[j], strings[j + 1]);
            }
        }
    }
    return;
}

int main() {
    int count = 0;
    printf("Enter string count: ");
    scanf("%d", &count);
    char ** string_array = init_strings(count);
    assign_strings(string_array, count);
    printf("Sorting from low to high\n");
    sort_strings(string_array, count, low_to_high);
    print_strings(string_array, count);
    printf("Sorting from high to low\n");
    sort_strings(string_array, count, high_to_low);
    print_strings(string_array, count);
}