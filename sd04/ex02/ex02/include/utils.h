#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

// Function prototypes for utility functions
char *trim_whitespace(char *str);
bool validate_phone(const char *phone);
bool validate_email(const char *email);
void print_error(const char *message);

#endif // UTILS_H