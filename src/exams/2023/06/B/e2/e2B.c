#include "e2B.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getBalanceMovements(const char* fname, int min, int max, int *bal){
    
    FILE *f = fopen(fname, "r");
    char line[15];
    int cnt = 0;
    int bal_value = 0;

    if (!f) return -1;

    while (fgets(line, sizeof(line), f)){
        char *day = strtok(line, "|");
        char *pm = strtok(NULL, "|");
        char *value = strtok(NULL, "|");

        if (atoi(day) >= min && atoi(day) <= max){
            cnt++;
            if (pm[0] == '+')
                bal_value += atoi(value);
            else
                bal_value -= atoi(value);
        }
    }

    *bal = bal_value;
    fclose(f);

    return cnt;
}
