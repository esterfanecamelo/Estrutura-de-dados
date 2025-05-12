#include "filaP.h"
#include <stdio.h>
#include <stdlib.h>

// fila de prioridade ordenada com encadeada e celula cabeca

typedef struct no
{
    Registro registro;
    struct no *prox;
}No;

typedef struct fila {
    No* cabeca;
    int tamanho;
}Fila;

Fila* criaFila(void){
    Fila* fila = (Fila*)malloc(sizeof(Fila));

    if(!fila){
        printf("Erro ao alocar memória");
        //exit();
    }

    fila->tamanho = 0;

    fila->cabeca = (No*)malloc(sizeof(No));

    if(!fila->cabeca){
        printf("erro ao alocar memoria");
    }

    fila->cabeca->prox = NULL;

    return fila;
}

int tamanhoDaFila(Fila *fila){
    if(fila->tamanho == 0){
        printf("fila vazia!");
        return 0;
    }
    return fila->tamanho;
}

void imprimeFila(Fila *fila){
    No* atual = fila->cabeca->prox;
    while(atual != NULL){
        printf("%d ", atual->registro.chave);
        atual = atual->prox;
    }
    printf("\n");
}

void insereNaFila(Registro *registro, Fila *fila){
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        printf("Erro ao alocar memória\n");
        return;
    }

    novo->registro = *registro;
    novo->prox = NULL;

    No* anterior = fila->cabeca;
    No* atual = fila->cabeca->prox;

    // Procurar o ponto certo para inserir em ordem decrescente
    while (atual != NULL && atual->registro.chave > registro->chave) {
        anterior = atual;
        atual = atual->prox;
    }

    // Inserção entre anterior e atual
    novo->prox = atual;
    anterior->prox = novo;

    fila->tamanho++;
}

void retiraMaxDaFila(Registro *registro, Fila *fila){
    if(fila->tamanho == 0){
        printf("Fila vazia!\n");
        return;
    }

    No* max = fila->cabeca->prox;
    fila->cabeca->prox = max->prox;

    *registro = max->registro;
    free(max);
    fila->tamanho--;
}