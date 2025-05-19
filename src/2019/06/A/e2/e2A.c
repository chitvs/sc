#include "e2A.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void run(int* v, int n, int (*f)(int i)){
    int ex;
    for (int i=0; i<n; i++){
        pid_t pid = fork();
        if (pid == -1) {
            exit(EXIT_FAILURE);
        }
        if (pid == 0) {
            ex = f(i);
            exit(ex);
        }
        int status;
        pid = wait(&status);
        if (WIFEXITED(status))
            v[i] = WEXITSTATUS(status);
    }
}
