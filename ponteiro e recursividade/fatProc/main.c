#include <stdio.h>
#include <stdlib.h>

void fatProc(int, int *);// Função criada antes do main para poder ser chamada nele e dps então ter suas linhas buscadas, que estão escritas dps do main

int main()
{
    int rf, num=5;

    fatProc(num, &rf);
    printf("Fatorial(%i) = %i\n", num, rf);

    printf("Pressione enter/return para finalizar... ");
    getchar();
    return 0;
}

void fatProc(int n, int *prf){ // fatorial de n armazena em prf
    int i, aux=1;

    for(i=2;i<=n;i++){ // 2*3*4*...*(n-10*n
        aux = aux * i;
    }
    *prf = aux;
}
