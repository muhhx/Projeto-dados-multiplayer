#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_MAX 100 //Numero limite

//Função menu principal
int menuPrincipal(int d, int sD, int sS[2], int player) {
  int op;
  do {
    printf("\n\nMENU PRINCIPAL\n1. Roll dice\n2. Salvar valor atual\n");
    printf("----------\nPlayer atual: %d\nDice: %d\nSoma dice: %d\nSoma salva (player1): %d\nSoma salva (player2): %d\n", player+1, d, sD, sS[0], sS[1]);
    scanf("%d", &op);
    if ((op < 1) || (op > 2))
      printf("\n\n[ERRO] Opção inválida!\n");
  } while((op < 1) || (op > 2));
  return op;
}

//Muda jogador
int mudaJogador(int x) {
  if (x == 0)
    x = 1;
  else
    x = 0;
  return x;
}

//Roll the dice
void rollDice(int *d, int *sD, int *player) {
  int x;
  srand(time(NULL));
  *d = (rand() % 6) + 1;
  if (*d != 1)
    *sD += *d;
  else {
    *sD = 0;
    x = *player;
    *player = mudaJogador(x);
  }
}

//Salvar valor atual da somaDice
void saveDice(int *sD, int sS[2], int *player, int *c) {
  int x;
  sS[*player] += *sD;
  *sD = 0;
  if (sS[*player] >= N_MAX) {
    printf("\n\nParabéns! O jogador %d venceu o jogo!\n\n", *player+1);
    *c = -1;
  } else {
    x = *player;
    *player = mudaJogador(x);
  }
}

//Função principal
int main(void) {
  int c, op, dice=0, somaDice=0, player=0, somaSalva[2] = {0, 0};

  do {
    op = menuPrincipal(dice, somaDice, somaSalva, player);
    switch(op) {
      case 1: rollDice(&dice, &somaDice, &player); break;
      case 2: saveDice(&somaDice, somaSalva, &player, &c);
    }
  } while(c != -1);
  printf("Fim do programa!\n\n");

  return 0;
}