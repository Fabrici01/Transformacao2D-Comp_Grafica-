#include <stdio.h>
#include <stdlib.h>
//#include <termios.h>
#include <unistd.h>
#include "main.h"
#include "transformacoes.h"

/*void enableRawMode(){
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void disableRawMode(){
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

char getch(){
    char c;
    enableRawMode();
    c = getchar();
    disableRawMode();
    return c;
}*/



int main(){
    Poligono p;
    //Poligono p2;
    p.coordenadasFloat = carregarPontos("trianguloNDC.dcg", &p.numPontos);
    p.coordenadasInteiras = ndcToViewport(p.coordenadasFloat, p.numPontos);
    
    /*p2.coordenadasFloat = carregarPontos("estrelaNDC.dcg", &p2.numPontos);
    p2.coordenadasInteiras = ndcToViewport(p2.coordenadasFloat, p2.numPontos);*/
    Transformacao t;

    int modo;
    printf("Escolha o modo de Edicao:\n");
    printf("1- Transformacoes tradicionais\n");
    printf("2- Transformacoes Homogeneas\n");
    printf("Escolha: ");
    scanf("%i", &modo);

    int **tela;
    tela = criaTela(WIDTH, HEIGHT);
    desenhaPoligono(tela, p.coordenadasInteiras, p.numPontos); 
    imprimeTela(tela);
    switch(modo){
        case 1:
            if(tela != NULL){
            while (1){
                char key_code;
                key_code = getchar();
                if(key_code == '+'){
                    for(int i = 0; i < p.numPontos; i++){
                        escala(1.5, 1.5, &p.coordenadasFloat[i][0], &p.coordenadasFloat[i][1]);
                    }
                    system("clear");
                    tela = criaTela(WIDTH, HEIGHT);
                    p.coordenadasInteiras = ndcToViewport(p.coordenadasFloat, p.numPontos);
                    desenhaPoligono(tela, p.coordenadasInteiras, p.numPontos); 
                    imprimeTela(tela);
                }

                if(key_code == '-'){
                    for(int i = 0; i < p.numPontos; i++){
                        escala(0.5, 0.5, &p.coordenadasFloat[i][0], &p.coordenadasFloat[i][1]);
                    }
                    system("clear");
                    tela = criaTela(WIDTH, HEIGHT);
                    p.coordenadasInteiras = ndcToViewport(p.coordenadasFloat, p.numPontos);
                    desenhaPoligono(tela, p.coordenadasInteiras, p.numPontos); 
                    imprimeTela(tela);
                }

                if(key_code == 'd'){
                    for(int i = 0; i < p.numPontos; i++){
                        translacao(0.2, 0.0, &p.coordenadasFloat[i][0], &p.coordenadasFloat[i][1]);
                    }
                    system("clear");
                    tela = criaTela(WIDTH, HEIGHT);
                    p.coordenadasInteiras = ndcToViewport(p.coordenadasFloat, p.numPontos);
                    desenhaPoligono(tela, p.coordenadasInteiras, p.numPontos); 
                    imprimeTela(tela);
                }

                if(key_code == 'a'){
                    for(int i = 0; i < p.numPontos; i++){
                        translacao(-0.2, 0.0, &p.coordenadasFloat[i][0], &p.coordenadasFloat[i][1]);
                    }
                    system("clear");
                    tela = criaTela(WIDTH, HEIGHT);
                    p.coordenadasInteiras = ndcToViewport(p.coordenadasFloat, p.numPontos);
                    desenhaPoligono(tela, p.coordenadasInteiras, p.numPontos); 
                    imprimeTela(tela);
                }

                if(key_code == 's'){
                    for(int i = 0; i < p.numPontos; i++){
                        translacao(0.0, -0.2, &p.coordenadasFloat[i][0], &p.coordenadasFloat[i][1]);
                    }
                    system("clear");
                    tela = criaTela(WIDTH, HEIGHT);
                    p.coordenadasInteiras = ndcToViewport(p.coordenadasFloat, p.numPontos);
                    desenhaPoligono(tela, p.coordenadasInteiras, p.numPontos); 
                    imprimeTela(tela);
                }

                if(key_code == 'w'){
                    for(int i = 0; i < p.numPontos; i++){
                        translacao(0.0, 0.2, &p.coordenadasFloat[i][0], &p.coordenadasFloat[i][1]);
                    }
                    system("clear");
                    tela = criaTela(WIDTH, HEIGHT);
                    p.coordenadasInteiras = ndcToViewport(p.coordenadasFloat, p.numPontos);
                    desenhaPoligono(tela, p.coordenadasInteiras, p.numPontos); 
                    imprimeTela(tela);
                }

                if(key_code == 'e'){
                    for(int i = 0; i < p.numPontos; i++){
                        rotacao(30, &p.coordenadasFloat[i][0], &p.coordenadasFloat[i][1]);
                    }
                    system("clear");
                    tela = criaTela(WIDTH, HEIGHT);
                    p.coordenadasInteiras = ndcToViewport(p.coordenadasFloat, p.numPontos);
                    desenhaPoligono(tela, p.coordenadasInteiras, p.numPontos); 
                    imprimeTela(tela);
                }

                if(key_code == 'q'){
                    for(int i = 0; i < p.numPontos; i++){
                        rotacao(-30, &p.coordenadasFloat[i][0], &p.coordenadasFloat[i][1]);
                    }
                    system("clear");
                    tela = criaTela(WIDTH, HEIGHT);
                    p.coordenadasInteiras = ndcToViewport(p.coordenadasFloat, p.numPontos);
                    desenhaPoligono(tela, p.coordenadasInteiras, p.numPontos); 
                    imprimeTela(tela);
                }
                system("clear");
                //desenhaPoligono(tela, p2.coordenadasInteiras, p2.numPontos);  
                imprimeTela(tela);
            }
        }else{
            printf("Frame não aceito\n");
        }
        break;
        case 2:
            if(tela != NULL){
                while (1){
                    printf("--- Configuracao ---\n");
                    printf("Escala X: ");
                    scanf("%f", &t.escalaX);
                    printf("\nEscala Y: ");
                    scanf("%f", &t.escalaY);
                    printf("\nTransladar X: ");
                    scanf("%f", &t.transladarX);
                    printf("\nTransladar Y: ");
                    scanf("%f", &t.transladarY);
                    printf("\nRotacionar: ");
                    scanf("%f", &t.angulo);

                    printf("teste1\n");
                    transformacaoHomogenia(&p, &t);
                    printf("teste2\n");
                    tela = criaTela(WIDTH, HEIGHT);
                    p.coordenadasInteiras = ndcToViewport(p.coordenadasFloat, p.numPontos);
                    desenhaPoligono(tela, p.coordenadasInteiras, p.numPontos); 
                    imprimeTela(tela);
                }
            }

        break;
        default:
        printf("Valor inválido!\n");
        break;
    }


     
    //desenhaPoligono(tela, p2.coordenadasInteiras, p2.numPontos);  

    
    
    return 0;
}

