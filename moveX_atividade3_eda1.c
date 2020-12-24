#include <stdio.h>
#include<string.h>
void ida(int *qtdX, char *frase, int contador);
void imprimeX(int *qtdX, int contador);
int main(){
    int qtdX=0, contador=0;
    char frase[105];
    scanf("%[^\n]", frase);
    ida(&qtdX, frase, contador);
    contador = 0;
    imprimeX(&qtdX, contador);
    printf("\n");
    return 0;
}
void ida(int *qtdX, char *frase, int contador){
    if(strlen(frase)<1){
        return;
    }
    else if(contador == strlen(frase)){
        return;
    }
    else if(frase[contador] == '\n'){
        return;
    }
    else if(frase[contador] == 'x'){
        *qtdX = *qtdX + 1;
        ida(qtdX, frase, contador + 1);
    }
    else{
        printf("%c", frase[contador]);
        ida(qtdX, frase, contador + 1);
    }
}
void imprimeX(int *qtdX, int contador){
    if(contador == *qtdX) {
        return;
    }
    else if(contador < *qtdX){
        printf("x");
        imprimeX(qtdX, contador + 1);
    }

}


