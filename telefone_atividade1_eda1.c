#include <stdio.h>
int main(){
    char numero[15];
    int aux;
    scanf("%s", numero);
    for (aux=0; aux< 15; aux++){
        if(numero[aux] == 'A' || numero[aux] == 'B' || numero[aux] == 'C'){
            numero[aux]= '2';
        }
        else if(numero[aux] == 'D' || numero[aux] == 'E' || numero[aux] == 'F'){
            numero[aux]= '3';
        }
        else if(numero[aux] == 'G' || numero[aux] == 'H' || numero[aux] == 'I'){
            numero[aux]= '4';
        }
        else if(numero[aux] == 'J' || numero[aux] == 'K' || numero[aux] == 'L'){
            numero[aux]= '5';
        }
        else if(numero[aux] == 'M' || numero[aux] == 'N' || numero[aux] == 'O'){
            numero[aux]= '6';
        }
        else if(numero[aux] == 'P' || numero[aux] == 'Q' || numero[aux] == 'R'|| numero[aux] == 'S'){
            numero[aux]= '7';
        }
        else if(numero[aux] == 'T' || numero[aux] == 'U' || numero[aux] == 'V'){
            numero[aux]= '8';
        }
        else if(numero[aux] == 'W' || numero[aux] == 'X' || numero[aux] == 'Y' || numero[aux] == 'Z'){
            numero[aux]= '9';
        }

    }
    printf("%s\n", numero);
    return 0;
}


