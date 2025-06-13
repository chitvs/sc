#include "e1A.h"

int* check_quiz(char** answers, char* solution, int n) {
    if (answers == 0)
        goto E1;
    if (solution == 0)
        goto E1;
    if (n <= 0)
        goto E1;
    int edi = 4*n;
    int* eax = malloc(edi);
    int esi = 0;
    edi = 0;
    char** edx = answers;
    char* ebp = solution;
L1:
    if (edi >= n)
        goto RET;
    eax[edi] = 0;
    esi = 0;
    goto L2;
L2:
    if (esi >= 4)
        goto NEXT;
    char* ecx = edx[edi];
    if (ecx[esi] == ebp[esi])
        eax[edi]++; 
    esi++;
    goto L2;
NEXT:
    edi++;
    goto L1;
E1:
    eax = NULL;
    goto RET;
RET:
    return eax;
}