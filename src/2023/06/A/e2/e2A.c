#include "e2A.h"

#include <stdio.h>

#include <string.h>

int examStats(const char* fname, int * min, int * max, float * avg){
    char line[256];

    int grades = 0;
    int maxx = 0;
    int minn = 30;
    int cnt = 0;
    
    FILE *f = fopen(fname, "r");

    if (!f) return -1;

    while (fgets(line, sizeof(line), f)){
        char* surname = strtok(line, "-");
        char* name = strtok(NULL, "-");
        char* grade = strtok(NULL, "-");
        if (atoi(grade) >= 18){
            grades += atoi(grade);
            cnt++;
        }
        if (atoi(grade) > maxx)
            maxx = atoi(grade);
        if (atoi(grade) < minn)
            minn = atoi(grade);
        *min = minn;
        *max = maxx;
        *avg = grades/cnt;
    }

    return cnt;
}
