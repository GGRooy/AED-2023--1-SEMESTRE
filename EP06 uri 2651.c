#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char S[100001];
    fgets(S, sizeof(S), stdin);
    S[strcspn(S, "\n")] = '\0';  
  
   
    for (int i = 0; S[i]; i++) {
        S[i] = tolower(S[i]);
    }
    
    bool ficouBolado = strstr(S, "zelda") != NULL;
    
    if (ficouBolado) {
        printf("Link Bolado\n");
    } else {
        printf("Link Tranquilo\n");
    }
    
    return 0;
}
