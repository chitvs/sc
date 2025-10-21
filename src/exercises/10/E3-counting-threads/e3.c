#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

unsigned int *shared_array;

typedef struct {
    long t;
    unsigned int it;
    unsigned int val;
} thread_args;

void *mul(void *param) {
    thread_args *args = (thread_args *)param;
    shared_array[args->t] = args->it * args->val;
}

unsigned int sum(unsigned int *arr, unsigned int n) {
    unsigned int s = 0;
    for (unsigned int i = 0; i < n; i++) {
        s += arr[i];
    }
    return s;
}

unsigned int counting_threads(unsigned int th, unsigned int it, unsigned int val) {
    
    pthread_t thread[th];

    int rc;
    long t;
    void *status;

    shared_array = malloc(th * sizeof(unsigned int));

    for (t = 0; t < th; t++) {

        thread_args *args = malloc(sizeof(thread_args));

        args->t = t;
        args->it = it;
        args->val = val;

        rc = pthread_create(&thread[t], NULL, mul, args);
        if (rc) {
            exit(-1);
        }
    }

    for (unsigned int t = 0; t < th; t++) {

        rc = pthread_join(thread[t], &status);
        if (rc) {
            exit(-1);
        }
    }

    return sum(shared_array, th);
}