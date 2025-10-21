#include "e4.h"

int lcm(int x, int y) {
    int si = x;
    int di = y;
    int c = di;
    if (si <= di)
        c = si;
    int a;
    
    L:
        a = c;
        int d = a % si;
        char bl = d == 0;
        a = c;
        d = a % di;
        char bh = d == 0;
        bl = bl & bh;
        if (bl == 0) 
            goto F;
        a = c;
        return a;
    F:
        c++;
        goto L;
}