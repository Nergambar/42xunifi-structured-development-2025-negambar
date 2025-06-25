#include "../../sd04/ex00/utils.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* trim_whitespace(char* str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
    return str;
}

void print_results(const char* message, const char* results[], int count) {
    printf("%s\n", message);
    for (int i = 0; i < count; ++i) {
        printf("%s\n", results[i]);
    }
}

void free_memory(char** array, int count) {
    for (int i = 0; i < count; ++i) {
        free(array[i]);
    }
    free(array);
}