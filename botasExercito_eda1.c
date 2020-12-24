#include<stdio.h>
int main(){
    int tamanho,numPares=0,direitos[61]={0},esquerdos[61]={0},aux;
    char pe;
    while(scanf("%d",&tamanho) != EOF){
        scanf(" %c",&pe);
        if(pe == 'E'){
            esquerdos[tamanho] = esquerdos[tamanho] + 1;
        }
        else if(pe == 'D'){
            direitos[tamanho] = direitos[tamanho] + 1;
        }
    }
    for(aux=30; aux<=60; aux++){

        if(esquerdos[aux] <= direitos[aux]){
            numPares = numPares + esquerdos[aux];
        }
        else if( esquerdos[aux] > direitos[aux]){
            numPares = numPares + direitos[aux];
        }
    }
    printf("%d\n", numPares);

    return 0;
}



