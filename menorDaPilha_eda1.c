#include <stdio.h>
#include <stdlib.h>
/* Explicação do código: existe uma pilha com os valores da entrada, e existe a pilha com valores dos menores.
 * Quando eu insiro um numero que é menor que o mínimo, eu empilho esse número nas duas pilhas. Quando esse número
 * não é menor que o mínimo, eu empilho esse numero na pilha principal, e empilho o valor do mínimo na pilha dos menores.
 * Isso acontece pq quando eu desempilho o menor da pilha principal, a pilha dos menores vai ter o valor do numero que era menor antes.
 */
typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula *cria_pilha();
void empilha(celula *p, int x);
void empilha_menor(celula *menores, int x);
int desempilha(celula *p);
int acessa_topo(celula *p);
int main(){

    celula *p = cria_pilha();
    celula *menores = cria_pilha();
    char instrucao[10];
    int qtdInstrucoes,aux,numero,desempilhou;
    scanf("%d", &qtdInstrucoes);

    for(aux = 0; aux < qtdInstrucoes; aux++){
        scanf("%s", instrucao);
        if(instrucao[1] == 'U'){
            scanf("%d", &numero);
            empilha(p, numero);
            empilha_menor(menores,numero);
        }
        else if(instrucao[1] == 'O'){
            desempilhou = desempilha(p);
            desempilha(menores);
            if(desempilhou == 0){
                printf("EMPTY\n");
            }
        }

        else if(instrucao[0] == 'M'){
            if(menores->prox==NULL){
                printf("EMPTY\n");
            }else{
                int topo = acessa_topo(menores);
                printf("%d\n",topo);
            }
        }
    }
    return 0;
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

void empilha_menor(celula *menores, int x){
    if (menores->prox==NULL){
        empilha(menores,x);
    }else{
        int menor = acessa_topo(menores);
        if(x<menor){
            empilha(menores,x);
        }else{
            empilha(menores,menor);
        }
    }
}

int desempilha(celula *p){
    celula *lixo = p->prox;
    if(lixo == NULL){
        return 0;
    }
    else{
        p->prox = lixo->prox;
        free(lixo);
        return 1;
    }

}

int acessa_topo(celula *p){
    celula *aux = p->prox;
    return aux->dado;
}