#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* esquerda;
    struct Node* direita;
} Node;

Node* criarNo(int valor) {
    Node* novo = malloc(sizeof(Node));
    novo->valor = valor;
    novo->esquerda = novo->direita = NULL;
    return novo;
}

void insere(Node** raiz, int valor) {
    if (*raiz == NULL) {
        *raiz = criarNo(valor);
        return;
    }
    
    if (valor < (*raiz)->valor) {
        insere(&(*raiz)->esquerda, valor);
    } else {
        insere(&(*raiz)->direita, valor);
    }
}

void preFixo(Node* raiz) {
    if (raiz == NULL) {
        return;
    }

    printf(" %d", raiz->valor);
    preFixo(raiz->esquerda);
    preFixo(raiz->direita);
}

void inFixo(Node* raiz) {
    if (raiz == NULL) {
        return;
    }

    inFixo(raiz->esquerda);
    printf(" %d", raiz->valor);
    inFixo(raiz->direita);
}

void posFixo(Node* raiz) {
    if (raiz == NULL) {
        return;
    }

    posFixo(raiz->esquerda);
    posFixo(raiz->direita);
    printf(" %d", raiz->valor);
}

int main() {
    int T, i, N, valor;
    scanf("%d", &T);

    for (i = 1; i <= T; i++) {
        Node* raiz = NULL;
        scanf("%d", &N);

        while (N--) {
            scanf("%d", &valor);
            insere(&raiz, valor);
        }

        printf("Case %d:\n", i);
        printf("Pre.:");
        preFixo(raiz);
        printf("\n");
        printf("In..:");
        inFixo(raiz);
        printf("\n");
        printf("Post:");
        posFixo(raiz);
        printf("\n\n");

        free(raiz);
    }

    return 0;
}
