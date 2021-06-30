#include "Pilha.h"

void alocarPilha(Pilha** pilha){
    *pilha = (Pilha*)malloc(sizeof(Pilha));
    (*pilha)->tamanho = 0;
    (*pilha)->proxPosicao = NULL;
}

void liberarPilha(Pilha* pilha){
    if(pilha!=NULL){
        free(pilha);
    }
}

int pilhaVazia(Pilha** pilha){
    if(pilha == NULL)
        return 1;
    if(*pilha == NULL)
        return 1;
    return 0;
}

int inserirPilha(Pilha** pilha, int linha, int coluna){
    if(pilha == NULL)
        return 0;
    Pilha* no = (Pilha*)malloc(sizeof(Pilha));
    if(no == NULL)
        return 0;
    no->posicaoMatriz.coluna = coluna;
    no->posicaoMatriz.linha = linha;
    no->proxPosicao = (*pilha);
    no->tamanho = (*pilha)->tamanho;

    *pilha = no;
    (*pilha)->tamanho ++;
    
    return 1;
}

int removerPilha(Pilha** pilha){
    if(pilhaVazia(&(*pilha))){
        return 0;
    }
    Pilha* no = (*pilha);
    (*pilha) = no->proxPosicao;
    free(no);
    return 1;
}

void mostrarPilha(Pilha* pilha){
    Pilha *no = pilha->proxPosicao;
    printf("Linha: %d Coluna: %d\n", pilha->posicaoMatriz.linha, pilha->posicaoMatriz.coluna);
    while (no != NULL) {
        if(no->posicaoMatriz.linha != 0){
            printf("Linha: %d Coluna: %d\n", no->posicaoMatriz.linha, no->posicaoMatriz.coluna);
        }
        no = no->proxPosicao;
    }
}

