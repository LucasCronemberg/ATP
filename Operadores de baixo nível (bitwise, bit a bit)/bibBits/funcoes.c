#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcoes.h"


Byte valorBit(Byte N, int posicao){
    Byte C,C1;

    C1 = pow(2,posicao);
    if((N & C1) == 0)   {C = 0;}
                    else{C = 1;}
    return C;
}

void printBits(Byte N){
    int i;
    printf("%3i ",N);
    for(i=7;i>=0;i--){
        if(valorBit(N,i) == 0)  {printf("0 "); }
                            else{printf("1 "); }
    }
    pulaLinha;
}

void ByteStr(Byte N, char *s){
    int i;
    for(i=7;i>=0;i--){
        if(valorBit(N,i) == 0){s[i] = '0'; }
                          else{s[i] = '1'; }
    }
    s[8] = '\0';
}

void StrByte(Byte *N, char *s){
    int i;
    Byte acum=0;
    for(i=7;i>=0;i--){
        if(s[i]=='0'){acum = acum + 0;}
                 else{acum = acum + pow(2,i);}
    }
    *N = acum;
}
