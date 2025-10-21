#include "e1A.h"

void init_matrix(short** m, unsigned n) {
    short** esi = m;
    unsigned ebx = 0;
F1:
    if (ebx >= n) goto E;
    unsigned ebp = 0;
F2:
    if (ebp >= n) goto NEXT;
    short ax = value(ebx,ebp);
    short* ecx = esi[ebx];
    ecx[ebp] = ax;
    ++ebp;
    goto F2;
NEXT:
    ++ebx;
    goto F1;
E:
    return;
}