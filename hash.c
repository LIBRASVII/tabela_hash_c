#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 251

struct matricula {
  int RA;
  char nome[81];
  char email[41];
  char turma;
};

typedef struct matricula Mat_aluno;
typedef Mat_aluno *Hash[N];

int funcao_Esp(int);
Mat_aluno *insere_Esp(Hash, int, char *, char *, char);
void remove_Esp(Hash, int);
Mat_aluno *busca_Esp(Hash, int);
int tamanho_Esp(Hash);

int main() {
  Hash tab;
  int op, RA;
  char nome[81], email[41], turma;

  for (int i = 0; i < N; i++) {
    tab[i] = NULL;
  }
  while (1) {
    printf("\n::1:: ==> Inserir"
           "\n::2:: ==> Remover"
           "\n::3:: ==> Busca"
           "\n::4:: ==> Tamanho da tabela"
           "\n::5:: ==> Sair"
           "\nOpcao ==> ");
    scanf("%d", &op);
  }

  return 0;
}

int funcao_Esp(int RA) { return (RA % N); }

Mat_aluno *insere_Esp(Hash tab, int RA, char *nome, char *email, char turma) {
  int h = funcao_Esp(RA);

  while (tab[h] != NULL) {
    if (tab[h]->RA == RA)
      break;

    h = (h + 1) % N;
  }

  if (tab[h] == NULL) {
    tab[h] = (Mat_aluno *)malloc(sizeof(Mat_aluno));
    tab[h]->RA = RA;
  }

  strcpy(tab[h]->nome, nome);
  strcpy(tab[h]->email, email);
  tab[h]->turma = turma;

  return tab[h];
}

void remove_Esp(Hash tab, int RA) {
  int h = funcao_Esp(RA);

  if (tab[h] != NULL && tab[h]->RA == RA) {
    free(tab[h]);
    tab[h] = NULL;
    printf("\nRA excluido");
  } else {
    printf("\nRA nao encontrado");
  }
}

Mat_aluno *busca_Esp(Hash tab, int RA) {
  int h = funcao_Esp(RA);

  while (tab[h] != NULL) {
    if (tab[h]->RA == RA) {
      return tab[h];
    }
    h = (h + 1) % N;
  }

  return NULL;
}

int tamanho_Esp(Hash tab) {
  int cont = 0;
  int total = 0;

  while (cont < N) {
    if (tab[cont] != NULL) {
      total++;
    }
    cont++;
  }
  return total;
}
