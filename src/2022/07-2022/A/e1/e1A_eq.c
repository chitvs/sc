#include "e1A.h"

int* count_vars(char** vars, int n) {
    char** esi = vars;
    int edi = n;
    if (esi == NULL) goto E1;
    if (n<=0) goto E1;
    int ecx = 4*edi;
    int* eax = malloc(4*edi);
    int* ebp = eax;
    int ebx = 0;
L:
    if (ebx >= edi) goto E2;
    char* edx = esi[ebx];
    eax = (int*)getenv(edx);
    if (eax != NULL)
        goto A;
    ebp[ebx] = 0;
    ebx++;
    goto L;
A:
    ebp[ebx] = 1;
    ebx++;
    goto L;
E1:
    eax = NULL;
    goto E3;
E2:
    eax = ebp;
    goto E3;
E3:
    return eax;
}