#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int i = 0;
	while(i< 100){
		printf("sleep 2 sec...\n");
		sleep(2);
		i++;
	}
	printf("hello world\n");
	return 0;
}