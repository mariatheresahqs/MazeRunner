#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define RESET "\x1B[0m"

/*
Valor 1 caso queira ver todos os passos dados pelo estudante. 
Obs: Caso não queira acompanhar o passo a passo durante este processo,
comente a linha 105 do arquivo Matriz.c
*/
#define MODOANALISE 1 

#include "Pilha.h"

typedef struct Matriz{
    char **labirinto;
    char **solucao;
    int linhas, colunas, chave, qntMovimento;
    int linhaInicial, colunaInicial, colunaFinal;
}Matriz;


void alocarMatriz(char ***matriz, Matriz matrizEscolhida);
void desalocarMatriz(char **matriz, int linhas);
void preencherMatrizSolucao(Matriz matriz);
void mostrarMatriz(Matriz matriz,char **matrizEscolhida);
void preencherMatrizLabirinto(FILE *arq, Matriz labirinto);
void inicializarMatrizSolucao(Matriz TAD, char ***matrizSolucao);
int movimenta_estudante(Matriz *matriz, Pilha** pilha, int linha, int coluna);
void posicaoEstudanteInicial(Matriz matriz, int *linha, int *coluna);
void posicaoEstudanteFinal(Matriz matriz, int *coluna);
void mostrarCaminhoColorido(Matriz matriz, char **matrizEscolhida);

#endif