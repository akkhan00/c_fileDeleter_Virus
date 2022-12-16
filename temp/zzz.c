// #include <stdio.h>
// #include <string.h>

// void addSomething(char *arr[], char *text, int index);

// int main(void){
// 	char *arr[20] = {"ahmad", "khalfan", "is"};
// 	printf("length is : %d\n", sizeof(arr)/sizeof(arr[0]));
// 	addSomething(arr, "end", 3);
// 	addSomething(arr, "end2", 4);
// 	addSomething(arr, "end", 5);
// 	addSomething(arr, "end2", 6);
// 	addSomething(arr, "end", 7);
// 	addSomething(arr, "end2", 8);
// 	addSomething(arr, "end9", 9);
// 	addSomething(arr, "end10", 10);
// 	addSomething(arr, "end11", 11);
// 	addSomething(arr, "end12", 12);
// 	printf("%s \n", arr[12]);
// 	printf("length is : %d\n", strlen(arr));
// 	return 0;
// }

// void addSomething(char *arr[], char *text, int index){
// 	arr[index] = text;
// 	// strcpy(arr[index], text);
// }


// Realll array 
// void addSomething(char arr[][20], char *text, int index);

// int main(void){
// 	char arr[][20] = {"Ahmad", "Khalfan"};
// 	printf("length is : %d\n", sizeof(arr)/sizeof(arr[0]));
// 	addSomething(arr, "end", 3);
// 	addSomething(arr, "end2", 4);
// 	addSomething(arr, "end", 5);
// 	addSomething(arr, "end2", 6);
// 	addSomething(arr, "end", 7);
// 	addSomething(arr, "end2", 8);
// 	addSomething(arr, "end9", 9);
// 	addSomething(arr, "end10", 10);
// 	addSomething(arr, "end11", 11);
// 	addSomething(arr, "end12", 12);
// 	printf("%s \n", arr[12]);
// 	printf("length is : %d\n", sizeof(arr)/sizeof(arr[0]));
// 	return 0;
// }

// void addSomething(char arr[][20], char *text, int index){
// 	// arr[index] = text;
// 	strcpy(arr[index], text);
// }


// int main(int argc, char *argv[]){
// 	int index = 0;
// 	char arr[20][20] = {}; // len willbe 0
// 	strcpy(arr[index++], "end");	// length will 1
// 	strcpy(arr[index++], "hack"); // lenth will 2
// 	strcpy(arr[index++], "something"); // lenth will 3
// 	printf("copyValue: %s\n", arr[1]);
// 	printf("length is : %d\n", index);
// 	return 0;
// }

// typedef struct {
// 	char a[5];
// 	char b[5];
// 	char c[5];
// } AK_Encryption;


// int main(void){

// 	// AK_Encryption arrr = {"0xyz9", "2wxy7"};

// 	char st[6] = "2abc1";
// 	printf("st: %s\n", st);

// 	return 0;
// }



// #include <stdio.h>
// #include <time.h>

// double fun(){
// 	double a = 1;
// 	for(int i = 1; i<100; i++){
// 		a *= i;
// 	}
// 	// getchar();
// 	return a;
// }

// int main(void){
// 	clock_t start, end;
// 	double cpu_time_used;

// 	start = clock();
// 	double a = fun();
// 	end = clock();
// 	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
// 	printf("Total time taken is: %f\n", cpu_time_used);
// 	printf("Value of a is: %lf\n", a);
// 	return 0;
// }



#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pthread.h>


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


void* listFilesRecursively(void *basepth)
{
	char *basePath = (char *) basepth;
    if(!isDirectory(basePath) == 0){
       // RemoveFilesAI();
    }
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    // Unable to open directory stream
    if (!dir)
        return NULL;
    // todo thread initialize here
    // max thread will be 10 -->
    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {

            // Construct new path from our base path
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            sleep(2);
            printf("%s\n", path);
            // if(remove(path)==0){
            //     printf("(%s) Succesffuly deteled\n", dp->d_name);
            // }else{
            //     printf("[%s] it's a dir?\n");
            // }

            listFilesRecursively(path);
        }
    }

    closedir(dir);

    return NULL;
}

int main(int argc, char *argv[]){

	pthread_t t1, t2;
	int result1 = pthread_create(&t1, NULL, listFilesRecursively, "./");
	int result2 = pthread_create(&t2, NULL, listFilesRecursively, "./");
	if(result1){
		printf("result1 error\n");
		return 1;
	}
	if (result2){
		printf("result2 error\n");
		return 2;
	}
	printf("inside main function\n");
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	listFilesRecursively("./");
	return 0;
}