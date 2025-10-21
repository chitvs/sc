#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "e1.h"

void get_cmd_line(char* argv[]){

    char line[1024];
    fgets(line, sizeof(line), stdin);
    int n=0;
    char* token = strtok(line, " \t\n");

    while (token && n<64) {
        argv[n] = malloc(sizeof(token));
        strcpy(argv[n], token);
        n++;
        token = strtok(NULL, " \t\n");
    }
    argv[n] = NULL;
}