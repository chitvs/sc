#include "e1A.h"

void rc4_encrypt(unsigned char *sbox, unsigned char *pt, unsigned char *ct) 
{
    unsigned char *ebp = pt;
    unsigned int esi = 0, edi = 0; // n, i
    unsigned char ebx = 0, edx; // j
L:
    if (*ebp==0)
        goto E;
    edi++;
    edi &= 255;
    unsigned char* eax = sbox;
    unsigned char cl = eax[edi];
    ebx += cl;
    rc4_helper(eax, edi, ebx, &edx);
    eax = ct;
    cl = *ebp;
    eax[esi] = edx ^ cl;
    esi++;
    ebp++;
    goto L;
E:
    return;
}
