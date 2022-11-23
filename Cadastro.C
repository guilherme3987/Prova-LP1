#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* TRABALHO FINAL LP1
                                  CADASTRO DE ALUNOS EM C
 ALUNO: GUILHERME DOS SANTOS
*/

int main() {
  // variáveis
  char *ptr_Aluno_nome[1], *ptr_Aluno_cpf[1], *ptr_Aluno_matricula[9];

  char *ptr_Consulta_nome[1], *ptr_Consulta_cpf[1];

  float nota1, nota2, nota3, *media;

  media = malloc(3 * sizeof(nota1, nota2, nota3));

  int opcao, x, op;

  // alocaçao de memoria
  ptr_Aluno_nome[10] = malloc(1 * sizeof(ptr_Aluno_nome));
  ptr_Aluno_cpf[11] = malloc(1 * sizeof(ptr_Aluno_cpf));
  ptr_Aluno_matricula[9] = malloc(1 * sizeof(ptr_Aluno_matricula));

  ptr_Consulta_nome[10] = malloc(1 * sizeof(ptr_Consulta_nome));
  ptr_Consulta_cpf[11] = malloc(1 * sizeof(ptr_Consulta_cpf));

  printf("\t\t\t\tC A R R E G A N D O");
  for (int tempo = 0; tempo < 5; tempo++) {
    system("sleep 1.5");
    printf(".");
    fflush(stdout);
  }
  system("clear");

  // funçao menu e condicionais
  void menu();
  menu();
  scanf("%d", &opcao);

  while (opcao == 1) {
    // funcoes de cadastrar dados,media e retornar ao menu  
    void entrada_dados(char *ptr_Aluno_nome, char *ptr_Aluno_cpf,
                       char *ptr_Aluno_matricula, int x);

    entrada_dados(ptr_Aluno_nome, ptr_Aluno_cpf, ptr_Aluno_matricula, x);

    float calculo_media(float nota1, float nota2, float nota3, float *media);
    calculo_media(nota1, nota2, nota3, media);

    void menu();
    menu();
    scanf("%d", &opcao);
  }

  while (opcao == 2) {
    // funcoes de consultar e retornar ao menu
    void consultar(char *ptr_Aluno_nome, char *ptr_Aluno_cpf,
                   char *ptr_Consulta_nome, char *ptr_Consulta_cpf,
                   float *media, int x);
    consultar(ptr_Aluno_nome, ptr_Aluno_cpf, ptr_Consulta_nome,
              ptr_Consulta_cpf, media, x);


    void menu();
    menu();
    scanf("%d", &opcao);

    while (opcao == 1) {

      void entrada_dados(char *ptr_Aluno_nome, char *ptr_Aluno_cpf,
                         char *ptr_Aluno_matricula, int x);
      entrada_dados(ptr_Aluno_nome, ptr_Aluno_cpf, ptr_Aluno_matricula, x);

      void menu();
      menu();
      scanf("%d", &opcao);
    }
  }

  while (opcao == 3) {
    // funcoes excluir ou alterar dados e retornar ao menu
    void excluir_altera_dados(
        char *ptr_Aluno_nome, char *ptr_Aluno_cpf, char *ptr_Aluno_matricula,
        char *ptr_Consulta_nome, char *ptr_Consulta_cpf, float nota1,
        float nota2, float nota3, float *media, int op, int x);
    excluir_altera_dados(*ptr_Aluno_nome, *ptr_Aluno_cpf, ptr_Aluno_matricula,
                         *ptr_Consulta_nome, *ptr_Consulta_cpf, nota1, nota2,
                         nota3, media, op, x);

    void menu();
    menu();
    scanf("%d", &opcao);
    while (opcao == 1 || opcao == 2) {
      void entrada_dados(char *ptr_Aluno_nome, char *ptr_Aluno_cpf,
                         char *ptr_Aluno_matricula, int x);
      entrada_dados(ptr_Aluno_nome, ptr_Aluno_cpf, ptr_Aluno_matricula, x);

      void consultar(char *ptr_Aluno_nome, char *ptr_Aluno_cpf,
                     char *ptr_Consulta_nome, char *ptr_Consulta_cpf,
                     float *media, int x);
      consultar(ptr_Aluno_nome, ptr_Aluno_cpf, ptr_Consulta_nome,
                ptr_Consulta_cpf, media, x);
    }
  }
}

// declaraçao de funçoes

// funcao menu
void menu() {
  printf("\n\n\n\n===============================\n-- Cadastrar Alunos e notas "
         "--\t\n===============================\n------------------------------"
         "\n\t\t----- MENU ------\n\t(0) - SAIR\n\t(1) - CADASTRAR\n\t(2) - "
         "CONSULTAR\n\t(3) - EXCLUIR ou "
         "ALTERAR\n------------------------------\n============================"
         "==\n->");
}

// funçao de entrada de dados
void entrada_dados(char *ptr_Aluno_nome, char *ptr_Aluno_cpf,
                   char *ptr_Aluno_matricula, int x) {

  ptr_Aluno_nome[11] = malloc(11 * sizeof(ptr_Aluno_nome));
  ptr_Aluno_cpf[12] = malloc(12 * sizeof(ptr_Aluno_cpf));
  ptr_Aluno_matricula[9] = malloc(9 * sizeof(ptr_Aluno_matricula));

  system("sleep 01");
  system("clear");
  printf("\n\n\t -=-=-=-=-=-=-= CADASTRO -=-=-=-=-=-=-=");

  printf("\n\tNOME: ");
  scanf("%s", &*ptr_Aluno_nome);

  system("sleep 01");
  //  scanf("%d",&x);

  printf("\n\tCPF: ");
  scanf("%s", &*ptr_Aluno_cpf);
  system("sleep 01");

  //  scanf("%x",&x);
  printf("\n\tMATRICULA: ");
  scanf("%s", &*ptr_Aluno_matricula);
  system("sleep 01");
}

