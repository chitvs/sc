#include "e1B.h"

void rc4_encrypt_rev(unsigned char *sbox, unsigned char *pt, unsigned char *ct)
{
unsigned int esi = 0; // i
unsigned char ebx = 0; // j
unsigned char *ebp = pt + strlen(pt) - 1;
unsigned char *edi = ct;
L:
    if (ebp < pt)
        goto E;
        esi++;
        esi &= 255;
        unsigned char *eax = sbox;
        ebx += eax[esi];
        unsigned char al = rc4_helper(eax, esi, ebx) ^ *ebp;
        edi = al;
        edi++;  
        ebp--;
        goto L;
E:
    return;
}
