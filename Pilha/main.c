#include "pilha.h"
#include <stdlib.h>

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
}