#define WIDTH 50
#define HEIGHT 100

int** ndcToViewport(float** matPontos, int numPontos);
float** carregarPontos(char* arq, int* numPontos);

void imprimeTela(int **tela);
int **criaTela(int larg, int alt);
void desenhaPoligono(int** tela, int** mat, int numPontos);