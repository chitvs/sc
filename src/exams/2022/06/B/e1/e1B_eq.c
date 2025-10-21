#include "e1B.h"

int crc32b(char *bytes, int n) {
    char *ebp = bytes;
    int ebx = n;
    int edi = ~0; // magic
    int esi = edi; // crc
L:
    if (ebx==0) goto E;
    int something; // value
    int edx = *ebp++; // byte
    int ecx = esi ^ edx; // index
    get_constant(&something, ecx & 0xFF);
    esi = something ^ (esi >> 8);
    ebx--;
    goto L;
E:
    int eax = edi;
    return eax ^ esi;
}