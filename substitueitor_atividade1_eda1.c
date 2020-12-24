#include <stdio.h>
int main(){
    char frase[10005],palavraSai[45],palavraEntra[45],temporaria[45],auxiliar[10005],verificadora[45];
    int auxFrase=0,ehDiferente=0,aux2=0,i=0,aux,tamanhoFrase=0,tmPalavraEntra=0,tmPalavraSai=0,tmVerificadora=0;
    scanf("%[^\n]", frase);
    scanf("%s", palavraSai);
    scanf("%s", palavraEntra);
    //calculando o tamanho da frase
    while(frase[tamanhoFrase] != '\0'){
        tamanhoFrase++;
    }
    //calculando o tamanho da palavra que entra
    while(palavraEntra[tmPalavraEntra] != '\0'){
        tmPalavraEntra++;
    }
    //calculando o tamanho da palavra que sai
    while(palavraSai[tmPalavraSai] != '\0'){
        tmPalavraSai++;
    }
    for(auxFrase=0; auxFrase<tamanhoFrase; auxFrase++){
        if(!((frase[auxFrase] >=65 && frase[auxFrase] <= 90)  || (frase[auxFrase] >= 97 && frase[auxFrase] <= 122))){
            printf("%c", frase[auxFrase]);
        }
        else{
            //esse while é usado para comparar a palavra que sai, com a palavra da frase
            while(frase[auxFrase] >=65 && frase[auxFrase] <= 90  && auxFrase < tamanhoFrase|| frase[auxFrase] >= 97 && frase[auxFrase] <= 122 && auxFrase < tamanhoFrase ){
                verificadora[aux2] = frase[auxFrase];
                aux2++;
                auxFrase++;
            }
            auxFrase--;
            verificadora[aux2] = '\0';
            //verificando o tamanho da string verificadora
            while(verificadora[tmVerificadora] != '\0'){
                tmVerificadora++;
            }
            //verificando se as palavras são iguais
            for(aux = 0; aux<tmVerificadora; aux++){
                if(verificadora[aux] != palavraSai[aux] || (verificadora[aux] < 65 && verificadora[aux] > 90)  || (verificadora[aux] < 97 && verificadora[aux] > 122)){
                    ehDiferente = 1;
                    aux = tmVerificadora;
                }
            }
            if(ehDiferente == 0 && tmVerificadora == tmPalavraSai){
                //printf("verificadora: %s\n", verificadora);
                printf("%s",palavraEntra);
            }
            else {
                printf("%s", verificadora);
            }

        }
        ehDiferente = 0;
        aux2 = 0;
        tmVerificadora = 0;
    }
    printf("\n");
    return 0;
}





