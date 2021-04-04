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
        Matriz matriz;
        int chave;
        matriz.qntMovimento = 0;
        fscanf(arq, "%d %d %d ", &matriz.linhas, &matriz.colunas, &matriz.chave);
        printf("%d %d %d",matriz.linhas,matriz.colunas,matriz.chave);
        
        alocarMatriz(&matriz.labirinto, matriz);
        alocarMatriz(&matriz.solucao, matriz);
        
        preencherMatrizSolucao(matriz);
        // mostrarMatriz(matriz, matriz.solucao);

        preencherMatrizLabirinto(arq, matriz);
        mostrarMatriz(matriz, matriz.labirinto);

        encontrarCaminho(&matriz, 0, 0);

        mostrarCaminhoColorido(matriz, matriz.solucao);
        printf("Quantidade movimentos: %d", matriz.qntMovimento);

        // mostrarMatriz(matriz, matriz.labirinto);


        desalocarMatriz(matriz.labirinto, matriz.linhas);
        desalocarMatriz(matriz.solucao, matriz.linhas);
    }
    
    printf("Teste\n");
}