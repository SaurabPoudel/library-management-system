# Library Management System

The Library Management System is a command-line application that allows managing books in a library. This project is developed in C and provides functionalities to add books, display book details, search for books, and manage borrowing and returning of books. To add features follow the CONTRIBUTION.md file.

## Prerequisites

- GCC compiler (MinGW for windows users and GCC for Linux users)

## Getting Started

### Clone the Repository

1. Open a terminal or command prompt.
2. Change the current working directory to the location where you want to clone the project.
3. Run the following command to clone the repository:

```
git clone https://github.com/SaurabPoudel/library-management-system.git
```

### Build Project if bin and obj folder are not present

1. Open a terminal or command prompt.
2. Change the current working directory to the location where you have cloned the project.
3. Run the following command to build the project:
   Linux User

```
make
```

Windows User

```
mingw32-make
```

### Run the Project

#### Method 1

1. Open a terminal or command prompt.
2. Change the current working directory to the location where you have cloned the project.
3. Run the following command to run the project:

Linux User

```
./bin/library
```

Windows User

```
bin\library.exe
```

#### Method 2

1. Go to the bin folder.
2. Copy the path to the bin folder and add it to the environment variable.
3. Open a terminal or command prompt.
4. Run the following command to run the project:

Linux User

```
library
```

Windows User

```
library.exe
```

### Clean the Project

1. Open a terminal or command prompt.
2. Change the current working directory to the location where you have cloned the project.
3. Run the following command to clean the project:

Linux User

```
make clean
```

Windows User

```
mingw32-make clean
```

## About the Project

### Features

- Add User
- Add books
- Display book details
- Search for books
- Manage borrowing and returning of books
