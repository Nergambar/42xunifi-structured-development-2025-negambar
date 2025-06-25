#include <stdio.h>
#include <stdlib.h>
#include "contact_manager.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <contacts_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    ContactManager *manager = create_contact_manager();

    if (load_contacts(manager, filename) != 0) {
        fprintf(stderr, "Error loading contacts from file: %s\n", filename);
        free_contact_manager(manager);
        return EXIT_FAILURE;
    }

    int choice;
    do {
        display_menu();
        choice = get_user_choice();

        switch (choice) {
            case 1:
                list_contacts(manager);
                break;
            case 2:
                search_contacts(manager);
                break;
            case 3:
                add_contact(manager);
                break;
            case 4:
                update_contact(manager);
                break;
            case 5:
                delete_contact(manager);
                break;
            case 6:
                if (save_contacts(manager, filename) != 0) {
                    fprintf(stderr, "Error saving contacts to file: %s\n", filename);
                }
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    free_contact_manager(manager);
    return EXIT_SUCCESS;
}