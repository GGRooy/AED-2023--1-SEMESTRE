#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int l;
        scanf("%d%*c", &l);
        int total = 0;

        for (int j = 0; j < l; j++) {
            char linha[51];
            scanf("%[^\n]%*c", linha);

            for (int k = 0; linha[k] != '\0'; k++) {
                total += linha[k] - 'A' + j + k;
            }
        }

        printf("%d\n", total);
    }

    return 0;
}
