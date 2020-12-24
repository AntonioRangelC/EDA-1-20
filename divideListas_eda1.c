#include<stdlib.h>
//#include<stdio.h>
typedef struct celula{
    int dado;
    struct celula *prox;
} celula;
/*void divide_lista(celula *l, celula *l1, celula *l2);
void imprimeLista(celula *le);
int main(){
    celula *l = malloc(sizeof(celula));
    celula *l1 = malloc(sizeof(celula));
    celula *l2 = malloc(sizeof(celula));
    celula *a = malloc(sizeof(celula));
    celula *b = malloc(sizeof(celula));
    celula *c = malloc(sizeof(celula));
    celula *d = malloc(sizeof(celula));
    celula *e = malloc(sizeof(celula));
    l->prox = a;                        //dando valores a primeira lista
    a->dado = 3;
    a->prox = b;
    b->dado = 0;
    b->prox = c;
    c->dado = 0;
    c->prox = d;
    d->dado = 0;
    d->prox = e;
    e->dado = 3;
    e->prox = NULL;
    l1->prox = NULL;
    l2->prox = NULL;
    divide_lista(l, l1, l2);

    printf("lista1: \n");
    imprimeLista(l1);
    printf("lista2: \n");
    imprimeLista(l2);

    return 0;
}*/
void divide_lista(celula *l, celula *l1, celula *l2){
    if(l->prox == NULL){
        return;
    }
    celula *atual;
    atual = l->prox;
    while(atual != NULL){
        if(atual->dado % 2 == 0){
            l2->prox = atual;
            l2 = l2->prox;
        }
        else if(atual->dado % 2 != 0){
            l1->prox = atual;
            l1 = l1->prox;
        }
        atual = atual->prox;
    }
    l1->prox =NULL;
    l2->prox = NULL;
}
/*void divide_lista(celula *l, celula *l1, celula *l2){
    if(l->prox == NULL){
        l1->prox = NULL;
        l2->prox = NULL;
        return;
    }
    celula *atualL1,*atualL2,*aux;
    l1->prox =NULL;
    l2->prox = NULL;
    while(l->prox != NULL){
        if(l->prox->dado % 2 == 0){
            if(l->prox == NULL){
                l2->prox = l->prox;
                l->prox = l->prox->prox;
                l2->prox->prox = NULL;
            }
            else{
                atualL2 = l2;
                while(atualL2->prox != NULL){
                    atualL2 = atualL2->prox;
                }
                atualL2->prox = l->prox;
                l->prox = l->prox->prox;
                atualL2->prox->prox = NULL;
            }
        }
        else if(l->prox->dado % 2 == 1){
            if(l->prox == NULL){
                l1->prox = l->prox;
                l->prox = l->prox->prox;
                l1->prox->prox = NULL;
            }
            else{
                atualL1 = l1;
                while(atualL1->prox != NULL){
                    atualL1 = atualL1->prox;
                }
                atualL1->prox = l->prox;
                l->prox = l->prox->prox;
                atualL1->prox->prox = NULL;
            }


        }

    }
    free(l);
    imprimeLista(l1);
    imprimeLista(l2);
}
void imprimeLista(celula *le){
    celula *aux = le->prox;
    if(aux == NULL){
        return;
    }
    else{
        printf("[ ");
        while(aux != NULL){
            printf("%d ", aux->dado);
            aux = aux->prox;
        }
        printf("]");
        printf("\n");
    }
}*/
