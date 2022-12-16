// this function is copy from chatgpt and it's working
// but i still can't fit in my project
// so i remove this and write my own function which
// is more suitable with my virus project

// > chatgpt copy

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


// chat gpt copy

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