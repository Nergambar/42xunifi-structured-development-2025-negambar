# Contact Manager

## Overview
The Contact Manager is a console-based application designed to manage a collection of contacts for a small organization. It allows users to add, update, delete, and search for contacts, while ensuring data integrity and validation.

## Features
- Load contacts from a CSV file.
- Validate contact information (ID, name, phone, email, city, address).
- List all contacts.
- Search contacts by name or city.
- Add new contacts.
- Update existing contacts.
- Delete contacts.
- Save contacts back to the CSV file.

## File Structure
- **include/**: Contains header files defining structures and function prototypes.
  - `contact.h`: Defines the `Contact` structure and related functions.
  - `contact_manager.h`: Prototypes for managing contacts.
  - `utils.h`: Utility functions for input validation and string manipulation.
  
- **src/**: Contains source files implementing the functionality.
  - `main.c`: Entry point of the application.
  - `contact.c`: Functions related to the `Contact` structure.
  - `contact_manager.c`: Core functionality for managing contacts.
  - `utils.c`: Utility functions for various tasks.

- **diagrams/**: Contains documentation and diagrams.
  - `flowchart.mdj`: Flowchart of the system workflow.
  - `use_cases.mdj`: Use cases for user interactions.
  - `requirements.txt`: Core requirements and specifications.

- **README.md**: Documentation for the project.
- **Makefile**: Automates the build process.

## Setup Instructions
1. Clone the repository or download the source files.
2. Navigate to the project directory.
3. Use the provided `Makefile` to compile the project:
   ```
   make
   ```
4. Run the application with a CSV file as an argument:
   ```
   ./contact_manager contacts.csv
   ```

## Usage Guidelines
- Follow the prompts in the console to interact with the contact management system.
- Ensure that the CSV file is formatted correctly to avoid errors during loading.
- Use the menu options to navigate through the functionalities of the application.

## Contributing
Contributions are welcome! Please submit a pull request or open an issue for any suggestions or improvements.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.