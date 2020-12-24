#include<stdio.h>
int main(){
    int vetor[1005],auxiliar=0,numero,i,j,temporaria;
    while(scanf("%d",&numero) != EOF){
        vetor[auxiliar] = numero;
        auxiliar++;
    }
    for(i=0; i<auxiliar-1; i++){
        for(j = i; j<auxiliar; j++){
            if(vetor[i] > vetor[j]){
                temporaria = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temporaria;
            }
        }
    }
    for(i=0; i < auxiliar; i++){
        if(i != auxiliar-1){
            printf("%d ", vetor[i]);
        }
        else{
            printf("%d\n",vetor[i]);
        }

    }
    return 0;
}

