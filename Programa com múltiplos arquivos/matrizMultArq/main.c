#include <stdio.h>
#include <stdlib.h>
#include "matrizMultArq.h"

int main()
{
    float **A, **B, **C;//A[2][3], B[3][2], C[2][2];
    int i, j, k;
    int la=2,ca=3, lb=3, cb=2;

    A = caloca(la,ca);
    B = caloca(lb,cb);
    C = caloca(la,cb);
    printf("Caloca foi!\n");

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
    printf("Iniciar matriz foi!\n");

    multiplica(A,B,C,ca,la,cb);
    printf("multiplica foi!\n");
    for(i=0;i<la;i++){ //Multiplicando a matriz A por B
       for(j=0;j<cb;j++){
                for(k=0;k<ca;k++){
                    printf("%4.1f * %4.1f = %4.1f\n",A[i][k], B[k][j], A[i][k] * B[k][j]);
                }
                printf("C[%i][%i] = %4.1f\n\n", i, j, C[i][j]);
        }
    }

    libera(la,A);
    libera(lb,B);
    libera(la,C);

    printf("Pressione enter/return para finalizar... ");
    getchar();
    return 0;
}
