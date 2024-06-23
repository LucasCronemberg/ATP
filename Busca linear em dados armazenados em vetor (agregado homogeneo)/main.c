// Busca linear em dados armazenados em vetor (agregado homogeneo)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *f1; //ponteiro do tipo file para ser utilizado para a leitura do arquivo

/*----------------------------------------------------*/
/*DISCIPLINAS*/
typedef struct {
  int Codigo;
  char Nome[51];
} TipoItemDisciplina;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  TipoItemDisciplina Item;
  TipoApontador Prox;   // ponteiro para o proximo struct
} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;  // ponteiro para struct
} TipoLista;

void FLVazia(TipoLista *Lista)
{ Lista -> Primeiro = (TipoCelula *)malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
}

void InsereDisciplina(TipoItemDisciplina x, TipoLista *Lista)
{ if((Lista -> Ultimo -> Prox = (TipoCelula *)malloc(sizeof(TipoCelula))) != NULL){
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> Item = x;
  Lista -> Ultimo -> Prox = NULL;
  }else printf("Não esta funcionando o malloc");

}
/*--------------------------------------------------------------------*/
/*NOTAS*/

typedef struct {
  TipoItemDisciplina disciplina;
  float Nota;
} TipoItemNotas;

typedef struct {
  char Nome[51];
  TipoItemNotas Notas;
} TipoItemRegistro;

typedef struct TipoCelulaRegistro *TipoApontadorRegistro;

typedef struct TipoCelulaRegistro {
  TipoItemRegistro Registro;
  TipoApontadorRegistro Prox;   // ponteiro para o proximo struct
} TipoCelulaRegistro;

typedef struct {
  TipoApontadorRegistro Primeiro, Ultimo;  // ponteiro para struct
} TipoListaRegistro;

void InsereRegistro(TipoItemRegistro x, TipoListaRegistro *Lista)
{ if((Lista -> Ultimo -> Prox = (TipoCelulaRegistro *)malloc(sizeof(TipoCelulaRegistro))) != NULL){
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> Registro = x;
  Lista -> Ultimo -> Prox = NULL;
  }else printf("Não esta funcionando o malloc");

}

void ImprimeRegistro(TipoListaRegistro Lista)
{ TipoCelulaRegistro *Aux;
  Aux = Lista.Primeiro -> Prox;
  printf("%s\n",Aux->Registro.Notas.disciplina.Nome);
  while (Aux != NULL)
    { printf("\t%s %5.2f\n",Aux ->Registro.Nome, Aux->Registro.Notas.Nota);
      Aux = Aux ->Prox;
    }
}

/*--------------------------------------------------------*/
void Disciplinas(TipoLista *Lista) { // associa valores aleatorios/randomicos
    char ch, linha[51]; //vetor para gurdar o nome do arquivo e utilizar no codigo //variavel para checagem dos caracteres do arquivo
    int inteiro; //fazer a contagem de linhas //fazer a finalização do conteudo do vetor com o caracter '\0', para não ocorrer erros
    TipoItemDisciplina Item;

    //Verificação se ocorreu a abertura do arquivo, ou ouve erro
    if ( ( f1=fopen("disciplina.txt","r") ) == NULL ) { //"r" significa leitura
        printf("Erro na abertura do arquivo disciplina.txt");
        exit(1); //verdadeiro:1 ativa o fechamento do arquivo
    }


     while ( (ch = fgetc(f1)) != EOF ) { // leitura do arquivo caracter a caracter
       if ( ch == '\n') {
        fscanf(f1,"%d%s",&inteiro,&linha); // uma vez que o caracter '\n' é encontrado, o bloco ao qual ele pertence é gravado como um inteiro
        Item.Codigo = inteiro;
        strcpy(Item.Nome, linha);
        InsereDisciplina(Item, &Lista[Item.Codigo]);// inserindo o item na lista, de forma a que o [] indique o codigo a ser requerido
       }
    }

     if ( fclose(f1) != 0 ){
        printf("\n Erro ao fechar o arquivo disciplina.txt");
        }
return;
}

