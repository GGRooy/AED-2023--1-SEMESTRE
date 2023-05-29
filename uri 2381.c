#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
} aluno;

int cmp(const void *a, const void *b) {
    const aluno *pa = (const aluno *) a;
    const aluno *pb = (const aluno *) b;
    return strcmp(pa->nome, pb->nome);
}

int main() {
    int quantidadeAlunos, alunoPremiado;
    scanf("%d %d", &quantidadeAlunos, &alunoPremiado);
    aluno *alunos = (aluno *) malloc(sizeof(aluno) * quantidadeAlunos);
    for (int i = 0; i < quantidadeAlunos; i++) {
        alunos[i].nome = (char *) malloc(sizeof(char) * 10000);
        scanf("%s", alunos[i].nome);
    }
    qsort(alunos, quantidadeAlunos, sizeof(aluno), cmp);
    printf("%s\n", alunos[alunoPremiado - 1].nome);
    for (int i = 0; i < quantidadeAlunos; i++) {
        free(alunos[i].nome);
    }
    free(alunos);
    return 0;
}
