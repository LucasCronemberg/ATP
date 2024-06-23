#include <stdio.h>
#include <stdlib.h>

#define tam 5

int main()
{
    int *v, i;

    v = (int *) calloc(tam, sizeof(int)); //alocando um vetor de forma dinamica
    printf("Tamanho em bytes de um inteiro: %i\n\n",sizeof(int));

    for(i = (tam - 1);i>=0;i--){
        printf("Endereço de v[%1i] = %i\n", i, (v + i));
    }
    printf("\nEndereço de v = %i\n",v);

    for(i=0;i<tam;i++){
        *(v + i) = i * 5 + 1;   //v[i]
    }
    printf("Conteudo na posicao v: %i\n",*v); //v[0]
    for(i=0;i<tam;i++){
        printf("Conteudo de v[%1i] = %i\n", i, v[i]);
    }

    printf("Pressione enter/return para finalizar... ");
    getchar();
    return 0;
}
