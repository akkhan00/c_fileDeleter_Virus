#include "virusFunc.h"
#include <stdio.h>
#include <sys/stat.h> // stat
#include <dirent.h>   // show dir
#include <unistd.h>   // rmdir

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

char listOfFilesAndFolder(char dirname[], char arrayOfFileAndFolder[])
{
    struct dirent *d;
    DIR *dir = opendir(dirname);
    if (dir != NULL)
    {
        int index = 0;
        for (d = readdir(dir); d != NULL; d = readdir(dir))
        {
            arrayOfFileAndFolder[index] = d->d_name;
            index++;
        }
        closedir(dir);
        return 1;
    }
    else
    {
        return 0;
    }
}

int removeEmptyDir(char dirname[])
{
    if (rmdir(dirname) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}