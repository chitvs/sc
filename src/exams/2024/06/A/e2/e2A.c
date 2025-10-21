#include "e2A.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void destinazioniDisponibili(const char *filename, const char *partenza, int budget, struct destinazione **list) {
    
    struct destinazione *head = NULL;
    struct destinazione *tail = NULL;
    
    FILE *f = fopen(filename, "r");
    if (!f)
        return;
    
        char s[15];
    
    while (fgets(s, sizeof(s), f) != NULL) {
        
        char *dep = strtok(s, "-");
        char *arr = strtok(NULL, "-");
        char *cost = strtok(NULL, "-");
        int costInt = atoi(cost);
        
        if (costInt <= budget && strcmp(dep, partenza) == 0) {
            
            struct destinazione *new_node = malloc(sizeof(struct destinazione));
            
            if (!new_node)
                return;

            strncpy(new_node->destinazione, arr, sizeof(new_node->destinazione));
            new_node->destinazione[sizeof(new_node->destinazione) - 1] = '\0';
            new_node->costo = costInt;
            new_node->next = NULL;

            if (head == NULL) {
                head = tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        }
    }

    fclose(f);
    *list = head;
}
