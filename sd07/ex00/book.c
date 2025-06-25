#include "../../sd04/ex00/book.h"
#include <stdio.h>
#include <string.h>

void initializeBook(Book *book, int id, const char *title, const char *author) {
    if (!book) return;
    book->id = id;
    strncpy(book->title, title, MAX_TITLE_LENGTH - 1);
    book->title[MAX_TITLE_LENGTH - 1] = '\0';
    strncpy(book->author, author, MAX_AUTHOR_LENGTH - 1);
    book->author[MAX_AUTHOR_LENGTH - 1] = '\0';
}

bool isValidBook(const Book *book) {
    if (!book) return false;
    if (book->id <= 0) return false;
    if (strlen(book->title) == 0) return false;
    if (strlen(book->author) == 0) return false;
    return true;
}

void printBook(const Book *book) {
    if (!book) return;
    printf("ID: %d | Title: %s | Author: %s\n", book->id, book->title, book->author);
}