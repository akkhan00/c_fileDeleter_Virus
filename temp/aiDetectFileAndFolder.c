#include <stdio.h>
#include <io.h>

int main() {
  struct _finddata_t fileInfo;
  long handle;

  handle = _findfirst(".", &fileInfo);
  if (handle == -1) {
    printf("No files or folders found\n");
  } else {
    if (fileInfo.attrib & _A_SUBDIR) {
      printf("%s (folder)\n", fileInfo.name);
    } else {
      printf("%s (file)\n", fileInfo.name);
    }
    while (_findnext(handle, &fileInfo) == 0) {
      if (fileInfo.attrib & _A_SUBDIR) {
        printf("%s (folder)\n", fileInfo.name);
      } else {
        printf("%s (file)\n", fileInfo.name);
      }
    }
  }

  _findclose(handle);
  return 0;
}