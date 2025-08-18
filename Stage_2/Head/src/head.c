#include "head.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        char user_input[2048];
        // Use of fgets() cause I was having trouble with scanf()
        while (fgets(user_input, sizeof(user_input), stdin) != NULL)
        {
            printf("%s", user_input);
        }
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (file != NULL)
    {
        char line[2048];

        for (int i = 0; i < 10; i++)
        {
            if (fgets(line, sizeof line, file) != NULL)
            {
                printf("%s", line);
            }
            else
            {
                i = 10;
            }
        }

        fclose(file);
    }
    else
    {
        perror(filename);
        return 1;
    }

    return 0;
}