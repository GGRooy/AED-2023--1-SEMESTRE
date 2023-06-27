#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cel{
    char data;
    struct cel *esq;
    struct cel *dir;
};
typedef struct cel no;

no* createNo(char data){
    no* newNode = (no*)malloc(sizeof(no));
    newNode -> data = data;
    newNode -> esq = NULL;
    newNode -> dir = NULL;
    return newNode;
}

int busca(no* raiz, char data){
    if(raiz == NULL)
    return 0;
    if(raiz->data == data){
        return 1;
    }else if(data < raiz -> data){
        return busca( raiz-> esq, data);
    }else{
        return busca(raiz->dir, data);
    }
}

no* insere(no* raiz, char data){
    if(raiz == NULL) return createNo(data);
    if(data < raiz ->data){
        raiz->esq = insere(raiz->esq, data);
    }else{
        raiz->dir = insere(raiz->dir, data);
    }
    return raiz;
}
    void infixa(no* raiz){
        if(raiz != NULL){
            infixa(raiz -> esq);
            printf("%c", raiz->data);
            infixa(raiz -> dir);
        }
    }
   
    void prefixa(no* raiz){
        if(raiz != NULL){
            printf("%c", raiz->data);
            prefixa(raiz->esq);
            prefixa(raiz-> dir);
        }
    }
   
    void posfixa(no* raiz){
        if(raiz != NULL){
            prefixa(raiz->esq);
            prefixa(raiz-> dir);
            printf("%c", raiz->data);
        }
    }
 
int main() {
    char comando[20], letra;
    no* raiz = NULL;
   
    while(scanf("%s", comando) != EOF){
        if(strcmp(comando, "I") == 0){
            scanf("%c", &letra);
            raiz = insere(raiz, letra);
        }else if(strcmp(comando, "INFIXA") == 0){
            infixa(raiz);
        }else if(strcmp(comando, "P") == 0){
            scanf("%c", &letra);
            if(busca(raiz, letra)){
                printf("%c existe\n", letra);
            }else{
                printf("%c nao existe\n", letra);
            }
        }
    }
   
 
    return 0;
}
