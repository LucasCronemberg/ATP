// ordenacao: Metodo da Bolha (Bubble Sort)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX2 400000    // numero maximo de numeros aleatorios


/*--------------------------------------------------------*/
int Leitura_Dimensao_Array(void) { // aceita somente dimensao valida
int dim, continua;
  do
   {
     printf("Insira o numero de componentes do array (>= 1 && <= %d): ",MAX2);
     scanf("%d",&dim);
     if ( (dim <= 0) || (dim > MAX2) ) {
        printf("0 < numero de componentes <= %d\n",MAX2);
        continua = 1;
     }
     else { continua = 0;}
   }
  while ( continua );

return(dim);
} // Leitura_Dimensao_Array

/*--------------------------------------------------------*/
void Associa_Valores_Array(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o array
time_t t;

  srand((unsigned) time(&t));
  for ( ; i < Dim; i++) *(Ptr+i) = rand();

return;
} // Associando_Valores_Array

/*--------------------------------------------------------*/
void Imprimindo_Valores_Array(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o array

 for (; i < Dim; i++)
   printf("\n [%d] = %d ",i,*(Ptr+i));
} // Imprimindo_Valores_Array

/*--------------------------------------------------------*/

// EXERCICIO
//Elabore e teste uma nova funcao Troca que utilize apenas 02 parametros


void Troca1(int *S, int Ind1) {
int aux;

  aux =  *(S+Ind1);
  *(S+Ind1) =  *(S+Ind1+1);
  *(S+Ind1+1) = aux;
} // Troca1

/*--------------------------------------------------------*/
void Ordenacao_Bolha1(int *Elem, int Dim) //ordem crescente
{
 int dif, ind, j, mdif=MAX2;
   for (j = 0; j < Dim-1; j++){   // aponta para as posicoes do array
      dif = *(Elem + j+1) - *(Elem+j);
      if ( dif<mdif){ // permutando elementos
	    mdif = dif;
        ind = j;
        }
   }
   printf("\n\n\nMenor par sao os indices %d e %d",ind, ind+1);
  return;
} // Ordenacao_Bolha1

/*--------------------------------------------------------*/
void Ordenacao_Bolha2(int *Elem, int Dim) //ordem crescente
{
 int i=1, j, continua=1, exp1;

 while ( (i < Dim ) && continua ) { // controla o numero de varreduras
     continua = 0;
     exp1 = Dim-i;
     for (j = 0; j < exp1; j++) {  // aponta para as posicoes do array
	   if ( *(Elem+j) > *(Elem+j+1) ) { // permutando elementos
	     Troca1(Elem,j);
	     continua = 1;          // realizou uma troca
	   }
	 }
     i++;
   }
  return;
} // Ordenacao_Bolha2

// EXERCICIO
// Elabore e teste a varredura da direita para esquerda
void Ordenacao_Bolha3(int *Elem, int Dim) //ordem crescente
{
 int i=Dim-1, j, continua=1, exp1;

 while ( (i > 0 ) && continua ) { // controla o numero de varreduras
     continua = 0;
     exp1 = Dim -1 - i ;
     for (j = i; j > exp1; j--) {  // aponta para as posicoes do array
	   if ( *(Elem+j-1) > *(Elem+j) ) { // permutando elementos
	     Troca1(Elem,j-1);
	     continua = 1;          // realizou uma troca
	   }
	 }
     exp1--;
   }
  return;
}
/*--------------------------------------------------------*/

int main(){


  int 	n1,             // tamanho real do array vetor1
	    vetor1[MAX2];   // array vetor1 para armazenar os elementos

  n1 = Leitura_Dimensao_Array();
  Associa_Valores_Array(vetor1,n1);
  puts("Vetor original:\n");
  Imprimindo_Valores_Array(vetor1,n1);
  Ordenacao_Bolha3(vetor1,n1);
  puts("\nVetor ordenado:\n");
  Imprimindo_Valores_Array(vetor1,n1);
  Ordenacao_Bolha1(vetor1,n1);

  puts("\n\n");

  printf("Pressione enter/return para finalizar ...");
  fflush(stdin);
  getchar();
  return(0);
}


