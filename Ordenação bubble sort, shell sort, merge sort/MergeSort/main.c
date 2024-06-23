// ordenacao: MergeSort

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
void Merge(int S[], int ini, int meio, int fim){
    int B[MAX2], i = ini, j = meio+1, k = ini;

    while( (i <= meio) && (j <= fim)){
        if(S[i] < S[j]){
            B[k] = S[i];
            k++;i++;
        }else{
            B[k] = S[j];
            k++;j++;
        }
    }

    while(i <= meio){ B[k] = S[i]; k++;i++;}
    while(j <= fim){ B[k] = S[j]; k++;j++;}

    for(i = ini; i <= fim; i++) S[i] = B[i];
}

/*--------------------------------------------------------*/
void Ordenacao_MergeSort(int *list, int ini, int fim){
    if(ini<fim){
        int meio = (fim + ini)/2; //variavel local

        Ordenacao_MergeSort(list, ini, meio);      //1° metade
        Ordenacao_MergeSort(list, meio+1, fim);    //2° metade
        Merge(list, 0, meio, fim);               //Função auxiliar que realiza a combianação(ordenação)
    }
}

int main(){


  int 	n1,             // tamanho real do array vetor1
	    vetor1[MAX2];   // array vetor1 para armazenar os elementos

  n1 = Leitura_Dimensao_Array();
  Associa_Valores_Array(vetor1,n1);
  puts("Vetor original:\n");
  Imprimindo_Valores_Array(vetor1,n1);
  Ordenacao_MergeSort(vetor1,0,n1);
  puts("\nVetor ordenado:\n");
  Imprimindo_Valores_Array(vetor1,n1);

  puts("\n\n");

  printf("Pressione enter/return para finalizar ...");
  fflush(stdin);
  getchar();
  return(0);
}
