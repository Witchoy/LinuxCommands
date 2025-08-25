#include "wc.h"

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

    int newline_counter = 0;
    int word_counter = 0;
    int byte_counter = 0;

    // Get file size
    struct stat st;
    if (stat(filename, &st) == -1)
    {
        perror("stat");
        fclose(file);
        return 1;
    }
    byte_counter = st.st_size;

    // Count words & lines
    int c;
    int in_word = 0;
    while ((c = fgetc(file)) != EOF)
    {
        // Count lines
        if (c == '\n')
        {
            newline_counter++;
        }

        // Check delimiters manually (space, tab, newline)
        if (c == ' ' || c == '\t' || c == '\n')
        {
            in_word = 0; // we left a word
        }
        else if (!in_word)
        {
            in_word = 1; // we entered a new word
            word_counter++;
        }
    }

    fclose(file);

    printf("%d %d %d %s\n", newline_counter, word_counter, byte_counter, filename);

    return 0;
}
