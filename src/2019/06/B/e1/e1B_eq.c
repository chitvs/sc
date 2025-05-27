#include "e1B.h"

int has_duplicates(short* v, unsigned n) {
    short* ecx = v;
    unsigned edx=0;
    int eax;
L1:
    if (edx>=n) goto E1;
    unsigned ebx = edx+1;
L2:
    if (ebx>=n) goto NEXT;
    short si = ecx[edx];
    if (si == ecx[ebx]) goto E2;
    ebx++;
    goto L2;
NEXT:
    edx++;
    goto L1;
E1:
    eax = 0;
    goto E3;
E2:
    eax = 1;
    goto E3; 
E3:
    return eax;
}