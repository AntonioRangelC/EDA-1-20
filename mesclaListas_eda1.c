
#include<stdlib.h>
typedef struct celula{
    int dado;
    struct celula *prox;
} celula;


void mescla_listas(celula *l1, celula *l2, celula *l3){
    l3->prox = NULL;
    if(l1->prox == NULL){
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
    else if(l1->prox == NULL && l2->prox == NULL){
        free(l1);
        free(l2);
        return;
    }
    else {
        celula *atual, *ultimo=NULL;
        int temp;
        atual = l1;
        while (atual->prox != NULL) {   //achando o ultimo termo da lista 1, para conectar com a lista 2
            atual = atual->prox;
        }
        atual->prox = l2->prox;         //dando free na cabeca da lista2
        free(l2);
        l3->prox = l1->prox;            //dando free na cabeca da lista1
        free(l1);
        atual = l3->prox;
        while (ultimo != l3->prox) {   //ordenando a lista
            while (atual->prox != ultimo) {
                if (atual->dado > atual->prox->dado) {
                    temp = atual->dado;
                    atual->dado = atual->prox->dado;
                    atual->prox->dado = temp;
                }
                atual = atual->prox;
            }
            ultimo = atual;
            atual = l3->prox;
        }
    }
}
/*
void mescla_listas(celula *l1, celula *l2, celula *l3){
    int flag = 0;
    l3->prox = NULL;
    if(l1->prox == NULL){
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
    else if(l1->prox == NULL && l2->prox == NULL){
        free(l1);
        free(l2);
        return;
    }
    else {
        celula *atualL1, *atualL2,*atualL3;
        atualL1 = l1->prox;
        atualL2 = l2->prox;
        atualL3 = l3;
        while(flag == 0){
            if(l2->prox == NULL && l1->prox == NULL){
                flag = 1;
            }
            else if(atualL1 == NULL){
                atualL3->prox = atualL2;
                l2->prox = NULL;
            }
            else if(atualL2 == NULL){
                atualL3->prox = atualL1;
                l1->prox = NULL;
            }
            else if(atualL1->dado < atualL2->dado){
                atualL3->prox = atualL1;
                l1->prox = atualL3->prox->prox;
                atualL3 = atualL3->prox;
                atualL3->prox = NULL;
                atualL1 = l1->prox;

            }
            else if(atualL2->dado < atualL1->dado){
                atualL3->prox = atualL2;
                l2->prox = atualL3->prox->prox;
                atualL3 = atualL3->prox;
                atualL3->prox = NULL;
                atualL2 = l2->prox;
            }
        }
        free(l1);
        free(l2);
    }
}
 */




