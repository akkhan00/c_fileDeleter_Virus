#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <sys/stat.h>

void *list_directory(void *arg) {
  char *path = (char *)arg;

  // Use _findfirst and _findnext to search for files and directories
  struct _finddata_t fd;
  long handle;
  char search_path[256];
  snprintf(search_path, sizeof(search_path), "%s/*", path);
  if ((handle = _findfirst(search_path, &fd)) == -1) {
    perror("Error finding files");
    return NULL;
  }

  do {
    // Get information about the current file or directory
    struct stat st;
    char full_path[256];
    snprintf(full_path, sizeof(full_path), "%s/%s", path, fd.name);
    if (stat(full_path, &st) != 0) {
      perror("Error getting file information");
      continue;
    }

    // Print the file or directory name
    printf("%s\n", fd.name);

    // If the current entry is a directory, create a new pthread to handle it
    if (st.st_mode & S_IFDIR) {
      pthread_t thread;
      int rc = pthread_create(&thread, NULL, list_directory, (void *)full_path);
      if (rc != 0) {
        fprintf(stderr, "Error creating thread: %s\n", strerror(rc));
      }
    }
  } while (_findnext(handle, &fd) == 0);

  _findclose(handle);
  return NULL;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s directory\n", argv[0]);
    return 1;
  }

  // Start the recursive traversal at the specified directory
  list_directory(argv[1]);
  return 0;
}