char my_strcmp(const char* s1, const char* s2) {
    const char* ecx = s1;
    const char* edx = s2;
L:  
    char al = *ecx;
    if (al == 0)
        goto W;
    if (al != *edx)
        goto W;
    ecx++;
    edx++;
    goto L;
W:
    al = al - *edx;
    return al;
}