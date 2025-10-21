#include "e2A.h"

#include <stdio.h>
#include <string.h>

int wordWithMaxCount(const char* text, const char c, char ** word){
    int cnt;
    int max = 0;
    int len;
    char* copy = strdup(text);
    char* token = strtok(copy, " ");
    while (token != NULL){
        cnt = 0;
        len = strlen(token);
        for (int i=0; i<len;i++){
            if (token[i] == c)
                cnt++;
            if (cnt > max){
                max = cnt;
                *word = strdup(token);
            }
        }
        token = strtok(NULL, " ");
    }
    return max;
}