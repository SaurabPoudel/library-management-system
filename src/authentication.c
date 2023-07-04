#include "utility.h"

#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE "\x1b[34m"

void addMember()
{
    /* CLS is for windows try uncommenting this for linux*/
    system("cls"); // uncomment this for linux
    // system("clear");
    printf(ANSI_COLOR_GREEN "Library Management System" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "Library Management System" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "\n----------------------------------------------------" ANSI_COLOR_RESET);
}
