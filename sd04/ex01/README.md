# Expense Tracker Application

## Overview
The Expense Tracker application is designed to help users manage and analyze their spending by reading expense records from a text file. The application processes each record, validates the data, and allows users to filter and view their expenses based on various criteria. It provides a summary of expenses, including total spending, average expense, and breakdown by category.

## Features
- Load expense records from a specified text file.
- Validate and skip invalid records while providing warnings.
- Filter expenses by category, date range, or view all records.
- Display a summary of filtered expenses, including:
  - Total number of records
  - Total amount spent
  - Average expense
  - Breakdown by category with percentages

## File Structure
- `include/expense_tracker.h`: Main data structures and function prototypes for the application.
- `include/expense_record.h`: Definition of the `ExpenseRecord` structure and related functions.
- `include/expense_utils.h`: Utility functions for parsing, validating, and formatting expenses.
- `include/filter.h`: Filtering mechanisms for expense records and user input validation.
- `diagrams/flowchart.mdj`: Flowchart representing the workflow of the application.
- `diagrams/use_case.txt`: Use cases outlining user interactions with the system.
- `requirements.md`: Core requirements and specifications for the application.

## Usage
1. Compile the application using the provided source files.
2. Run the executable with the path to the expense records file as a command-line argument.
3. Follow the prompts to filter and view expenses.

## Setup
Ensure that the necessary libraries and dependencies are installed. Refer to the `requirements.md` file for detailed specifications.

## Contribution
Contributions to enhance the functionality and usability of the Expense Tracker application are welcome. Please follow the standard guidelines for submitting changes.