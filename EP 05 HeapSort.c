#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int n, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && arr[esquerda] > arr[maior])
        maior = esquerda;

    if (direita < n && arr[direita] > arr[maior])
        maior = direita;

    if (maior != i) {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;

        heapify(arr, n, maior);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    int n = 20000;
    int arr[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("Array não ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t start_time = clock();

    heapSort(arr, n);

    clock_t end_time = clock();

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    double total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos\n", total_time);

    return 0;
}
