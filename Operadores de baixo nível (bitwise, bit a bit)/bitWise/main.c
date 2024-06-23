#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


int main()
{
    Byte A,B,C;
    StringByte s8, test;

    A=195;
    B=90;

    printf("A: %3i ",A);
    ByteStr(A,s8);
    printf("%s\n",s8);
    pulaLinha;

    C = A & B;
    printBits(A);
    printf("    &\n");
    printBits(B);
    separador;
    printBits(C);
    pulaLinha;

    C = A | B;
    printBits(A);
    printf("    |\n");
    printBits(B);
    separador;
    printBits(C);
    pulaLinha;

    C = A ^ B;
    printBits(A);
    printf("    ^\n");
    printBits(B);
    separador;
    printBits(C);
    pulaLinha;

    StrByte(&C, s8);
    printf("%s = %3i ",s8,C);

    printf("\nPressione enter/return para finalizar... ");
    getchar();
    return 0;
}
