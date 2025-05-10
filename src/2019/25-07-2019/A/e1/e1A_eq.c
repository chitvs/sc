#include "e1A.h"

int most_freq_char(const char* s, int* map) {
    int i=0, max = 0;
    clear(map, 256);
L:
    if (!*s) goto E1;
    map[*s]++;
    *s++;
    goto L;
E1:
    if (i>=256) goto E2;
    if (map[i] <= map[max]) goto NEXT;
    max = i;
NEXT:
    ++i;
    goto E1;
E2:
    return max;
}