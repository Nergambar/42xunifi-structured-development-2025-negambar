# Expense Tracker Application Requirements

## Core Requirements

- **File Handling**
  - The application must read expense records from a specified text file.
  - It should handle errors gracefully, providing warnings for invalid lines and skipping them.

- **Data Structure**
  - Define a structure to store individual expense records, including:
    - Date (formatted as YYYY-MM-DD)
    - Amount (positive floating-point number)
    - Category (case-insensitive)
    - Description (trimmed of extra whitespace)

- **Input Validation**
  - Ensure that the date format is valid (YYYY-MM-DD).
  - Validate that the amount is a positive number.
  - Handle cases of missing fields, typos, and extra spaces in the input.

- **User Interaction**
  - Prompt the user for filtering options:
    - By category (case-insensitive)
    - By date range (start date and end date)
    - Option to view all records
  - Re-prompt for valid input if the user provides invalid data.

- **Filtering and Summary**
  - Filter records based on user-selected criteria.
  - Compute and display a summary of filtered records, including:
    - Total number of records
    - Total amount spent
    - Average expense
    - Breakdown by category (total spent per category and percentage of total)

- **Memory Management**
  - Allocate memory for storing expense records and ensure proper cleanup before exiting the program.

- **Error Handling**
  - Print error messages for file access issues and invalid input.
  - Indicate when no records match the selected filter.

## Additional Considerations

- The application should be user-friendly, providing clear prompts and feedback.
- The design should allow for easy extension and maintenance of the codebase.
- Consider edge cases, such as all records being invalid or no records matching the filter criteria.