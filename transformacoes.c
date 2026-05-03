#include <math.h>
#include <stdlib.h>
#include "main.h"
#include "transformacoes.h"

void transformacaoHomogenia(Poligono* p, Transformacao* t){

    //Matriz Escala
    Matriz3* escala = (Matriz3*) calloc(1, sizeof(Matriz3));
    escala->matriz[0][0] = t->escalaX;
    escala->matriz[1][1] = t->escalaY;
    escala->matriz[2][2] = 1;

    //Matriz Translação
    Matriz3* translacao = (Matriz3*) calloc(1, sizeof(Matriz3));
    translacao->matriz[0][0] = 1;
    translacao->matriz[1][1] = 1;
    translacao->matriz[2][2] = 1;
    translacao->matriz[2][0] = t->transladarX;
    translacao->matriz[2][1] = t->transladarY;

    //Matriz Rotação
    Matriz3* rotacao = (Matriz3*) calloc(1, sizeof(Matriz3));
    float radiano = t->angulo * (3.14 / 180.0);
    float cos = cosf(radiano);
    float sen = sinf(radiano);
    rotacao->matriz[0][0] = cos;
    rotacao->matriz[0][1] = sen;
    rotacao->matriz[1][0] = sen * -1.0;
    rotacao->matriz[1][1] = cos;
    rotacao->matriz[2][2] = 1;

    //Multiplicação das Matrizes
    Matriz3* temp1 = multiplicaMatriz(translacao,escala);
    Matriz3* matrizTransformacao = multiplicaMatriz(rotacao,temp1);

    float vetPonto[3];
    for(int x=0; x<p->numPontos; x++){
        /*vetPonto[0] = p->coordenadasFloat[x][0] * matrizTransformacao->matriz[0][0] + p->coordenadasFloat[x][1] * matrizTransformacao->matriz[0][1] + matrizTransformacao->matriz[0][2];
        vetPonto[1] = p->coordenadasFloat[x][0] * matrizTransformacao->matriz[1][0] + p->coordenadasFloat[x][1] * matrizTransformacao->matriz[1][1] + matrizTransformacao->matriz[1][2];
        */
        vetPonto[0] = p->coordenadasFloat[x][0] * matrizTransformacao->matriz[0][0]
            + p->coordenadasFloat[x][1] * matrizTransformacao->matriz[1][0]   // linha 1, coluna 0
            + matrizTransformacao->matriz[2][0];                              // linha 2, coluna 0
        vetPonto[1] = p->coordenadasFloat[x][0] * matrizTransformacao->matriz[0][1]
            + p->coordenadasFloat[x][1] * matrizTransformacao->matriz[1][1]   // linha 1, coluna 1
            + matrizTransformacao->matriz[2][1];                              // linha 2, coluna 1
        p->coordenadasFloat[x][0] = vetPonto[0];
        p->coordenadasFloat[x][1] = vetPonto[1];
    }

    free(escala);
    free(translacao);
    free(rotacao);
    free(temp1);
    free(matrizTransformacao);
}

void rotacao(float anguloRotacao, float *x, float *y){
    float coseno, seno, x2, y2;
    float radiano = anguloRotacao * (3.14 / 180.0);
    coseno = cosf(radiano);
    seno = sinf(radiano);
    y2 = *y*coseno + (*x * seno);
    x2 = *x * coseno - (*y * seno);
    *x = x2;
    *y = y2;
}

void translacao(float transX, float transY, float *x, float *y){
    *x +=transX;
    *y +=transY; 
}

void escala(float multX, float multY, float *x, float *y){
    *x *= multX;
    *y *= multY;
}

void desenhaPoligono(int** tela, int** mat, int numPontos){ 
    int dx;
    int dy;
    int D;

    for(int i = 0; i < numPontos; i++){
        int dir = 1;
        int i2 = (i+1) % numPontos;
        
        int x0 = mat[i][0];
        int x1 = mat[i2][0];
        int y0 = mat[i][1];
        int y1 = mat[i2][1];

        if(abs(x1 - x0) > abs(y1 - y0)){
            if(x0 > x1){
                int auxX = x0;
                int auxY = y0;
                
                x0 = x1;
                y0 = y1;

                x1 = auxX;
                y1 = auxY;
            }
            
            dx = x1 - x0;
            dy = y1 - y0;
            D = 2*dy - dx;
            
            if(dy < 0){
                dir = -1;
                dy = dy * -1;
            }
            
            int y = y0;

            for(int x = x0; x <= x1; x++){
                int wx = ((x % WIDTH)  + WIDTH)  % WIDTH;
                int wy = ((y % HEIGHT) + HEIGHT) % HEIGHT;
                tela[wy][wx] = 1;

                if(D > 0){
                    y = y + dir;
                    D += 2 * (dy - dx);
                }else{
                    D += 2 * dy;
                }
            }
        }else{
            if(y0 > y1){
                int auxX = x0;
                int auxY = y0;
                
                x0 = x1;
                y0 = y1;

                x1 = auxX;
                y1 = auxY;
            }
            
            dx = x1 - x0;
            dy = y1 - y0;
            D = 2*dx - dy;

            if(dx < 0){
                dir = -1;
                dx = dx * -1;
            }

            int x = x0;

            for(int y = y0; y <= y1; y++){
                int wx = ((x % WIDTH)  + WIDTH)  % WIDTH;
                int wy = ((y % HEIGHT) + HEIGHT) % HEIGHT;
                tela[wy][wx] = 1;

                if(D > 0){
                    x = x + dir;
                    D += 2 * (dx - dy);
                }else{
                    D += 2 * dx;
                }
            }
        }
    }
}