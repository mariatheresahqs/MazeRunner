#ifndef _PILHA_H_
#define _PILHA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct No{
    int linha, coluna;
}No;

typedef struct Pilha{
   No posicaoMatriz;
   struct Pilha* proxPosicao;
   int tamanho;
}Pilha;

void alocarPilha(Pilha** pilha);
void liberarPilha(Pilha* pilha);
int pilhaVazia(Pilha** pilha);
int inserirPilha(Pilha** pilha, int linha, int coluna);
void mostrarPilha(Pilha* pilha);
int removerPilha(Pilha** pilha);


#endif