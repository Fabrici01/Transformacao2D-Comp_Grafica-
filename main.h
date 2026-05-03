#define WIDTH 100
#define HEIGHT 50

typedef struct poligono{
    int numPontos;
    float** coordenadasFloat;
    int** coordenadasInteiras;
} Poligono;

typedef struct transformacao{
    //Escala
    float escalaX;
    float escalaY;
    
    //Translação
    float transladarX;
    float transladarY;

    //Rotação
    float angulo;
} Transformacao;

typedef struct matriz3{ //Estrutura de matriz 3x3
    float matriz[3][3];
} Matriz3;

int** ndcToViewport(float** matPontos, int numPontos);
float** carregarPontos(char* arq, int* numPontos);

void imprimeTela(int **tela);
int **criaTela(int larg, int alt);

Matriz3* multiplicaMatriz(Matriz3* a, Matriz3* b);