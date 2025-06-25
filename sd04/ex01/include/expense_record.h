#ifndef EXPENSE_RECORD_H
#define EXPENSE_RECORD_H

#include <stdbool.h>

typedef struct s_expense_record {
    char *date;          // Date of the expense in YYYY-MM-DD format
    float amount;       // Amount spent
    char *category;     // Category of the expense
    char *description;  // Description of the expense
} ExpenseRecord;

// Function prototypes
ExpenseRecord *create_expense_record(const char *date, const char *amount, const char *category, const char *description);
bool validate_expense_record(const ExpenseRecord *record);
void free_expense_record(ExpenseRecord *record);
void print_expense_record(const ExpenseRecord *record);

#endif // EXPENSE_RECORD_H