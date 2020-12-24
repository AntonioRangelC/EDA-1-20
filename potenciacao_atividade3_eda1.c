#include<stdio.h>
float potencia(float base, float expoente);
int main(){
    float base,expoente,resultado;
    scanf("%f%f", &base, &expoente);
    if(base == 0 && expoente == 0) {
        printf ("indefinido\n");
    }
    else{
        if (expoente < 0) {
            expoente = expoente * -1;
            resultado = potencia(base, expoente);
            resultado = 1 / resultado;
            printf("%.3f\n", resultado);
        } else if (expoente >= 0) {
            resultado = potencia(base, expoente);
            printf("%.1f\n", resultado);
        }
    }
    return 0;
}
float potencia(float base, float expoente){
    if(expoente == 0)
        return 1;
    else{
       return base * potencia(base, expoente -1);
    }
}

