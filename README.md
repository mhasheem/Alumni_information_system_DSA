
# Alumni Information Portal

## Project Overview

The Alumni Information Portal is a C++ application designed to manage and manipulate alumni records. It features functionality for adding, updating, deleting, searching, and sorting records. The application uses a linked list for data storage and offers runtime sorting using merge sort. Data can be persisted in CSV format.

## Features

- **Add Records**: Insert new alumni records into the linked list and save them to a CSV file.
- **Delete Records**: Remove specific records based on user input.
- **Update Records**: Modify existing records.
- **Search Records**: Find records by name or other fields.
- **Sort Records**: Display records sorted by different fields.
- **CSV Export**: Save the linked list to a CSV file for persistent storage.

## Prerequisites

- **Compiler**: C++ compiler (e.g., g++, clang++)
- **Libraries**: Standard C++ libraries
- **Operating System**: Windows (due to use of `conio.h` for `_getch()`, though cross-platform alternatives exist)

## Installation

1. **Clone the Repository**:
   
   git clone https://github.com/yourusername/alumni-information-portal.git
   cd alumni-information-portal
   

2. **Compile the Project**:
   Ensure you have a C++ compiler installed. Compile the project using:
   
   g++ -o alumni_portal main.cpp LinkList.cpp SortList.cpp
   

3. **Run the Application**:
   ./alumni_portal
   

## File Structure

- **main.cpp**: Contains the main function and the menu system for interacting with the user.
- **LinkList.h / LinkList.cpp**: Defines and implements the linked list operations for managing alumni records.
- **SortList.h / SortList.cpp**: Defines and implements the sorting functionality for alumni records.
- **Node.h / Node.cpp**: Defines the structure of the node used in linked lists.
- **alumni_data.csv**: (Optional) The CSV file where records are stored.

## Usage

1. **Show All Records**:
   Displays all alumni records currently stored in the linked list.

2. **Add Record**:
   Prompts the user to enter new alumni details and saves them to the linked list. Records are also saved to a CSV file.

3. **Delete Record**:
   Allows the user to search for records by name and delete a specific record from the linked list.

4. **Update Record**:
   Allows the user to search for records by name and update specific records.

5. **Show Sorted Record**:
   Displays records sorted by the selected field (e.g., Name, Batch, Company, etc.).

6. **Search for Record**:
   Searches and displays records matching a specified name.

## Code Overview

### Linked List

- **Node Class**: Represents an individual record in the linked list.
- **LinkList Class**: Manages operations on the linked list, such as adding, removing, updating, and searching records.

### Sorting

- **SortNode Class**: Represents a node in the sorted linked list.
- **SortList Class**: Manages operations on the sorted list, including merging and sorting using merge sort.

### User Interface

- **Menu Function**: Provides a text-based menu for interacting with the user, handling various operations like adding, deleting, updating, and sorting records.

## Known Issues

- **Platform Dependency**: Uses `conio.h` and `_getch()` for console input, which is platform-dependent. Consider using cross-platform alternatives for broader compatibility.
- **Error Handling**: Basic error handling; more robust mechanisms may be needed.

## Future Enhancements

- **Cross-Platform Compatibility**: Replace Windows-specific functions with cross-platform alternatives.
- **Graphical User Interface (GUI)**: Develop a GUI for a more user-friendly experience.
- **Database Integration**: Integrate with a database for better data management and persistence.

## Contributing

Contributions are welcome! Please fork the repository, make changes, and submit a pull request. For significant changes, open an issue first to discuss the changes you plan to make.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

