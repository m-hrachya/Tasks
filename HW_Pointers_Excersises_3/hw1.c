#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define MAX_NAME_SIZE 16

char ** init_names(int count) {
    assert(count > 0);
    char ** names = (char **) malloc(sizeof(char *) * count);
    assert(names != NULL);
    for (int i = 0; i < count; ++i) {
        names[i] = (char *) malloc(sizeof(char) * MAX_NAME_SIZE);
        assert(names[i] != NULL);
    }
    return names;
} 

void get_names(char ** names, int count) {
    printf("Enter %d names: ", count);
    for (int i = 0; i < count; ++i) {
        scanf("%s", names[i]);
    }
    return;
}

int exists(char * example, char ** names, int * count_of_each_element, int size) {
    if (size == 0) return 0;
    int flag = 0;
    for (int i = 0; i < size; ++i) {
        if (!strcmp(example, names[i])) {
            --count_of_each_element[i];
            flag = 1;
        }
    }
    return flag;
}

int get_duplicates_count(int * count_of_each_element, int count) {
    int new_count = 0;
    for (int i = 0; i < count; ++i) {
        if (count_of_each_element[i] > 0) ++new_count;
    }
    return new_count;
}

char ** get_duplicates(char ** names, int count, int * new_count) {
    int * count_of_each_element = (int *) calloc(sizeof(int), count);
    assert(count_of_each_element != NULL);
    for (int i = 0; i < count; ++i) {
        if (exists(names[i], names, count_of_each_element, i)) {
            count_of_each_element[i] = 1;
        }
    }
    *new_count = get_duplicates_count(count_of_each_element, count);
    char ** duplicates = init_names(*new_count);
    int ind = 0;
    for (int i = 0; i < count; ++i) {
        if (count_of_each_element[i] > 0) {
            strcpy(duplicates[ind++], names[i]);
        }
    }
    free(count_of_each_element);
    return duplicates;
}

void print_duplicates(char ** duplicates, int count) {
    for (int i = 0; i < count; ++i) {
        printf("%s ", duplicates[i]);
    } printf("\n");
    return;
}

void destroy_matrix(char *** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        free((*matrix)[i]);
    }
    free(*matrix);
    *matrix = NULL;
}

int main() {
    int count = 0;
    int duplicates_count = 0;
    printf("Enter count: ");
    scanf("%d", &count);
    char ** names = init_names(count);
    get_names(names, count);
    char ** duplicates = get_duplicates(names, count, &duplicates_count);
    print_duplicates(duplicates, duplicates_count);
    destroy_matrix(&duplicates, duplicates_count);
    destroy_matrix(&names, count);
    return 0;
}