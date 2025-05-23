#include "e2A.h"

#include <stdio.h>
#include <string.h>

struct contatto {
    nomecompleto[31];
    numero[15];
};

int cercaEdEsporta(const char * filenameSource, const char * prefix, const char * filenameDest){
    FILE *f1 = fopen(filenameSource, "r");
    if (!f1)
        return -1;

    FILE *f2 = fopen(filenameDest, "w");
    if (!f2)
        return -1;

    struct contatto *array[32];

    char line[46];

    while (fgets(line, sizeof(line), f1)){
        
    }
    
}