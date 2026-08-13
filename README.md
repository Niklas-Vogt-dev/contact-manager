# Contact Manager

A simple command-line contact manager written in C.

The project was created to practice fundamental C programming concepts such as structs, pointers, dynamic memory management, file I/O, modular programming and error handling.

## Features

- Display all contacts
- Add new contacts
- Change phone numbers
- Search contacts by name
- Delete contacts
- Save contacts to a file
- Load contacts from a file
- Dynamic memory management
- Input validation
- Modular project structure using `.c` and `.h` files

## Project Structure

```text
contact-manager/
├── main.c
├── contact.c
├── contact.h
├── input.c
├── input.h
├── contacts.txt
├── .gitignore
└── README.md

### `main.c`

Contains the main program loop and the command-line menu.

### `contact.c`

Contains the contact management functionality:

- Adding contacts
- Deleting contacts
- Searching contacts
- Changing phone numbers
- Saving and loading contacts

### `contact.h`

Contains the `Contact` structure and declarations for the contact-related functions.

### `input.c`

Contains reusable functions for handling and validating user input.

### `input.h`

Contains the declarations for the input functions.

## Memory Management

The contact list is stored in dynamically allocated memory.

The program uses `malloc()` to initially allocate memory and `realloc()` to dynamically adjust the capacity of the contact list.

When contacts are removed, the allocated capacity can also be reduced.

Memory is released using `free()` when the program terminates.

The project therefore uses:

- `malloc()`
- `realloc()`
- `free()`

## Data Storage

Contacts are stored in a simple text file called `contacts.txt`.

Each contact consists of three lines:

```text
Name
Phone
Email
```

Example:

```text
Max Mustermann
0123456789
max@muster.de
```

The program automatically loads existing contacts when it starts and can save the current contact list back to the file.

## Input Handling

User input is handled through reusable functions in `input.c`.

The project currently provides:

- `get_int()` for validated integer input
- `get_string()` for reading strings safely with `fgets()`

This keeps the input handling separate from the contact management logic.

## Building

The project can be compiled using a C compiler such as Microsoft Visual C or GCC.

### MSVC

```bash
cl main.c contact.c input.c
```

### GCC

```bash
gcc main.c contact.c input.c -o contact-manager
```

## Running

With MSVC:

```bash
main.exe
```

With GCC:

```bash
./contact-manager
```

## Learning Goals

This project was built to practice the following C concepts:

- Structs
- Arrays
- Pointers
- Pointer-to-pointer parameters
- Strings and character arrays
- Dynamic memory allocation
- `malloc()`, `realloc()` and `free()`
- File I/O
- `fopen()`, `fgets()`, `fprintf()` and `fclose()`
- Error handling
- Input validation
- Header files
- Modular program structure
- Basic Git workflow

## Git

The project is version-controlled with Git and hosted on GitHub.

The repository is intended to document the development of the project and the application of C programming concepts in a practical project.