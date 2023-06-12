#include <stdio.h>

int main() {
    int n, L;
    char linha[51];
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &L);
        int total = 0;
               
        while (getchar() != '\n');

        for (int j = 0; j < L; j++) {
            fgets(linha, sizeof(linha), stdin);

            for (int k = 0; linha[k] != '\n'; k++) {
                if (linha[k] != ' ') {
                    total += linha[k] - 'A' + j + k;
                }
            }
        }

        printf("%d\n", total);
    }

    return 0;
}
