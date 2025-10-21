#include "e1A.h"

unsigned char* deleetify(unsigned char* v, unsigned len)
{
    unsigned temp = len;
    unsigned char* eax = malloc(temp);
    unsigned char* ebx = v;
    unsigned esi=0;
    unsigned char* edi = eax;
    unsigned char al;
L:
    if (esi>=len) goto RET;
    if (ebx[esi] > 57) goto L2;
    al = edi[esi];
    al = deleetify_helper(ebx[esi]);
    edi[esi] = al;
    esi++;
    goto L;
L2:
    al = ebx[esi];
    edi[esi] = al;
    esi++;
    goto L;
RET:
    return eax;
}