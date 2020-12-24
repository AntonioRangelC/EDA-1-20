#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int *v;
    int N, topo;
}pilha;

pilha *cria_pilha(int tamanho);
void empilha(pilha *p, int x);
int desempilha(pilha *p, int *y);

int main(){
    pilha *p;
    int tamanho, novoElemento, i,desempilhou,y;
    scanf("%d", &tamanho);
    p = cria_pilha(tamanho);
    empilha(p, 4);
    empilha(p, 8);
    empilha(p, 1);
    empilha(p,5);
    for(i = 0; i < p->topo; i++){
        printf("%d ", p->v[i]);
    }
    printf("\n");
    return 0;
}

pilha *cria_pilha(int tamanho){
    pilha *p = malloc(sizeof(pilha));
    p->N = tamanho;
    p->v = malloc(p->N * sizeof(int));
    p->topo = 0;
    return p;
}

void empilha(pilha *p, int x){
    if(p->topo == p->N){
        p->v = realloc(p->v, 2*sizeof(int));
        p->N = p->N * 2;
    }
    p->v[p->topo] = x;
    p->topo = p->topo + 1;
}

int desempilha(pilha *p, int *y){
    if(p->topo > 0){
        p->topo = p->topo - 1;
        *y = p->v[p->topo];
        return 1;
    }
    else{
        return 0;
    }
}