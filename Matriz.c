#include "Matriz.h"


void alocarMatriz(char ***matriz, int linhas, int colunas){
    *matriz = (char**)malloc(linhas*(sizeof(char*))); // Alocando linhas do tipo ponteiro

    for(int i=0; i<linhas; i++){
        (*matriz)[i] = (char*)malloc(colunas*(sizeof(char))); // Alocando colunas do tipo inteiro
    }
}

void desalocarMatriz(char **matriz, int linhas){
    for(int i=0; i<linhas; i++){
        free(matriz[i]);
    }
    free(matriz);
}

void mostrarMatriz(char **matriz, int linhas, int colunas){
    printf("\n");
    for(int i =0; i<linhas; i++){
        for(int j=0; j<colunas;j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
}

void inicializarMatrizSolucao(char **matrizSolucao, int linhas, int colunas){
    for(int i=0; i<linhas;i++){
        for(int j=0;j<colunas;j++){
            matrizSolucao[i][j] = '0';
        }
    }
}

void preencherMatrizLabirinto(FILE *arq, char **matrizLabirinto, int linhas, int colunas){
    char c = ' ';
    while (c != EOF){
        char c = ' ';
        if(feof(arq))
            break;

        for(int i=0;i<linhas;i++){
            for(int j=0;j<colunas;j++){
                fscanf(arq,"%c",&matrizLabirinto[i][j]);
            }
        }

        for(int i=0;i<linhas;i++){
            c = fgetc(arq); //captura o \n
        }
        c = fgetc(arq); //captura o \n
    }
}

void mostrarMatrizLabirinto(char **matrizLabirinto, int linhas, int colunas){
    
    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            printf("%c", matrizLabirinto[i][j]);
        }
    }
            
}