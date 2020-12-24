#include<stdio.h>
#include<string.h>
void transformaNum(char *numeros, int *numerosInt, int contador, int tamanhoString);
void somaDigitos(int *numerosInt, int contador, int *somaNum, int tamanhoString);
int main(){
    char numeros[14];
    int contador=0,numerosInt[13], somaNum=0,tamanhoString;
    scanf("%[^\n]", numeros);
    tamanhoString = strlen(numeros);
    transformaNum(numeros, numerosInt, contador, tamanhoString);
    contador = 0;
    somaDigitos(numerosInt, contador, &somaNum, tamanhoString);
    printf("%d\n", somaNum);
    return 0;
}
void transformaNum(char *numeros, int *numerosInt, int contador, int tamanhoString){
    if(contador == tamanhoString){
        return;
    }
    else{
        numerosInt[contador] = numeros[contador] - '0';
        transformaNum(numeros, numerosInt, contador+1, tamanhoString);
    }
}
void somaDigitos(int *numerosInt, int contador, int *somaNum, int tamanhoString){
    if(contador == tamanhoString){
        return;
    }
    else{
        *somaNum = *somaNum + numerosInt[contador];
        somaDigitos(numerosInt, contador + 1, somaNum, tamanhoString);
    }
}
