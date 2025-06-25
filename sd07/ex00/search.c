#include "../../sd04/ex00/search.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static void toLowerStr(char *dst, const char *src) {
    while (*src) {
        *dst++ = tolower((unsigned char)*src++);
    }
    *dst = '\0';
}

int caseInsensitiveSubstringMatch(const char *str, const char *substr) {
    char lstr[MAX_TITLE_LENGTH], lsubstr[MAX_TITLE_LENGTH];
    toLowerStr(lstr, str);
    toLowerStr(lsubstr, substr);
    return strstr(lstr, lsubstr) != NULL;
}

void trimInput(char *input) {
    if (!input) return;
    char *end;
    while (isspace((unsigned char)*input)) input++;
    end = input + strlen(input) - 1;
    while (end > input && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
}

void searchByTitle(Library *library) {
    char query[MAX_TITLE_LENGTH];
    printf("Enter title to search: ");
    fgets(query, sizeof(query), stdin);
    trimInput(query);
    int found = 0;
    for (int i = 0; i < library->count; ++i) {
        if (caseInsensitiveSubstringMatch(library->books[i].title, query)) {
            printBook(&library->books[i]);
            found = 1;
        }
    }
    if (!found) printf("No matches found.\n");
}

void searchByAuthor(Library *library) {
    char query[MAX_AUTHOR_LENGTH];
    printf("Enter author to search: ");
    fgets(query, sizeof(query), stdin);
    trimInput(query);
    int found = 0;
    for (int i = 0; i < library->count; ++i) {
        if (caseInsensitiveSubstringMatch(library->books[i].author, query)) {
            printBook(&library->books[i]);
            found = 1;
        }
    }
    if (!found) printf("No matches found.\n");
}