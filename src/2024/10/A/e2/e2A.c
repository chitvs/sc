#include "e2A.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

void check_error(int res, char* msg) {
    if (res != -1) return;
    perror(msg);
    exit(EXIT_FAILURE);
}

int countMinWords(const char** s, int n){
    if (s == NULL || n == 0)
        return -1;

    int minWords = 1000;

    for (int i=0; i<n;i++){
        pid_t pid = fork();
        check_error(pid, "fork");
        if (pid == 0){
            int words = 0;
            for (int j = 0; j<strlen(s[i]); j++)
                if (s[i][j] == ' ') words++;
            if (words != 0)
                words++;
            exit(words);
        }
    }

    for (int i = 0; i < n; i++) {
        int status;
	    wait(&status);
        if(WIFEXITED(status)){
            if (WEXITSTATUS(status) < minWords)
                minWords = WEXITSTATUS(status);
        }
    }

    return minWords;
}