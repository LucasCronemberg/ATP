// Contando o numero de ocorrencias de um caractere (maiusculas e minusculas) arquivo e usando passagem de parametros
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_NOME 31

/*
    Uma boa pratica seria colocar as funcoes em um outro arquivo funcoes.c, e criar um arquivo header para
    fazer a ligação entre o contagemCaracter...arquivo.c e o funcoes.c
*/

int Conta_Caracteres(char *Nome, char Ch) { // conta as ocorrencias do caracter Ch no arquivo Nome
 FILE *f1;
 int cont = 0;
 char ch, ch1 = toupper(Ch); // toupper: converte o caracter para maiuscula

 if ( ( f1=fopen(Nome,"r") ) == NULL )
    {
     printf("Erro na abertura do arquivo %s", Nome);
     exit(1);
    }

   while ( (ch=fgetc(f1)) != EOF) {
	   printf("%c", ch);
       ch = toupper(ch);
       if (ch == ch1) cont++;
      }
  fclose(f1);
  return(cont);
}

int  main(void) {
 char nome_arq[TAM_NOME], ch;
 int cont = 0,tam;
 printf("\n Introduza o NOME DO ARQUIVO: ");
 fgets(nome_arq,TAM_NOME,stdin); // stdin: entrada padrao: teclado
 tam = strlen(nome_arq) - 1; // primeira posicao apos o ultimo caracter digitado
 nome_arq[tam] = '\0'; // final de string

 printf("\n Informe o caracter (nao diferencia maiusculas e minusculas) a contar: ");
 ch = fgetc(stdin);

 cont = Conta_Caracteres(nome_arq,ch);

 printf("\nO numero de ocorrencias da letra < %c > no arquivo %s e igual a %d\n\n",ch, nome_arq, cont);
 getchar();
 return(0);
}
