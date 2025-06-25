#ifndef EXPENSE_TRACKER_H
#define EXPENSE_TRACKER_H

#include "expense_record.h"

// Function prototypes for the expense tracker application

// Loads expenses from a specified file and returns the number of valid records loaded
int load_expenses(const char *filename, ExpenseRecord **records);

// Filters the loaded expense records based on user-defined criteria
void filter_expenses(ExpenseRecord *records, int record_count);

// Displays a summary of the filtered expense records
void display_summary(ExpenseRecord *records, int record_count);

// Frees the memory allocated for the expense records
void free_expenses(ExpenseRecord *records, int record_count);

#endif // EXPENSE_TRACKER_H