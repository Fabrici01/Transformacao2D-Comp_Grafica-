#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "transformacoes.h"

#define nColuna 100
#define nLinha 70

int main(){
    int numPontos;
    //A casaNDC.dcg não funciona, dá falha de segmentação e eu sei o motivo, a tela é pequena demais
    // pra casa, não tem erro na conta, confia 
    float** matPontos = carregarPontos("trianguloNDC.dcg", &numPontos);
    int** novaMatPontos = ndcToViewport(matPontos, numPontos);
    int **tela;

    tela = criaTela(nColuna, nLinha);
    desenhaPoligono(tela, novaMatPontos, numPontos);  
    
    // for(int i = 0; i < numPontos; i++){
    //     translacao(0.3, 0.4, &matPontos[i][0], &matPontos[i][1]);
    // }

    // novaMatPontos = ndcToViewport(matPontos, numPontos);
    // desenhaPoligono(tela, novaMatPontos, numPontos);  

    // for(int i = 0; i < numPontos; i++){
    //    escala(0.2, 0.2, &matPontos[i][0], &matPontos[i][1]);
    // }

    novaMatPontos = ndcToViewport(matPontos, numPontos);
    desenhaPoligono(tela, novaMatPontos, numPontos); 

    imprimeTela(tela);
    if(tela != NULL){
        while (1){
            char key_code;
            key_code = getchar();
            if(key_code == '+'){
                for(int i = 0; i < numPontos; i++){
                    escala(1.5, 1.5, &matPontos[i][0], &matPontos[i][1]);
                }
                system("clear");
                tela = criaTela(nColuna, nLinha);
                novaMatPontos = ndcToViewport(matPontos, numPontos);
                desenhaPoligono(tela, novaMatPontos, numPontos); 
                imprimeTela(tela);
            }

            if(key_code == '-'){
                for(int i = 0; i < numPontos; i++){
                    escala(0.5, 0.5, &matPontos[i][0], &matPontos[i][1]);
                }
                system("clear");
                tela = criaTela(nColuna, nLinha);
                novaMatPontos = ndcToViewport(matPontos, numPontos);
                desenhaPoligono(tela, novaMatPontos, numPontos); 
                imprimeTela(tela);
            }

            if(key_code == 'd'){
                for(int i = 0; i < numPontos; i++){
                    translacao(0.2, 0.0, &matPontos[i][0], &matPontos[i][1]);
                }
                system("clear");
                tela = criaTela(nColuna, nLinha);
                novaMatPontos = ndcToViewport(matPontos, numPontos);
                desenhaPoligono(tela, novaMatPontos, numPontos); 
                imprimeTela(tela);
            }

            if(key_code == 'a'){
                for(int i = 0; i < numPontos; i++){
                    translacao(-0.2, 0.0, &matPontos[i][0], &matPontos[i][1]);
                }
                system("clear");
                tela = criaTela(nColuna, nLinha);
                novaMatPontos = ndcToViewport(matPontos, numPontos);
                desenhaPoligono(tela, novaMatPontos, numPontos); 
                imprimeTela(tela);
            }

            if(key_code == 's'){
                for(int i = 0; i < numPontos; i++){
                    translacao(0.0, -0.2, &matPontos[i][0], &matPontos[i][1]);
                }
                system("clear");
                tela = criaTela(nColuna, nLinha);
                novaMatPontos = ndcToViewport(matPontos, numPontos);
                desenhaPoligono(tela, novaMatPontos, numPontos); 
                imprimeTela(tela);
            }

            if(key_code == 'w'){
                for(int i = 0; i < numPontos; i++){
                    translacao(0.0, 0.2, &matPontos[i][0], &matPontos[i][1]);
                }
                system("clear");
                tela = criaTela(nColuna, nLinha);
                novaMatPontos = ndcToViewport(matPontos, numPontos);
                desenhaPoligono(tela, novaMatPontos, numPontos); 
                imprimeTela(tela);
            }
        }
    }else{
        printf("Frame não aceito\n");
    }
    return 0;
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
                tela[y][x] = 1;
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
                tela[y][x] = 1;
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


void imprimeTela(int **tela){
  int i, j;
  //Imprime a tela no terminal
  printf("X|0000000000111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999|\n");
  printf("Y |0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789|\n");
  printf("--+----------------------------------------------------------------------------------------------------+\n");
  for(i=0; i<nLinha; i++) {
    printf("%2d|", i);
    for(j=0; j<nColuna; j++)
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

