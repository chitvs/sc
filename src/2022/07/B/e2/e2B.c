#include "e2B.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getBookingsAfterTime(struct booking **list, const char *filename, const char *time) {
    struct booking *head = NULL;
    struct booking *tail = NULL;

    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        perror("Error opening file");
        return;
    }

    char surname[31];     
    char places[3];        
    char time_booked[6];   

    while (
        fread(surname, 1, 30, f) == 30 &&
        fread(places, 1, 2, f) == 2 &&
        fread(time_booked, 1, 5, f) == 5
    ) {
        surname[30] = '\0';
        places[2] = '\0';
        time_booked[5] = '\0';

        for (int j = 29; j >= 0; j--) {
            if (surname[j] == '_')
                surname[j] = '\0';
            else
                break;
        }

        if (strcmp(time_booked, time) >= 0) {
            struct booking *b = malloc(sizeof(struct booking));
            if (!b) {
                perror("malloc failed");
                fclose(f);
                return;
            }

            b->surname = strdup(surname);
            b->places = atoi(places);
            b->time = strdup(time_booked);
            b->next = NULL;

            if (head == NULL) {
                head = b;
                tail = b;
            } else {
                tail->next = b;
                tail = b;
            }
        }
    }

    fclose(f);
    *list = head;
}
