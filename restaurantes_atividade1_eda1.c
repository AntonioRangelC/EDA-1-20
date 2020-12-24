#include <stdio.h>
int main(){
    int quantidade, notas[200],codigos[200],aux,codigo,nota,dia = 1,maior = -1,auxiliar[200]={0},menor=10000000,aux2=0;
    while(scanf("%d", &quantidade) != EOF){
        for(aux=0; aux<quantidade; aux++){
            scanf("%d%d",&codigo,&nota);
            notas[aux] = nota;
            codigos[aux] = codigo;
        }
        printf("Dia %d\n",dia);
        for(aux=0; aux<quantidade; aux++){
            if(notas[aux] > maior){
                maior = notas[aux];
            }
        }
        for(aux = 0; aux<quantidade; aux++){
            if(notas[aux] == maior){
                auxiliar[aux2] = codigos[aux];
                aux2++;
            }
        }
        for(aux = 0; aux<quantidade; aux++){
            if(auxiliar[aux] < menor && auxiliar[aux] != 0){
                menor = auxiliar[aux];
            }
        }
        printf("%d\n",menor);
        printf("\n");
        for(aux = 0; aux<quantidade; aux++){
            auxiliar[aux] = 0;
        }
        for(aux = 0; aux<quantidade; aux++){
            notas[aux] = 0;
        }
        for(aux = 0; aux<quantidade; aux++){
            codigos[aux] = 0;
        }
        menor = 10000000;
        maior = -1;
        dia++;
        aux2=0;
    }

    return 0;
}


