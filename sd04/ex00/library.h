#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"

#define MAX_BOOKS 1000

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

// Function prototypes
int readCatalog(const char *filename, Library *library);
void parseLine(const char *line, Library *library);
void freeLibrary(Library *library);
void printLibrary(const Library *library);

#endif // LIBRARY_H