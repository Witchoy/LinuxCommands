#include "../include/echo.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("\n");
    }

    int n_option = 1;
    int start = 1;

    if (strcmp(argv[1], "-n") == 0)
    {
        n_option = 0;
        start++;
    }

    for (int i = start; i < argc; i++)
    {
        printf("%s", argv[i]);
        if (i != argc - 1)
        {
            printf(" ");
        }
        if (i == argc - 1 && n_option == 1)
        {
            printf("\n");
        }
    }
}