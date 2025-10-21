#include "e1A.h"

unsigned int* div_vectors(unsigned int* a, unsigned int* b, int n) {
    unsigned int* ebx = a;
    unsigned int* ebp = b;
    int esi = n;
    if (ebx == 0)
        goto E1;
    if (ebp == 0)
        goto E1;
    if (esi == 0)
        goto E1;
    int edi = 4*esi;
    unsigned int* eax = malloc(edi);
    int ecx = 0;
L:
    if (ecx>=esi)
        goto E2;
    eax[ecx] = ebx[ecx] / ebp[ecx];
    ecx++;
    goto L;
E1:
    eax = NULL;
    goto E2; 
E2:
    return eax;
}