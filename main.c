#include <stdio.h>
#include "main.h"

int main(){

    ndcToViewport(-1.0, -1.0, 1.0, 1.0);

    printf("Hello World");
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
