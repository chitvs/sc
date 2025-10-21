#include "e2A.h"

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

int multicount(const char** s, char c, int n){
    if (c == '\0' || n == 0){
        return -1;
    }

    int max = 0;

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        check_error(pid, "fork");
        if (pid == 0) {
            int cnt = 0;
            int len = strlen(s[i]);
            const char* str = s[i];
            for (int j = 0; j < len; j++) {
                if (str[j] == c) {
                    cnt++;
                }
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
