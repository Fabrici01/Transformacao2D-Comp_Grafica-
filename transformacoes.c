#include <math.h>
#include <stdlib.h>
#include "main.h"

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