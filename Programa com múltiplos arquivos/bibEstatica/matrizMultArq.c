#include "matrizMultArq.h"


float** caloca(int l, int c){
    float **A;
    A = (float **) calloc(l, sizeof(float *));
    for(int i=0;i<l;i++){
        A[i] = (float *) calloc(c, sizeof(float));
    }
    return (A);
}

void libera(int l, float **A ){
    for(int i=0;i<l;i++){
        free(A[i]);
    }
    free(A);
}

void multiplica(float **A,float **B,float **C,int ca,int la,int cb){
    int i,j,k;
    float somaAcumulada;

    for(i=0;i<la;i++){
       for(j=0;j<cb;j++){
            somaAcumulada = 0 ;
            for(k=0;k<ca;k++){
                somaAcumulada = somaAcumulada + (A[i][k]*B[k][j]);
            }
            C[i][j] = somaAcumulada;
        }
    }
}

void soma(float **A,float **B,float **C,int l, int c){
    int i,j,k;

    for(i=0;i<l;i++){
       for(j=0;j<c;j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtracao(float **A,float **B,float **C,int l, int c){
    int i,j,k;
    float sub;

    for(i=0;i<l;i++){
        sub = 0;
       for(j=0;j<c;j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}
