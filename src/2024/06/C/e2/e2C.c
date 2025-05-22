#include "e2C.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void destinazioniSottoBudget(const char * filesorgente, const char *partenza, int budget, const char * filedestinazione){
    
    FILE *f1 = fopen(filesorgente, "r");
    FILE *f2 = fopen(filedestinazione, "w");

    char s[100];

    while (fgets(s, sizeof(s), f1)){
        char* dep = strtok(s, "-");
        char* arr = strtok(NULL, "-");
        char* cost = strtok(NULL, "-");
        if (atoi(cost) <= budget && strcmp(dep, partenza) == 0){
            fprintf(f2, "%s-%s-%s\n", dep, arr, cost);
        }
    }

    fclose(f1);
    fclose(f2);

}