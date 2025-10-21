int comp(const void* xv, const void* yv) {
    int* a = (int*)xv; // nota: in IA32 gli indirizzi non hanno tipo
    int* c = (int*)yv; // e sono semplicemente dei numeri senza segno
    return *a - *c;
}