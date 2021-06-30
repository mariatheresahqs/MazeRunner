#include "Menu.h"

void opcoes(int* opcao) {
    int valor;
    printf(BLU "============================================\n");
    printf("|Opções do Programa:                       |\n");
    printf("|1 - Carregar novo arquivo de dados.       |\n");
    printf("|2 - Sair do programa.                     |\n");
    printf(BLU "============================================\n");
    
    printf(GRN "Ecolha uma opção: ");
    scanf("%d", &valor); 
    *opcao = valor;
    printf(BLU "==========================================\n");
    system("@cls||clear");
}

void opcoes2(int* opcao){
    int opcao2;
    printf(BLU "==================================================\n");
    printf("|Opções do Programa para a utilização do arquivo:|\n");
    printf("|1 - Mostrar resultados.                         |\n");
    printf("|2 - Voltar menu anterior.                       |\n");
    printf(BLU "==================================================\n");

    printf(GRN "Ecolha uma opção: ");
    scanf("%d", &opcao2);
    printf(BLU "==============================================\n");
    *opcao = opcao2;
    system("@cls||clear");

}

void menu(){
    system("@cls||clear");
    char nomeArq[25];
    FILE *arq;

    Matriz matriz;
    Pilha* pilha;

    int escolha = 0;
    int opcao2 = 0;
    
    printf(RED "\nPROGRAMA LABIRINTO: OPÇÕES DO PROGRAMA\n");

    while (escolha != 2) {
        opcoes(&escolha);

        if (escolha == 1) {
            printf(RESET"Entre com o nome do arquivo: ");
            scanf("%s", nomeArq);
            arq = fopen (nomeArq, "r");
            if (arq == NULL) {
                printf("Erro na leitura do arquivo!\n");
                printf("Tente inserir outro nome ou corrigir o que foi inserido.\n");
            } else {
                printf("\nARQUIVO INSERIDO COM SUCCESSO!! \n");
                int chave;
                matriz.qntMovimento = 0;

                fscanf(arq, "%d %d %d ", &matriz.linhas, &matriz.colunas, &matriz.chave);
               
                alocarMatriz(&matriz.labirinto, matriz);
                alocarMatriz(&matriz.solucao, matriz);
                alocarPilha(&pilha);

                preencherMatrizSolucao(matriz);
                preencherMatrizLabirinto(arq, matriz);

                system("@cls||clear");
                opcao2 = 0;
                while (opcao2 != 2) {
                    opcoes2(&opcao2);
                    if(opcao2 == 1){
                        printf(RESET"Labirinto inserido: ");
                        mostrarMatriz(matriz, matriz.labirinto);
                        posicaoEstudanteInicial(matriz, &matriz.linhaInicial, &matriz.colunaInicial);
                        if(movimenta_estudante(&matriz, &pilha, matriz.linhaInicial, matriz.colunaInicial) == 0){
                            printf("\nO estudante se movimentou %d vezes e concluiu que o labirinto não possui saída.\n",matriz.qntMovimento);
                        }else{
                            posicaoEstudanteFinal(matriz, &matriz.colunaFinal);

                            printf(RESET"\nSaída do labirinto inserido: ");
                            mostrarCaminhoColorido(matriz, matriz.solucao);

                            printf("\nO estudante se movimentou %d vezes e chegou na coluna %d da primeira linha.\n",matriz.qntMovimento, matriz.colunaFinal+1);

                            // Impressão do percurso de sucesso 
                            printf("\nCaminho percorrido pelo estudante até a saída: ");
                            printf("\nLinha: %d Coluna: %d\n", matriz.linhaInicial, matriz.colunaInicial);
                            mostrarPilha(pilha);
                            printf("Linha: 0 Coluna: %d\n", matriz.colunaFinal);
                            printf("\nO estudante se movimentou %d vezes no caminho bem sucedido.\n\n", pilha->tamanho);
                            liberarPilha(&(*pilha));
                            matriz.colunaFinal = 0;
                            desalocarMatriz(matriz.labirinto, matriz.linhas);
                            desalocarMatriz(matriz.solucao, matriz.linhas); 
                        }
                        opcao2 = 2;
                    }

                }
            }
            
        }

    }
    printf(RED"Programa encerrado!\n\n");
}