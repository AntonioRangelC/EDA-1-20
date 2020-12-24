#include<stdio.h>
#include<stdlib.h>
typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3);
void imprimeLista(celula *le);
void divide_listas(celula *l, celula *l1, celula *l2);
int main(){
    celula *l1 = malloc(sizeof(celula)); //alocando a primeira lista
    //celula *l = malloc(sizeof(celula));
    //celula *lista1 = malloc(sizeof(celula));
    //celula *lista2 = malloc(sizeof(celula));
    celula *a = malloc(sizeof(celula));
    celula *b = malloc(sizeof(celula));
    celula *c = malloc(sizeof(celula));
    /*l->prox = a;                        //dando valores a primeira lista
    a->dado = 1;
    a->prox = b;
    b->dado = 8;
    b->prox = c;
    c->dado = 5;
    c->prox = NULL;*/
    l1->prox = a;                        //dando valores a primeira lista
    a->dado = 100;
    a->prox = NULL;
    b->dado = 15;
    b->prox = c;
    c->dado = 15;
    c->prox = NULL;

    celula *l2 = malloc(sizeof(celula)); //alocando a segunda lista
    celula *d = malloc(sizeof(celula));
    celula *e = malloc(sizeof(celula));
    celula *f = malloc(sizeof(celula));
    l2->prox = d;                        //dando valores a segunda lista
    d->dado = 1;
    d->prox = e;
    e->dado = 4;
    e->prox = f;
    f->dado = 9;
    f->prox = NULL;

    celula *l3 = malloc(sizeof(celula)); //alocando a terceira lista
    l3->prox = NULL;
    mescla_listas(l1, l2, l3);
    imprimeLista(l3);
    return 0;
}
void divide_listas(celula *l, celula *l1, celula *l2){
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
            l2->prox = l->prox;
            l2 = l2->prox;
        }
        else if(l->prox->dado % 2 == 1){
            l1->prox = l->prox;
            l1 = l1->prox;
        }

    }
    free(l);
    imprimeLista(l1);
    imprimeLista(l2);
}

void mescla_listas(celula *l1, celula *l2, celula *l3){
    if(l1->prox == NULL && l2->prox == NULL){
        free(l1);
        free(l2);
        return;
    }
    else if(l1->prox == NULL){
        l3->prox = l2->prox;
        l2->prox = NULL;
        free(l2);
        return;
    }
    else if(l2->prox == NULL){
        l3->prox = l1->prox;
        l1->prox = NULL;
        free(l1);
        return;
    }
    else{
        celula *atualL1;
        celula *atualL2;

        atualL1 = l1->prox;
        atualL2 = l2->prox;

        while(1){

            if(atualL1 == NULL && atualL2 == NULL){
                return;
            }

            else if(atualL1 == NULL && atualL2 != NULL){
                l3->prox = atualL2;
                atualL2 = atualL2->prox;
            }

            else if(atualL2 == NULL && atualL1 != NULL){
                l3->prox = atualL1;
                atualL1 = atualL1->prox;
            }

            else if (atualL1->dado >= atualL2->dado){
                l3->prox = atualL2;
                atualL2 = atualL2->prox;
            }

            else if(atualL1->dado < atualL2->dado){
                l3->prox = atualL1;
                atualL1 = atualL1->prox;
            }
            l3 = l3->prox;
        }
    }
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
        if(aux == NULL){
            printf("->NULL ");
        }
        printf("]");
        printf("\n");
    }
}



