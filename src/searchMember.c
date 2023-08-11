#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "utility.h"

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

void searchMember()
{
    char key[50];
    int flag = 0;
    FILE *fp = NULL;
    fp = fopen("./data/members.csv", "r");
    if (fp == NULL)
    {
        printf(ANSI_COLOR_RED "Error opening file.\n" ANSI_COLOR_RESET);
    }
    printf(ANSI_COLOR_GREEN "Enter the username: \n>");
    scanf("%s", key);
    getchar();
    char line[256];
    char members[100][256];
    int memberCount = 0;

    while (fgets(line, sizeof(line), fp))
    {
        char *token = strtok(line, ",");
        if (token != NULL)
        {
            strcpy(members[memberCount], token);
            memberCount++;
        }
    }

    fclose(fp);

    for (int i = 0; i < memberCount; i++)
    {
        if (strcmp(key, members[i]) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf(ANSI_COLOR_GREEN "User Exists\n" ANSI_COLOR_RESET);
    }
    else
    {

        printf(ANSI_COLOR_RED "User Doesn't Exist:\n" ANSI_COLOR_RESET);
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
        searchMember();
    }

    printf(ANSI_COLOR_RESET);
}
