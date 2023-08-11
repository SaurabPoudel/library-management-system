#include <stdio.h>
#include <stdlib.h>
#include "authentication.h"
#include "addBook.h"
#include "displayBooks.h"
#include "searchBooks.h"
#include "searchMember.h"
#include "displayMembers.h"
#include "issueBook.h"
#include "returnBook.h"

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE "\x1b[34m"

void printBanner()
{
    printf(ANSI_COLOR_GREEN "          _____                    _____                            _____          \n");
    printf("         /\\    \\                  /\\    \\                          /\\    \\         \n");
    printf("        /::\\____\\                /::\\____\\                        /::\\    \\        \n");
    printf("       /:::/    /               /::::|   |                       /::::\\    \\       \n");
    printf("      /:::/    /               /:::::|   |                      /::::::\\    \\      \n");
    printf("     /:::/    /               /::::::|   |                     /:::/\\:::\\    \\     \n");
    printf("    /:::/    /               /:::/|::|   |                    /:::/__\\:::\\    \\    \n");
    printf("   /:::/    /               /:::/ |::|   |                    \\:::\\   \\:::\\    \\   \n");
    printf("  /:::/    /               /:::/  |::|___|______            ___\\:::\\   \\:::\\    \\  \n");
    printf(" /:::/    /               /:::/   |::::::::\\    \\          /\\   \\:::\\   \\:::\\    \\ \n");
    printf("/:::/____/               /:::/    |:::::::::\\____\\        /::\\   \\:::\\   \\:::\\____\\\n");
    printf("\\:::\\    \\               \\::/    / ~~~~~/:::/    /        \\:::\\   \\:::\\   \\::/    /\n");
    printf(" \\:::\\    \\               \\/____/      /:::/    /          \\:::\\   \\:::\\   \\/____/ \n");
    printf("  \\:::\\    \\                          /:::/    /            \\:::\\   \\:::\\    \\     \n");
    printf("   \\:::\\    \\                        /:::/    /              \\:::\\   \\:::\\____\\    \n");
    printf("    \\:::\\    \\                      /:::/    /                \\:::\\  /:::/    /    \n");
    printf("     \\:::\\    \\                    /:::/    /                  \\:::\\/:::/    /     \n");
    printf("      \\:::\\    \\                  /:::/    /                    \\::::::/    /      \n");
    printf("       \\:::\\____\\                /:::/    /                      \\::::/    /       \n");
    printf("        \\::/    /                \\::/    /                        \\::/    /        \n");
    printf("         \\/____/                  \\/____/                          \\/____/         \n");
    printf("                                                                                    \n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "}-------{+} Developed by  079BEIAB Prajit, Santosh, Sashmin, Saurab {+}-------{\n");
    printf("}----------{+} github.com/SaurabPoudel/library-management-system {+}----------{\n" ANSI_COLOR_RESET);
}

void menuBar()
{
    printf("\n");
    printf(ANSI_COLOR_GREEN "{1}-- Add Book\n");
    printf("{2}-- Add Member\n");
    printf("{3}-- Issue Book\n");
    printf("{4}-- Return Book\n");
    printf("{5}-- Search Book\n");
    printf("{6}-- Search Member\n");
    printf("{7}-- Display Books\n");
    printf("{8}-- Display Members\n");
    printf("{99}-- Exit\n" ANSI_COLOR_RESET);
    printf("\n");
}

void prompt()
{
    int input;

    while (1)
    {
        printf("\n");
        printf(ANSI_COLOR_GREEN "> " ANSI_COLOR_RESET);

        scanf("%d", &input);
        printf("\n");

        switch (input)
        {
        case 99:
            printf(ANSI_COLOR_RED "LMS has been terminated. \n" ANSI_COLOR_RESET);
            return;

        case 1:

            addBook();
            break;

        case 2:
            addMember();
            break;

        case 3:
            issueBook();
            break;

        case 4:
            returnBook();
            break;

        case 5:
            searchBooks();
            break;

        case 6:
            searchMember();
            break;

        case 7:
            displayBooks();
            break;

        case 8:
            displayMembers();
            break;

        default:
            printf(ANSI_COLOR_RED "\nPlease enter corresponding values only. \n" ANSI_COLOR_RESET);

            return;
        }
    }
}
