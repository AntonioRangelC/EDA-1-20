#include<stdio.h>
#include<string.h>
int main(){
    char expressao[500];
    int aux,tamanho,chaveAberta=0,chaveFechada=0,colchAberto=0, colchFechado=0, parenAberto=0,parenFechado=0;
    scanf("%s", expressao);
    tamanho = strlen(expressao);
    for(aux=0; aux<tamanho; aux++){
        if(expressao[aux] == '{'){
            chaveAberta++;
        }
        else if(expressao[aux] == '}'){
            chaveFechada++;
        }
        else if(expressao[aux] == '['){
            colchAberto++;
        }
        else if(expressao[aux] == ']'){
            colchFechado++;
        }
        else if(expressao[aux] == '('){
            parenAberto++;
        }
        else if(expressao[aux] == ')'){
            parenFechado++;
        }
    }
    if(chaveAberta == chaveFechada && colchFechado == colchAberto && parenFechado == parenAberto){
        printf("sim\n");
    }
    else{
        printf("nao\n");
    }
    return 0;
}

