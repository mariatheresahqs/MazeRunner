#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alocarMatriz(char ***matriz, int linhas, int colunas);
void desalocarMatriz(char **matriz, int linhas);
void mostrarMatriz(char **matriz, int linhas, int colunas);
void inicializarMatrizSolucao(char **matrizSolucao, int linhas, int colunas);
void mostrarMatriz(char **matriz, int linhas, int colunas);
void preencherMatrizLabirinto(FILE *arq, char **matrizLabirinto, int linhas, int colunas);
void mostrarMatrizLabirinto(char **matrizLabirinto, int linhas, int colunas);

#endif