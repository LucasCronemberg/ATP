#include <stdio.h>
#include <stdlib.h>
//função que faz a alocação dinamica da matriz(ponteiros)
float** caloca(int l, int c){
    float **A;
    A = (float **) calloc(l, sizeof(float *));
    for(int i=0;i<l;i++){
        A[i] = (float *) calloc(c, sizeof(float));
    }
    return A;
}
void libera(int l, float **A ){
    for(int i=0;i<l;i++){
        free(A[i]);
    }
    free(A);
}
int main()
{
    float **A, **B, **C;//A[2][3], B[3][2], C[2][2];
    float somaAcumulada;
    int i, j, k;
    int la=2,ca=3, lb=3, cb=2;

    //alocação Dinamica dos Ponteiros de Ponteiros
  /*A = (float **) calloc(la, sizeof(float *));
    for(i=0;i<la;i++){
        A[i] = (float *) calloc(ca, sizeof(float));
    }

    B = (float **) calloc(lb, sizeof(float *));
    for(i=0;i<lb;i++){
        B[i] = (float *) calloc(cb, sizeof(float));
    }

    C = (float **) calloc(la, sizeof(float *));
    for(i=0;i<la;i++){
        C[i] = (float *) calloc(cb, sizeof(float));
    }
  */
    A = caloca(la,ca);
    B = caloca(lb,cb);
    C = caloca(la,cb);

    for(i=0;i<la;i++){ //Inicializando a matriz A
       for(j=0;j<ca;j++){
                A[i][j] = i+j+1;
        }
    }

    for(i=0;i<lb;i++){//Inicializando a matriz B
       for(j=0;j<cb;j++){
                B[i][j] = i+j+2;
        }
    }

    for(i=0;i<la;i++){ //Multiplicando a matriz A por B
       for(j=0;j<cb;j++){
                somaAcumulada = 0;
                for(k=0;k<ca;k++){
                    somaAcumulada = somaAcumulada + A[i][k] * B[k][j];
                    printf("%4.1f * %4.1f = %4.1f\n",A[i][k], B[k][j], A[i][k] * B[k][j]);
                }
                C[i][j] = somaAcumulada;
                printf("C[%i][%i] = %4.1f\n\n", i, j, C[i][j]);
        }
    }


    //Liberando da memória caso não esteja sendo utilizado, possivel devivdo a alocação dinamica feita
  /*for(i=0;i<la;i++){
        free(A[i]);
    }
    free(A);
    for(i=0;i<lb;i++){
        free(B[i]);
    }
    free(B);
    for(i=0;i<la;i++){
        free(C[i]);
    }
    free(C);
  */
    libera(la,A);
    libera(lb,B);
    libera(la,C);

    printf("Pressione enter/return para finalizar... ");
    getchar();
    return 0;
}
