#include<stdio.h>
#include<stdlib.h>
typedef struct numeros{
    int dado, posAntiga;
}numeros;

int cmpfunc (const void * a, const void * b);
int buscaBinaria(numeros *vetor, int qtdNum, int numero);
int main(){
    int qtdNum, qtdBusca,aux,numero,dado;
    scanf("%d%d",&qtdNum,&qtdBusca);
    numeros *vetor = malloc(sizeof(numeros) * qtdNum);
    for(aux=0; aux<qtdNum; aux++){
        scanf("%d", &dado);
        vetor[aux].dado = dado;
        vetor[aux].posAntiga = aux;
    }
    qsort(vetor, qtdNum, sizeof(numeros), cmpfunc);
    /*for(aux=0; aux<qtdNum; aux++){
        printf("%d ", vetor[aux].dado);
    }
    printf("\n");*/
    for(aux=0; aux<qtdBusca; aux++){
        scanf("%d",&numero);
        printf("%d\n", buscaBinaria(vetor,qtdNum, numero));
    }
    return 0;
}
int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}
int buscaBinaria(numeros *vetor, int qtdNum, int numero){
    int esquerda=-1, direita=qtdNum,meio;
    while(esquerda < direita-1){  //se 'esquerda' estiver uma posicao atras de 'direita', sai do laco,
        meio = (esquerda + direita)/2;
        if(vetor[meio].dado < numero){   // se o elemento do meio for menor, preciso procurar no sub-vetor da direita
            esquerda = meio;
        }
        else{                      // se o elemento do meio for maior, preciso procurar no sub-vetor da esquerda
            direita = meio;
        }
    }
    if(vetor[direita].dado == numero){
        return vetor[direita].posAntiga;
    }
    else{
        return -1;
    }
}



