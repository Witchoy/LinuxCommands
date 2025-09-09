#ifndef PWD_H
#define PWD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int get_name_from_ino(char *dir, ino_t inode, char *dirname);

#endif
