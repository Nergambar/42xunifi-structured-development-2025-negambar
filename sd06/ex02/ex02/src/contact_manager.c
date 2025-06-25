#include "contact_manager.h"
#include "contact.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000

static Contact *contacts[MAX_CONTACTS];
static int contact_count = 0;
static int max_id = 0;

static void load_contacts(const char *filename);
static void save_contacts(const char *filename);
static void display_menu();
static void list_contacts();
static void search_contacts();
static void add_contact();
static void update_contact();
static void delete_contact();

void start_contact_manager(const char *filename) {
    load_contacts(filename);
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: list_contacts(); break;
            case 2: search_contacts(); break;
            case 3: add_contact(); break;
            case 4: update_contact(); break;
            case 5: delete_contact(); break;
            case 6: save_contacts(filename); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

static void load_contacts(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        Contact *contact = parse_contact(line);
        if (contact && contact_count < MAX_CONTACTS) {
            contacts[contact_count++] = contact;
            if (contact->id > max_id) {
                max_id = contact->id;
            }
        } else {
            printf("Warning: Invalid contact line skipped: %s", line);
        }
    }
    fclose(file);
}

static void save_contacts(const char *filename) {
    FILE *file = fopen("temp.csv", "w");
    if (!file) {
        perror("Error creating temporary file");
        return;
    }

    for (int i = 0; i < contact_count; i++) {
        fprintf(file, "%d,%s,%s,%s,%s,%s\n", 
                contacts[i]->id, contacts[i]->name, 
                contacts[i]->phone, contacts[i]->email, 
                contacts[i]->city, contacts[i]->address);
    }
    fclose(file);

    if (rename("temp.csv", filename) != 0) {
        perror("Error saving contacts");
    }
}

static void display_menu() {
    printf("\nContact Manager Menu:\n");
    printf("1. List Contacts\n");
    printf("2. Search Contacts\n");
    printf("3. Add Contact\n");
    printf("4. Update Contact\n");
    printf("5. Delete Contact\n");
    printf("6. Save & Exit\n");
    printf("0. Exit without saving\n");
    printf("Enter your choice: ");
}

static void list_contacts() {
    for (int i = 0; i < contact_count; i++) {
        print_contact(contacts[i]);
    }
}

static void search_contacts() {
    char query[100];
    printf("Enter name or city to search: ");
    scanf("%s", query);
    for (int i = 0; i < contact_count; i++) {
        if (strstr(contacts[i]->name, query) || strstr(contacts[i]->city, query)) {
            print_contact(contacts[i]);
        }
    }
}

static void add_contact() {
    // Implementation for adding a new contact
}

static void update_contact() {
    // Implementation for updating an existing contact
}

static void delete_contact() {
    // Implementation for deleting a contact
}