#include "e2A.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contatto {
    char nomecompleto[31];
    char numero[15];
};

int cercaEdEsporta(const char * filenameSource, const char * prefix, const char * filenameDest){
    FILE *f1 = fopen(filenameSource, "r");
    if (!f1)
        return -1;

    FILE *f2 = fopen(filenameDest, "w");
    if (!f2)
        return -1;

    struct contatto *array = malloc(sizeof(struct contatto) * 100);
    char line[46];
    int cnt = 0, scar = 0;

    while (fgets(line, sizeof(line), f1)){
        if (strncmp(line, prefix, strlen(prefix)) == 0){

            int j=0, k=0;
            char name[31];
            char number[15];

            strncpy(name, line, 30);
            name[30] = '\0';
            strncpy(number, line + 30, 14);
            number[14] = '\0';

            for (int i = 29; i >= 0 && name[i] == '_'; i--) name[i] = '\0';
            for (int i = 13; i >= 0 && number[i] == '_'; i--) number[i] = '\0';

            strcpy(array[cnt].nomecompleto, name);
            strcpy(array[cnt].numero, number);
            cnt++;
        }
        else
            scar++;
    }
    
    for (int num = cnt-1; num >= 0; num--){
        fprintf(f2, "%s,%s\n", array[num].nomecompleto, array[num].numero);
    }

    fclose(f1);
    fclose(f2);
    return scar;
}