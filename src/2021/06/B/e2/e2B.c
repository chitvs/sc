#include "e2B.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

off_t searchfile(char* filename, char c){
    int file = open(filename, O_RDONLY);
    if (file == -1){
        perror("errore nell'aprire il file");
        exit(EXIT_FAILURE);
    }
    off_t offset = 0;
    char buffer;
    ssize_t res = read(file, &buffer, 1);
    while (res > 0) {
        if (buffer == c) {
            close(file);
            return offset;
        }
        offset++;
        res = read(file, &buffer, 1);
    }
    if (res == -1) {
        perror("errore in read");
        close(file);
        exit(EXIT_FAILURE);
    }
    close(file);
    return -1;
}