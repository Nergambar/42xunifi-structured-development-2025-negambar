#ifndef FILTER_H
#define FILTER_H

#include "expense_record.h"

// Function prototypes for filtering mechanisms
int filter_by_category(ExpenseRecord *records, int record_count, const char *category, ExpenseRecord **filtered_records);
int filter_by_date_range(ExpenseRecord *records, int record_count, const char *start_date, const char *end_date, ExpenseRecord **filtered_records);
int validate_date(const char *date);
int validate_amount(const char *amount);
void trim_whitespace(char *str);
int is_valid_input(const char *input);

#endif // FILTER_H