Matriz3* multiplicaMatriz(Matriz3* a, Matriz3* b){
    Matriz3* matrizFinal = (Matriz3*) calloc(1,sizeof(Matriz3));
    float temp;

    for(int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            temp = 0;

            for(int z=0; z<3; z++){
                temp += a->matriz[x][z] * b->matriz[z][y];
            }
            
            matrizFinal->matriz[x][y] = temp;
        }
    }

    return matrizFinal;
}

int** ndcToViewport(float** matPontos, int numPontos){
    int xa, xb, ya, yb;
    int** novaMatPontos;
    novaMatPontos = (int**)malloc(numPontos * sizeof(int*));
    for(int i = 0; i < numPontos; i++){
        novaMatPontos[i] = (int*)malloc(2 * sizeof(int));
        novaMatPontos[i][0] = (int)(WIDTH * ((matPontos[i][0] + 1)/2));
        novaMatPontos[i][1] = (int)(HEIGHT * ((-matPontos[i][1] + 1)/2));
    }
    return novaMatPontos;
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

void imprimeTela(int **tela){
  int i, j;
  //Imprime a tela no terminal
  printf("X |0000000000111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999|\n");
  printf("Y |0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789|\n");
  printf("--+----------------------------------------------------------------------------------------------------+\n");
  for(i=0; i<HEIGHT; i++) {
    printf("%2d|", i);
    for(j=0; j<WIDTH; j++)
      if(tela[i][j]) printf("*");
      else printf(" ");
    printf("|\n");
  }  printf("--+----------------------------------------------------------------------------------------------------+\n");
}

int **criaTela(int larg, int alt){

  int **tela, i, j;
  //Alocando a tela totalmente limpa
  tela = (int **) malloc(alt * sizeof(int *));
  for(i=0; i<alt; i++) {
    tela[i] = (int *) malloc(larg * sizeof(int));
    for(j=0; j<larg; j++) tela[i][j] = 0;
  }
  return tela;
}

