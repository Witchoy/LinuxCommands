#ifndef LS_H
#define LS_H

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int is_visible(const struct dirent *file);
int is_folder(const struct dirent *file);

#endif