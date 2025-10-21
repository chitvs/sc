#include <stdio.h>

int count_digits(const char *s) {
    int a = 0;
    if (*s==0) 
        goto E;
    goto L;
    L: 
        if (*s==0) goto E;
        if (*s >= 48 && *s <= 57) a++;
            s++;
        goto L;
    E:
        return a;
}