void Registro(TipoListaRegistro *ListaR, TipoLista ListaD[]) { // associa valores aleatorios/randomicos
    char ch, nome[51]; //vetor para gurdar o nome do arquivo e utilizar no codigo //variavel para checagem dos caracteres do arquivo
    int codigo; //fazer a contagem de linhas //fazer a finalização do conteudo do vetor com o caracter '\0', para não ocorrer erros
    float nota;
    TipoItemRegistro registro;// struct para inserir o item na lista
    TipoItemDisciplina disc;// struct para repassar do arquivo para o TipoItemNota
    TipoItemNotas notas;//struct para repassar os valores ao registro

    //Verificação se ocorreu a abertura do arquivo, ou ouve erro
    if ( ( f1=fopen("notas.txt","r") ) == NULL ) { //"r" significa leitura
        printf("Erro na abertura do arquivo notas.txt");
        exit(1); //verdadeiro:1 ativa o fechamento do arquivo
    }


     while ( (ch = fgetc(f1)) != EOF ) { // leitura do arquivo caracter a caracter
       if ( ch == '\n') {
        fscanf(f1,"%s%d%f",&nome,&codigo,&nota); // uma vez que o caracter '\n' é encontrado, o bloco ao qual ele pertence é gravado como um inteiro
            TipoCelula *Aux; //auxiliar para acessar as celular
            for(int i=1;i<6;i++){ //for para percorrer as celulas
            Aux = ListaD[i].Primeiro -> Prox;
            while (Aux != NULL)
              { if(Aux->Item.Codigo == codigo){ //if que recebe o nome da disciplina se o codigo for igual ao recebido
                  disc = Aux->Item;
                  }
                Aux = Aux ->Prox; //trazendo a próxima celular ao auxiliar
              }
            }
            //atribuindo os valores aos itens para serem repassados ao registro(TipoItemRegistro)
          notas.disciplina = disc;
          notas.Nota = nota;
          strcpy(registro.Nome, nome);
          registro.Notas = notas;

          InsereRegistro(registro, &ListaR[registro.Notas.disciplina.Codigo]);
      }
    }

     if ( fclose(f1) != 0 ){
        printf("\n Erro ao fechar o arquivo notas.txt");
        }
return;
}

void Busca(TipoLista Lista[], int codigo)
{ TipoCelula *Aux; //auxiliar para verificar as celulas
  int k=0; //variavel para confirmar que nao foi encontrado na busca
  for(int i=1;1<6;i++){
  Aux = Lista[i].Primeiro -> Prox;
  while (Aux != NULL)
    {
      if(Aux->Item.Codigo == codigo){//if para verificar se o codigo digitado foi encontrado
        printf("%s\n\n", Aux ->Item.Nome);
        return;//se encontrando terminar a função para não entrar no if do sem cadastro
      }else{k=1;};
      Aux = Aux ->Prox;
      if(i==5 && k==1){ printf("Sem Cadastro!\n\n"); return;}
    }
  }
}

/*--------------------------------------------------------*/

int main(void) {

int 	 n1, codigo;          // tamanho real do array vetor1
TipoLista ListaDisciplinas[6];
TipoListaRegistro ListaRegistro[16];

  for (int i = 1; i <= 6; i++) FLVazia(&ListaDisciplinas[i-1]);
  Disciplinas(&ListaDisciplinas);

  printf("\n");
  for (int i = 1; i <= 16; i++) FLVazia(&ListaRegistro[i-1]);
  Registro(&ListaRegistro, ListaDisciplinas);

  printf("Digite o codigo a ser pesquisado:");
  scanf("%d",&codigo);
  Busca(ListaDisciplinas,codigo);

  printf("LISTAGEM DOS REGISTROS POR DISCIPLINA:\n");
  for (int i = 1; i < 6; i++) ImprimeRegistro(ListaRegistro[i]);

  printf("Pressione enter/return para finalizar ...");
  fflush(stdin); // esvaziando o buffer de entrada
  getchar();
  return(0);
}
