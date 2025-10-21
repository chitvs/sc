#include "e2A.h"

#include <stdio.h>

void getStudents(const char * filename, student * in_list, int min_mark){
    FILE *f = fopen(filename, "w");

    while (in_list){
        if (in_list->mark >= min_mark){
            fprintf(f, "%s %s - %d\n", in_list->surname, in_list->name, in_list->mark);
        }
        in_list = in_list->next;
    }
    
    fclose(f);
}
