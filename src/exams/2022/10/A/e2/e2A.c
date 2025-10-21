#include "e2A.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int loadStringsFromFile(const char *filename, char ***list) {
    FILE *f = fopen(filename, "r");
    if (!f) return -1;

    char c;
    int n_lines = 0, n_chars = 0;

    while (c = fgetc(f)){
        if (c==EOF)
            break;
        if (c=='\n')
            n_lines++;
        n_chars++;
    }

    char line[n_chars];
    int i = 0;

    char **temp = malloc(n_lines * sizeof(char*)); 

    fseek(f,0,SEEK_SET);
    while (fgets(line, sizeof(line), f)) {
        if (isalpha(line[0])) {
            temp[i] = strdup(line);
            i++;
        }
    }

    fclose(f);
    *list = temp;

    return i;
}
