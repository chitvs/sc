#include "e1A.h"

int suffix(const char* a, const char* b) {
    const char* ebx = a;
    const char* ebp = b;
    int eax = strlen(ebx); 
    int esi = eax; // alen
    eax = strlen(ebp);
    int edi = eax; // blen
    int ecx; // i
    int edx; // *b++
    if (edi > esi)
        goto E1;
    ecx = esi-edi;
L:
    if (ecx >= esi) goto E2;
    edx = *ebp++;
    if (ebx[ecx] != edx) goto E1;
    ecx++;
    goto L;
E1:
    eax = 0;
    goto E3;
E2:
    eax = 1;
    goto E3;
E3:
    return eax;
}