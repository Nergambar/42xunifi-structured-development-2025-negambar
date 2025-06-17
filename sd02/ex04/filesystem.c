#include "filesystem.h"


FSNode *create_file(const char *name, int size) {
    static FSNode nodes[100];
    static int i = 0;
    FSNode *node = &nodes[i++];
    int i = 0;
    while (name[i] && i < 63)
    {
        node->name[i] = name[i];
        i++;
    }
    node->name[i] = '\0';
    node->size = size;
    node->is_folder = 0;
    node->child = 0;
    node->sibling = 0;
    return node;
}

FSNode *create_folder(const char *name) {
    static FSNode nodes[100];
    static int i = 0;
    FSNode *node = &nodes[i++];
    int i = 0;
    while (name[i] && i < 63) {
        node->name[i] = name[i];
        i++;
    }
    node->name[i] = '\0';
    node->size = 0;
    node->is_folder = 1;
    node->child = 0;
    node->sibling = 0;
    return node;
}

void add_child(FSNode *parent, FSNode *child) {
    if (!parent || !parent->is_folder)
        return;
    if (!parent->child)
        parent->child = child;
    else {
        FSNode *cur = parent->child;
        while (cur->sibling) cur = cur->sibling;
        cur->sibling = child;
    }
}

FSNode *get_children(const FSNode *parent) {
    if (!parent || !parent->is_folder)
        return 0;
    return parent->child;
}

FSNode *get_sibling(const FSNode *node) {
    if (!node)
        return 0;
    return node->sibling;
}