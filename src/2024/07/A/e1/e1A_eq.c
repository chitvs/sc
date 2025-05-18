#include "e1A.h"

short* cond_compute(short* array, unsigned* cond, int n, short* out)
{
    int edi = 0;
    short* esi = out;
    short* eax;
    short* ebp = array;
    unsigned* ebx = cond;
L:
    if (edi >= n)
        goto RET;
    short cx = ebp[edi];
    if (ebx[edi] == 0)
        goto L2;
    short ax = compute(cx);
    esi[edi] = ax;
    edi++;
    goto L;
L2:
    esi[edi] = cx;
    edi++;
    goto L;
RET:
    eax = esi;
    return eax;
}