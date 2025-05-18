#include "e1B.h"

void deleetify(unsigned char* v, unsigned len, unsigned char* res)
{
    unsigned esi = 0;
    unsigned char al;
    unsigned char* ebx = v;
    unsigned char* edi = res;
    unsigned char cl;
L:
    if (esi >= len)
        goto RET;
    if (ebx[esi] > 57) goto L2;
    cl = ebx[esi];
    deleetify_helper(cl, &al);
    edi[esi] = al;
    esi++;
    goto L;
L2:
    cl = ebx[esi];
    edi[esi] = cl;
    esi++;
    goto L;
RET:;
}