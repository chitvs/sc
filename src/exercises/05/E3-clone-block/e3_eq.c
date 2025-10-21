#include <stdlib.h>
#include <string.h>

void* clone(const void* src, int n) {
    const void* si = src;
    int b = n;
    void* a = malloc(b);
    void* di = a;
    if (di==0) goto A;
    memcpy(a, si, b);
    return a;
    A:
        return a;
}