#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int hParticao(int arr[], int anterior, int proximo) {
    int pivo = arr[anterior];
    int i = anterior - 1;
    int j = proximo + 1;

    while (1) {
        do {
            i++;
        } while (arr[i] < pivo);

        do {
            j--;
        } while (arr[j] > pivo);

        if (i >= j)
            return j;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void quickSort(int arr[], int anterior, int proximo) {
    if (anterior < proximo) {
        int indicePivo = hParticao(arr, anterior, proximo);

        quickSort(arr, anterior, indicePivo);
        quickSort(arr, indicePivo + 1, proximo);
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

    quickSort(arr, 0, n - 1);

    clock_t end_time = clock();

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos\n", total_time);

    return 0;
}
