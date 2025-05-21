#include "e2A.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getLargeTables(struct booking **list, const char *filename, int num) {
    struct booking *head = NULL;
    struct booking *tail = NULL;

    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        perror("Error opening file");
        return;
    }

    char surname[31] ;
    char places[3];
    char time[6];

    while (
        fread(surname, 1, 30, f) == 30 &&
        fread(places, 1, 2, f) == 2 &&
        fread(time, 1, 5, f) == 5
    ) {
        for (int i = 29; i >= 0; i--){
            if (surname[i] == '_')
                surname[i] = '\0';
            else
                break;
        }

        if (atoi(places) >= num) {

            struct booking *new_node = malloc(sizeof(struct booking));
            
            if (!new_node) {
                perror("malloc failed");
                fclose(f);
                return;
            }

            new_node->surname = strdup(surname);  
            new_node->time = strdup(time);        
            new_node->places = atoi(places);
            new_node->next = NULL;

            if (head == NULL) {
                head = new_node;
                tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        }
    }

    fclose(f);
    *list = head;
}
