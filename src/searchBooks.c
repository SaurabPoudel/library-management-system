#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "utility.h"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

struct Book
{
    unsigned int id;
    char title[100];
    char author[100];
    unsigned int year;
    bool isBorrow;
};

void searchBooks()
{
    char key[50];
    int flag = 0;
    struct Book book;
    unsigned int borrowInt;

    FILE *fp = NULL;
    fp = fopen("./data/books.csv", "r");

    if (fp == NULL)
    {
        printf(ANSI_COLOR_RED "Error opening file.\n" ANSI_COLOR_RESET);
    }

    printf(ANSI_COLOR_RED "Make sure to type [-] wherever there are spaces.\n>" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "Enter the book TITLE: \n>" ANSI_COLOR_RESET);
    scanf("%s", key);
    getchar();

    while (fscanf(fp, "%d,%[^,],%[^,],%u,%u\n", &book.id, book.title, book.author, &book.year, &borrowInt) != EOF)
    {

        if (strcmp(key, book.title) == 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        printf("%d\t%s\t\t\t%s\t\t\t%d\t\t%s\n", book.id, book.title, book.author, book.year, book.isBorrow ? "Borrowed" : "Not Borrowed");
    }
    else
    {

        printf(ANSI_COLOR_RED "Sorry the book that you have searched doesn't exist in this Library:\n" ANSI_COLOR_RESET);
    }

    printf(ANSI_COLOR_BLUE "\nEnter [Y] to Continue OR [N] to go to Main Menu \n>" ANSI_COLOR_RESET);

    char continueSearch;
    scanf("%c", &continueSearch);

    if (continueSearch == 'N' || continueSearch == 'n')
    {

        system("cls");
        printBanner();
        menuBar();
        prompt();
    }
    else
    {
        searchBooks();
    }

    printf(ANSI_COLOR_RESET);
}
