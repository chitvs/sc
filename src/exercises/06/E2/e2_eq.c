#include <stdlib.h>
#include "e2.h"

int list_equal(const node_t *l1, const node_t *l2) {
    const node_t *a = l1;
    const node_t *c = l2;
    L:
        if (a==0) goto E;
        if (c==0) goto E;
        short d = (*c).elem;
        if ((*a).elem == d) goto F;
        return 0;
    F:
        a = (*a).next;
        c = (*c).next;
        goto L;
    E:
        char al = a == 0;
        char ah = c == 0;
        al = al & ah;
        return (int) al;
}