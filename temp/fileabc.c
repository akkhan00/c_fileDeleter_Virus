#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


void* wait(){
	printf("Sleeping for 1s...\n");
	sleep(1);
}
int main(void){

	pthread_t *t1 = malloc(sizeof(pthread_t)*1);
	pthread_create(&t1[0], NULL, wait, NULL);
	printf("%lu\n", t1[0]);
	pthread_join(t1[0], NULL);
	free(t1);

	return 0;
}