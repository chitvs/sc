#include "e2A.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

void check_error(int res, char* msg) {
    if (res != -1) return;
    perror(msg);
    exit(EXIT_FAILURE);
}

int contains(char* s, char c, int n){
    int i;
    int len = strlen(s);
    int m = len/n;
    int ex = 0;
    if (m*n < len){
        for (i=n*m; i<len; i++){
            if (s[i] == c)
                ex = 1;
        }
    }
    for (i=0; i<n; i++){
        pid_t pid = fork();
        if (pid == -1)
            check_error(pid, "fork");
                    if (pid==0){
            for (int j = i*m;j<(i+1)*m;j++){
                if (s[j] == c)
                    ex = 1;
            }
        _exit(ex);
        }
    }
    for (i=0; i<n; i++) {
        int status;
        pid_t pid = wait(&status);
        check_error(pid, "wait");
        if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
            ex = 1;
    }
    return ex;
}

