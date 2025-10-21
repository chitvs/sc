#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "e2.h"

void getBookingsAfterTime(struct booking **list, const char *data, int size, const char *time) {
    
    struct booking *head = NULL;
    struct booking *tail = NULL;

    for (int i = 0; i < size / 37; i++) {
        const char *record = data + i * 37;

        char my_surname[31];
        strncpy(my_surname, record, 30);
        my_surname[30] = '\0';

        for (int j = 29; j >= 0; j--) {
            if (my_surname[j] == '_') {
                my_surname[j] = '\0';
            } else {
                break;
            }
        }

        char my_places[3];
        strncpy(my_places, record + 30, 2);
        my_places[2] = '\0';
        int places = atoi(my_places);

        char my_time[6];
        strncpy(my_time, record + 32, 5);
        my_time[5] = '\0';

        if (strcmp(my_time, time) >= 0) {
            struct booking *b = malloc(sizeof(struct booking));
            b->surname = strdup(my_surname);
            b->places = places;
            b->time = strdup(my_time);
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

    *list = head;
}
