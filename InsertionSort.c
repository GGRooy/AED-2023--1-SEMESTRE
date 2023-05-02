#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j-1]) {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

int main() {
    int n = 20000;
    int arr[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("Algoritmo não ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t start_time = clock();

    insertion_sort(arr, n);

    clock_t end_time = clock();

    printf("Algoritmo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    double total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos\n", total_time);

    return 0;
}
