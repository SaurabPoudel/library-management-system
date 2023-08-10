#include "utility.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define MAX_LINE_LENGTH 1000

struct Book
{
    unsigned int id;
    char title[100];
    char author[100];
    unsigned int year;
    bool isBorrow;
};

void addBook();
/*
 * ADD BOOK
 * Adds new books to the records
 * Adds the IDs according to the sequence
 * Asks for the book name (records it)
 * Asks for the book author (records it)
 * When new book is added isBorrow will be set to False
 * books.csv's SYNTAX [ID, TITLE, AUTHOR, isBorrow]
 */

unsigned int getBookID(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    unsigned int lineCount = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            lineCount++;
        }
    }

    fclose(file);
    return lineCount;
}

void addBookBanner()
{
    printf(ANSI_COLOR_GREEN "-----------Library Management System-----------\n");
    printf("\n------------------Add Book-------------------\n" ANSI_COLOR_RESET);
}

void voidReplacer(char title[])
{
    int i;

    for (i = 0; i < strlen(title); i++)
    {
        if (title[i] == ' ')
        {
            title[i] = '-';
        }
    }
}

void addBookMenu()
{
    struct Book book;
    printf("\n");
    getchar();
    printf(ANSI_COLOR_GREEN "Enter the book TITLE: \n>");
    scanf("%[^\n]", book.title);
    getchar();

    printf("Enter the book AUTHOR: \n>");
    scanf("%[^\n]", book.author);
    getchar();

    voidReplacer(book.title);
    voidReplacer(book.author);

    printf("Enter the book YEAR: (Integer value only)\n>");
    scanf("%u", &book.year);

    unsigned int lastId = getBookID("./data/books.csv");
    book.id = lastId + 1;
    book.isBorrow = false;

    // Write or append data to the file here
    FILE *file = fopen("./data/books.csv", "a");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%u,%s,%s,%u,%d\n", book.id, book.title, book.author, book.year, book.isBorrow);
    fclose(file);

    printf("Book added with ID: %u\n", book.id);

    printf("\nEnter [Y] to Continue OR [N] to go to Main Menu \n>");

    char inputBook;
    getchar();
    scanf("%c", &inputBook);

    if (inputBook == 'Y' || inputBook == 'y')
    {

        addBook();
    }
    else
    {
        system("cls");
        printBanner();
        menuBar();
        prompt();
    }

    printf(ANSI_COLOR_RESET);
}

void addBook()
{
    system("cls"); // Uncomment this for Linux: system("clear");
    addBookBanner();
    addBookMenu();
    printf(ANSI_COLOR_RESET);
}