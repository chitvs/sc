#include "e2.h"

long f_opt(const short *v, unsigned n){
    long x = 0;
    unsigned i;
    
    for (i=0; i<n; i+=1) x += v[i];
    
    return x;
}