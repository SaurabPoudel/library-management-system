#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE "\x1b[34m"

#define ROT 13

void addMemberBanner();
void addMemberMenu();
void rot13algorithm(char *);

void addMember()
{
    system("cls"); // Uncomment this for Linux: system("clear");
    addMemberBanner();
    addMemberMenu();
}

void addMemberBanner()
{
    printf(ANSI_COLOR_GREEN "-----------Library Management System-----------\n");
    printf("\n------------------Add Member---------------------\n" ANSI_COLOR_RESET);
}

void addMemberMenu()
{
    char username[20], password[20], confirmPassword[20];
    printf("\n");
    printf(ANSI_COLOR_GREEN "Enter your username:\n> ");
    scanf("%s", username);

    printf("Enter your password:\n> ");
    scanf("%s", password);

    printf("\nConfirm your password:\n> ");
    scanf("%s", confirmPassword);
    printf("\n");

    rot13algorithm(password);
    rot13algorithm(confirmPassword);
    if (strcmp(password, confirmPassword) != 0)
    {
        printf(ANSI_COLOR_RED "Passwords do not match!\n" ANSI_COLOR_RESET);
        addMemberMenu();
    }
    else
    {
        // printf(ANSI_COLOR_GREEN "Account created successfully!\n" ANSI_COLOR_RESET);
        FILE *file = NULL;
        FILE *file2 = NULL;
        if (access("./data/members.csv", F_OK) != -1)
        {
            file = fopen("./data/members.csv", "a");
            fprintf(file, "\n%s,%s", username, password);
            fclose(file);
            printf(ANSI_COLOR_GREEN "Member added to members.csv file.\n" ANSI_COLOR_RESET);
        }
        else
        {
            file2 = fopen("./data/members.csv", "w");
            fprintf(file2, "%s,%s", username, password);
            fclose(file2);
            printf(ANSI_COLOR_GREEN "Member added to members.csv file.\n" ANSI_COLOR_RESET);
        }
    }
    printf(ANSI_COLOR_GREEN "\nEnter [Y] to add new member again OR [N] to go to Main Menu \n>" ANSI_COLOR_RESET);

    char inputMember;
    getchar();
    scanf("%c", &inputMember);

    if (inputMember == 'Y' || inputMember == 'y')
    {

        addMemberMenu();
    }
    else
    {
        system("cls");
        printBanner();
        menuBar();
        prompt();
    }
    printf("\n");
}

void rot13algorithm(char *string)
{
    int i;
    for (i = 0; i < strlen(string); i++)
    {
        if (string[i] >= 'a' && string[i] <= 'm')
        {
            string[i] += ROT;
        }
        else if (string[i] >= 'n' && string[i] <= 'z')
        {
            string[i] -= ROT;
        }
        else if (string[i] >= 'A' && string[i] <= 'M')
        {
            string[i] += ROT;
        }
        else if (string[i] >= 'N' && string[i] <= 'Z')
        {
            string[i] -= ROT;
        }
    }
}