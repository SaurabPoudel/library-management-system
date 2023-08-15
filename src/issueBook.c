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

void updateBookStatus(int id, int newStatus)
{
    FILE *file = fopen("./data/books.csv", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    FILE *tempFile = fopen("./data/temp.csv", "w");
    if (tempFile == NULL)
    {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file))
    {
        int currentId, isborrow;
        char bookname[100], authorname[100], year[100];

        if (sscanf(line, "%d,%[^,],%[^,],%[^,],%d", &currentId, bookname, authorname, year, &isborrow) == 5)
        {
            if (currentId == id)
            {
                fprintf(tempFile, "%d,%s,%s,%s,%d\n", currentId, bookname, authorname, year, newStatus);
            }
            else
            {
                fprintf(tempFile, "%d,%s,%s,%s,%d\n", currentId, bookname, authorname, year, isborrow);
            }
        }
    }

    fclose(file);
    fclose(tempFile);

    if (remove("./data/books.csv") != 0)
    {
        printf("Error deleting original file. Try changing permission of data using \'mingw32-make change-permission-win\' command\n");
        return;
    }

    if (rename("./data/temp.csv", "./data/books.csv") != 0)
    {
        printf("Error renaming temporary file. Try changing permission of data using \'mingw32-make change-permission-win\'\n");
        return;
    }
}

void issueBook_here()
{
    int book_id;

    printf("Enter the book id that you want to issue from here\n:");
    scanf("%d", &book_id);
    updateBookStatus(book_id, 1);

    printf("Book with ID %d has been marked as borrowed.\n", book_id);
}
void issueBook()
{
    system("cls");
    printf(ANSI_COLOR_GREEN "-----------Library Management System-----------\n");
    printf("\n------------------Issue Book------------------\n" ANSI_COLOR_RESET);
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
        issueBook_here();

    else
        printf("Sorry you're not registered yet:");

    printf(ANSI_COLOR_GREEN "\nEnter [Y] to Continue OR [N] to go to Main Menu \n>" ANSI_COLOR_RESET);

    char inputBook;
    getchar();
    scanf("%c", &inputBook);

    if (inputBook == 'Y' || inputBook == 'y')
    {

        issueBook();
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