// copia dos campos de arquivo ORIGEM para arquivo DESTINO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 31

FILE *f1, *f2;

int main(void) {
 char nome_arq1[TAM_NOME], nome_arq2[TAM_NOME], cadCaracteres[30];
 int tam,inteiro;
 float real;

 printf("\n Introduza o nome do arquivo ORIGEM: ");
 fgets(nome_arq1,TAM_NOME,stdin); // stdin: entrada padrao: teclado
 tam = strlen(nome_arq1) - 1; // primeira posicao apos o ultimo caracter digitado
 nome_arq1[tam] = '\0'; // final de string

 printf("\n Introduza o nome do arquivo DESTINO: ");
 fgets(nome_arq2,TAM_NOME,stdin); // stdin: entrada padrao: teclado
 tam = strlen(nome_arq2) - 1; // primeira posicao apos o ultimo caracter digitado
 nome_arq2[tam] = '\0'; // final de string

 if ( (f1=fopen(nome_arq1,"r")) == NULL ) { // abertura de arquivo texto para leitura
    printf("Erro na abertura do arquivo %s", nome_arq1);
    exit(1);
    }

 if ( ( f2=fopen(nome_arq2,"w") ) == NULL ) { // abertura de arquivo texto para escrita
    printf("Erro na abertura do arquivo %s", nome_arq2);
    exit(1);
    }

  if (fgetc(f1) && !feof(f1)) { // teste para verificar se o arquivo eh vazio
     rewind(f1); // retorna o ponteiro para o inicio do arquivo
     while ( !feof(f1) ) { // copia dos campos de ORIGEM para DESTINO
           fscanf(f1,"%i %s %f",&inteiro,cadCaracteres,&real);
           fprintf(f2,"%i %s %.1f\n",inteiro,cadCaracteres,real);
     }
  }

  if ( fclose(f1) != 0 )
   printf("\n Erro ao fechar o arquivo %s ",nome_arq1);

  if ( fclose(f2) != 0 )
   printf("\n Erro ao fechar o arquivo %s ",nome_arq2);

 printf("\nCampos de %s copiados com sucesso para %s !!! ",nome_arq1,nome_arq2);

 fputs("\n\n\nPressione uma tecla para finalizar",stdout);
 getchar();
 return(0);

}
