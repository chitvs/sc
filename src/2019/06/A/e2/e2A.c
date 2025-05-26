#include "e2A.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void check_error(int res, char* msg){
    if (res!=-1) return;
    perror(msg);
    exit(EXIT_FAILURE);
}

void run(int* v, int n, int (*f)(int i)){

    for (int i=0; i<n; i++){
        pid_t pid = fork();
        check_error(pid, "fork");
        if (pid == 0) {
            int res = f(i);
            exit(res);
        }
    }

    for (int i=0; i<n; ++i){
        int status;
        pid_t pid = wait(&status);
        if (WIFEXITED(status))
            v[i] = WEXITSTATUS(status);
    }

}