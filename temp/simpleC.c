#include <stdio.h>
#include <unistd.h>
#include <direct.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>


void * wait(void *th){
	pthread_t *thread = (pthread_t *)th;
	printf("Sleeping 2sec...\n");
	sleep(2);
	free(thread);
}

int main(int argc, char *argv[]){
	pthread_t *rmthread = (pthread_t*)malloc(5 * sizeof(pthread_t));
	for(int i = 0; i<5; i++){
		pthread_create(&rmthread[i], NULL, wait, (void*)&rmthread[i]);
	}
	for(int i = 0; i<5; i++){
		pthread_join(rmthread[i], NULL);
	}
	return 0;
}