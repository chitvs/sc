#include "e1A.h"

int count_tokens(char* str, const char* sep) {
    char* ecx = str;
    const char* esi = sep;
    int ebx = 0;
    char* eax = strtok(ecx, esi);
L:
    if (eax == 0) goto E;
    ebx++;
    eax = strtok(0, esi);
    goto L;
E:
    return ebx;
}