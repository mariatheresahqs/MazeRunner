#include "Matriz.h"


void alocarMatriz(char ***matrizTAD, Matriz matriz){
    *matrizTAD = (char**)malloc(matriz.linhas*(sizeof(char*))); // Alocando linhas do tipo ponteiro

    for(int i=0; i<matriz.linhas; i++){
        (*matrizTAD)[i] = (char*)malloc(matriz.colunas*(sizeof(char))); // Alocando colunas do tipo inteiro
    }
}

//Preenchendo a matriz solução
void preencherMatrizSolucao(Matriz matrizSolucao){
    for(int i=0; i<matrizSolucao.linhas;i++){
        for(int j=0;j<matrizSolucao.colunas;j++){
            matrizSolucao.solucao[i][j] = '0';
        }
    }
}

//Preenchendo a matriz Labirinto. Aqui são usados os dados do arquivo.
void preencherMatrizLabirinto(FILE *arq, Matriz labirinto){
        for(int i=0;i<labirinto.linhas;i++){
            for(int j=0;j<labirinto.colunas;j++){
                labirinto.labirinto[i][j] = fgetc(arq);
            }
            fgetc(arq);
        }
}

//Liberando a matriz
void desalocarMatriz(char **matriz, int linhas) {
  for (int i = 0; i < linhas; i++) {
    free(matriz[i]);
  }
  free(matriz);
}

//
void mostrarMatriz(Matriz matriz, char **matrizEscolhida){
    printf("\n");
    for(int i =0; i<matriz.linhas; i++){
        for(int j=0; j<matriz.colunas;j++){
            printf("%c", matrizEscolhida[i][j]);
        }
        printf("\n");
    }
}

//mostra a solução colorida
void mostrarCaminhoColorido(Matriz matriz, char **matrizEscolhida){
    printf("\n");
    for(int i =0; i<matriz.linhas; i++){
        for(int j=0; j<matriz.colunas;j++){
            if (matrizEscolhida[i][j] == '0'){ // se for 0, colocar amarelo
                printf(YEL "%c", matrizEscolhida[i][j]);
                printf(RESET);
            }else if(matrizEscolhida[i][j] == 'S'){ // se for a posição do aluno, colocar vermelho            
                printf(RED "%c", matrizEscolhida[i][j]);
                printf(RESET);
            }else{ // se for o caminho feito pelo aluno, colocar verde
                printf(GRN "%c", matrizEscolhida[i][j]);
                printf(RESET);
            }
        }
        printf("\n");
    }
}

void posicaoEstudanteInicial(Matriz matriz, int *linha, int *coluna){
    for(int i =0; i<matriz.linhas; i++){
        for(int j=0; j<matriz.colunas;j++){
            if(matriz.labirinto[i][j]=='0'){
                *linha = i;
                *coluna = j;
            }
        }
    }
}

void posicaoEstudanteFinal(Matriz matriz, int *coluna){
    for(int i =0; i<matriz.colunas; i++){
        if(matriz.labirinto[0][i]=='0'){
            *coluna = i;
        }
    }
}


int movimenta_estudante(Matriz *matriz, Pilha** pilha, int linha, int coluna){ 

    if(MODOANALISE ==1){
        char teste;
        mostrarCaminhoColorido(*matriz, matriz->solucao);
        printf("Linha: %d Coluna: %d Quantidade movimentos: %d", linha+1, coluna+1, matriz->qntMovimento);
        scanf("%c", &teste); // Comente o comando caso queira observar o caminho em detalhes, a cada passo 
    }
    
    // checa se a posicao pode ser visitada ou nao
    // os  indices da matriz devem estar entre (0,linhas-1) e (0,colunas-1) 
    // a solucao[linha][coluna] != 0 serve para  garantir que essa posicao ja foi visitada
    // labirinto[linha][coluna] == 2 serve para garantir que posicao é uma parede
    // estudante encontrou uma porta e não possui chave para abri-la
    if(linha<0 || 
       coluna<0 ||
       linha>=matriz->linhas ||
       coluna>=matriz->colunas || 
       matriz->solucao[linha][coluna] != '0' ||
       matriz->labirinto[linha][coluna] == '2' ||
       (matriz->labirinto[linha][coluna] =='3' && matriz->chave == 0))
    {
        return 0;
    }else if(linha == 0){
        matriz->colunaFinal = coluna;
        matriz->solucao[linha][coluna] = 'S';
        inserirPilha(&(*pilha), linha, coluna);
        return 1;
    }
    // labirinto[linha][coluna] == 3 e chave == 1 garantem que o estudante pegue um atalho pela porta
    if(matriz->chave >= 1 && matriz->labirinto[linha][coluna] =='3'){
        matriz->solucao[linha][coluna] = 'P';
        matriz->chave --;
    }

    // caso nao encontre saida pela porta ou normal o estudante precisa continuar
    // percorrendo o labirinto ate esgotar todas as opcoes de percurso
    // prioridade de movimento: descer, direita, subir, esquerda
    // subir 
    matriz->solucao[linha][coluna] = '^';
    matriz->qntMovimento++;
    if(movimenta_estudante(matriz, pilha, linha-1, coluna)){
        inserirPilha(&(*pilha), linha-1, coluna);
        return 1;
    }
    // esquerda
    matriz->qntMovimento++;
    matriz->solucao[linha][coluna] = '<';
    if(movimenta_estudante(matriz, pilha, linha, coluna-1)){
        inserirPilha(&(*pilha), linha, coluna-1);
        return 1;
    }
    // direita 
    matriz->solucao[linha][coluna] = '>';
    matriz->qntMovimento++;
    if(movimenta_estudante(matriz, pilha, linha, coluna+1)){
        inserirPilha(&(*pilha), linha, coluna+1);
        return 1;
    }
    // descer 
    matriz->solucao[linha][coluna] = 'V';
    matriz->qntMovimento++;
    if(movimenta_estudante(matriz, pilha, linha+1, coluna)){
        inserirPilha(&(*pilha), linha+1, coluna);
        return 1;
    }
    // labirinto[linha][coluna] == 3 o estudante recupera a chave que usou na linha 121
    if(matriz->labirinto[linha][coluna] =='3'){
        matriz->chave ++;
    }
    // caso nao seja mais possivel andar pela matriz
    matriz -> solucao[linha][coluna] = '0';
    return 0;
}
