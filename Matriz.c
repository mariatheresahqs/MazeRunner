#include "Matriz.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define RESET "\x1B[0m"


void alocarMatriz(char ***matrizTAD, Matriz matriz){
    *matrizTAD = (char**)malloc(matriz.linhas*(sizeof(char*))); // Alocando linhas do tipo ponteiro

    for(int i=0; i<matriz.linhas; i++){
        (*matrizTAD)[i] = (char*)malloc(matriz.colunas*(sizeof(char))); // Alocando colunas do tipo inteiro
    }
}

void preencherMatrizSolucao(Matriz matrizSolucao){
    for(int i=0; i<matrizSolucao.linhas;i++){
        for(int j=0;j<matrizSolucao.colunas;j++){
            matrizSolucao.solucao[i][j] = '0';
        }
    }
}

void preencherMatrizLabirinto(FILE *arq, Matriz labirinto){

        for(int i=0;i<labirinto.linhas;i++){
            for(int j=0;j<labirinto.colunas;j++){
                labirinto.labirinto[i][j] = fgetc(arq);
            }
            fgetc(arq);
        }
}

// void inicializarMatrizSolucao(Matriz matriz, char ***matrizSolucao){
//     printf("aqui\n");
//     alocarMatriz(matrizSolucao, matriz);
//     printf("ali\n");
//     preencherMatrizSolucao(matriz);
// }

void desalocarMatriz(char **matriz, int linhas) {
  for (int i = 0; i < linhas; i++) {
    free(matriz[i]);
  }
  free(matriz);
}

void mostrarMatriz(Matriz matriz, char **matrizEscolhida){
    printf("\n");
    for(int i =0; i<matriz.linhas; i++){
        for(int j=0; j<matriz.colunas;j++){
            printf("%c", matrizEscolhida[i][j]);
        }
        printf("\n");
    }
}

void mostrarCaminhoColorido(Matriz matriz, char **matrizEscolhida){
    printf("\n");
    for(int i =0; i<matriz.linhas; i++){
        for(int j=0; j<matriz.colunas;j++){
            if (matrizEscolhida[i][j] == '0')
            {
                printf(YEL "%c", matrizEscolhida[i][j]);
                printf(RESET);
            }else if(matrizEscolhida[i][j] == 'S'){            
                printf(RED "%c", matrizEscolhida[i][j]);
                printf(RESET);
            }else{
                printf(GRN "%c", matrizEscolhida[i][j]);
                printf(RESET);
            }
        }
        printf("\n");
    }
}

char encontrarCaminho(Matriz *matriz, int linha, int coluna){ 
    // char teste;
    // mostrarCaminhoColorido(*matriz, matriz->solucao);
    // printf("Linha: %d Coluna: %d Quantidade movimentos: %d", linha, coluna, matriz->qntMovimento);
    // scanf("%c", &teste);

    // checa se a posicao pode ser visitada ou nao
    // os  indices da matriz devem estar entre (0,linhas-1) e (0,colunas-1) 
    // a solucao[linha][coluna] != 0 serve para  garantir que essa posicao ja foi visitada
    // labirinto[linha][coluna] == 2 serve para garantir que posicao é uma parede
    if(linha<0 || 
       coluna<0 ||
       linha>=matriz->linhas ||
       coluna>=matriz->colunas || 
       matriz->solucao[linha][coluna] != '0' ||
       matriz->labirinto[linha][coluna] == '2')
    {
        return 0;
    }
    // labirinto[linha][coluna] == 3 e chave ==1 garantem a saida pela porta
    // labirinto[linha][coluna] == 0 garante que o estudante achou a saida
    if(matriz->labirinto[linha][coluna] =='3' && matriz->chave==1){
        matriz->solucao[linha][coluna] = 'P';
        return 1;
    }
    else if(matriz->labirinto[linha][coluna]=='0'){
        matriz->solucao[linha][coluna] = 'S';
        printf("encontrou a saida.\n");
        return 1;
    }

    // caso nao encontre saida pela porta ou normal o estudante precisa continuar
    // percorrendo o labirinto ate esgotar todas as opcoes de percurso
    // prioridade de movimento: descer, direita, subir, esquerda
    // descer 
    matriz->solucao[linha][coluna] = 'V';
    matriz->qntMovimento++;
    if(encontrarCaminho(matriz, linha+1, coluna))
        return 1;
    // direita 
    matriz->solucao[linha][coluna] = '>';
    matriz->qntMovimento++;
    if(encontrarCaminho(matriz, linha, coluna+1))
        return 1;
    // subir 
    matriz->solucao[linha][coluna] = '^';
    matriz->qntMovimento++;
    if(encontrarCaminho(matriz, linha-1, coluna))
        return 1;
    // esquerda
    matriz->qntMovimento++;
    matriz->solucao[linha][coluna] = '<';
    if(encontrarCaminho(matriz, linha, coluna-1))
        return 1;
    // caso nao seja mais possivel andar pela matriz
    matriz->solucao[linha][coluna] = '0';
    return 0;
}