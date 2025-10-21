#include <stdio.h>

void drop_spaces(char* text){
    char* ris = text;
    while (*text != '\0'){
        if (*text == ' '){
            text++;
        }
        else {
        *ris++ = *text++;
        }
    }
    *ris = '\0';
    return;
}