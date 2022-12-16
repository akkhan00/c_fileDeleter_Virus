// #include <stdio.h>
// #include <io.h>
// #include <string.h>

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
//         // This is a subdirectory, so search it recursively
//         char subdir[1000];
//         sprintf(subdir, "%s\\%s", dir, fileInfo.name);
//         listFiles(subdir);
//       } else {
//         // This is a file, so print its name
//         printf("%s\\%s\n", dir, fileInfo.name);
//       }
//     }
//   } while (_findnext(handle, &fileInfo) == 0);

//   _findclose(handle);
// }

// int main() {
//   listFiles("E:\\");
//   return 0;
// }












#include <stdio.h>
#include <io.h>
#include <string.h>

void listFiles(char *dir) {
  char searchPath[1000];
  sprintf(searchPath, "%s\\*", dir);

  struct _finddata_t fileInfo;
  long handle;

  handle = _findfirst(searchPath, &fileInfo);
  if (handle == -1) {
    return;
  }

  do {
    if (strcmp(fileInfo.name, ".") != 0 && strcmp(fileInfo.name, "..") != 0) {
      if (fileInfo.attrib & _A_SUBDIR) {
        // This is a subdirectory, so search it recursively
        char subdir[1000];
        sprintf(subdir, "%s\\%s", dir, fileInfo.name);
        listFiles(subdir);
      } else {
        // This is a file, so print its name
        printf("%s\\%s\n", dir, fileInfo.name);
      }
    }
  } while (_findnext(handle, &fileInfo) == 0);

  _findclose(handle);
}

int main() {
  listFiles("E:\\");
  return 0;
}