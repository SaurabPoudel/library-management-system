#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utility.h"
#include <stdbool.h>
#include "authentication.h"

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

struct member
{
    char user_name[30];
    char pass_word[30];
};

void updateBookStatus_R(int id, int newStatus)
{
    FILE *file = fopen("./data/books.csv", "r+");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    char line[100];
    FILE *tempFile = fopen("./data/temp.csv", "w");

    while (fgets(line, sizeof(line), file))
    {
        int currentId, isborrow;
        char bookname[100], authorname[100], year[100];

        sscanf(line, "%d,%[^,],%[^,],%[^,],%d", &currentId, bookname, authorname, year, &isborrow);

        if (currentId == id)
        {
            fprintf(tempFile, "%d,%s,%s,%s,%d\n", currentId, bookname, authorname, year, newStatus);
        }
        else
        {
            fprintf(tempFile, "%d,%s,%s,%s,%d\n", currentId, bookname, authorname, year, isborrow);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove("./data/books.csv");
    rename("./data/temp.csv", "./data/books.csv");
}

void returnBook_here()
{
    int book_id;

    printf("Enter the book id that you want to return from here\n:");
    scanf("%d", &book_id);
    updateBookStatus_R(book_id, 0);

    printf("Book with ID %d has been marked as returned.\n", book_id);
}
void returnBook()
{
    int flag = 0;
    struct member mem;
    char usr[30], pass[30];
    printf(ANSI_COLOR_GREEN "Enter the username:" ANSI_COLOR_RESET);
    scanf("%s", usr);
    printf(ANSI_COLOR_GREEN "Enter the password:" ANSI_COLOR_RESET);
    scanf("%s", pass);
    rot13algorithm(pass);
    FILE *fp = NULL;
    fp = fopen("./data/members.csv", "r");
    if (fp == NULL)
    {
        printf("Error the file is not exist here");
    }
    while (fscanf(fp, "%[^,],%[^\n]\n", mem.user_name, mem.pass_word) != EOF)
    {
        if (strcmp(mem.pass_word, pass) == 0 && strcmp(mem.user_name, usr) == 0)
        {
            flag = 1;
        }
    }
    if (flag == 1)
        returnBook_here();

    else
        printf("Sorry you're not registered yet:");

    printf("\nEnter [Y] to Continue OR [N] to go to Main Menu \n>");

    char inputBook;
    getchar();
    scanf("%c", &inputBook);

    if (inputBook == 'Y' || inputBook == 'y')
    {

        returnBook();
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