#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alocarMatriz(int ***matriz, int linhas, int colunas);
void desalocarMatriz(int **matriz, int linhas);
void mostrarMatriz(int **matriz, int linhas, int colunas);

#endif