// função de calculo de media
float calculo_media(float nota1, float nota2, float nota3, float *media) {

  printf("\n\tDigite as notas do aluno: ");

  scanf("%f %f %f", &nota1, &nota2, &nota3);
  while (nota1 < 0 || nota2 < 0 || nota3 < 0) {
    printf("\tNotas inválidas\n\trepita: ");
    scanf("%f %f %f", &nota1, &nota2, &nota3);

    system("clear");
  }

  *media = (nota1 + nota2 + nota3) / 3;
  system("sleep 01");
  printf("\n\tMedia do aluno = %.1f\n", *media);
  if (*media < 7.0) {
    printf("\n\t ******** ALUNO REPROVADO ********");
    system("sleep 03");
    system("clear");
  } else {
    printf("\n\t******** ALUNO APROVADO ******** ");
    system("sleep 03");
    system("clear");
  }
}
// funçao de consulta dos dados cadastrados
void consultar(char *ptr_Aluno_nome, char *ptr_Aluno_cpf,
               char *ptr_Consulta_nome, char *ptr_Consulta_cpf, float *media,
               int x) {

  *ptr_Consulta_nome = malloc(11 * sizeof(ptr_Consulta_nome));
  *ptr_Consulta_cpf = malloc(12 * sizeof(ptr_Consulta_cpf));

  system("clear");

  printf("\n\t-=-=-=-=-=-=-= CONSULTAR -=-=-=-=-=-=-=");
  system("sleep 01");
  printf("\n\n\tNOME A SER CONSULTADO: ");

  scanf("%s", &*ptr_Consulta_nome);

  system("sleep 01");
  printf("\n\n\tCPF A SER CONSULTADO: ");
  scanf(" %s", &*ptr_Consulta_cpf);

  if ((*ptr_Consulta_nome == *ptr_Aluno_nome) &&
      (*ptr_Consulta_cpf == *ptr_Aluno_cpf)) {
    system("sleep 01");
    printf("\n\n\t         ***** ALUNO CADASTRADO *****\n");
    system("sleep 01");
    printf("\n\n\t| ---- NOME ---- |    | ---- MÉDIA ---- |\n\t");

    printf("%s %s", ptr_Consulta_nome, ptr_Consulta_cpf);
    printf("\t\t                   Media do aluno = %.2f", *media);
  } else {
    system("sleep 01");
    system("clear");
    printf(
        "\n\n*******************************************************\n\t*****"
        " ALUNO NÃO CADASTRADO OU CPF INVÁLIDO "
        "*****\n*******************************************************\n ");
  }
}

// funçao para alterar ou excluir
void excluir_altera_dados(char *ptr_Aluno_nome, char *ptr_Aluno_cpf,
                          char *ptr_Aluno_matricula, char *ptr_Consulta_nome,
                          char *ptr_Consulta_cpf, float nota1, float nota2,
                          float nota3, float *media, int op, int x) {

  ptr_Aluno_nome = malloc(11 * sizeof(ptr_Aluno_nome));
  ptr_Aluno_cpf = malloc(12 * sizeof(ptr_Aluno_cpf));
  ptr_Aluno_matricula = malloc(9 * sizeof(ptr_Aluno_matricula));
  ptr_Consulta_nome = malloc(11 * sizeof(ptr_Consulta_nome));
  ptr_Consulta_cpf = malloc(12 * sizeof(ptr_Consulta_cpf));
  system("clear");

  system("sleep 01");
  printf("\n\n\n\t -----------------------");
  system("sleep 01");
  printf("\n\t(0) - Excluir dados\n\t(1) - Alterar dados\n  \t = > ");
  scanf("%d", &op);

  if (op == 0) {
    system("clear");
    printf("\n\tExlcuindo dados");
    for (int tempo = 0; tempo < 10; tempo++) {
      system("sleep 01");
      printf(".");
      fflush(stdout);
    }
    system("clear");
    printf(" \n\t************************************************\n\t "
           "**************** DADOS EXCLUIDOS **************** "
           "\n\t************************************************");
    free(ptr_Aluno_nome);
    free(ptr_Aluno_cpf);
    free(ptr_Aluno_matricula);
    free(ptr_Consulta_nome);
    free(ptr_Consulta_cpf);

  }

  else {
    ptr_Aluno_nome = malloc(11 * sizeof(ptr_Aluno_nome));
    ptr_Aluno_cpf = malloc(12 * sizeof(ptr_Aluno_cpf));
    system("sleep 01");
    printf("\n\nAlterar dados ");
    for (int x = 0; x < 1; x++) {
      system("sleep 01");
      printf("\n\tNOME: ");
      fgets(&ptr_Aluno_nome[x], 11, stdin);
    }
    scanf(" %d", &x);

    for (int x = 0; x < 1; x++) {
      system("sleep 01");
      printf("\n\tCPF: ");
      fgets(&ptr_Aluno_cpf[x], 11, stdin);
    }
    scanf(" %d", &x);
    for (int x = 0; x < 1; x++) {
      system("sleep 01");
      printf("\n\tMATRICULA: ");
      fgets(&ptr_Aluno_matricula[x], 9, stdin);
    }
    system("sleep 01");
    printf("\n\n Alterar notas\n\tDigite as notas do aluno: ");

    scanf("%f %f %f", &nota1, &nota2, &nota3);
    *media = (nota1 + nota2 + nota3) / 3;
    system("sleep 01");
    printf("\n\tMedia do aluno = %.1f\n", *media);
  }
}
