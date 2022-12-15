#include <stdio.h>
#include <string.h>

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


int main(int argc, char *argv[]){
	int index = 0;
	char arr[20][20] = {}; // len willbe 0
	strcpy(arr[index++], "end");	// length will 1
	strcpy(arr[index++], "hack"); // lenth will 2
	strcpy(arr[index++], "something"); // lenth will 3
	printf("copyValue: %s\n", arr[1]);
	printf("length is : %d\n", index);
	return 0;
}