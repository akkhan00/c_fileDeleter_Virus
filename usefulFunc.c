#include "virusFunc.h"
#include <stdio.h>
#include <sys/stat.h>

int deleteFile(const filename[])
{
    if (remove(filename) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isDirectory(char *path)
{
    struct stat statbuf;
    if (stat(path, &statbuf) != 0)
    {
        return 0;
    }
    else
    {
        return S_ISDIR(statbuf.st_mode);
    }
}