#include <stdio.h>
int main(){
    int idadeMonica, idadeFilho1,idadeFilho2,idadeFilho3;
    scanf("%d", &idadeMonica);
    scanf("%d", &idadeFilho1);
    scanf("%d", &idadeFilho2);
    idadeFilho3 = idadeMonica - (idadeFilho1 + idadeFilho2);
    if (idadeFilho3 > idadeFilho1 && idadeFilho3 > idadeFilho2){
        printf("%d\n",idadeFilho3);
    }
    else if (idadeFilho2 > idadeFilho1 && idadeFilho2 > idadeFilho3){
        printf("%d\n",idadeFilho2);
    }
    else {
        printf("%d\n", idadeFilho1);
    }

    return 0;
}



