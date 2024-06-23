#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#define pulaLinha printf("\n");
#define separador printf("     - - - - - - - -\n");

typedef unsigned char Byte;
typedef char StringByte[9]; //8 caracteres + '\0'

Byte valorBit(Byte N, int posicao);
void printBits(Byte N);
void ByteStr(Byte N, char *s);
void StrByte(Byte *N, char *s);


#endif // FUNCOES_H_INCLUDED
