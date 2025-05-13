#include "e1B.h"

int has_duplicates(short* v, unsigned n) {
    short* ecx = v;
    unsigned eax = n;
    unsigned edx=0; // i
    unsigned ebx; // j
L1:
    if (edx>=eax) goto E1;
    ebx = edx+1;
L2:
    if (ebx>=eax) goto NEXT;
    short tmp = ecx[edx];
    if (tmp == ecx[ebx]) goto E2;
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