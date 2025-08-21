#include "head.h"

int isnumber(char *numbers)
{
    for (size_t i = 0; i < strlen(numbers); i++)
    {
        if (!isdigit(numbers[i]))
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *option = argv[1];
    int line_number = LINE_NUMBER;
    char *filename = argv[1];

    if ((strcmp(option, "-n") == 0))
    {
        if (isnumber(argv[2]))
        {
            fprintf(stderr, "Invalid number of lines: %s\n", argv[2]);
            return 1;
        }
        line_number = atoi(argv[2]);
        filename = argv[3];
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror(filename);
        return 1;
    }

    char line[2048];
    int count = 1;
    while (fgets(line, sizeof line, file) != NULL)
    {
        printf("%s", line);
        if (count == line_number)
        {
            return 0;
        }
        count++;
    }

    return 0;
}