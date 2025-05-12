#include "e1B.h"

int count_matching_vars(char** vars, char* pattern) {
    char** ebx = vars;
    char* ebp = pattern;
    int edi = 0;
    int eax;
    if (ebx == 0)
        goto E1;
    if (ebp == 0)
        goto E1;
L:
    char* edx = *ebx;
    if (edx==0)
        goto E2;
    eax = (int)getenv(edx);
    if ((char*)eax && strstr((char*)eax, ebp))
        goto A;
    ebx++;
    goto L;
A:
    edi++;
    ebx++;
    goto L;    
E1:
    eax = -1;
    goto RET;
E2:
    eax = edi;
    goto RET;
RET:
    return eax;

}