#define WIDTH 100
#define HEIGHT 50

typedef struct poligono{
    int numPontos;
    float** coordenadasFloat;
    int** coordenadasInteiras;
} Poligono;

int** ndcToViewport(float** matPontos, int numPontos);
float** carregarPontos(char* arq, int* numPontos);

void imprimeTela(int **tela);
int **criaTela(int larg, int alt);