#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Matriz{
    char **labirinto;
    char **solucao;
    int linhas, colunas, chave, qntMovimento;
}Matriz;


void alocarMatriz(char ***matriz, Matriz matrizEscolhida);
void desalocarMatriz(char **matriz, int linhas);
void preencherMatrizSolucao(Matriz matriz);
void mostrarMatriz(Matriz matriz,char **matrizEscolhida);
void preencherMatrizLabirinto(FILE *arq, Matriz labirinto);
void inicializarMatrizSolucao(Matriz TAD, char ***matrizSolucao);
char encontrarCaminho(Matriz *matriz, int linha, int coluna);
void mostrarCaminhoColorido(Matriz matriz, char **matrizEscolhida);

#endif