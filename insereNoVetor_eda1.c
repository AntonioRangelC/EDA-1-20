#include <stdio.h>
//objetivo: fazer uma funcao que insere um numero em um vetor ordenado, e depois o vetor continue ordenado
void insere(int *vetor, int numero, int tamanho);
int main(){
    int vetor[10]={1,2,3,5,6,7,8}, tamanho = 10,aux;
    insere(vetor, 4, tamanho);
    for(aux = 0; aux<tamanho; aux++){
        printf("%d ", vetor[aux]);
    }
    printf("\n");
    return 0;
}
//parametros: vetor, numero a ser inserido, tamanho do vetor
void insere(int *vetor, int numero, int tamanho){
    int i,j;
    for(i=0; i < tamanho && vetor[i] <= numero; i++);
    for(j=tamanho; j > i; j--){
        vetor[j] = vetor[j-1];
    }
    vetor[i] = numero;
}

