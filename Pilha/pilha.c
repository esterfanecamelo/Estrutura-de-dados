#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

void criaPilha(Pilha *pilha, int tamanhoMax){
    pilha->max = tamanhoMax;
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

void empilha(Pilha *pilha, int elemento){
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->elemento = elemento;
    novoNo->prox = pilha->topo;
    pilha->topo = novoNo;
    pilha->tamanho++;
}

void desempilha(Pilha *pilha, int* elemento){
    if(pilha->topo == NULL){
        printf("pilha vazia!");
    }
    No *remover = pilha->topo;
    *elemento = remover->elemento;
    pilha->topo = remover->prox;
    free(remover);
    pilha->tamanho--;
}

int tamanhoDaPilha(Pilha* pilha){
    return pilha->tamanho;
}

void imprimeTopo(Pilha* pilha){
    printf("TOPO: %d\n", pilha->topo->elemento);
}

void imprimePilha(Pilha* pilha){
    No* atual = pilha->topo;
    
    printf("Pilha completa:\n");
    while (atual != NULL)
    {
        printf("%d ", atual->elemento);
        atual = atual->prox;
    }
    printf("\n");
}

