#include <stdio.h>
#include <stdlib.h>

int fibNRecursivo(int n){
    int i=1, k, f=0;
    int fibnrc=1;
    for(k=1;k<=n;k++){
        f = i+f;
        i = f-i;
        //printf("k = %i ------ f = %i ------ i = %i\n",k,f,i); //forma de ver os valores que assumem as variaveis
    }
        fibnrc = f;
    return fibnrc;
}

int fibRecursivo(int n){
    int fibrc = 1;

    if(n<2){
        fibrc = n;
    }else {
        fibrc = fibRecursivo(n-1) + fibRecursivo(n-2); //chamada recursiva
    }
    return fibrc;
}

int main()
{
    int n, fr=1, fnr=1;

    printf("Digite um numero para o calculo do fibonacci: ");
    scanf("%i",&n);
    getchar();
    if(n<0){
        printf("o numero deve ser inteiro positivo");
    }else{
        //fibNRecursivo(n); //forma de ver os valores que as variaveis assumem
        fr = fibRecursivo(n);
        fnr = fibNRecursivo(n);
        printf("Nao recursivo fib(%i) = %i\n",n,fnr);
        printf("    Recursivo fib(%i) = %i\n",n,fr);
    }

    printf("Pressione enter/return para finalizar... ");
    getchar();
    return 0;
}
