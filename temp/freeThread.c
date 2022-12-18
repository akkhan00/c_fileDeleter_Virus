#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10000

void *thread_function(void *arg)
{
    // Do something with the argument here
    pthread_t thread = *(pthread_t *)arg;
    printf("Thread ID: %lu\n", thread);

    // Free the memory allocated for the argument
    free(arg);

    return NULL;
}

int main(void)
{
    pthread_t *threads = malloc(sizeof(pthread_t) * NUM_THREADS);

    for (int i = 0; i < NUM_THREADS; i++) {

        pthread_t *thread_arg = malloc(sizeof(pthread_t));

        *thread_arg = threads[i];

        int rc = pthread_create(&threads[i], NULL, thread_function, thread_arg);

        if (rc != 0) {
            // Handle error
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free the memory allocated for the threads
    free(threads);

    return 0;
}