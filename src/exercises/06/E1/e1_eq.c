#include <stdlib.h>
#include "e1.h"

int list_add_first(node_t **l, short elem) {
    short ebx = elem;

    node_t **ecx = l;
    node_t *edx = *ecx; // node_t *p = *l;
    node_t *eax = malloc(8);
    node_t *edi = eax; // node_t *n = malloc(sizeof(node_t));
    if (edi==NULL) return -1;
    edi->elem = ebx;
    edi->next = edx;
    node_t *esi = edi;
    *l = esi;
    return 0;
}