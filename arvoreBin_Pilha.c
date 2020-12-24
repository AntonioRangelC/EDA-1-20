#include<stdio.h>
#include<stdlib.h>
typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;


no *criar_arvore (int x, no *esq, no *dir);
no *procurar (no *raiz, int x);
void inserir (no *raiz, int x, int y, char L);
void pre_ordem(no *raiz);
void em_ordem(no *raiz);
void pos_ordem(no *raiz);
int main(){
    //criacao da arvore
    no *raiz = criar_arvore (1, NULL, NULL);
    inserir(raiz, 2, 1 , 'D');
    inserir(raiz, 3, 2, 'D');
    inserir(raiz, 4, 3, 'D');
    //inserir(raiz, 8, 4, 'D');
    /*inserir(raiz, 4, 8, 'E');
    inserir(raiz, 1, 7, 'E');
    inserir(raiz, 9, 1, 'D');
    inserir(raiz, 6, 7, 'D');*/

    //no *raiz = malloc (sizeof (no));
    //pre_ordem(raiz);

    //printf("%d\n", &raiz);
    pos_ordem(raiz);
    return 0;
}


void pos_ordem(no *raiz){
    if(raiz == NULL){
        return;
    }
    struct no pilha[1000];
    int topo=0,esquerda=0;
    pilha[topo].dado = raiz->dado;         // empilhando a primeira raiz
    pilha[topo].esq = raiz->esq;
    pilha[topo].dir = raiz->dir;
    if(raiz->esq == NULL){
        raiz = raiz->dir;
    }
    else{
        esquerda = 1;
        raiz = raiz->esq;
    }
    while(1){
        if(raiz){
            topo++;
            pilha[topo].dado = raiz->dado;              //empilhando
            pilha[topo].esq = raiz->esq;
            pilha[topo].dir = raiz->dir;
            raiz = raiz->esq;
        }
        else{
            if(topo==0){                             // se a pilha esta vazia
                printf("%d ", pilha[topo].dado);
                printf("\n");
                return;
            }
            else{
                if(pilha[topo].dir == NULL){
                    printf("%d ", pilha[topo].dado);
                    topo--;                                   // desempilha
                    if(pilha[topo].dir != NULL && pilha[topo+1].dado == pilha[topo].dir->dado){    // o filho esta a direita do pai?
                        if(topo != 0){                                                             // esse if existe para que o topo nao seja negativo
                            printf("%d ", pilha[topo].dado);
                            topo--;                                                                // desempilha
                        }
                    }
                }

                if(topo > 0){                              // se a pilha tem elementos
                    raiz = pilha[topo].dir;                // raiz vai para o no da direita
                }
                else if(esquerda == 1 && topo == 0 && pilha[topo+1].dado == pilha[topo].esq->dado){            // esta na subarvore da esquerda?
                    raiz = pilha[topo].dir;
                }
                else {
                    raiz = NULL;
                }
            }

        }
    }
}
void em_ordem(no *raiz){
    struct no pilha[1000];
    int topo=0;
    pilha[topo].dado = raiz->dado;
    pilha[topo].esq = raiz->esq;
    pilha[topo].dir = raiz->dir;
    while(1) {
        while(raiz != NULL) {
            topo++;
            pilha[topo].dado = raiz->dado;
            pilha[topo].esq = raiz->esq;
            pilha[topo].dir = raiz->dir;
            raiz = raiz->esq;
        }
        if(topo == 0){
            printf("\n");
            return;
        }
        printf("%d ", pilha[topo].dado);
        topo--;
        raiz = pilha[topo+1].dir;
    }

}

void pre_ordem(no *raiz){
    if(raiz){
        struct no pilha[1000];
        int topo=0;
        pilha[topo].dado = raiz->dado;                     //empilhando a primeira raiz
        pilha[topo].esq = raiz->esq;
        pilha[topo].dir = raiz->dir;
        printf("%d ", pilha[topo].dado);
        topo++;
        while(topo != 0){
            if(pilha[topo-1].esq != NULL){
                printf("%d ", pilha[topo-1].esq->dado);
                pilha[topo].dado = pilha[topo-1].esq->dado;
                pilha[topo].esq = pilha[topo-1].esq->esq;
                pilha[topo].dir = pilha[topo-1].esq->dir;
                topo++;
            }
            else if(pilha[topo-1].dir != NULL){
                printf("%d ", pilha[topo-1].dir->dado);
                pilha[topo].dado = pilha[topo-1].dir->dado;
                pilha[topo].dir = pilha[topo-1].dir->dir;
                pilha[topo].esq = pilha[topo-1].dir->esq;
                topo++;
            }
            else if(pilha[topo-1].dir == NULL && pilha[topo-1].esq == NULL){
                if(topo == 1){         //caso de raiz unica
                    topo--;
                }
                else if(pilha[topo-2].esq != NULL){
                    pilha[topo-2].esq = NULL;         //desempilhando
                    topo--;
                }
                else{
                    pilha[topo-2].dir = NULL;          //desempilhando
                    topo--;
                }
            }
        }
        printf("\n");
    }
    else{

    }

}

no *procurar (no *raiz, int x) {
    if (raiz == NULL || raiz->dado == x) return raiz;
    no *esq = procurar (raiz->esq, x);
    if (esq != NULL) return esq;
    return procurar (raiz->dir, x);
}

void inserir (no *raiz, int x, int y, char L) {
    // inserir x do lado L de y
    no *procurado = procurar (raiz, y);
    if (L == 'E') {
        no *novo = criar_arvore (x, procurado->esq, NULL);
        procurado->esq = novo;
    }
    else {
        no *novo = criar_arvore (x, NULL, procurado->dir);
        procurado->dir = novo;
    }
}
no *criar_arvore (int x, no *esq, no *dir) {
    no *raiz = malloc (sizeof (no));
    raiz->dado = x;
    raiz->esq = esq;
    raiz->dir = dir;
    return raiz;
}


