# Library Management System

## Overview
This project implements a console-based library management system that reads a catalog of books from a text file, allows users to search for books by title or author, and displays the results. The program is designed to handle up to 1000 books, ensuring that it can efficiently manage and search through a reasonable collection of literature.

## Project Structure
The project consists of the following files:

- **book.h**: Defines the `Book` struct, which contains fields for storing the book's ID, title, and author. It also includes function prototypes for managing book-related operations.
  
- **library.h**: Defines the `Library` struct, which holds an array of `Book` structs and a count of the number of valid books. It includes function prototypes for reading and parsing the catalog file, storing valid entries, and freeing memory.
  
- **search.h**: Contains function prototypes for searching books by title or author. It includes functions for case-insensitive substring matching and trimming input.
  
- **utils.h**: Includes utility function prototypes for general operations such as trimming whitespace and printing results.
  
- **README.md**: This documentation file, which provides an overview of the project, its structure, and instructions for compiling and running the program.
  
- **flowchart.md**: Provides a flowchart visualizing the program's workflow, detailing how the program reads the catalog, processes input, and performs searches.
  
- **use_case.txt**: Outlines use cases for the program, describing different scenarios in which a user might interact with the library system, including examples of valid and invalid inputs.

## Compilation and Execution
To compile the program, use a C compiler (e.g., `gcc`) with the following command:

```
gcc -o library main.c -I. 
```

Replace `main.c` with the name of your main source file that includes the necessary headers.

To run the program, use the following command:

```
./library catalog.txt
```

Where `catalog.txt` is the text file containing the book catalog in the format `id,title,author`.

## Usage
1. The program will read the catalog file and parse each line.
2. It will skip any malformed lines and provide warnings for them.
3. Users can search for books by entering a title or author.
4. The search is case-insensitive and matches substrings.
5. If no matches are found, a "not found" message will be displayed.
6. The program will clean up memory and exit gracefully.

## Future Enhancements
- Implement additional search features, such as filtering by publication year or genre.
- Add a user interface for easier interaction.
- Enable the ability to add or remove books from the catalog dynamically.

This project serves as a foundational library management system and can be expanded with additional features and functionalities as needed.