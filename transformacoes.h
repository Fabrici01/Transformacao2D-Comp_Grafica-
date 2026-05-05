void rotacao(float anguloRotacao, float *x, float *y);
void translacao(float transX, float transY, float *x, float *y);
void escala(float multX, float multY, float *x, float *y);
void desenhaPoligono(int** tela, int** mat, int numPontos);

void transformacaoHomogenia(Poligono* p, Transformacao* t);