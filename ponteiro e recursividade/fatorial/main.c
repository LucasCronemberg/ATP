#include <stdio.h>
#include <stdlib.h>

int fatNRecursivo(int n){
    int i;
    int fatnr = 1;

    for(i=n;i>1;i--){
        fatnr = fatnr * i;
    }
    return fatnr;
}

int fatRecursivo(int n){
    int fatnr = 1;

    if(n==0){
        fatnr = 1;
    }else {
        fatnr = n * fatRecursivo(n-1); //chamada recursiva
    }
    return fatnr;
}

int main()
{
    int n, i;
    int fr, fnr;

    printf("Digite um numero para o calculo do fatorial: ");
    scanf("%i",&n);
    getchar();
    if(n<0){
        printf("o numero deve ser inteiro positivo");
    }else{
        //fr = fatRecursivo(n);
        fnr = fatNRecursivo(n);
        printf("Não recursivo fat(%i) = %i\n",n,fnr);
        printf("    Recursivo fat(%i) = %i\n",n,fr);
    }

    printf("Pressione enter/return para finalizar... ");
    getchar();
    return 0;
}
