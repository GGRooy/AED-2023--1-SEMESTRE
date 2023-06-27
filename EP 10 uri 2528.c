#include <stdio.h>
#include <stdbool.h>

#define MAX_CIDADES 1000
#define MAX_ROTAS 500000

typedef struct {
    int cidades[MAX_CIDADES][MAX_CIDADES];
    int numCidades;
    int numRotas;
    int curitiba;
    int riacho;
    int estadunido;
} Grafo;

void iGrafo(Grafo* grafo, int numCidades) {
    grafo->numCidades = numCidades;
    grafo->numRotas = 0;
    for (int i = 0; i < numCidades; i++) {
        for (int j = 0; j < numCidades; j++) {
            grafo->cidades[i][j] = 0;
        }
    }
}

void addRota(Grafo* grafo, int cidadeA, int cidadeB) {
    grafo->cidades[cidadeA][cidadeB] = 1;
    grafo->cidades[cidadeB][cidadeA] = 1;
    grafo->numRotas++;
}

int bfs(Grafo* grafo, int origem, int destino, int evitar) {
    bool visitado[MAX_CIDADES] = {false};
    int fila[MAX_CIDADES];
    int dist[MAX_CIDADES] = {0};
    int frente = 0;
    int tras = 0;

    fila[tras++] = origem;
    visitado[origem] = true;

    while (frente != tras) {
        int atual = fila[frente++];
        if (atual == destino) {
            return dist[atual];
        }

        for (int i = 0; i < grafo->numCidades; i++) {
            if (grafo->cidades[atual][i] == 1 && i != evitar && !visitado[i]) {
                visitado[i] = true;
                fila[tras++] = i;
                dist[i] = dist[atual] + 1;
            }
        }
    }

    return -1;
}

int main() {
    int n, m;

    while (scanf("%d %d", &n, &m) == 2) {
        Grafo grafo;
        iGrafo(&grafo, n);

        for (int i = 0; i < m; i++) {
            int cidadeA, cidadeB;
            scanf("%d %d", &cidadeA, &cidadeB);
            addRota(&grafo, cidadeA - 1, cidadeB - 1);
        }

        int curitiba, riacho, estadunido;
        scanf("%d %d %d", &curitiba, &riacho, &estadunido);

        int resultado = bfs(&grafo, curitiba - 1, riacho - 1, estadunido - 1);
        printf("%d\n", resultado);
    }

    return 0;
}
