#include "e2A.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cerca(const char * filename, const char * prefix, struct contatto ** arrayMatches){
    
    FILE *f = fopen(filename, "r");
    if (!f)
        return -1;

    char line[48];
    int cnt = 0;

    struct contatto *results = malloc(sizeof(struct contatto) * 32);
    if (!results) {
        fclose(f);
        return -1;
    }

    while (fgets(line, sizeof(line), f)){
        char name[32];
        char number[16];

        int j = 0;
        for (int i = 0; i < 31; i++) {
            if (line[i] != '_'){
                name[j] = line[i];
                j++;
            }
        }

        name[j] = '\0';

        int k = 0;
        for (int i = 31; i < 46; i++) {
            if (line[i] != '_'){
                number[k] = line[i];
                k++;
            }
        }

        number[k] = '\0';

        if (strncmp(name, prefix, strlen(prefix)) == 0) {

            strncpy(results[cnt].nomecompleto, name, sizeof(results[cnt].nomecompleto) - 1);
            results[cnt].nomecompleto[sizeof(results[cnt].nomecompleto) - 1] = '\0';

            strncpy(results[cnt].numero, number, sizeof(results[cnt].numero) - 1);
            results[cnt].numero[sizeof(results[cnt].numero) - 1] = '\0';

            cnt++;
        }
    }

    fclose(f);
    *arrayMatches = results;
    return cnt;
}
