#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINGUAGEM_TAMANHO 20
#define MAX_PESSOAS 100 

int main() {
    unsigned short casos, numeroPessoas;

    scanf("%hu", &casos);

    while (casos--) {
        scanf("%hu", &numeroPessoas);

        char idiomaAtual [MAX_LINGUAGEM_TAMANHO + 1];
        char idiomaAnterior [MAX_LINGUAGEM_TAMANHO + 1];
        bool ingles = false;

        scanf(" %s", idiomaAtual);
        strcpy(idiomaAnterior, idiomaAtual);

        numeroPessoas--;

        while (numeroPessoas--) {
            if (strcmp(idiomaAtual, idiomaAnterior) != 0 && !ingles) {
                ingles = true;
            } else {
                strcpy(idiomaAnterior, idiomaAtual);
            }

            scanf(" %s", idiomaAtual);
        }

        if (ingles) {
            printf("ingles\n");
        } else {
            printf("%s\n", idiomaAtual);
        }
    }

    return 0;
}
