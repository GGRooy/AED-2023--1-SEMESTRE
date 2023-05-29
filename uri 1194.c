#include <stdio.h>
#include <stdlib.h>

typedef struct noArv {
    char letra;
    struct noArv* direita;
    struct noArv* esquerda;
} noArv;

noArv* novoNo(char letra) {
    noArv* no = (noArv*)malloc(sizeof(noArv));
    no->letra = letra;
    no->esquerda = no->direita = NULL;
    return no;
}

int searchIndex(char* str, int inicio, int fim, char letra) {
    for (int i = inicio; i <= fim; ++i) {
        if (str[i] == letra)
            return i;
    }
    return -1;
}

noArv* construirArvore(char* infixa, char* prefixa, int inInicio, int inFim, int* indice) {
    if (inInicio > inFim)
        return NULL;

    noArv* no = novoNo(prefixa[(*indice)++]);
    if (inInicio == inFim)
        return no;

    int infixaIndice = searchIndex(infixa, inInicio, inFim, no->letra);
    no->esquerda = construirArvore(infixa, prefixa, inInicio, infixaIndice - 1, indice);
    no->direita = construirArvore(infixa, prefixa, infixaIndice + 1, inFim, indice);

    return no;
}

void imprimirPosfixa(noArv* no) {
    if (no == NULL)
        return;

    imprimirPosfixa(no->esquerda);
    imprimirPosfixa(no->direita);
    printf("%c", no->letra);
}

int main() {
    short C;
    scanf("%hu", &C);

    while (C--) {
        short qtsNodes;
        scanf("%hu ", &qtsNodes);

        char prefixa[qtsNodes], infixa[qtsNodes];
        scanf("%s %s", prefixa, infixa);

        int indice = 0;
        noArv* raiz = construirArvore(infixa, prefixa, 0, qtsNodes - 1, &indice);
        imprimirPosfixa(raiz);
        printf("\n");

        free(raiz);
    }

    return 0;
}
