#include "e2A.h"

#include <stdio.h>
#include <string.h>

int getFirstEmptySlot(const char * filename, int len, char ** output){
    FILE *f = fopen(filename, "r");
    if (!f) return -1;

    char line[50];
    char surname[31], day[11], time[6], length[4];

    while (fgets(line, sizeof(line), f)) {
        if (strlen(line) < 48) break;  
        line[48] = '\0'; 

        strncpy(surname, line, 30);
        surname[30] = '\0';
        strncpy(day, line + 30, 10);
        day[10] = '\0';
        strncpy(time, line + 40, 5);
        time[5] = '\0';
        strncpy(length, line + 45, 3);
        length[3] = '\0';

        printf("Surname: '%s'\n", surname);
        printf("Day: '%s'\n", day);
        printf("Time: '%s'\n", time);
        printf("Length: '%s'\n", length);
    }

    //TODO

    fclose(f);
    return 0;
}
