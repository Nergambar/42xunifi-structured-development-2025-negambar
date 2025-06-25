#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

char *trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate after the last non-space character
    *(end + 1) = '\0';

    return str;
}

int validate_phone(const char *phone) {
    int has_digit = 0;

    for (const char *p = phone; *p; p++) {
        if (isdigit((unsigned char)*p)) {
            has_digit = 1;
        } else if (!isdigit((unsigned char)*p) && *p != '+' && *p != '-' && *p != ' ' && *p != '(' && *p != ')') {
            return 0; // Invalid character found
        }
    }

    return has_digit; // Must contain at least one digit
}

int validate_email(const char *email) {
    const char *at = strchr(email, '@');
    if (!at || at == email || at == email + strlen(email) - 1) {
        return 0; // No '@' or empty local/domain part
    }

    const char *dot = strchr(at, '.');
    return dot && dot != at + 1 && dot != email + strlen(email) - 1; // Must have at least one dot in the domain
}

void report_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
}