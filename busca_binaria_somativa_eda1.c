#include<stdio.h>
#include<stdlib.h>
int buscaBinaria(int *vetor, int qtdNum, int numero);
int main(){
    int qtdNum, qtdBusca,aux,numero,dado;
    scanf("%d%d",&qtdNum,&qtdBusca);
    int *vetor = malloc(sizeof(int) * qtdNum);
    for(aux=0; aux<qtdNum; aux++){
        scanf("%d", &dado);
        vetor[aux] = dado;
    }
    for(aux=0; aux<qtdBusca; aux++){
        scanf("%d",&numero);
        printf("%d\n", buscaBinaria(vetor,qtdNum, numero));
    }
    return 0;
}
int buscaBinaria(int *vetor, int qtdNum, int numero){
    int esquerda=-1, direita=qtdNum,meio;
    while(esquerda < direita-1){  //se 'esquerda' estiver uma posicao atras de 'direita', sai do laco,
        meio = (esquerda + direita)/2;
        if(vetor[meio] < numero){   // se o elemento do meio for menor, preciso procurar no sub-vetor da direita
            esquerda = meio;
        }
        else{                      // se o elemento do meio for maior, preciso procurar no sub-vetor da esquerda
            direita = meio;
        }
    }
    return direita;
}
