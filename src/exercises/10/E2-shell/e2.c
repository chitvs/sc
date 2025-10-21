#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "../E1-get-cmd-line/e1.c"
#include "e2.h"

int do_shell(const char* prompt){
    
    char* argv[64];

    while (1) {
        printf("%s", prompt);          
        get_cmd_line(argv);            

        if (argv[0] == NULL) {
            continue;                 
        }

        if (strcmp(argv[0], "quit") == 0) {
            break;                   
        }

        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            execvp(argv[0], argv);
            fprintf(stderr, "unknown command: %s\n", argv[0]);
            _exit(EXIT_FAILURE);
        }

        if (wait(NULL) == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }  

    }

        return EXIT_SUCCESS;
}
