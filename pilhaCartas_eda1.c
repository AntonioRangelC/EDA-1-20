#include <stdio.h>
#include <stdlib.h>
typedef struct celula{
    int dado;
    struct celula *prox;

}celula;

celula *cria_fila();

void enfileira(celula **f, int x);
void desenfileira(celula *fila);

int main(){
    celula *principal = cria_fila();
    celula *descartados = cria_fila();
    celula *auxiliar;
    int ultimo,aux;
    scanf("%d", &ultimo);
    for(aux=1; aux<=ultimo; aux++){
        enfileira(&principal, aux);
    }
    while(principal->prox->prox != principal){
            enfileira(&descartados, principal->prox->dado);
            desenfileira(principal);
            enfileira(&principal, principal->prox->dado);
            desenfileira(principal);
    }
    auxiliar = descartados->prox;
    printf("Cartas descartadas: ");
    while(auxiliar != descartados){
        if(auxiliar->prox == descartados){
            printf("%d", auxiliar->dado);
        }
        else{
            printf("%d, ", auxiliar->dado);
        }
        auxiliar = auxiliar->prox;
    }
    printf("\n");
    printf("Carta restante: %d\n", principal->prox->dado);
    return 0;
}

celula *cria_fila(){
    celula *novo = malloc(sizeof(celula));
    novo->prox =novo;
    return novo;
}

// vai ser usada para tirar o elemento do começo e colocar no final
void enfileira(celula **f, int x){
    struct celula *novo = malloc(sizeof(celula));
    novo->prox = (*f)->prox;
    (*f)->prox =novo;
    (*f)->dado = x;
    *f= novo;
}
// vai ser usada para tirar o primeiro elemento
void desenfileira(celula *fila){
    celula *lixo = fila->prox;
        fila->prox = lixo->prox;
        free(lixo);
}

