#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FSNode {
    char *name;
    int size;               // 0 for folders
    int is_folder;          // 1 if folder, 0 if file
    struct FSNode *child;   // Points to first child (if folder)
    struct FSNode *sibling; // Points to next item in same folder
} FSNode;



FSNode *create_file(const char *name, int size);
FSNode *create_folder(const char *name);
void add_child(FSNode *parent, FSNode *child);
FSNode *get_children(const FSNode *parent);
FSNode *get_sibling(const FSNode *node);
void print_fs(const FSNode *node, int depth);


#endif