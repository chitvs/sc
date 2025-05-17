#include "e1A.h"

int* strings_are_upper(const char** array, int n) {
    if (array == 0) goto E1;
    if (n <= 0) goto E1;
    int* eax = malloc(4*n);
    int* edi = eax;
    int esi = 0;
    const char** ebp = array;
L:
    if (esi >= n)
        goto E2;
    const char* ebx = ebp[esi];
    edi[esi] = 1;
L2:
    if (*ebx==0)
        goto NEXT;
    eax = (int*)isupper(*ebx);
    if (eax==0){
        goto L3;
    }
    ebx++;
    goto L2;
L3:
    edi[esi] = 0;
    goto NEXT;
NEXT:
    esi++;
    goto L;
E1:
    eax = NULL;
    goto RET;
E2:
    eax = edi;
    goto RET;
RET:
    return eax;
}