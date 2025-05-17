#include "e1A.h"

unsigned char* base64lessless(unsigned char *data, unsigned out_len, unsigned char* b64_table) {
    unsigned char* eax = NULL;
    unsigned char* esi = data;
    if (esi == NULL) goto E;
    if(out_len == 0) goto E;
    eax = malloc(out_len);
    unsigned char dl = 0; 
    unsigned char dh = 0; 
    unsigned char cl, ch; 
    int edi = 0; 
L:
    if (edi >= out_len) goto E;
    cl = 6;
    cl -= dl;
    unsigned char bl = dh; 
    bl = bl << cl;
    cl = dl;
    ch = *esi;
    ch = ch >> cl;
    ch = ch >> 2;
    bl = bl | ch;
    cl = 8;
    cl = cl - 6;
    cl = cl + dl;
    cl = cl & 7;
    dl = cl;
    cl = 8;
    cl = cl - dl;
    dh = *esi;
    dh = dh << cl;
    dh = dh >> cl;
    if (dl >= 6) goto F;
    esi += 1;
F:
    unsigned ebx = bl;
    eax[edi] = b64_table[ebx];
    edi += 1;
    goto L;
E:
    return eax;
}
