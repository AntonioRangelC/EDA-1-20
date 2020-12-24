#include <stdio.h>
int main(){
    int qtdTrilhas,menor, auxiliar[200],aux,alturas[1000],qtdLeituras,aux2,indo=0,voltando=0;
    scanf("%d", &qtdTrilhas);
    for(aux=0; aux<qtdTrilhas; aux++){
        scanf("%d", &qtdLeituras);
        for(aux2=0; aux2<qtdLeituras; aux2++){
            scanf("%d", &alturas[aux2]);
        }
        for(aux2=0; aux2 < qtdLeituras-1; aux2++){
            if(alturas[aux2] < alturas[aux2 + 1]){
                indo = indo + (alturas[aux2 + 1] - alturas[aux2]);
            }
        }
        for(aux2=qtdLeituras-1; aux2>0; aux2--){
            if(alturas[aux2 - 1] > alturas[aux2]) {
                voltando = voltando + (alturas[aux2 - 1] - alturas[aux2]);
            }
        }
        if(indo < voltando){
            auxiliar[aux] = indo;
        }
        else if(voltando <= indo){
            auxiliar[aux] = voltando;
        }
        indo = 0;
        voltando = 0;
    }
    //achando o menor número
    for(aux=0;aux<qtdTrilhas;aux++){
        if(aux==0){
            menor = auxiliar[aux];
        }
        if(auxiliar[aux] < menor){
            menor = auxiliar[aux];
        }
    }
    //assim que ele achar o maior, ele imprime, pq o exercicio quer o que tenha o menor índice, no caso de empate
    for(aux=0;aux<qtdTrilhas;aux++){
        if(auxiliar[aux] == menor){
            printf("%d\n", aux+1);
            aux = qtdTrilhas;
        }
    }

    return 0;

}


