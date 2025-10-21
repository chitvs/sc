#include "e1C.h"

int hextodec_sum(unsigned char *in, int *out)
{
    int edi = 0;
    unsigned esi = 0;
    int ebp;
    unsigned char *ebx = in;
    int eax;
    int tmp;
L:
    if (*ebx==0)
        goto RET;
    hextodec_helper(ebx, &tmp);
    ebp = tmp;
    int *ecx = out;
    if (ebp > 0) goto L2;
    ecx[esi] = ebp;
    esi++;
    ebx++;
    ebx++;
    goto L;
L2:
    edi += ebp;
    ecx[esi] = ebp;
    esi++;
    ebx++;
    ebx++;
    goto L;
RET:
    eax = edi;
    return eax;
}