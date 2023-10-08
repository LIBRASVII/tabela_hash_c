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
      cripto->mensagem[i] = cripto->mensagem[i];
    }
  }
  printf("\nMensagem criptografada");
  for (int i = 0; i < strlen(cripto->mensagem); i++) {
    putchar(cripto->mensagem[i]);
  }
}

int main() { return 0; }
