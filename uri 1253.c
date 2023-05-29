#include <stdio.h>
#include <string.h>

int main() {

  int N, i;
  scanf("%d", &N);
  for (i=0;i<N;i++){
    
    char input[51];
    int right_shift;
    scanf("%s", input);
    scanf("%d", &right_shift);
    int j, length = strlen(input);
    for (j=0; j<length; j++){
      char c= input[j]- right_shift;
      if(c<65){
        c=c+26;
      }
      printf("%c", c);
      
    }
    printf("\n");
  }
  
  
}
