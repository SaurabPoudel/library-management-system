#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"

void displayMembers()
{
    FILE *file = fopen("./data/members.csv", "r");
    if (file == NULL)
    {
        printf(ANSI_COLOR_RED "Error opening file.\n" ANSI_COLOR_RESET);
        return;
    }
    system("cls");
    printf(ANSI_COLOR_GREEN "-----------Library Management System-----------\n");
    printf("\n------------------Members------------------\n");
    char line[256];
    char members[100][256];
    int memberCount = 0;

    while (fgets(line, sizeof(line), file))
    {
        char *token = strtok(line, ",");
        if (token != NULL)
        {
            strcpy(members[memberCount], token);
            memberCount++;
        }
    }

    fclose(file);

    for (int i = 0; i < memberCount; i++)
    {
        printf(ANSI_COLOR_GREEN "Member: %s\n" ANSI_COLOR_RESET, members[i]);
    }

    printf("\n");
    fclose(file);
    printf("\nEnter [Y] to Continue OR [N] to go to Main Menu \n>");

    char input;
    getchar();
    scanf("%c", &input);

    if (input == 'Y' || input == 'y')
    {

        displayMembers();
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
