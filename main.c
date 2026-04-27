#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(){
    int numPontos;
    float** matPontos = carregarPontos("trianguloNDC.dcg", &numPontos);
    //ndcToViewport(-1.0, -1.0, 1.0, 1.0);
}

void ndcToViewport(float x1, float y1, float x2, float y2){
    int xa, xb, ya, yb;
    printf("Valores unificado: x1: %f, y1: %f, x2: %f, y2: %f\n", x1, y1, x2, y2);
    xa = WIDTH * ((x1 + 1)/2);
    xb = WIDTH * ((x2 + 1)/2);
    ya = HEIGHT * ((-y1 + 1)/2);
    yb = HEIGHT * ((-y2 + 1)/2);
    printf("Valores dispositivo: xa: %d, ya: %d, xb: %d, yb: %d\n", xa, ya, xb, yb);
}

float** carregarPontos(char* arq, int* numPontos){
    FILE *f = fopen(arq, "r");

    fscanf(f, "%d", numPontos);
    float** matPontos;

    matPontos = (float**)malloc(*numPontos * sizeof(float*));

    for(int i = 0; i < *numPontos; i++){
        matPontos[i] = (float*)malloc(2 * sizeof(float));
        fscanf(f, "%f", &matPontos[i][0]);
        fscanf(f, "%f", &matPontos[i][1]);
    }

    return matPontos;
}
