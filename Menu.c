#include "Menu.h"


void menu(){
    char nomeArq[25];
    FILE *arq;
    printf("Entre com o nome do arquivo: ");
	scanf("%s", nomeArq);
	arq = fopen (nomeArq, "r");
    if (arq == NULL) {
        printf("Erro na leitura do arquivo!\n");
        printf("Tente inserir outro nome ou corrigir o que foi inserido.\n");
    } else {
        printf("\nARQUIVO ABERTO COM SUCCESSO!! \n");
        int linhas, colunas, chave;
        fscanf(arq, "%d %d %d", &linhas, &colunas, &chave);
        printf("%d %d %d",linhas,colunas,chave);
        char **matrizLabirinto, **matrizSolucao;
        alocarMatriz(&matrizLabirinto, linhas, colunas);
        alocarMatriz(&matrizSolucao, linhas, colunas);

        inicializarMatrizSolucao(matrizSolucao, linhas, colunas);
        mostrarMatriz(matrizSolucao, linhas, colunas);

        preencherMatrizLabirinto(arq, matrizLabirinto, linhas, colunas);
        mostrarMatrizLabirinto(matrizLabirinto, linhas, colunas);

        desalocarMatriz(matrizLabirinto, linhas);
        desalocarMatriz(matrizSolucao, linhas);
    }
    
    printf("Teste\n");
}