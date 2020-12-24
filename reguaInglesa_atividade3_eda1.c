#include<stdio.h>
void imprimeRegua(int contador);
void imprimeTraco(int contador, int aux);
int main(){
    int n,contador;
    scanf("%d", &n);
    contador = n;
    imprimeRegua(contador);
    return 0;
}
void imprimeRegua(int contador){
    if(contador ==  1){
        printf(".");
        imprimeTraco(contador,0);
        printf("\n");
        return;
    }
    else if(contador > 1){
        imprimeRegua(contador - 1);
        printf(".");
        imprimeTraco(contador, 0);
        printf("\n");
        imprimeRegua(contador - 1);
    }
}
void imprimeTraco(int contador, int aux){
    if(aux == contador){
        return;
    }
    else if(aux<contador){
        printf("-");
        imprimeTraco(contador,aux+1);

    }
}
