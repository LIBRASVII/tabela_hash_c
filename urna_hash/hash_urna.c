/* #include <conio.h> */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 251

typedef struct {
  char mensagem[N];
} urna;

void criptografa(urna *cripto);
void descriptografar(urna *cripto);

void criptografa(urna *cripto) {
  printf("\nInforme a mensagem => ");
  fgets(cripto->mensagem, N, stdin);

  for (int i = 0; i < strlen(cripto->mensagem); i++) {
    if (cripto->mensagem[i] == 'z') {
      cripto->mensagem[i] = 'c';
    } else if (cripto->mensagem[i] == 'y') {
      cripto->mensagem[i] = 'b';
    } else if (cripto->mensagem[i] == 'x') {
      cripto->mensagem[i] = 'a';
    } else {
      cripto->mensagem[i] = cripto->mensagem[i] + 3;
    }
  }
  printf("\nMensagem criptografada => ");
  for (int i = 0; i < strlen(cripto->mensagem); i++) {
    putchar(cripto->mensagem[i]);
  }
  printf("\n");
  for (int i = 0; i < strlen(cripto->mensagem); i++) {
    printf("%d", cripto->mensagem[i]);
  }
}

void descriptografar(urna *cripto) {
  for (int i = 0; i < strlen(cripto->mensagem); ++i) {
    cripto->mensagem[i] = (char)((int)cripto->mensagem[i] - 3);
  }
  printf("\nMensagem original =>");
  printf(" %s", cripto->mensagem);
  printf("\n");
}

int main() {
  urna mensagem;
  criptografa(&mensagem);
  descriptografar(&mensagem);
  printf("\n");

  return 0;
}
