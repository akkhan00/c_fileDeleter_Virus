#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{ 
	printf("hello world\n");

	char* ext;
	char* p;
	char fullname []="file.txt";
	ext = strchr(fullname,'.');
	printf("extension - %s\n",ext+1);
	for(p=fullname;p!=ext;p++)
	{
		printf("%c",*p);
	}
	printf("\n");

}
