#include "yes.h"

void print_text(int nb, char *text[])
{
    for (int i = 1; i < nb; i++)
    {
        printf("%s ", text[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        while (1)
        {
            printf("y\n");
        }
    }
    else
    {
        while (1)
        {
            print_text(argc, argv);
        }
    }

    return 1;
}