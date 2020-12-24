#include <stdio.h>
#include <string.h>
void somaNoves(int *soma, int contador,char *numero);
int main(){
    char numero[1005];
    int soma=0,contador=1,aux;
    scanf("%s", numero);
    for(aux=0; aux<strlen(numero); aux++){
        soma = soma + numero[aux] - '0';
    }
    while(numero[0] != '0' && numero[0] != '\n'){
        somaNoves(&soma, contador, numero);
        scanf("%s", numero);
        contador = 1;
        for(aux=0; aux<strlen(numero); aux++) {
            soma = soma + numero[aux] - '0';
        }
    }
    return 0;
}

void somaNoves(int *soma, int contador, char *numero){
    int auxiliar;
    auxiliar = *soma;
    if(*soma == 9){
        *soma = 0;
        printf("%s is a multiple of 9 and has 9-degree %d\n", numero, contador);
        return;
    }
    else if(*soma>9){
        *soma = 0;
        while(auxiliar != 0){
            *soma = *soma + (auxiliar % 10);
            auxiliar = auxiliar / 10;
        }
        somaNoves(soma, contador+1, numero);
    }
    else{
        *soma = 0;
        printf("%s is not a multiple of 9.\n", numero);
    }
}


