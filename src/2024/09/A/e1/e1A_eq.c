#include "e1A.h"

int slice(char* str, int start, int end, char* res)
{
    char* ebx = str;
    int esi = 0; // i
    int edi = end - start -1; // size
    int eax;
L:
    if (*ebx == 0)
        goto E1;
    if (esi == start)
        goto E0;
    esi++;
    ebx++;
    goto L;
E0:
    esi++;
    slice_helper(ebx, edi, res);
    ebx++;
    goto L;
E1: 
    if (esi < start)
        goto E2;
    goto RET;
E2:
    edi = 0;
RET:
    eax = edi;
    return eax;
}