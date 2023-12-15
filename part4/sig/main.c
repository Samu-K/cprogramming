#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <signal.h>

#include "signaalit.h"

#define MAX_COMMAND_LEN 100
#define MAX_BUFFER_SIZE 100

int main(void) {
    int *taulu = NULL;
    size_t taulunKoko = 0;
    char komento[10];
    int arvo1,arvo2;
    int arvo;
    size_t i;
    int signaali;
    const char* signaalinNimi;
    char input[MAX_COMMAND_LEN];
    
    signal(SIGFPE,hoidaSIGFPE);
    signal(SIGSEGV,hoidaSIGSEGV);

    while (1) {
        if (setjmp(paluuTila) == 0) {
            printf("Anna komento: ");
            fgets(input, sizeof(input), stdin);

            if (sscanf(input, "%s %d %d", komento, &arvo1, &arvo2) == 3) {
                if (strcmp(komento, "lisää") == 0) {
                    if (arvo2 != 0) {
                        arvo = arvo1 / arvo2;
                        taulu = realloc(taulu, (taulunKoko + 1) * sizeof(int));
                        taulu[taulunKoko++] = arvo;
                    } else {
                        raise(SIGFPE);
                    }
                } else {
                    printf("Tuntematon komento\n");
                }
            } else if (sscanf(input, "%s %u", komento, &arvo1) == 2) {
                if (strcmp(komento, "tulosta") == 0) {
                    if (arvo1 < taulunKoko) {
                        printf("%d\n", taulu[arvo1]);
                    } else {
                        raise(SIGSEGV);
                    }
                } else {
                    printf("Tuntematon komento\n");
                }
            } else if (strcmp(input, "tulosta\n") == 0) {
                for (i = 0; i < taulunKoko; i++) {
                    printf("%d ", taulu[i]);
                }
                printf("\n");
            } else {
                printf("Tuntematon komento\n");
            }
        } else {
            signaali = setjmp(paluuTila);

            switch (signaali) {
                case SIGFPE:
                    signaalinNimi = "SIGFPE";
                    break;
                case SIGSEGV:
                    signaalinNimi = "SIGSEGV";
                    break;
                default:
                    signaalinNimi = "UNKNOWN";
            }

            printf("Aiheutui signaali %s\n", signaalinNimi);
        }
    }

    free(taulu);

    return 0;
}
