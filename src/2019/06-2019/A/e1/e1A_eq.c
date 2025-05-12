#include "e1A.h"

void init_matrix(short** m, unsigned n) {
    unsigned i = 0;
    unsigned j;
F1:
    if (i >= n) goto E;
    j = 0;
F2:
    if (j >= n) goto NEXT;
    short tmp = value(i,j);
    short* tmp2 = m[i];
    tmp2[j] = tmp;
    ++j;
    goto F2;
NEXT:
    ++i;
    goto F1;
E:
    return;
}