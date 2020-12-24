#include <stdio.h>
int main(){
    char frase[1000];
    int aux=0;
    scanf("%s", frase);
    while(frase[aux] != '\0'){
        aux++;
    }
    printf("%d\n", aux);
    return 0;
}

