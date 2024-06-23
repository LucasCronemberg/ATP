// Busca linear em dados armazenados em vetor (agregado homogeneo)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX1 500000  // numero max de componentes do vetor
#define TAM_NOME 20  // numero max de caracters do vetor

FILE *f1; //ponteiro do tipo file para ser utilizado para a leitura do arquivo

typedef enum boleano {falso, verdadeiro} Boleano;
// Boleano eh o sinonimo para o tipo enumeravel

Boleano Busca_Linear(int *Ptr, int Dim, int Chave);

//int Leitura_Dimensao_Array(void);

// as funcoes a seguir usam passagem de parametro por referencia
// int *Ptr
void Associa_Valores_Array(int *Ptr, int *num); //int *num para poder repassar o tamanho do vetor, para utilizar na funcao imprimindo e maior elemento
void Imprimindo_Valores_Array(int *Ptr, int Dim);
int Maior_Elemento_Vetor(int *Ptr, int Dim);

/*--------------------------------------------------------*/
Boleano Busca_Linear(int *Ptr, int Dim, int Chave) { //funcao que retorna um Boleano, logo verdadeiro:1 ou falso:0 podem ser utilizados no return
int i=0;   // indice para percorrer o array

 for (; i < Dim; i++)
      if ( *(Ptr+i) == Chave ) return(verdadeiro);  // elemento localizado

 return(falso);  // elemento nao pertence ao array
}  // Busca_Linear

/*--------------------------------------------------------*/
/*int Leitura_Dimensao_Array(void) { // aceita somente dimensao valida
int dim, continua;
  do
   {
     printf("Insira o numero de componentes do array (>= 1 && <= %d): ",MAX1);
     scanf("%d",&dim);
     if ( (dim <= 0) || (dim > MAX1) ) {
        printf("0 < numero de componentes <= %d\n",MAX1);
        continua = verdadeiro; //continua identifica se o "do while" continua ou não, então como ao cair dentro do if continua o valor verdadeiro:1 pode ser utilizado
     }
     else { continua = falso;} //continua identifica se o "do while" continua ou não, então como ao nao cair dentro do if, nao continua o valor falso:0 pode ser utilizado
   }
  while ( continua );

return(dim);
} // Leitura_Dimensao_Array
*/
/*--------------------------------------------------------*/
void Associa_Valores_Array(int *Ptr, int *num) { // associa valores aleatorios/randomicos
    char nome_arq[TAM_NOME], ch; //vetor para gurdar o nome do arquivo e utilizar no codigo //variavel para checagem dos caracteres do arquivo
    int cont=0, tam=0, inteiro; //fazer a contagem de linhas //fazer a finalização do conteudo do vetor com o caracter '\0', para não ocorrer erros

    printf("\n Introduza o NOME DO ARQUIVO : ");

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

     if ( fclose(f1) != 0 )
        printf("\n Erro ao fechar o arquivo %s ",nome_arq);
        *num = cont;
        fputs("\n\n\n",stdout); // stdout: saida padrao, tela do computador
return;
} // Associando_Valores_Array


/*--------------------------------------------------------*/
void Imprimindo_Valores_Array(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o array

 for (; i < Dim; i++)
   printf("\n [%d] = %d ",i,*(Ptr+i));  // ~ Prt[i]
} // Associando_Valores_Array

/*--------------------------------------------------------*/

int Maior_Elemento_Vetor(int *Ptr, int Dim) {
int i = 1, maior1;

  maior1 = *(Ptr);  // inicializando maior1 com o primeiro elemento do vetor

  for ( ; i < Dim; i++)	// a partir do segundo elemento - posição 1
    if ( *(Ptr+i) > maior1 )
	   maior1 = *(Ptr+i);

return(maior1);
}   // Maior_Elemento_Vetor

/*--------------------------------------------------------*/

int main(void) {

int 	 n1,             // tamanho real do array vetor1
      vetor1[MAX1],   // array vetor1 para armazenar os elementos
      chave;          // chave a ser pesquisada


  //n1 = Leitura_Dimensao_Array(); //nao precisa, pois a dimensao esta voltando da funcao associa valores
  Associa_Valores_Array(vetor1, &n1);

// imprimindo os valores associados aos diferentes arrays

  printf("\n\n VETOR1\n");
  Imprimindo_Valores_Array(vetor1,n1);

// Encontrando o maior elemento de vários vetores com a mesma função

 printf("\n\nO maior elemento do vetor1 e o valor: << %d >> ", Maior_Elemento_Vetor(vetor1,n1) );

 //chave = rand();   // valor pode nao estar presente no vetor
  chave = vetor1[n1-1];  // valor presente no vetor
  // O valor associado a chave também poderia ser lido

  printf("\n\nRealizando uma busca linear ... ");

  if ( Busca_Linear(&vetor1[0],n1,chave) )
     printf("\n\n O elemento %d PERTENCE ao vetor1.\n\n ",chave);
     else printf("\n\n O elemento %d NAO PERTENCE ao vetor1.\n\n",chave);

  printf("Pressione enter/return para finalizar ...");
  fflush(stdin); // esvaziando o buffer de entrada
  getchar();
  return(0);
}

