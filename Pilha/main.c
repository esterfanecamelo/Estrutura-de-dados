#include "pilha.h"
#include <stdlib.h>

void main(){
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    int elemento;

    criaPilha(pilha, 10);

    empilha(pilha, 10);
    empilha(pilha, 20);
    empilha(pilha, 50);

    imprimeTopo(pilha);

}