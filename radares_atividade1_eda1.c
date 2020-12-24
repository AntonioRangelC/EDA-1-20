
double calculaVM(int tA, int tB, double distancia){
    double velocidadeMedia;
    velocidadeMedia = (distancia/(tB - tA)) * 3600;
    return velocidadeMedia;
}
int levouMulta(int tA, int tB, double distancia, double velocidadeMax){
    double velocidadeMedia;
    velocidadeMedia = calculaVM(tA, tB, distancia);
    if(velocidadeMedia > velocidadeMax){
        return 1;
    }
    else if(velocidadeMedia <= velocidadeMax){
        return 0;
    }
}




