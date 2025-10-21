#include <stdio.h>

void uint2bin(unsigned x, char bin[32]){
    for (int i=31;i>=0;i--){
        bin[i] = '0' + (x & 1);
        x = x >> 1;
    }               
}
