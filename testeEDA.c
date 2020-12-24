#include<stdio.h>
#include<stdlib.h>
typedef struct numeros{
    int dado, posAntiga;
}numeros;

int buscaBinaria(numeros *vetor, int qtdNum, int numero);
void ordena(numeros *vetor, int qtdNum);
int main(){
    int qtdNum=3, qtdBusca,dado;
    float numero = 3.5;
    if(numero > qtdNum){
        printf("aqui\n");
    }
    return 0;
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
void ordena(numeros *vetor, int qtdNum){
    int i,j;
    numeros temporaria;
    for(i=0; i<qtdNum-1; i++){
        for(j = i; j<qtdNum; j++){
            if(vetor[i].dado > vetor[j].dado){
                temporaria = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temporaria;
            }
        }
    }
}


