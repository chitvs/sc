int min(int x, int y, int z) {
    int a = x;
    int c = y;
    int d = z;
    if (a >= c)
        goto E1;
    if (a >= d)
        goto E2;
    return a;

    E1: 
        if (c >= d)
            goto E2;
        a = c;
        return a;

    E2:
        a = d;
        return a;
}