#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, *pa, **ppa;

    printf("Endereço das vars:\n&a: %i\n&pa: %i\n&ppa: %i\n",&a,&pa,&ppa);
    printf("Conteudo das vars:\na: %i\npa: %i\nppa: %i\n\n",a,pa,ppa);

    a = 10;
    pa = &a;
    ppa = &pa;
    printf("Conteudo das vars:\na: %i\npa: %i\nppa: %i\n\n",a,pa,ppa);

    printf("Conteudo das vars:\na: %i\n*pa: %i\n**ppa: %i\n\n",a,*pa,**ppa);
    printf("Conteudo das vars:\na: %i\npa: %i\n*ppa: %i\n\n",a,pa,*ppa);

    printf("Pressione enter/return para finalizar... ");
    getchar();
    return 0;
}
