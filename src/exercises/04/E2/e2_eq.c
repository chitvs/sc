int find(int* v, int n, int x) {
    int* ecx = v;
    int eax = n;
    int edx = x;
L:
    if (eax <= 0)
        return 0;  
    eax--;
    if (ecx[eax] != edx)
        goto L;
    return 1;
}