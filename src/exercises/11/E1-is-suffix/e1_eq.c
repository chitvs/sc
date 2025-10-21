#include "e1.h"

int is_suffix(const char* s1, const char* s2){

    const char *ecx = s1;
    const char *edx = s2;

L:  if (*ecx == 0) goto L2;
        ecx++;
        goto L;
L2:
    if (*edx == 0) goto L3;
        edx++;
        goto L2;
L3:
    if (s1 == ecx) goto E1;
    if (s2 == edx) goto E1;
    char bl = *edx;
    if (*ecx != bl) goto E1;
    ecx--;
    edx--;
    goto L3;
E1:
    if (s1 != ecx) goto E2;
    if (*ecx != *edx) goto E2;
    return 1;
E2:
    return 0;
}