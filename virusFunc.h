
int deleteFile(char filename[]);

// char listOfFilesAndFolder(char dirname[], char arrayOfFileAndFolder[][20]);

int removeEmptyDir(char dirname[]);

int isDirectory(const char *path);

int detectDrives(char existDrivesName[10][10], int *length);

void listFilesRecursively(char *basePath);
