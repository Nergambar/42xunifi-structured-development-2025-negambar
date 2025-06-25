#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include "contact.h"

// Function prototypes for the contact management system

// Load contacts from a CSV file
int load_contacts(const char *filename, Contact **contacts, int *count);

// Save contacts back to the CSV file
int save_contacts(const char *filename, Contact *contacts, int count);

// List all contacts
void list_contacts(Contact *contacts, int count);

// Search for contacts by name or city substring
void search_contacts(Contact *contacts, int count, const char *query);

// Add a new contact
int add_contact(Contact **contacts, int *count, const Contact *new_contact);

// Update an existing contact by ID
int update_contact(Contact *contacts, int count, int id, const Contact *updated_contact);

// Delete a contact by ID
int delete_contact(Contact **contacts, int *count, int id);

// Display the main menu and handle user input
void display_menu(Contact **contacts, int *count, const char *filename);

#endif // CONTACT_MANAGER_H