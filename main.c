#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include "transformacoes.h"

int main(){
    Poligono p;
    Poligono p2;
    Transformacao t;
    
    p.coordenadasFloat = carregarPontos("trianguloNDC.dcg", &p.numPontos);
    
    p2.coordenadasFloat = carregarPontos("estrelaNDC.dcg", &p2.numPontos);

    Poligono poligonos[2] = {p, p2};
    int numPoligonos = 2;

    int modo = 0;
    printf("Escolha o modo de Edicao:\n");
    printf("1 - Transformacoes Tradicionais\n");
    printf("2 - Transformacoes Homogeneas\n");
    printf("3 - Para brincar com o R2D2\n");
    printf("Escolha: ");
    scanf("%d", &modo);

    int **tela;
    tela = criaTela(WIDTH, HEIGHT);
    
    switch(modo){
        case 1:
            if(tela != NULL){
                while (1){
                    tela = criaTela(WIDTH, HEIGHT);
                    p.coordenadasInteiras = ndcToViewport(p.coordenadasFloat, p.numPontos);
                    p2.coordenadasInteiras = ndcToViewport(p2.coordenadasFloat, p2.numPontos);
                    
                    desenhaPoligono(tela, p.coordenadasInteiras, p.numPontos);
                    desenhaPoligono(tela, p2.coordenadasInteiras, p2.numPontos);

                    imprimeTela(tela);
                    
                    char key_code;
                    printf("Escolha as Operações:\n");
                    printf("- Pressione + para aumentar a escala\n");
                    printf("- Pressione - para diminuir a escala\n");
                    printf("- Pressione d para transladar para a direita\n");
                    printf("- Pressione a para transladar para a esquerda\n");
                    printf("- Pressione s para transladar para baixo\n");
                    printf("- Pressione w para transladar para cima\n");
                    printf("- Pressione e para rotacionar para direita\n");
                    printf("- Pressione q para rotacionar para esquerda\n");
                    printf("- Pressione p para trocar de polígono\n");
                    printf("Escolha: ");
                    key_code = getchar();

                    if(key_code == '+'){
                        for(int i = 0; i < p.numPontos; i++){
                            escala(1.5, 1.5, &p.coordenadasFloat[i][0], &p.coordenadasFloat[i][1]);
                        }
                    }

                    if(key_code == '-'){
                        for(int i = 0; i < p.numPontos; i++){
                            escala(0.5, 0.5, &p.coordenadasFloat[i][0], &p.coordenadasFloat[i][1]);
                        }
                    }

                    if(key_code == 'd'){
                        for(int i = 0; i < p.numPontos; i++){
                            translacao(0.2, 0.0, &p.coordenadasFloat[i][0], &p.coordenadasFloat[i][1]);
                        }
                    }

                    if(key_code == 'a'){
                        for(int i = 0; i < p.numPontos; i++){
                            translacao(-0.2, 0.0, &p.coordenadasFloat[i][0], &p.coordenadasFloat[i][1]);
                        }
                    }

                    if(key_code == 's'){
                        for(int i = 0; i < p.numPontos; i++){
                            translacao(0.0, -0.2, &p.coordenadasFloat[i][0], &p.coordenadasFloat[i][1]);
                        }
                    }

                    if(key_code == 'w'){
                        for(int i = 0; i < p.numPontos; i++){
                            translacao(0.0, 0.2, &p.coordenadasFloat[i][0], &p.coordenadasFloat[i][1]);
                        }
                    }

                    if(key_code == 'q'){
                        for(int i = 0; i < p.numPontos; i++){
                            rotacao(30, &p.coordenadasFloat[i][0], &p.coordenadasFloat[i][1]);
                        }
                    }

                    if(key_code == 'e'){
                        for(int i = 0; i < p.numPontos; i++){
                            rotacao(-30, &p.coordenadasFloat[i][0], &p.coordenadasFloat[i][1]);
                        }
                    }

                    if (key_code == 'p'){
                        Poligono aux;
                        aux = p;
                        p = p2;
                        p2 = aux;
                    }         
                    system("clear");
                    free(tela);
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
        case 3:
            //Projeto r2d2
            Poligono r2d2P1;
            Poligono r2d2P2;
            Poligono r2d2P3;
            Poligono r2d2P4;
            Poligono r2d2P5;
            Poligono r2d2P6;
            Poligono r2d2P7;
            Poligono r2d2P8;
            Poligono r2d2P9;
            Poligono r2d2P10;
            Poligono r2d2P11;
            Poligono r2d2P12;
            Poligono r2d2P13;
            Poligono r2d2P14;

            r2d2P1.coordenadasFloat = carregarPontos("R2D2/r2d2NDC.dcg", &r2d2P1.numPontos);
            r2d2P2.coordenadasFloat = carregarPontos("R2D2/r2d2PartesNDC.dcg", &r2d2P2.numPontos);
            r2d2P3.coordenadasFloat = carregarPontos("R2D2/r2d2Partes2NDC.dcg", &r2d2P3.numPontos);
            r2d2P4.coordenadasFloat = carregarPontos("R2D2/r2d2Partes3NDC.dcg", &r2d2P4.numPontos);
            r2d2P5.coordenadasFloat = carregarPontos("R2D2/r2d2Partes4NDC.dcg", &r2d2P5.numPontos);
            r2d2P6.coordenadasFloat = carregarPontos("R2D2/r2d2Partes5NDC.dcg", &r2d2P6.numPontos);
            r2d2P7.coordenadasFloat = carregarPontos("R2D2/r2d2Partes6NDC.dcg", &r2d2P7.numPontos);
            r2d2P8.coordenadasFloat = carregarPontos("R2D2/r2d2Partes7NDC.dcg", &r2d2P8.numPontos);
            r2d2P9.coordenadasFloat = carregarPontos("R2D2/r2d2Partes8NDC.dcg", &r2d2P9.numPontos);
            r2d2P10.coordenadasFloat = carregarPontos("R2D2/r2d2Partes9NDC.dcg", &r2d2P10.numPontos);
            r2d2P11.coordenadasFloat = carregarPontos("R2D2/r2d2Partes10NDC.dcg", &r2d2P11.numPontos);
            r2d2P12.coordenadasFloat = carregarPontos("R2D2/r2d2Partes11NDC.dcg", &r2d2P12.numPontos);
            r2d2P13.coordenadasFloat = carregarPontos("R2D2/r2d2Partes12NDC.dcg", &r2d2P13.numPontos);
            r2d2P14.coordenadasFloat = carregarPontos("R2D2/r2d2Partes13NDC.dcg", &r2d2P14.numPontos);
            
            int numPontos = 14;
            Poligono r2d2Poligonos[14] = {r2d2P1, r2d2P2, r2d2P3, r2d2P4, r2d2P5, r2d2P6, r2d2P7, r2d2P8, r2d2P9, r2d2P10, r2d2P11, r2d2P12, r2d2P13, r2d2P14};
            
            while (1){
                tela = criaTela(WIDTH, HEIGHT);                    
                r2d2P1.coordenadasInteiras = ndcToViewport(r2d2P1.coordenadasFloat, r2d2P1.numPontos);
                r2d2P2.coordenadasInteiras = ndcToViewport(r2d2P2.coordenadasFloat, r2d2P2.numPontos);
                r2d2P3.coordenadasInteiras = ndcToViewport(r2d2P3.coordenadasFloat, r2d2P3.numPontos);
                r2d2P4.coordenadasInteiras = ndcToViewport(r2d2P4.coordenadasFloat, r2d2P4.numPontos);
                r2d2P5.coordenadasInteiras = ndcToViewport(r2d2P5.coordenadasFloat, r2d2P5.numPontos);
                r2d2P6.coordenadasInteiras = ndcToViewport(r2d2P6.coordenadasFloat, r2d2P6.numPontos);
                r2d2P7.coordenadasInteiras = ndcToViewport(r2d2P7.coordenadasFloat, r2d2P7.numPontos);
                r2d2P8.coordenadasInteiras = ndcToViewport(r2d2P8.coordenadasFloat, r2d2P8.numPontos);
                r2d2P9.coordenadasInteiras = ndcToViewport(r2d2P9.coordenadasFloat, r2d2P9.numPontos);
                r2d2P10.coordenadasInteiras = ndcToViewport(r2d2P10.coordenadasFloat, r2d2P10.numPontos);
                r2d2P11.coordenadasInteiras = ndcToViewport(r2d2P11.coordenadasFloat, r2d2P11.numPontos);
                r2d2P12.coordenadasInteiras = ndcToViewport(r2d2P12.coordenadasFloat, r2d2P12.numPontos);
                r2d2P13.coordenadasInteiras = ndcToViewport(r2d2P13.coordenadasFloat, r2d2P13.numPontos);
                r2d2P14.coordenadasInteiras = ndcToViewport(r2d2P14.coordenadasFloat, r2d2P14.numPontos);

                desenhaPoligono(tela, r2d2P1.coordenadasInteiras, r2d2P1.numPontos);
                desenhaPoligono(tela, r2d2P2.coordenadasInteiras, r2d2P2.numPontos);
                desenhaPoligono(tela, r2d2P3.coordenadasInteiras, r2d2P3.numPontos);
                desenhaPoligono(tela, r2d2P4.coordenadasInteiras, r2d2P4.numPontos);
                desenhaPoligono(tela, r2d2P5.coordenadasInteiras, r2d2P5.numPontos);
                desenhaPoligono(tela, r2d2P6.coordenadasInteiras, r2d2P6.numPontos);
                desenhaPoligono(tela, r2d2P7.coordenadasInteiras, r2d2P7.numPontos);
                desenhaPoligono(tela, r2d2P8.coordenadasInteiras, r2d2P8.numPontos);
                desenhaPoligono(tela, r2d2P9.coordenadasInteiras, r2d2P9.numPontos);
                desenhaPoligono(tela, r2d2P10.coordenadasInteiras, r2d2P10.numPontos);
                desenhaPoligono(tela, r2d2P11.coordenadasInteiras, r2d2P11.numPontos);
                desenhaPoligono(tela, r2d2P12.coordenadasInteiras, r2d2P12.numPontos);
                desenhaPoligono(tela, r2d2P13.coordenadasInteiras, r2d2P13.numPontos);
                desenhaPoligono(tela, r2d2P14.coordenadasInteiras, r2d2P14.numPontos);

                imprimeTela(tela);
                
                char key_code;
                printf("Escolha as Operações:\n");
                printf("- Pressione + para aumentar a escala\n");
                printf("- Pressione - para diminuir a escala\n");
                printf("- Pressione d para transladar para a direita\n");
                printf("- Pressione a para transladar para a esquerda\n");
                printf("- Pressione s para transladar para baixo\n");
                printf("- Pressione w para transladar para cima\n");
                printf("- Pressione e para rotacionar para direita\n");
                printf("- Pressione q para rotacionar para esquerda\n");
                printf("Escolha: ");
                key_code = getchar();

                if(key_code == '+'){
                    for(int j = 0; j < 14; j++){
                        for(int i = 0; i < r2d2Poligonos[j].numPontos; i++){
                            escala(1.5, 1.5, &r2d2Poligonos[j].coordenadasFloat[i][0], &r2d2Poligonos[j].coordenadasFloat[i][1]);
                        }
                    }
                }

                if(key_code == '-'){
                    for(int j = 0; j < 14; j++){
                        for(int i = 0; i < r2d2Poligonos[j].numPontos; i++){
                            escala(0.5, 0.5, &r2d2Poligonos[j].coordenadasFloat[i][0], &r2d2Poligonos[j].coordenadasFloat[i][1]);
                        }
                    }
                }

                if(key_code == 'd'){
                    for(int j = 0; j < 14; j++){
                        for(int i = 0; i < r2d2Poligonos[j].numPontos; i++){
                            translacao(0.2, 0.0, &r2d2Poligonos[j].coordenadasFloat[i][0], &r2d2Poligonos[j].coordenadasFloat[i][1]);
                        }
                    }
                }

                if(key_code == 'a'){
                    for(int j = 0; j < 14; j++){
                        for(int i = 0; i < r2d2Poligonos[j].numPontos; i++){
                            translacao(-0.2, 0.0, &r2d2Poligonos[j].coordenadasFloat[i][0], &r2d2Poligonos[j].coordenadasFloat[i][1]);
                        }
                    }
                }

                if(key_code == 's'){
                    for(int j = 0; j < 14; j++){
                        for(int i = 0; i < r2d2Poligonos[j].numPontos; i++){
                            translacao(0.0, -0.2, &r2d2Poligonos[j].coordenadasFloat[i][0], &r2d2Poligonos[j].coordenadasFloat[i][1]);
                        }
                    }
                }

                if(key_code == 'w'){
                    for(int j = 0; j < 14; j++){
                        for(int i = 0; i < r2d2Poligonos[j].numPontos; i++){
                            translacao(0.0, 0.2, &r2d2Poligonos[j].coordenadasFloat[i][0], &r2d2Poligonos[j].coordenadasFloat[i][1]);
                        }
                    }
                }

                if(key_code == 'q'){
                    for(int j = 0; j < 14; j++){
                        for(int i = 0; i < r2d2Poligonos[j].numPontos; i++){
                            rotacao(30, &r2d2Poligonos[j].coordenadasFloat[i][0], &r2d2Poligonos[j].coordenadasFloat[i][1]);
                        }
                    }
                }

                if(key_code == 'e'){
                    for(int j = 0; j < 14; j++){
                        for(int i = 0; i < r2d2Poligonos[j].numPontos; i++){
                            rotacao(-30, &r2d2Poligonos[j].coordenadasFloat[i][0], &r2d2Poligonos[j].coordenadasFloat[i][1]);
                        }
                    }
                }       
                system("clear");
                free(tela);
            }
        default:
            printf("Valor inválido!\n");
        break;
    }

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
    if (f == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo %s\n", arq);
        exit(1); // Ou trate o erro para não quebrar
    }
    
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

