#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
char* trim_whitespace(char* str);
void print_results(const char* message, const char* results[], int count);
void free_memory(char** array, int count);

#endif // UTILS_H