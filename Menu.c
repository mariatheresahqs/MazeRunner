#include "Menu.h"


void menu(){

    int **matrizLabirinto, **matrizSolucao;
    int linhas, colunas;
    printf("Digite o valor das linhas e colunas: ");
    scanf("%d %d", &linhas, &colunas);

    alocarMatriz(&matrizLabirinto, linhas, colunas);
    alocarMatriz(&matrizSolucao, linhas, colunas);



    desalocarMatriz(matrizLabirinto, linhas);
    desalocarMatriz(matrizSolucao, linhas);
    printf("Teste\n");
}