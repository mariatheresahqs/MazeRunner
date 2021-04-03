#include "Matriz.h"


void alocarMatriz(int ***matriz, int linhas, int colunas){
    *matriz = (int**)malloc(linhas*(sizeof(int*))); // Alocando linhas do tipo ponteiro

    for(int i=0; i<linhas; i++){
        (*matriz)[i] = (int*)malloc(colunas*(sizeof(int))); // Alocando colunas do tipo inteiro
    }
}

void desalocarMatriz(int **matriz, int linhas){
    for(int i=0; i<linhas; i++){
        free(matriz[i]);
    }
    free(matriz);
}

void mostrarMatriz(int **matriz, int linhas, int colunas){
    for(int i =0; i<linhas; i++){
        for(int j=0; j<colunas;j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
