#include "e2A.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int examStats(const char* fname, int *min, int *max, float *avg) {
    FILE *f = fopen(fname, "r");
    if (!f) return -1;

    char line[256];
    int passedCount = 0;
    float sum = 0;

    int localMin = 31;
    int localMax = 0;

    while (fgets(line, sizeof(line), f)) {
        char *surname = strtok(line, "-");
        char *name = strtok(NULL, "-");
        char *gradeStr = strtok(NULL, "-");

        if (!surname || !name || !gradeStr)
            continue;

        int grade = atoi(gradeStr);

        if (grade >= 18) {
            if (grade < localMin) localMin = grade;
            if (grade > localMax) localMax = grade;
            sum += grade;
            passedCount++;
        }
    }

    fclose(f);

    if (passedCount == 0) {
        *min = 0;
        *max = 0;
        *avg = 0.0;
        return 0;
    }

    *min = localMin;
    *max = localMax;
    *avg = sum / passedCount;
    return passedCount;
}
