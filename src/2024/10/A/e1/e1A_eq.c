#include "e1A.h"

char* cond_compute(char* array, unsigned* cond, int n, char* out)
{
    int esi = 0; // i
    char al; // res
    char* edi = out; 
    char* eax;
    char* ebx = array;
L:
    if (esi >= n)
        goto RET;
    char cl = ebx[esi];
    edi[esi] = cl;
    unsigned *edx = cond;
    if (edx[esi]==0)
        goto NEXT;
    compute(edi[esi], &al);
    edi[esi] = al;
    esi++;
    goto L;
NEXT:
    esi++;
    goto L;
RET:
    eax = edi;
    return eax;
}