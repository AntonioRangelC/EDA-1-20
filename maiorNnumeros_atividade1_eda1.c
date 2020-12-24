#include <stdio.h>
int main(){
    int numero,aux=0,maior = -1947483648;
    while(scanf("%d",&numero) != EOF){
        if(numero > maior){
            maior = numero;
        }
        aux++;
    }

    if(aux>=1){
        printf("%d\n", maior);
    }
    return 0;
}


