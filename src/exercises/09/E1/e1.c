#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "e1.h"

int parseCSV(const char* file, person_t** out, int minYear) {
    FILE *myfile = fopen(file, "r"); 
    *out = NULL;
    person_t *last = NULL;

    if (!myfile)
        return -1;

    char line[64];
    while (fgets(line, sizeof(line), myfile)) {

        char* name = strtok(line, ",");
        char* surname = strtok(NULL, ",");
        char* bornDate = strtok(NULL, ",");
        char* has_phd = strtok(NULL, ",");

        char* day = strtok(bornDate, "-");
        char* month = strtok(NULL, "-");
        char* yearStr = strtok(NULL, "-");

        int year = atoi(yearStr);
        if (year >= minYear) {
            person_t* new_person = malloc(sizeof(person_t));

            new_person->name = strdup(name);
            new_person->surname = strdup(surname);
            new_person->year = year;
            new_person->has_phd = (strcmp(has_phd, "yes") == 0) ? 1 : 0;
            new_person->next = NULL;

            if (*out == NULL)
                *out = new_person;
            else
                last->next = new_person;

            last = new_person;
        }
    }

    fclose(myfile);
    return 0;
}
