#include "tail.h"

// Not efficient but it works

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        fprintf(stderr, "Usage: %s <filename> [lines]\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int n = (argc > 2) ? atoi(argv[2]) : DEFAULT_LINES;

    // Open file
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror(filename);
        return 1;
    }

    // Get file size
    struct stat st;
    if (stat(filename, &st) == -1)
    {
        perror("stat");
        fclose(file);
        return 1;
    }
    long file_size = st.st_size;

    // Allocate buffer
    char *buffer = malloc(file_size + 1);
    if (!buffer)
    {
        perror("malloc");
        fclose(file);
        return 1;
    }

    // Read file into buffer
    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';
    fclose(file);

    // Count lines backwards
    int count = 0;
    long pos = file_size - 1;
    while (pos >= 0 && count < n)
    {
        if (buffer[pos] == '\n')
            count++;
        pos--;
    }

    // Print from the right position
    printf("%s", buffer + pos + 2);

    free(buffer);
    return 0;
}
