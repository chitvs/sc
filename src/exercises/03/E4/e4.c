#include <stdio.h>

char *my_strcpy(char *dest, const char *src){
    char *orig = dest;
    
    while (*src != '\0'){
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return orig;
}