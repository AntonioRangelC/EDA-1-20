#include<stdio.h>
#include<stdlib.h>
int buscaBinaria(long long int *raios2, int qtdNum, long long int numero);
int main(){
    int qtdCirculos, qtdTiros,aux;
    long long int modulo,pontuacao=0,raio,x,y;
    scanf("%d%d", &qtdCirculos, &qtdTiros);
    long long int *raios2 = malloc(sizeof(long long int) * qtdCirculos);
    for(aux=0; aux<qtdCirculos; aux++){
        scanf("%lld", &raio);
        raios2[aux] = raio * raio;          //estou armazenando os raios ao quadrado para o caso de numeros negativos
    }
    for(aux=0; aux<qtdTiros; aux++){
        scanf("%lld%lld", &x, &y);
        modulo = (x*x) + (y*y);
        pontuacao = pontuacao + (qtdCirculos - buscaBinaria(raios2, qtdCirculos, modulo));
    }
    printf("%lld\n", pontuacao);
    return 0;
}
int buscaBinaria(long long int *raios2, int qtdNum, long long int numero){
    int esquerda=-1, direita=qtdNum,meio;
    while(esquerda < direita-1){  //se 'esquerda' estiver uma posicao atras de 'direita', sai do laco,
        meio = (esquerda + direita)/2;
        if(raios2[meio] < numero){   // se o elemento do meio for menor, preciso procurar no sub-vetor da direita
            esquerda = meio;
        }
        else{                      // se o elemento do meio for maior, preciso procurar no sub-vetor da esquerda
            direita = meio;
        }
    }
    return direita;
}

