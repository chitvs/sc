#include "e1A.h"

unsigned adler32(unsigned char *data, unsigned len) {
    unsigned char *ebx = data;
    if (data == NULL)
        goto E1;
    if (len == 0)
        goto E1;
    unsigned edi = 1, esi = 0;
    unsigned ebp;
    get_adler_constant(&ebp);
    int ecx = 0;
    unsigned eax, edx;
L:
    if (ecx >= len)
        goto E2;
    eax = edi;
    eax += ebx[ecx];
    eax %= ebp;
    eax = edx;
    edi = edx;
    edx = esi;
    edx += edi;
    edx %= ebp;
    esi = edx;
    ecx++;
    goto L;
E1:
    eax = 0;
    goto RET;
E2:
    esi = esi << 16;
    esi = esi | edi;
    eax = esi;
    goto RET;
RET:
    return eax;
}
