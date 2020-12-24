#include<stdio.h>
#include<stdlib.h>
typedef struct celula{
    int dado;
    struct celula *prox;
}celula;
celula *cria_fila();
celula *enfileira_pSimples(celula *fila, int x);
int desenfileira(celula *fila, int *y);
void enfileira(celula **f, int x);
int main(){
    celula *fila = cria_fila();
    celula *aux;
    int auxiliar,y;
    auxiliar = desenfileira(fila, &y);
    aux = fila->prox;
    while(aux != fila){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");


    return 0;
}
celula *cria_fila(){
    celula *novo = malloc(sizeof(celula));
    novo->prox =novo;
    return novo;
}

void enfileira(celula **f, int x){
    struct celula *novo = malloc(sizeof(celula));
    novo->prox = (*f)->prox;
    (*f)->prox =novo;
    (*f)->dado = x;
    *f= novo;
}

int desenfileira(celula *fila, int *y){
    celula *lixo = fila->prox;
    if(lixo->prox == lixo){
        return 0;
    }
    else{
        *y = lixo->dado;
        fila->prox = lixo->prox;
        free(lixo);
        return 1;
    }

}


celula *enfileira_pSimples(celula *fila, int x){
    struct celula *novo = malloc(sizeof(celula));
    novo->prox = fila->prox;
    fila->prox = novo;
    fila->dado = x;
    return novo;
}


