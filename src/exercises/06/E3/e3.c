#include <stddef.h>
#include "e3.h"

char *my_strpbrk(const char *s1, const char *s2){
    while (*s1!='\0'){
        const char *copy = s2;
        while (*copy!='\0'){
            if (copy[0]==s1[0])
                return s1;
            copy++;
        }
        s1++;
    }
    return NULL;
}