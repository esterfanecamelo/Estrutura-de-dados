#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>


void imprimePorOrdemDeInsercao(Pilha *pilha){
    printf("Imprimindo por ordem de insercao:\n");

    int elemento;
    Pilha *pilhaInversa = (Pilha*)malloc(sizeof(Pilha));

    criaPilha(pilhaInversa, 10);

    while(pilha->topo != NULL){
        desempilha(pilha, &elemento);
        empilha(pilhaInversa, elemento);
    }

    imprimePilha(pilhaInversa);
}

void main(){
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    int elemento;

    criaPilha(pilha, 10);

    empilha(pilha, 10);
    empilha(pilha, 20);
    empilha(pilha, 50);
    empilha(pilha, 2);

    imprimePilha(pilha);
    imprimeTopo(pilha);

    desempilha(pilha, &elemento);

    imprimePilha(pilha);
    imprimeTopo(pilha);

    imprimePorOrdemDeInsercao(pilha);
}