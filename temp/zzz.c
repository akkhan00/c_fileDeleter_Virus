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
#include <stdlib.h>
#include <pthread.h>

int isDirectory(const char *path){
  struct stat statbuf;
  if(stat(path, &statbuf)!= 0){
    return 0;
  }else{
    return S_ISDIR(statbuf.st_mode);
  }
}


struct thread_data{
	char *path;
	// pthread_t th;
	pthread_t th;
};

void* wait(void *arg){
	struct thread_data *data = (struct thread_data *)arg;
	printf("[path]: %s\n", data->path);
	printf("[threadID] %lu\n", data->th);
	free(arg->th);
	// sleep(2);
	return NULL;	
}




int thSize = 2000;
void* listFilesRecursively(char *basepth)
{

    char *basePath = (char *) basepth;
    // char path[1000];
    char *path = malloc(sizeof(char)*1000);
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    // Unable to open directory stream
    if (!dir)
        return NULL;

	// pthread_t *thread_arg = malloc(sizeof(pthread_t));
    // pthread_t *rmthread = malloc(thSize * sizeof(pthread_t));
    struct thread_data *rmthread = malloc(sizeof(struct thread_data) * thSize);

    int threadCount = 0;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {

            // Construct new path from our base path
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            // printf("%s\n", path);
            if(isDirectory(path)){

                if(threadCount > 0){
                    printf("***********Found FileCount greater ********\n");
                    for(int i = 0; i<threadCount; i++){
                        pthread_join(rmthread[i].th, NULL);
                        printf("thread[%d] join\n",i);
                    }
                    printf("******** end ***********\n");
                }
                threadCount = 0;
                // printf("######### FileCount is 0\n");
            
                listFilesRecursively(path);
            }else{
                // printf("(file): %s\n", path);
				// Inistilaiz data 

                // int result = pthread_create(&rmthread[threadCount], NULL, wait, &data);
                rmthread[threadCount].path = path;
                int result = pthread_create(&rmthread[threadCount].th, NULL, wait, &rmthread[threadCount]);

                if(result){
                    printf("Creating file thread error\n");
                }else{
                	printf("FileCount: %d\n", threadCount);
                    threadCount += 1;
                }
                if(thSize == threadCount){
					for(int i = 0; i<threadCount; i++){
                		pthread_join(rmthread[i].th, NULL);
                		printf("thread[%d] join\n",i);
                	}
                	threadCount = 0;

                }

            }

        }
    }

    closedir(dir);
}





int main(int argc, char *argv[]){
	listFilesRecursively("c:");

	return 0;
}


	// pthread_t t1, t2;
	// pthread_t thread[1000];
	// for(int i = 0; i<500; i++){
	// 	if(pthread_create(&thread[i], NULL, listFilesRecursively, "./")){
	// 		printf("Error : during creating threads\n");
	// 	}
	// }

	// printf("inside main function\n"); // first run this and then thread

	// for(int i = 0; i< 500; i++){
	// 	pthread_join(thread[i], NULL);
	// }

	// int result1 = pthread_create(&t1, NULL, listFilesRecursively, "./");
	// int result2 = pthread_create(&t2, NULL, listFilesRecursively, "./");
	// if(result1){
	// 	printf("result1 error\n");
	// 	return 1;
	// }
	// if (result2){
	// 	printf("result2 error\n");
	// 	return 2;
	// }
	// pthread_join(t1, NULL);
	// pthread_join(t2, NULL);
	// listFilesRecursively("./");





 // if(strcmp(dp->d_name, "..")==0 || strcmp(dp->d_name, ".") == 0){
        // 	printf("Found . and ..\n");
        // 	if(threAdcount > 0){
        // 		printf("***********Found FileCount greater ********\n");
        // 		for(int i = 0; i<threAdcount; i++){
        // 			pthread_join(rmthread[i], NULL);
        // 			printf("thread[%d] join\n",i);
        // 		}
        // 		threAdcount = 0;
        // 		printf("######### FileCount is 0\n");
        // 	}
        // }



            	// still work same
            	// printf("(Directory): %s\n", path);
            	// pthread_t thread;
            	// int rc = pthread_create(&thread, NULL, listFilesRecursively, (void *)path);
            	// if(rc != 0){
            	// 	printf("Error Creating insideThread\n");
            	// }
            	// pthread_join(thread, NULL);






// void* listFilesRecursively(void *basepth)
// {
// 	char *basePath = (char *) basepth;
//     char path[1000];
//     struct dirent *dp;
//     DIR *dir = opendir(basePath);

//     // Unable to open directory stream
//     if (!dir)
//         return NULL;

//     while ((dp = readdir(dir))!= NULL)
//     {
//         if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
//         {

//             // Construct new path from our base path
//             strcpy(path, basePath);
//             strcat(path, "/");
//             strcat(path, dp->d_name);
//             // printf("%s\n", path);
//             if(isDirectory(path)){

//             	if(threAdcount > 0){
//         			printf("***********Found FileCount greater ********\n");
//         			for(int i = 0; i<threAdcount; i++){
//         				pthread_join(rmthread[i], NULL);
//         				printf("thread[%d] join\n",i);
//         			}
//         		}
//         		threAdcount = 0;
//         		// printf("######### FileCount is 0\n");
        	
//             	listFilesRecursively(path);

//             }else{
//             	// printf("(file): %s\n", path);
//             	if(thSize< threAdcount){
//             		rmthread = realloc(rmthread, threAdcount);
//             	}
 				
//  				int result = pthread_create(&rmthread[threAdcount], NULL, wait, (void *)path);
//  				if(result){
//  					printf("Creating file thread error\n");
//  				}else{
//  					printf("threAdcount: %d\n", threAdcount);
//  					threAdcount ++;
//  				}

//             }

//         }
//      }

//     closedir(dir);
	
// }