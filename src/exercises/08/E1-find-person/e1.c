#include <string.h>

#include "e1.h"

int comp(const void *a, const void *b) {
    person_t *p1 = (person_t*) a;
    person_t *p2 = (person_t*) b;
    return (strcmp(p1->name, p2->name));
}

void sort_people(person_t p[], size_t n){
    qsort(p,n, sizeof(p[0]), comp);
}

person_t *find_person(char *key, person_t sorted[], size_t n){
    return bsearch(&key, sorted, n, sizeof(sorted[0]), comp);
}