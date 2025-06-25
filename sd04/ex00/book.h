#ifndef BOOK_H
#define BOOK_H

#include <stdbool.h>

#define MAX_TITLE_LENGTH 256
#define MAX_AUTHOR_LENGTH 256

// Struct to represent a book
typedef struct {
    int id;                         // Unique identifier for the book
    char title[MAX_TITLE_LENGTH];   // Title of the book
    char author[MAX_AUTHOR_LENGTH];  // Author of the book
} Book;

// Function prototypes for book-related operations
void initializeBook(Book *book, int id, const char *title, const char *author);
bool isValidBook(const Book *book);
void printBook(const Book *book);

#endif // BOOK_H