unsigned int adler32_simplified(unsigned char* data, int len){
    unsigned char* ebx = data;
    int ecx = len;
    unsigned int edx = 1, esi = 0; // a,b
    int edi = 0; // index
    unsigned int eax;
    unsigned int ebp;
L:
    if (edi >= ecx) goto E;
    ebp = ebx[edi];
    edx += ebp;
    edx = edx & 0xFFFF;
    esi += edx;
    esi = esi & 0xFFFF;
    edi++;
    goto L;
E:

    esi = (esi << 16);
    eax = esi | edx;
    return eax;
}


