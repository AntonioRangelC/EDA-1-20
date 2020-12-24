#include <stdio.h>
#include <stdlib.h>
typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void insereInicio(celula **p, int elemento);
celula *criaLista();
void imprimeLista(celula *p);

int main(){
    int escolha=0,elemento;
    celula *p = criaLista();
    while(escolha >= 0) {
        printf("Escolha uma opcao\n");
        printf("1. Inserir elemento no comeco da lista\n");
        printf("2. Imprimir elementos da lista\n");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                printf("Digite o novo elemento: ");
                scanf("%d", &elemento);
                insereInicio(&p, elemento);
                break;
            case 2:
                imprimeLista(p);
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
        printf("Quer continuar?\n");
        printf("0. Sim\n");
        printf(" -1. Nao\n");
        scanf("%d", &escolha);
    }
    return 0;
}

celula *criaLista(){
    celula *p = NULL;
    return p;
}

void insereInicio(celula **p, int elemento){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL){
        return;
    }
    else{
        novo->dado = elemento;
        novo->prox = *p;
        *p = novo;
    }
}

void imprimeLista(celula *p){
    celula *aux;
    aux = p;
    if(aux == NULL){
        return;
    }
    else{
        while(aux != NULL){
            printf("%d ", aux->dado);
            aux = aux->prox;
        }
        printf("\n");
    }
}