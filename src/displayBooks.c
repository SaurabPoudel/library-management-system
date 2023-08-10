#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"

struct Book
{
    unsigned int id;
    char title[100];
    char author[100];
    unsigned int year;
    bool isBorrow;
};

void charFiller(char info[], int spaces) {
    int currentLength = strlen(info);
    int fillNumber = spaces - currentLength;
    
    if (fillNumber > 0) {
        for (int i = 0; i < fillNumber; i++) {
            strcat(info, " ");
        }
    }
}

void displayBooks()
{
    FILE *file = fopen("./data/books.csv", "r");
    if (file == NULL)
    {
        printf(ANSI_COLOR_RED "Error opening file.\n" ANSI_COLOR_RESET);
        return;
    }

    struct Book book;
    system("cls");
    printf(ANSI_COLOR_GREEN "-----------Library Management System-----------\n");
    printf("\n------------------Display Books------------------\n" ANSI_COLOR_RESET);
    printf("\nID\tTitle\t\t\t\t\tAuthor\t\t\t\t\tYear\t\tBorrowed\n");
    unsigned int borrowInt;
    while (fscanf(file, "%d,%[^,],%[^,],%u,%u\n", &book.id, book.title, book.author, &book.year, &borrowInt) != EOF)
    {
        charFiller(book.title, 20);
        charFiller(book.author, 20);
        book.isBorrow = borrowInt ? true : false;
        printf("%d\t%s\t\t\t%s\t\t\t%d\t\t%s\n", book.id, book.title, book.author, book.year, book.isBorrow ? "Yes" : "No");
    }
    printf("\n");
    fclose(file);

}
