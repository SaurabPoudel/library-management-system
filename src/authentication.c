#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("\n------------------Add Member------------------\n" ANSI_COLOR_RESET);
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
        printf(ANSI_COLOR_GREEN "Account created successfully!\n" ANSI_COLOR_RESET);
        FILE *file = fopen("./data/members.csv", "a");
        if (file == NULL)
        {
            printf(ANSI_COLOR_RED "Failed to open members file!\n" ANSI_COLOR_RESET);
            return;
        }

        fprintf(file, "%s,%s\n", username, password);
        fclose(file);
        printf(ANSI_COLOR_GREEN "Member added to members.csv file.\n" ANSI_COLOR_RESET);
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