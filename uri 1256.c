#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct No {
    struct No *prox;
    int valor;
} No;

typedef struct {
    No *inicio;
    No *fim;
} TabelaHash;

void inicializa(TabelaHash *, int);
void insereNo(TabelaHash *, int, int);
void imprimeHash(No *, int);

int main() {
    TabelaHash tabela[MAX];
    int chave, num, n, elemento, i, j;
	
    scanf("%d", &n);
	
    for (j = 0; j < n; j++) {	
        scanf("%d %d", &chave, &num);
        inicializa(tabela, chave);
		
        for (i = 0; i < num; i++) {
            scanf("%d", &elemento);
            insereNo(tabela, elemento % chave, elemento);
        }
		
        for (i = 0; i < chave; i++)
            imprimeHash(tabela[i].inicio, i);
		
        if (j + 1 < n)
            printf("\n");
    }
	
    return 0;
}

void imprimeHash(No *inicio, int indice) {
    No *aux = inicio;
    printf("%d -> ", indice);
	
    while (aux != NULL) {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }
	
    printf("\\\n");
}

void insereNo(TabelaHash *tabela, int indice, int elemento) {
    No *aux = (No *)malloc(sizeof(No));
    aux->valor = elemento;
    aux->prox = NULL;
	
    if (tabela[indice].inicio == NULL) {
        tabela[indice].inicio = aux;
    } else {
        tabela[indice].fim->prox = aux;
    }
	
    tabela[indice].fim = aux;
}

void inicializa(TabelaHash *tabela, int n) {
    int i;
    for (i = 0; i < n; i++) {
        tabela[i].inicio = NULL;
        tabela[i].fim = NULL;
    }
}
