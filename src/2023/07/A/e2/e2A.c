#include "e2A.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_vocals(char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return 1;
    return 0;
}

int vowelcount(const char** s, int n){
    if (n == 0)
        return -1;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < strlen(s[i]); j++){
            if (check_vocals(s[i][j]))
                cnt++;
        }
    }
    return cnt;
}