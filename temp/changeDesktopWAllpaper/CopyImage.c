#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

// int getName(char uname[]);

int main(void){
	char targetPath[50] = "C:\\Users\\";

	char imagePath[20] = "img\\bg4.jpg";


	char picName[6] = "A.jpg";

	strcat(targetPath, getenv("USERNAME"));
	strcat(targetPath, "\\");
	strcat(targetPath, picName);


	if(!CopyFile(imagePath, targetPath, FALSE)){
		printf("File Failed To Copy\n");
	}else{
		printf("File Copied\n");
	}

	printf("%s\n", targetPath);

	return 0;
}

