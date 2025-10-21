int fib(int n){
    int di=n;
    int a=1;
    if (di>=2)
        goto A;
    return a;
    A:
    di--;
    a = fib(di);
    int b = a;
    di--;
    a = fib(di);
    a = a+b;
    return a;
}