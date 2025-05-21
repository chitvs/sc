#include "e2B.h"

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void check_error(int res, char* msg) {
    if (res != -1) return;
    perror(msg);
    exit(EXIT_FAILURE);
}

int wordcount(const char** s, int n){
    if (n == 0){
        return -1;
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        check_error(pid, "fork");
        if (pid == 0) {
            const char* str = s[i];
            char* str2 = strdup(str);
            char* token = strtok(str2, " ");
            int cnt = 0;
            while (token != NULL){     
                cnt++;
                token = strtok(NULL, " ");
            }
            exit(cnt);
        }
    }
    int status;
    while (wait(&status) > 0) {
        if (WIFEXITED(status)) {
            int child_count = WEXITSTATUS(status);
            if (child_count > max) {
                max = child_count;
            }
        }
    }
    return max;
}
