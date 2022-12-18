#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(void){

	char *path = malloc(sizeof(char)*1000);
	strcpy(path, "hello world");
	printf("%s\n", path);
}