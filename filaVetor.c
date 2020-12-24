#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int *v;
    int N,inicio,fim;

}fila;

fila *criaFila(int tamanho);
int enfileira(fila *f, int x);
int desenfileira(fila *f, int *y);
int main(){
    fila *f;
    int aux,auxiliar,i,y;
    f = criaFila(5);
    i=enfileira(f, 1);
    i=enfileira(f, 2);
    i=enfileira(f, 3);
    i=enfileira(f, 4);
    i = enfileira(f,5);
    printf("%d\n", i);
    for(aux = 0; aux < 5; aux ++){
        printf("%d ", f->v[aux]);
    }
    printf("\n");
    printf("Inicio: %d\n", f->inicio);
    printf("Fim: %d\n", f->fim);
    return 0;
}

int desenfileira(fila *f, int *y){
    if(f->fim == f->inicio){
        return 0;
    }
    else{
        *y = f->v[f->inicio];
        f->inicio = (f->inicio + 1) % f->N;
        return 1;
    }
}

int enfileira(fila *f, int x){
    //verificando se a fila está cheia
    if(f->fim == f->inicio -1 || (f->fim == f->N-1  && f->inicio == 0)){
        return 0;
    }
    else{
        if(f->fim < f->N){
            f->v[f->fim] = x;
            f->fim = (f->fim + 1) % f->N;
            return 1;
        }
    }

}
fila *criaFila(int tamanho){
    fila *f = malloc(sizeof(fila));
    f->N = tamanho;
    f->v = malloc(f->N * sizeof(int));
    f->inicio = 0;
    f->fim = 0;
    return f;
}
