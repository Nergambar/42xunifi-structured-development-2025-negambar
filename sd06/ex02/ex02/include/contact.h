#ifndef CONTACT_H
#define CONTACT_H

#include <stdbool.h>

typedef struct s_contact {
    int id;
    char *name;
    char *phone;
    char *email;
    char *city;
    char *address;
} t_contact;

// Function prototypes
t_contact *create_contact(int id, const char *name, const char *phone, 
                          const char *email, const char *city, 
                          const char *address);
bool validate_contact(const t_contact *contact);
void free_contact(t_contact *contact);

#endif // CONTACT_H