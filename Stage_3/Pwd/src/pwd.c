#include "pwd.h"

int get_name_from_ino(char *dir, ino_t inode, char *dirname)
{
    struct dirent **namelist;
    int n, found = 0;

    n = scandir(dir, &namelist, 0, alphasort);
    if (n == -1)
    {
        perror("scandir");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        if (!found && namelist[i]->d_ino == inode)
        {
            strcpy(dirname, namelist[i]->d_name);
            found = 1;
        }
        free(namelist[i]);
    }
    free(namelist);
    return found ? EXIT_SUCCESS : EXIT_FAILURE;
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }

    char path[1024] = "";
    char dirname[64];
    struct stat st_cur, st_par;
    ino_t cur_ino, par_ino;

    while (1)
    {
        // Get inode of current directory
        if (stat(".", &st_cur) == -1)
        {
            perror("stat");
            exit(EXIT_FAILURE);
        }
        cur_ino = st_cur.st_ino;

        // Get inode of parent directory
        if (stat("..", &st_par) == -1)
        {
            perror("stat");
            exit(EXIT_FAILURE);
        }
        par_ino = st_par.st_ino;

        // If at root, break
        if (cur_ino == par_ino)
        {
            break;
        }

        // Move to parent directory
        if (chdir("..") == -1)
        {
            perror("chdir");
            exit(EXIT_FAILURE);
        }

        // Find name in parent directory
        if (get_name_from_ino(".", cur_ino, dirname) != EXIT_SUCCESS)
        {
            fprintf(stderr, "Failed to find directory name\n");
            exit(EXIT_FAILURE);
        }

        // Prepend to path
        char temp[PATH_MAX];
        snprintf(temp, sizeof(temp), "/%s%s", dirname, path);
        strncpy(path, temp, sizeof(path));
    }

    // If path is empty, we are at root
    printf("%s\n", path[0] ? path : "/");

    return 0;
}