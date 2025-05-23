#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "e2A.h"

int getFirstEmptySlot (const char * filename, int len, char ** output){

	FILE* fp;
	* output = (char *) malloc((sizeof(char)*17));

	fp = fopen(filename, "r");
	if (fp==NULL) return -1;

	char data_corrente [11];
	char ora_corrente [6];
	char buf[50];
	char data_tmp [11];
	char ora_tmp [6];
	char ora_next [6];
	char durata_tmp [4];
	int termina = 0;

	char * ret = fgets(buf, sizeof(buf), fp);
	if (ret!=NULL) {
		strncpy(data_tmp, buf+30, 10);
		data_tmp[10] = '\0';
		strncpy(ora_tmp, buf+40, 5);
		ora_tmp[5] = '\0';
		strncpy(durata_tmp, buf+45, 3);
		durata_tmp[3] = '\0';
	}

	for (int d=18; d<23; d++) {

        sprintf(data_corrente, "%02d/09/2023", d);
		strcpy(ora_corrente,"08:00");

		while (strcmp(data_tmp,data_corrente)==0) {
			strcpy(ora_next,ora_tmp);
			if (calculateTimeDifference(ora_corrente,ora_next)>=len) {
				sprintf(*output, "%s %s", data_corrente, ora_corrente);
				termina=1;
				break;
			}
			strcpy(ora_corrente,addMinutesToTime(ora_next, atoi(durata_tmp)));

			ret = fgets(buf, sizeof(buf), fp);
			if (ret!= NULL){
				strncpy(data_tmp, buf+30, 10);
				data_tmp[10] = '\0';
				strncpy(ora_tmp, buf+40, 5);
				ora_tmp[5] = '\0';
				strncpy(durata_tmp, buf+45, 3);
				durata_tmp[3] = '\0';
			} else {
				strcpy(data_tmp, "23/09/2023");
				strcpy(ora_next,"18:00");
			}
		}

		if(termina==1) break;

		strcpy(ora_next,"18:00");
		
		if (calculateTimeDifference(ora_corrente,ora_next)>=len) {
			sprintf(*output, "%s %s", data_corrente, ora_corrente);
			termina=1;
			break;
		}
	
		strcpy(ora_corrente, "08:00");
	}

	fclose(fp);
	if (termina==1)
		return 0;
	else
		return -1;
}