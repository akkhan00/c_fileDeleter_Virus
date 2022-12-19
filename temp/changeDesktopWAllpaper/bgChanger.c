#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// void sleeping(int val){
// 	sleep(val);
// }

// int main(int argc, char *argv[]){
// 	// set the wallpaper to bg1.jpg
// 	char basePath[] = "E:\\ProgrammingProjects\\cProgramming\\c_fileDeleter_Virus\\temp\\changeDesktopWAllpaper\\";

// 	char img[][10] = {"bg1.jpg", "bg2.jpg", "bg3.jpg", "bg4.jpg", "bg5.jpg", "bg6.jpg"};

// 	for(int i = 0; i<6; i++){
// 		char *location = malloc(sizeof(char)*100);
// 		strcpy(location, basePath);
// 		strcat(location, img[i]);

//     	SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, location, SPIF_UPDATEINIFILE);

//     	printf("%s\n", location);
//     	free(location);
// 	    printf("sleeping 3s....\n");
// 	    sleeping(3);
//     }
//     return 0;
// }


int changeBg(void){

	char imgPath[100] = "C:\\Users\\";

	strcat(imgPath, getenv("USERNAME")); 
	strcat(imgPath, "\\A.jpg");

	SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, imgPath, SPIF_UPDATEINIFILE);

	printf("%s\n", imgPath);

	return 0;
}

int main(){
	changeBg();

	return 0;
}