
int deleteFile(char filename[]);

// char listOfFilesAndFolder(char dirname[], char arrayOfFileAndFolder[][20]);

int removeEmptyDir(char dirname[]);

int isDirectory(const char *path);

int detectDrives(char existDrivesName[10][10], int *length);

void listFilesRecursively(char *basePath);

// int RemoveFilesAI(void);

// void listFiles(char *dir);

// struct AK_Encryption{
// 	char a[5];
// 	char b[5];
// 	char c[5];
// 	char d[5];
// 	char e[5];
// 	char f[5];
// 	char g[5];
// 	char h[5];
// 	char i[5];
// 	char j[5];
// 	char k[5];
// 	char l[5];
// 	char m[5];
// 	char n[5];
// 	char o[5];
// 	char p[5];
// 	char q[5];
// 	char r[5];
// 	char s[5];
// 	char t[5];
// 	char u[5];
// 	char v[5];
// 	char w[5];
// 	char x[5];
// 	char y[5];
// 	char z[5];
// 	char dot[5];
// };

// AKencryption(
	// "0xyz9",
	// "2wxy7",
	// "9vwx2",
	// "6uvw3",
	// "6tuv3",
	// "4stu2",
	// "4rst2",
	// "3qrs2",
	// "2pqr5",
	// "3opq1",
	// "2nop7",
	// "2mno1",
	// "2lmn3",
	// "8klm7",
	// "8jkl7",
	// "1ijk4",
	// "1hij2",
	// "g4hi3",
	// "5fgh6",
	// "9efg7",
	// "0def8",
	// "1cef7",
	// "2bef9",
	// "abc85",
	// "2yyy2",
	// "2zzz1",
	// "2d291"
// )