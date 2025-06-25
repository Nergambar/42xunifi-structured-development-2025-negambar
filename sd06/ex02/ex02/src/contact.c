#include "contact.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

Contact *create_contact(int id, const char *name, const char *phone, const char *email, const char *city, const char *address) {
    Contact *new_contact = (Contact *)malloc(sizeof(Contact));
    if (!new_contact) {
        return NULL;
    }
    new_contact->id = id;
    new_contact->name = strdup(name);
    new_contact->phone = strdup(phone);
    new_contact->email = strdup(email);
    new_contact->city = strdup(city);
    new_contact->address = strdup(address);
    return new_contact;
}

void free_contact(Contact *contact) {
    if (contact) {
        free(contact->name);
        free(contact->phone);
        free(contact->email);
        free(contact->city);
        free(contact->address);
        free(contact);
    }
}

int validate_contact(const Contact *contact) {
    if (contact->id <= 0) {
        return 0; // Invalid ID
    }
    if (!contact->name || strlen(contact->name) == 0) {
        return 0; // Invalid name
    }
    if (!contact->city || strlen(contact->city) == 0) {
        return 0; // Invalid city
    }
    if (!is_valid_phone(contact->phone)) {
        return 0; // Invalid phone
    }
    if (!is_valid_email(contact->email)) {
        return 0; // Invalid email
    }
    return 1; // Valid contact
}

int is_valid_phone(const char *phone) {
    // Implement phone validation logic
    return 1; // Placeholder for valid phone
}

int is_valid_email(const char *email) {
    // Implement email validation logic
    return 1; // Placeholder for valid email
}