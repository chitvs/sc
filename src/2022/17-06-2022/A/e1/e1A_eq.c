#include "e1A.h"

int crc32(char *bytes, int n) {
    char *ebx = bytes;
    int ebp = n;
    int edi=0, esi; // i,j
    int eax = 0xFFFFFFFF; // crc
L1:
    if (edi >= ebp) goto E;
    int ecx = ebx[edi];
    eax = eax ^ edi;
    esi = 0;
L2:
    if (esi >= 8) goto NEXT;
    int edx = eax & 1;
    edx = -edx;
    eax = (eax >> 1) ^ (0xEDB88320 & edx);
    esi++;
    goto L2;
NEXT:
    edi++;
    goto L1;
E:
    return ~eax;
}