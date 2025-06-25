#ifndef EXPENSE_UTILS_H
#define EXPENSE_UTILS_H

#include "expense_record.h"

// Function prototypes for utility functions

// Parses a line from the expense file and returns an ExpenseRecord
ExpenseRecord *parse_expense_line(const char *line);

// Validates the date format (YYYY-MM-DD)
int validate_date(const char *date);

// Validates the amount to ensure it is a positive floating-point number
int validate_amount(const char *amount);

// Trims whitespace from the beginning and end of a string
char *trim_whitespace(const char *str);

// Formats the output for display
void format_expense_output(const ExpenseRecord *record);

#endif // EXPENSE_UTILS_H