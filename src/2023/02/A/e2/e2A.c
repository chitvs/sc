#include "e2A.h"

#include <stdio.h>
#include <string.h>

void reverseTextFile(const char * input_file, const char * output_file){
	char line[1000];
	int input_size;

    FILE *f1 = fopen(input_file, "r");
    FILE *f2 = fopen(output_file, "w");

	if (f1==NULL || f2==NULL) 
        return;
    
    fseek(f1, 0, SEEK_END);
    input_size = ftell(f1);
    fseek(f1, 0, SEEK_SET);

	for (int i=0; i<input_size; i++) fputc('0', f2);

	while(fgets(line, sizeof(line), f1)) {
	    fseek(f2, -strlen(line), SEEK_CUR);
        fputs(line, f2);
	    fseek(f2, -strlen(line), SEEK_CUR);
	}

    fclose(f1);
	fclose(f2);
	return;
}