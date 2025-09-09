#include "ls.h"

int is_visible(const struct dirent *file) {
    int is_visible;

    if(file->d_name[0] == '.') {
        is_visible = 0;
    } else {
        is_visible = 1;
    }

    return is_visible;
}

int is_folder(const struct dirent *file) {
    // TODO
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }

    struct dirent **namelist;
    int n;

    n = scandir(".", &namelist, is_visible, alphasort);
    if (n == -1)
    {
        perror("scandir");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t", namelist[i]->d_name);
        free(namelist[i]);
    }
    printf("\n");
    free(namelist);

    exit(EXIT_SUCCESS);
    return 0;
}
