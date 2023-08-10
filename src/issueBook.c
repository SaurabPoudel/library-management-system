#include <stdio.h>

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
/*#define ANSI_COLOR_BLUE "\x1b[34m"*/
#define ANSI_COLOR_RESET "\x1b[0m"

void issueBook()
{
    printf(ANSI_COLOR_GREEN "----------Library Management System----------\n");
    printf(ANSI_COLOR_GREEN "----------Issue Book----------\n");
    printf("Search the book and remember the ID\n");
    printf("Enter the ID of the book you want to issue: \n>");

    int id1;
    scanf("%d", &id1);
    getchar();

    FILE *fp = fopen("./data/books.csv", "r+");

    if (fp == NULL)
    {
        printf(ANSI_COLOR_RED "Error opening file.\n" ANSI_COLOR_RESET);
        return;
    }

    int id, borrowInt;
    int found = 0;
    long offset = 0; // To store the offset of the line to be modified

    while (fscanf(fp, "%d,%*[^,],%*[^,],%*d,%d\n", &id, &borrowInt) != EOF)
    {
        if (id == id1 && borrowInt == 0)
        {
            found = 1;
            break;
        }
        offset = ftell(fp); // Store the offset of the current line
    }

    if (found)
    {
        fseek(fp, offset, SEEK_SET);                              // Move to the start of the line
        fprintf(fp, "%d,%*[^,],%*[^,],%*d,%d\n", id, "borrowed"); // Write the updated line
        printf("Book issued successfully\n");
    }
    else
    {
        printf("Book not found or already issued\n");
    }

    fclose(fp);
}