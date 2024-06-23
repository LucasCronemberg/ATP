#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int *pa; //pa é ponteiro para o tipo int (variaveis inteiras)

    printf("Digite um valor para a variavel a: ");
    scanf("%i",&a);
    getchar(); //artificio para limpar o buffer de entrada
    printf("a = %i\n",a);

    pa = &a;
    printf("a = %i\n",*pa); //a e *pa são a mesma coisa

    printf("Digite outro valor para a variavel a: ");
    scanf("%i",pa);
    getchar();
    printf("a = %i\n",a);
    printf("a = %i\n",*pa);

    printf("Pressione enter/return para finalizar... ");
    getchar();
    return 0;
}
