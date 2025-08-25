#include "cat.h"

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    // Open file
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror(filename);
        return 1;
    }

    // Read File
    char line[2048];
    while (fgets(line, sizeof line, file) != NULL)
    {
        printf("%s", line);
    }

    return 0;
}