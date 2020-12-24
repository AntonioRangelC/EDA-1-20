#include <stdio.h>
#include <stdlib.h>
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *criaLista();
void insere_inicio(celula *le, int x);
void insere_antes(celula *le, int x, int y);
void imprimeLista(celula *le);
int remove_depois(celula *p);
void remove_elemento(celula *le, int x);
void remove_todos_elementos(celula *le, int x);
void imprime(celula *le);
void imprime_rec(celula *le);
celula *busca (celula *le, int x);
celula *busca_rec(celula *le, int x);
int main(){
    int escolha=0,elemento,procura,elemRemovido;
    celula *le = criaLista();
    celula *pBusca;
    while(escolha >= 0) {
        printf("Escolha uma opcao\n");
        printf("1. Inserir elemento no comeco da lista\n");
        printf("2. Imprimir elementos da lista\n");
        printf("3. Buscar um elemento, e inserir antes dele\n");
        printf("4. Remover elemento do inicio\n");
        printf("5. Remover um elemento especifico\n");
        printf("6. Remover todos os elementos especificos\n");
        printf("7. Buscar um elemento na lista\n");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                printf("Digite o novo elemento: ");
                scanf("%d", &elemento);
                insere_inicio(le, elemento);
                break;
            case 2:
                imprimeLista(le);
                break;
            case 3:
                printf("Digite o elemento que procura, e o elemento a ser inserido\n");
                scanf("%d", &procura);
                scanf("%d", &elemento);
                if(le->prox != NULL){
                    insere_antes(le, elemento, procura);
                }
                else{
                    insere_inicio(le, elemento);
                }
                break;
            case 4:
                if(le->prox != NULL){
                    elemRemovido = remove_depois(le);
                    printf("Elemento %d foi removido\n", elemRemovido);
                }
                else{
                    printf("A lista esta vazia, nao ha elementos para remover\n");
                }
                break;
            case 5:
                if(le->prox != NULL){
                    printf("Digite o elemento a ser removido\n");
                    scanf("%d", &elemento);
                    remove_elemento(le, elemento);
                    printf("Elemento %d removido\n", elemento);
                }
                else{
                    printf("A lista esta vazia, nao ha elementos para remover\n");
                }
                break;
            case 6:
                if(le->prox != NULL){
                    printf("Digite o elemento a ser removido\n");
                    scanf("%d", &elemento);
                    remove_todos_elementos(le, elemento);
                    printf("Todos os elementos %d foram removidos\n", elemento);
                }
                else{
                    printf("A lista esta vazia, na ha elemento para remover\n");
                }
                break;
            case 7:
            if(le->prox != NULL){
                printf("Digite o elemento que deseja buscar\n");
                scanf("%d", &elemento);
                pBusca = busca_rec(le, elemento);
                if(pBusca != NULL){
                    printf("Elemento encontrado: %d\n", pBusca->dado);
                }
                else{
                    printf("Elemento nao encontrado\n");
                }

            }
            else{
                printf("A lista esta vazia, na ha elemento para buscar\n");
            }
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
    celula *le = malloc(sizeof(celula));
    le->prox = NULL;
    return le;
}

void insere_inicio(celula *le, int x){
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
}

void insere_antes(celula *le, int x, int y){
    celula *atual,*anterior,*novoElemento;
    anterior = le;
    atual = le->prox;
    while(atual->dado != y && atual->prox != NULL){  //fazendo uma busca para achar y
        anterior = atual;
        atual = atual->prox;
    }
    novoElemento = malloc(sizeof(celula));
    novoElemento->dado = x;
    if(atual->prox != NULL){
        novoElemento->prox = anterior->prox;
        anterior->prox = novoElemento;
    }
    else{
        novoElemento->prox = atual->prox;
        atual->prox = novoElemento;
    }


}

//remove o primeiro elemento da lista
int remove_depois(celula *p){
    celula *lixo = p->prox;
    int dado = lixo->dado;
    p->prox = lixo->prox;
    free(lixo);
    return dado;
}

//remove a primeira ocorrencia do elemento x
void remove_elemento(celula *le, int x){
    celula *atual,*anterior;
    atual = le;
    while(atual->prox != NULL && atual->dado != x){
        anterior = atual;
        atual = atual->prox;
    }
    if(atual->dado == x){
        anterior->prox = atual->prox;
        free(atual);
    }

}

//remove todas as ocorrencias de x
void remove_todos_elementos(celula *le, int x){
    celula *atual,*anterior,*lixo,*proximo;
    atual = le;
    while(atual->prox != NULL){
        anterior = atual;
        atual = atual->prox;
        if(atual->dado == x && atual->prox != NULL) {
            lixo = atual;
            atual = atual->prox;
            proximo = atual;
            free(lixo);
            atual = anterior;
            atual->prox = proximo;
        }
        else if (atual->dado == x && atual->prox == NULL){
            anterior->prox = atual->prox;
            free(atual);
            return;
        }

    }
}
void imprime(celula *le){
    celula *aux = le->prox;
    if(aux == NULL){
        printf("NULL\n");
        return;
    }
    else{
        while(aux != NULL){
            printf("%d->", aux->dado);
            aux = aux->prox;
        }
        printf("NULL");
        printf("\n");
    }
}

void imprime_rec(celula *le){
    celula *aux = le->prox;
    if(aux == NULL){
        printf("NULL\n");
        return;
    }
    else{
        printf("%d->",aux->dado);
        imprime_rec(aux);
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
        printf("]");
        printf("\n");
    }
}
//busca um elemento x, e retorna o ponteiro que aponta pra ele;
celula *busca (celula *le, int x){
    if(le->prox == NULL){
        return NULL;
    }
    else{
        celula *anterior, *atual;
        atual = le;
        while(atual->prox != NULL && atual->dado != x){
            anterior = atual;
            atual = atual->prox;
        }
        if(atual->dado == x){
            return anterior->prox;
        }
        else{
            return NULL;
        }
    }

}
celula *busca_rec(celula *le, int x){
    if(le->prox == NULL){
        return NULL;
    }
    else{
        celula *atual;
        atual = le;
        if(atual->prox->dado == x){
            return atual->prox;
        }
        else if(atual->prox->dado != x && atual->prox->prox == NULL){
            return NULL;
        }
        else{
            atual = busca_rec(atual->prox, x);
        }
        return atual;
    }
}