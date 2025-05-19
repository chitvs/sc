#include "e1A.h"

int count_tokens(char* str, const char* sep) {
    int edi = 0;
    int eax;
    const char* esi = sep;
    char* tmp = str;
    char* a = strtok (tmp, esi);
    char* ebx = a;
L:
    if (ebx == 0)
        goto RET;
    edi++;
    a = strtok(0, esi);
    ebx = a;
    goto L;
RET:
    eax = edi;
    return eax;
}