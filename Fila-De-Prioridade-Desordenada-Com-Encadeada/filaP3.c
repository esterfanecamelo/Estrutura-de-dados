#include "filaP.h"
#include <stdio.h>
#include <stdlib.h>

// fila de prioridade desordenada com encadeada e celula cabeca

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
    No* no = (No*)malloc(sizeof(No));
    if (!no) {
        printf("Erro ao alocar memória para novo nó\n");
        return;
    }

    no->registro = *registro;
    no->prox = NULL;

    No* atual = fila->cabeca;
    while(atual->prox != NULL){
        atual = atual->prox;
    }

    atual->prox = no;
    fila->tamanho++;

}

void retiraMaxDaFila(Registro *registro, Fila *fila){
    if(fila->tamanho == 0){
        printf("Fila vazia!\n");
        return;
    }

    No* anterior = fila->cabeca;
    No* atual = fila->cabeca->prox;

    No* anteriorMax = anterior;
    No* max = atual;

    while(atual != NULL){
        if(atual->registro.chave > max->registro.chave){
            max = atual;
            anteriorMax = anterior;
        }
        anterior = atual;
        atual = atual->prox;
    }

    // Copia o valor removido
    *registro = max->registro;

    // Remove o nó da lista
    anteriorMax->prox = max->prox;
    free(max);
    fila->tamanho--;
}
