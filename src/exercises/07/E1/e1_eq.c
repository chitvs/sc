#include "e1.h"

int binsearch(int *v, int n, int x) {
    int* ebx=v;
    int ecx=n;
    int edx=x;
    int eax=0;
    int esi=0;
L:
    if (esi>=ecx)
        goto E;
    int edi = (esi+ecx)/2;
    if (ebx[edi]==edx){
        eax = 1;
        goto E;
    }
    if (ebx[edi]>edx){
        ecx = edi;
    }
    if (ebx[edi]<edx){
        esi = edi+1;
    }
    goto L;
E:
    return eax;
}