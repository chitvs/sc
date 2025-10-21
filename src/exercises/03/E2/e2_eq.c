unsigned int fib(unsigned int n) {
    unsigned int a = 0;
    unsigned int c = 1;
    unsigned int d = n;
    
    if (d != 0)
        goto E;
    return a;
        
    E:
        if (d != 1)
            goto L;
        a = c;
        return a;
    L:
        if (d <= 1) 
            goto W;
        a = a + c;
        a = a + c;
        int di = a - c;
        c = di;
        a = a - c;
        d--;
        goto L;
    W:
        a = c;
        return a;
}