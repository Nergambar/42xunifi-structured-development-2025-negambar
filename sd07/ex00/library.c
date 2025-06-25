#include "../../sd04/ex00/library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readCatalog(const char *filename, Library *library) {
    if (!filename || !library) return -1;
    FILE *file = fopen(filename, "r");
    if (!file) return -1;
    char line[512];
    library->count = 0;
    while (fgets(line, sizeof(line), file) && library->count < MAX_BOOKS) {
        parseLine(line, library);
    }
    fclose(file);
    return library->count;
}

void parseLine(const char *line, Library *library) {
    if (!line || !library) return;
    int id;
    char title[MAX_TITLE_LENGTH], author[MAX_AUTHOR_LENGTH];
    if (sscanf(line, "%d,%255[^,],%255[^\n]", &id, title, author) == 3) {
        initializeBook(&library->books[library->count], id, title, author);
        if (isValidBook(&library->books[library->count]))
            library->count++;
    }
    // else: skip malformed line
}

void freeLibrary(Library *library) {
    // No dynamic allocation in this implementation
    (void)library;
}

void printLibrary(const Library *library) {
    if (!library) return;
    for (int i = 0; i < library->count; ++i) {
        printBook(&library->books[i]);
    }
}