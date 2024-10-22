#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define EXPRESSION_SIZE 64
#define TOKEN_COUNT 16
#define TOKEN_SIZE 16
#define GET_OPERATOR(OPERATOR) #OPERATOR

void reverse(char str[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char* itoa(int num) {
    int i = 0;
    int isNegative = 0;
    char* str = (char*)malloc(12 * sizeof(char));

    if (str == NULL) {
        return NULL;
    }

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    do {
        str[i++] = (num % 10) + '0';
        num = num / 10;
    } while (num != 0);

    if (isNegative)
        str[i++] = '-';

    str[i] = '\0';
    reverse(str, i);

    return str;
}

int operate(int num1, char * operator, int num2) {
    if (!strcmp(operator, "%")) return num1 % num2;
    if (!strcmp(operator, "/")) return num1 / num2;
    if (!strcmp(operator, "*")) return num1 * num2;
    if (!strcmp(operator, "-")) return num1 - num2;
    if (!strcmp(operator, "+")) return num1 + num2;
    return 0;
}

void get_and_operate(char * operator, char ** tokens, int * index) {
    for (int i = 0; i < *index; ++i) {
        if (!strcmp(tokens[i], operator)) {
            char * itoa_tmp_val = itoa(operate(atoi(tokens[i - 1]), operator, atoi(tokens[i + 1])));
            strcpy(tokens[i - 1], itoa_tmp_val);
            free(itoa_tmp_val);
            free(tokens[i]);
            free(tokens[i + 1]);
            for (int j = i; j < (*index) - 2; ++j) {
                tokens[j] = tokens[j + 2];
            }
            --i;
            (*index) -= 2;
        } 
    }
}

void get_and_operate_two(char * operator1, char * operator2, char ** tokens, int * index) {
    for (int i = 0; i < *index; ++i) {
        if (!strcmp(tokens[i], operator1)) {
            char * itoa_tmp_val = itoa(operate(atoi(tokens[i - 1]), operator1, atoi(tokens[i + 1])));
            strcpy(tokens[i - 1], itoa_tmp_val);
            free(itoa_tmp_val);
            free(tokens[i]);
            free(tokens[i + 1]);
            for (int j = i; j < (*index) - 2; ++j) {
                tokens[j] = tokens[j + 2];
            }
            --i;
            (*index) -= 2;
        } else if (!strcmp(tokens[i], operator2)) {
            char * itoa_tmp_val = itoa(operate(atoi(tokens[i - 1]), operator2, atoi(tokens[i + 1])));
            strcpy(tokens[i - 1], itoa_tmp_val);
            free(itoa_tmp_val);
            free(tokens[i]);
            free(tokens[i + 1]);
            for (int j = i; j < (*index) - 2; ++j) {
                tokens[j] = tokens[j + 2];
            }
            --i;
            (*index) -= 2;
        } 
    }
}

void calculate(char * expression) {
    int size = strlen(expression);
    int index = 1;
    char * expression_copy = (char *) calloc(sizeof(char), (size + 1));
    assert(expression_copy != NULL);
    strcpy(expression_copy, expression);
    char ** tokens = (char **) malloc(sizeof(char *) * TOKEN_COUNT);
    assert(tokens != NULL);
    for (int i = 0; i < TOKEN_COUNT; ++i) {
        tokens[i] = (char *) calloc(sizeof(char), TOKEN_SIZE);
        assert(tokens[i] != NULL);
    }
    char * tmp_token = strtok(expression_copy, " ");
    strcpy(tokens[0], tmp_token);
    while (tmp_token) {
        tmp_token = strtok(NULL, " ");
        if (tmp_token == NULL) break;
        strcpy(tokens[index++], tmp_token);
    }
    for (int i = index; i < TOKEN_COUNT; ++i) {
        free(tokens[i]);
    }
    tokens = realloc(tokens, sizeof(char *) * index);
    get_and_operate("%", tokens, &index);
    get_and_operate_two("/", "*", tokens, &index);
    get_and_operate_two("+", "-", tokens, &index);

    printf("%s\n", tokens[0]);
    free(tokens[0]);
    free(tokens);
    return;
}

int main() {
    char * expression = (char *) malloc(sizeof(char) * EXPRESSION_SIZE);
    assert(expression != NULL);
    printf("Welcome to infix calculator! To exit, just type \"exit\".\nExpression \033[1;31mmust\033[0m contain spaces between operands and operators!\nGood Luck!\n\n");
    while (1) {
        printf(">>> ");
        fgets(expression, EXPRESSION_SIZE - 2, stdin);
        expression[strlen(expression) - 1] = '\0';
        if (!strcmp(expression, "exit")) break;
        calculate(expression);
        memset(expression, 0, EXPRESSION_SIZE);
    }
    free(expression);
    expression = NULL;
    return 0;
}