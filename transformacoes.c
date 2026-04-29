#include <math.h>

void rotacao(float anguloRotacao, float *x, float *y){
    float cos, sen;

}

void translacao(float transX, float transY, float *x, float *y){
    *x +=transX;
    *y +=transY; 
}

void escala(float multX, float multY, float *x, float *y){
    *x *= multX;
    *y *= multY;
}