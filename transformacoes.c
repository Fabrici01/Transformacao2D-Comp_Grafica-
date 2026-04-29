void rotacao(float a11, float a12, float a21, float a22, float *x, float *y){
    float a31, a32;
    a31 = (-(*x)*a11) - (*y)*a21;
    a32 = (-(*x)*a12) - (*y)*a22;
    
    *x = (*x)*a11 + (*y)*a21 + a31 + (*x);
    *y = (*x)*a12 + (*y)*a22 + a32 + (*y);
}

void translacao(float transX, float transY, float *x, float *y){
    *x +=transX;
    *y +=transY; 
}

void escala(float multX, float multY, float *x, float *y){
    *x *= multX;
    *y *= multY;
}