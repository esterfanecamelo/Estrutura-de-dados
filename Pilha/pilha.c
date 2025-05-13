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

}

int tamanhoDaPilha(Pilha* pilha){
    return pilha->tamanho;
}

void imprimeTopo(Pilha* pilha){
    printf("%d", pilha->topo->elemento);
}