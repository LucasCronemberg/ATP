// Ordenacao: Shell Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 400000

/*--------------------------------------------------------*/
int Leitura_Dimensao_Array(void) {
int dim, continua;
  do
   {
     continua = 0;
     printf("Insira o numero de componentes do array (>= 1 && <= %d): ",MAX);
     scanf("%d",&dim);
     if ( (dim <= 0) || (dim > MAX) ) {
     	printf("0 < numero de componentes <= %d\n",MAX);
     	continua = 1;
     }
     else {continua = 0;}
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
   printf("\n CC[%d] = %d, ",i, *(Ptr+i));

} // Imprimindo_Valores_Array

/*--------------------------------------------------------*/
void Troca(int *Ind1, int *Ind2) {
int aux;
  aux =  *Ind1;
  *Ind1 =  *Ind2;
  *Ind2 = aux;
} // Troca

// EXERCICIO
// implementar o Shell Sort com a sequencia para h: h(1)=1; h(t+1) = 3*h(t) + 1

/*--------------------------------------------------------*/
void ShellSort (int *Str, int Dim) { // sequencia para h: original paper
int i, j, x, salto, h;

for(h=1; h<=Dim/9; h = 3*h+1) salto = h;

for (salto; salto>0; salto = (salto-1)/3){
   for (i = salto; i < Dim; i++) {
     x = *(Str+i);
     for (j=i; j >= salto && x < *(Str+j-salto); j=j-salto)
        *(Str+j) = *(Str+j-salto);
     *(Str+j) = x;
   }	//for i
}	// for k
return;
}	//ShellSort

void ShellSort2 (int *Str, int Dim) { // sequencia para h: original paper
int i, j, x, salto;

for (salto=Dim/2; salto>0; salto /=2){
   for (i = salto; i < Dim; i++) {
     x = *(Str+i);
     for (j=i; j >= salto && x < *(Str+j-salto); j=j-salto)
        *(Str+j) = *(Str+j-salto);
     *(Str+j) = x;
   }	//for i
}	// for k
return;
}	//ShellSort

/*--------------------------------------------------------*/

int main(void){
int     n1,            // tamanho real do array vetor1
	    vetor1[MAX];   // array vetor1 para armazenar os elementos

  n1 = Leitura_Dimensao_Array();
  Associa_Valores_Array(vetor1,n1);
  puts("Vetor original:\n");
  Imprimindo_Valores_Array(vetor1,n1);
  ShellSort(vetor1,n1);
  puts("\nVetor ordenado:\n");
  Imprimindo_Valores_Array(vetor1,n1);
  puts("\n\n");

  printf("Pressione return/enter para finalizar ...");
  fflush(stdin);
  getchar();
  return(0);
}
