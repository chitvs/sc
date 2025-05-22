#include "e2B.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareConnessioni(const void *a, const void *b) {
    struct connessione *ca = *(struct connessione **)a;
    struct connessione *cb = *(struct connessione **)b;
    return ca->costo - cb->costo;
}

void destinazioniAcquistabili(struct connessione *list, const char* partenza, int budget, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f)
        return;

    struct connessione *validi[100];
    int count = 0;

    while (list) {
        if (list->costo <= budget && strcmp(list->partenza, partenza) == 0) {
            validi[count] = list;
            count++;
        }
        list = list->next;
    }

    qsort(validi, count, sizeof(struct connessione*), compareConnessioni);

    for (int i = 0; i < count; i++) {
        fprintf(f, "%s-%s-%d\n", validi[i]->partenza, validi[i]->destinazione, validi[i]->costo);
    }

    fclose(f);
}
