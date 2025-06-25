#ifndef SEARCH_H
#define SEARCH_H

#include "book.h"
#include "library.h"

// Function prototypes for searching books
void searchByTitle(Library *library);
void searchByAuthor(Library *library);
int caseInsensitiveSubstringMatch(const char *str, const char *substr);
void trimInput(char *input);

#endif // SEARCH_H