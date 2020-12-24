#include <stdio.h>
#include<string.h>
void contaSetes(char *numero, int contador, int *qtdSete);
int main(){
    char numero[15];
    int contador=0, qtdSete = 0;
    scanf("%[^\n]", numero);
    contaSetes(numero, contador, &qtdSete);
    printf("%d\n", qtdSete);
    return 0;
}
void contaSetes(char *numero, int contador, int *qtdSete){
    if(contador == strlen(numero)){
        return;
    }
    else if(numero[contador] == '7'){
        *qtdSete = *qtdSete + 1;
        contaSetes(numero, contador + 1, qtdSete);
    }
    else
        contaSetes(numero, contador + 1, qtdSete);
}

