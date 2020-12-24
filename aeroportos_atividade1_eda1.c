#include <stdio.h>
int main(){
    int aeroportos,voos,aux,origem[10000],destino[10000],frequencia[100],maior=-1,teste=0;
    scanf("%d%d", &aeroportos,&voos);
    while(aeroportos != 0 && voos != 0){
        teste++;
        for(aux=1; aux<=voos; aux++){
            scanf("%d%d", &origem[aux],&destino[aux]);
            frequencia[origem[aux]]++;
            frequencia[destino[aux]]++;
        }
        for(aux=1; aux<=aeroportos; aux++){
            if(frequencia[aux] > maior){
                maior = frequencia[aux];
            }
        }
        printf("Teste %d\n", teste);
        for(aux=1; aux<=aeroportos; aux++){
            if(frequencia[aux] == maior){
                printf("%d ", aux);
            }
        }
        printf("\n");
        printf("\n");
        for(aux=1; aux<=aeroportos; aux++){
            frequencia[aux] = 0;
        }
        maior = 0;
        scanf("%d%d", &aeroportos,&voos);
    }
    return 0;
}


