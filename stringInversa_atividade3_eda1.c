#include <stdio.h>
#include<string.h>
void imprimeString(char *frase, int contador);
int main(){
    int contador;
    char frase[505];
    scanf("%[^\n]", frase);
    contador = strlen(frase) - 1;
    imprimeString(frase, contador);
    printf("\n");
    return 0;
}
void imprimeString(char *frase, int contador){
    if(contador == -1){
        return;
    }
    else{
        printf("%c", frase[contador]);
        imprimeString(frase, contador-1);
    }
}
