#include "e1A.h"

int most_freq_char(const char* s, int* map) {
    int esi = 0;
    int edi = 0;
    int* ebx = map;
    clear(ebx, 256);
    const char* dl = s;
L:
    if (*dl==0) goto L2;
    char cl = *dl;
    dl++;
    (ebx[cl])++;
    goto L;
L2:
    if (esi >= 256) goto RET;
    int ebp = ebx[edi];
    if (ebx[esi] <= ebp) goto NEXT;
    edi = esi;
    esi++;
    goto L2;
NEXT:
    esi++;
    goto L2;   
RET:
    int eax = edi;
    return eax;
}