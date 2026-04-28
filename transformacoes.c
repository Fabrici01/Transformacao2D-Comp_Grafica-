void rotacao(float a11, float a12, float a21, float a22, float x, float y){
    float matIda[3][3], matRota[3][3], matVolta[3][3];
    //montando matrizes
    matRota[0][0] = a11;
    matRota[0][1] = a12;
    matRota[1][0] = a21;
    matRota[1][1] = a22;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                matIda[i][j] = 1;
                matVolta[i][j] = 1;
            }
            else
            {
                matIda[i][j] = 0;
                matVolta[i][j] = 0;
            }
        }
    }
    matIda[2][0] = -x;
    matIda[2][1] = -y;
    matVolta[2][0] = x;
    matVolta[2][1] = y;
}

void translacao(float transX, float transY, float x, float y){}

void escala(float multX, float multY, float x, float y){}