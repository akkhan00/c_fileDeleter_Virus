#include <stdio.h>
#include <dirent.h>
#include <string.h>


void listFilesRecursively(char *basePath)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    // Unable to open directory stream
    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {

            // Construct new path from our base path
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            
            printf("%s\n", path);
            listFilesRecursively(path);
        }
    }

    closedir(dir);
}

int main(void){
    listFilesRecursively("../");
    return 0;
}