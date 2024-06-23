//Ordenação: Dado uma base de dados arbitraria (Conjunto de números inteiros), organize estes dados
//numa estrutura de array, de forma que eles estejam ordenados (crescentemente).


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX2 400000    // numero maximo de numeros aleatorios
#define TAM_NOME 20

typedef enum boleano {falso, verdadeiro} Boleano;
// Boleano eh o sinonimo para o tipo enumeravel

FILE *f1, *f2; //ponteiro do tipo file para ser utilizado para a leitura do arquivo


// funcoes com a logica; nao so prototipos

/*--------------------------------------------------------*/
/*int Leitura_Dimensao_Array(void) {
int dim, continua;
  do
   {
     fflush(stdin);
     printf("Insira o numero de componentes do array (>= 1 && <= %d): ",MAX2);
     scanf("%d",&dim);
     if ( (dim <= 0) || (dim > MAX2) ) {
      printf("0 < numero de componentes <= %d\n",MAX2);
      continua = verdadeiro;
     }
     else { continua = falso;}
   }
  while ( continua );

return(dim);
} // Leitura_Dimensao_Array
*/
/*--------------------------------------------------------*/
void Associa_Valores_Array(int *Ptr, int *num) { // associa valores aleatorios/randomicos
    char nome_arq[TAM_NOME], ch; //vetor para gurdar o nome do arquivo e utilizar no codigo //variavel para checagem dos caracteres do arquivo
    int cont=0, tam=0, inteiro; //fazer a contagem de linhas //fazer a finalização do conteudo do vetor com o caracter '\0', para não ocorrer erros

    printf("\n Introduza o NOME DO ARQUIVO(vetor.txt): ");

    // controlando a quantidade maxima de caracteres
    // inserir '\0' ao final de nome_arq
    fgets(nome_arq,TAM_NOME,stdin); // stdin: entrada padrao: teclado
    tam = strlen(nome_arq) - 1; // primeira posicao apos o ultimo caracter digitado
    nome_arq[tam] = '\0'; // final de string

    //Verificação se ocorreu a abertura do arquivo, ou ouve erro
    if ( ( f1=fopen(nome_arq,"r") ) == NULL ) { //"r" significa leitura
        printf("Erro na abertura do arquivo %s", nome_arq);
        exit(verdadeiro); //verdadeiro:1 ativa o fechamento do arquivo
    }


     while ( (ch = fgetc(f1)) != EOF ) { // leitura do arquivo caracter a caracter
       if ( ch == '\n') {
        cont++; //Contagem acionada toda vez que o '\n' for encontrado como caracter
        fscanf(f1,"%i",&inteiro); // uma vez que o caracter '\n' é encontrado, o bloco ao qual ele pertence é gravado como um inteiro
        *(Ptr+(cont-1)) = inteiro;//alocando o valor dos blocos para cada indice do vetor
       }
    }

     if ( fclose(f1) != 0 ){
        printf("\n Erro ao fechar o arquivo %s ",nome_arq);
        }
        *num = cont;
        fputs("\n\n\n",stdout); // stdout: saida padrao, tela do computador
return;
} // Associando_Valores_Array // Associando_Valores_Array

/*--------------------------------------------------------*/
void Imprimindo_Valores_Array_Ordenado(int *Ptr, int Dim) { //para pedir o nome do arquivo destino apenas quando for ordenar
char nome_arq2[TAM_NOME];
int i = 0, tam=0;   // indice para percorrer o array

 printf("\n Introduza o nome do arquivo DESTINO: ");
 fgets(nome_arq2,TAM_NOME,stdin); // stdin: entrada padrao: teclado
 tam = strlen(nome_arq2) - 1; // primeira posicao apos o ultimo caracter digitado
 nome_arq2[tam] = '\0'; // final de string

if ( ( f2=fopen(nome_arq2,"w") ) == NULL ) { // abertura de arquivo texto para escrita
    printf("Erro na abertura do arquivo %s", nome_arq2);
    exit(1);
    }

 for (i=0; i < Dim; i++){
   printf("\n[%d] = %d ",i,*(Ptr+i));
   fprintf(f2,"\n[%d] = %d ",i,*(Ptr+i));
 }
 if ( fclose(f2) != 0 )
   printf("\n Erro ao fechar o arquivo %s ",nome_arq2);
} // Associando_Valores_Array em outro arquivo

void Imprimindo_Valores_Array(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o array

 for (; i < Dim; i++)
   printf("\n[%d] = %d ",i,*(Ptr+i));
} // Associando_Valores_Array


/*-------------------------------------------------------*/
void Troca(int *S,int Ind1, int Ind2) {
int aux;
  aux =  *(S +Ind1);
  *(S+Ind1) =  *(S+Ind2);
  *(S+Ind2) = aux;
} // Troca

/*-------------------------------------------------------*/

void SelectionSort(int *Str, int Dim) {
int i, j, ind, lim = Dim-1;
  for (i = 0; i < lim; i++){ // percorre as posicoes para o elemento correto
    ind = i; // iniciando ind para guardar o indice do menor numero
    for (j = i+1; j < Dim; j++){		// j= i+1
      if ( *(Str+j) <  *(Str+ind) ){ // permutando elementos associados as posições i e j
	     ind = j; //guardando o indice do numero mais perto do ultimo organizado vindo da direita
      }
    }
      if(ind != i)  Troca(Str,i,ind); //realizar a troca apenas se o ind estiver com valor diferente do que lhe foi atribuido
                    //ind entra no lugar do j como indice do caracter que queremos modificar
  }
  return;
} // SelectionSort

void insertionSort(int *Str, int Dim) {
int i, j, aux;
  for (i = 1; i < Dim; i++){ // para cada elemento na posicao i
    aux = *(Str + i); //guardando o valor do elemento atual
    j = i-1;    // posicao de inicio da busca da posicao correta

    while ((j>=0) && (*(Str + j)>aux)){ //comecando a busca da posicao correta
	     *(Str + j+1) = *(Str + j); //deslocando os elementos para a direita
         j--;  // atualizando o indice (testando o elemento a esquerda)
    }
      *(Str + j+1) = aux; //colocando o elemento(aux) em sua posicao correta
  }
  return;
} // SelectionSort

/*-------------------------------------------------------*/

int main(void) {

int 	    n1,             // tamanho real do array vetor1
	    vetor1[MAX2];   // array vetor1 para armazenar os elementos

  //n1 = Leitura_Dimensao_Array(); nao precisa, pois a dimensao esta voltando da funcao associa valores
  Associa_Valores_Array(vetor1,&n1);

  Imprimindo_Valores_Array(vetor1,n1);

  puts("\n");
  //SelectionSort(vetor1,n1);
  insertionSort(vetor1,n1);
  puts("Array ordenado:\n");
  Imprimindo_Valores_Array_Ordenado(vetor1,n1);
  printf("\n\nAcabei!!!!\n");

  printf("Pressione enter/return para finalizar ...");
  fflush(stdin); // esvaziando o buffer de entrada
  getchar();
  return(0);
}
