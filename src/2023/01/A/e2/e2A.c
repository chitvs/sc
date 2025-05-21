#include "e2A.h"

#include <stdio.h>
#include <stdlib.h>

void decodeTextFile(const char *encoded_file, const char *key_file, char **decoded_text) {
    int c;
    char *keymap = (char *) malloc(sizeof(char) * 58);
    if (keymap == NULL) {
        perror("Errore allocazione keymap");
        *decoded_text = NULL;
        return;
    }

    FILE *f = fopen(key_file, "r");
    if (f == NULL) {
        perror("File con la chiave non esistente");
        free(keymap);
        *decoded_text = NULL;
        return;
    }

    for (int i = 0; i < 58; i++) {
        keymap[i] = getc(f);
    }
    fclose(f);

    f = fopen(encoded_file, "r");
    if (f == NULL) {
        perror("File da decodificare non esistente");
        free(keymap);
        *decoded_text = NULL;
        return;
    }

    fseek(f, 0, SEEK_END);
    int text_size = ftell(f);
    fseek(f, 0, SEEK_SET);

    *decoded_text = (char *) malloc((text_size + 1) * sizeof(char));
    if (*decoded_text == NULL) {
        perror("Errore allocazione memoria per testo decodificato");
        fclose(f);
        free(keymap);
        return;
    }

    int i = 0;
    while ((c = fgetc(f)) != EOF) {
        if (c >= 65 && c <= 122) {
            (*decoded_text)[i] = keymap[c - 65];
        } else {
            (*decoded_text)[i] = (char)c;
        }
        i++;
    }
    (*decoded_text)[i] = '\0';

    fclose(f);
}
