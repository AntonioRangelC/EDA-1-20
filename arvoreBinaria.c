#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

void preordem (no *raiz) {
    if (raiz != NULL) {
        printf ("%d ", raiz->dado);
        preordem (raiz->esq);
        preordem (raiz->dir);
    }
}

void emordem (no *raiz) {
    if (raiz != NULL) {
        emordem (raiz->esq);
        printf ("%d ", raiz->dado);
        emordem (raiz->dir);
    }
}

void posordem (no *raiz) {
    if (raiz != NULL) {
        posordem (raiz->esq);
        posordem (raiz->dir);
        printf ("%d ", raiz->dado);
    }
}

no *criar_arvore (int x, no *esq, no *dir) {
    no *raiz = malloc (sizeof (no));
    raiz->dado = x;
    raiz->esq = esq;
    raiz->dir = dir;
    return raiz;
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

int main () {
    int elem, novo;
    char lado;
    scanf ("%d", &novo);
    no *raiz = criar_arvore (novo, NULL, NULL);
    inserir(raiz, 3, 4, 'E');
    inserir(raiz, 1, 3, 'E');
    inserir(raiz, 10, 1, 'E');
    inserir(raiz, 8, 3, 'D');
    inserir(raiz, 5, 4 , 'D');
    inserir(raiz, 2, 5, 'E');
    inserir(raiz, 7, 5 , 'D');


    printf ("Pre-ordem: ");
    preordem (raiz);
    printf ("\n");
    printf (" Em-ordem: ");
    emordem (raiz);
    printf ("\n");
    printf ("Pos-ordem: ");
    posordem (raiz);
    printf ("\n");

    return 0;
}

