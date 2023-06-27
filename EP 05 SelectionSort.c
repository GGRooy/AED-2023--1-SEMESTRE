#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int N = 20000;
    int arr[N];
    int i;

    srand(time(NULL));

    printf("Algoritmo não ordenado: \n");
    for (i = 0; i < N; i++) {
        arr[i] = rand();
        printf("%d ", arr[i]);
    }

    clock_t start = clock();
    selectionSort(arr, N);
    clock_t end = clock();

    printf("\n\n Algoritmo ordenado: \n");
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execução: %f segundos\n", cpu_time_used);

    return 0;
}
