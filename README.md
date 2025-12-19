# Library Management System

A C++ Data Structures project implementing a Library Management System using:
- **Linked Lists**: For storing Book and Member records.
- **Binary Search Tree (BST)**: For efficient book searching by ID.
- **Queue**: For managing the Waiting List of issued books.
- **Stack**: For an Undo system (tracking Issue/Return actions).

## File Structure

- `main.cpp`: Entry point and menu logic.
- `Book.h` / `Book.cpp`: Manages Books, BST, Waiting Queue (waiting list), and Action Stack (undo).
- `Member.h` / `Member.cpp`: Manages Member records and login authentication.

## How to Compile and Run

Ensure you have a C++ compiler (like g++) installed.

### Using g++
```bash
g++ main.cpp Book.cpp Member.cpp -o library_app
./library_app
```

## Features
1. **Admin Module**:
    - Add Books
    - View Books
    - Issue/Return Books
    - Undo last action
    - Add Members

2. **Member Module**:
    - Login
    - View Books
    - Borrow/Return Books
