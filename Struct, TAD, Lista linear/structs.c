#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // funcoes de manipulacao de string

#define ESPACOS "                          "
#define MAXALUNOS 10

typedef char Str50[51];    // reserva de uma posicao para '\0'


typedef enum mes {janeiro = 1,fevereiro,marco,abril,maio,junho,julho,
                   agosto,setembro,outubro,novembro,dezembro} MES;

typedef struct data {
			          int dia;  // componente ou campo dia
			          MES mes;  // componente ou campo mes
			          int ano;  // componente ou campo ano
                    } DATA;

typedef struct notas {
                        float nota_prova[5];  // 5 provas
                        float nota_trabalho[6];  // 6 trabalhos
                        float media_final;
                     } NOTAS;

typedef struct dados_pessoais {
					           Str50 nome;    // string
					           DATA nasc;     // outra struct
                                  NOTAS notas;   // struct com vetores
                              } DADOS_PESSOAIS;


int main() {

 DADOS_PESSOAIS  alunos[MAXALUNOS];   // vetor de struct
 DADOS_PESSOAIS  aluno1,       // variavel para um tipo struct
                 *ptra1;       // ponteiro para um tipo struct
 MES m1=fevereiro;            // enumeravel; fevereiro equivale a 2; interpretacao facilitada

    // preenchimento básico de alguns dados para ilustrar acesso e outros detalhes.
    // A consistência dos dados de entrada pode/deve ser feita. Por exemplo,
    // garantir que o dia de nascimento do aluno deve estar entre 1 e 31.

  strcpy(aluno1.nome, "Fulano de Tal"); // copia de uma string
  aluno1.nasc.dia = 12;
  aluno1.nasc.mes = m1;                 // enumeravel
  // aluno1.nasc.mes = fevereiro;       // pode ser assim também
  aluno1.nasc.ano = 1985;
  aluno1.notas.nota_prova[0] = 7.5;
  aluno1.notas.nota_prova[1] = 7.0;
  aluno1.notas.nota_prova[2] = 8.5;
  aluno1.notas.nota_prova[3] = 7.0;
  aluno1.notas.nota_prova[4] = 7.8;
  aluno1.notas.media_final =   7.56;   // EXERCICIO: implementar a funcao que calcula a media

  ptra1 = &aluno1;  // atribuicao do endereco de memoria de aluno1 a um ponteiro
                    // ptra1 e aluno1 representam a mesma estrutura depois da atribuicao

  printf("\nImpressao das componentes por meio de uma variavel (aluno1)\n");
  printf("operador de selecao: .\n");
  printf("==========================================================================\n");
  printf("ALUNO: %s ",aluno1.nome); printf(ESPACOS);
  printf("NASCIMENTO: %2d/%02d/%4d  \n",aluno1.nasc.dia, aluno1.nasc.mes, aluno1.nasc.ano);
  printf("\nProvas (P1,P2,P3,P4) = (%3.1f,%3.1f,%3.1f,%3.1f)\n",aluno1.notas.nota_prova[0],
  aluno1.notas.nota_prova[1],aluno1.notas.nota_prova[2],aluno1.notas.nota_prova[3]);
  printf("==========================================================================\n\n");

  printf("impressao das componentes por meio de um ponteiro para a variavel (ptra1)\n");
  printf("operador de selecao: ->\n");
  printf("==========================================================================\n");
  printf("ALUNO: %s ",(*ptra1).nome); printf(ESPACOS);  // uso do operador de selecao '.' com ponteiro
  printf("NASCIMENTO: %2d/%02d/%4d  \n",ptra1->nasc.dia, ptra1->nasc.mes, ptra1->nasc.ano);
  printf("MEDIA FINAL: %5.2f\n",ptra1->notas.media_final);  // campos nasc e notas nao sao ponteiros
                                                          // por isso, o operador de selecao '.'
  printf("==========================================================================\n");

  puts("\n");
  printf("Tamanho em bytes da estrutura DADOS_PESSOAIS : %d \n", sizeof(DADOS_PESSOAIS));
  printf("Tamanho TOTAL em bytes da estrutura alunos (%d * DADOS_PESSOAIS) : %d \n",MAXALUNOS, sizeof(alunos));

  printf("\nPressione enter/return para finalizar ... ");
  fflush(stdin);
  getchar();
  return(0);
}
