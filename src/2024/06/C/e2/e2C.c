#include "e2C.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct destinazione {
        char* dep;
        char* arr;
        int cost;
};

int compare(const void *a, const void *b){
    struct destinazione *ca = *(struct destinazione **)a;
    struct destinazione *cb = *(struct destinazione **)b;
    return ca->cost - cb->cost;
}

void destinazioniSottoBudget(const char * filesorgente, const char *partenza, int budget, const char * filedestinazione){
    
    FILE *f1 = fopen(filesorgente, "r");
    FILE *f2 = fopen(filedestinazione, "w");

    int count = 0;

    struct destinazione *array[100];
    char s[15];

    while (fgets(s, sizeof(s), f1)){
        char* dep = strtok(s, "-");
        char* arr = strtok(NULL, "-");
        char* cost = strtok(NULL, "-");

        if (atoi(cost) <= budget && strcmp(dep, partenza) == 0){
            
            struct destinazione *x = malloc(sizeof(struct destinazione));
            x->dep = strdup(dep);
            x->arr = strdup(arr);
            x->cost = atoi(cost);
            array[count] = x;
            count++;
        }
    }

    qsort(array, count, sizeof(struct destinazione*), compare);

    for (int i = 0; i < count; i++){
        fprintf(f2, "%s-%s-%d\n", array[i]->dep, array[i]->arr, array[i]->cost);
    }

    fclose(f1);
    fclose(f2);

}