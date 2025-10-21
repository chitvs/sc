int counteq(short* v1, short* v2, int n) {
    short* di = v1;
    short* si = v2;
    int c=n;
    int a=0;
    c--;
L:
    if (c<0) goto E;
    short b = di[c];
    short d = si[c];
    char dl = d==b ? 1 : 0;
    int dd = (int)dl;
    a = a+dd;
    c--;
    goto L;
E:
    return a;
}