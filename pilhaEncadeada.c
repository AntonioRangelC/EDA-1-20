#include<stdio.h>
#include <stdlib.h>
typedef struct celula{
    int dado;
    struct celula *prox;

}celula;
celula *cria_pilha();
void empilha(celula *p, int x);
int desempilha(celula *p, int *y);
int main(){
    celula *p = cria_pilha();
    int auxiliar,y;
    empilha(p,1);
    empilha(p, 2);
    empilha(p, 3);


    celula *aux = p->prox;
    while(aux != NULL){
        printf("%d\n", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
    auxiliar = desempilha(p,&y);
    aux = p->prox;
    while(aux != NULL){
        printf("%d\n", aux->dado);
        aux = aux->prox;
    }
    return 0;
}

int desempilha(celula *p, int *y){
    celula *lixo = p->prox;
    if(lixo == NULL){
        return 0;
    }
    else{
        *y = lixo->dado;
        p->prox = lixo->prox;
        free(lixo);
        return 1;
    }

}
celula *cria_pilha(){
    celula *p = malloc(sizeof(celula));
    p->prox = NULL;
    return p;
}

void empilha(celula *p, int x){
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = p->prox;
    p->prox = novo;

}

