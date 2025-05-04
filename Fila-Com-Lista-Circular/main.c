#include "fila.h"
#include <stdio.h>

void main(){

    Fila fila;
    TipoRegistro registro;

    fazFilaVazia(&fila);

    registro = 1;
    while(registro <= MAX){
        enfileira(&fila, &registro);
        registro++;
    }

    imprimeFila(&fila);

    while(!fila.tamanho == 0){
        desenfileira(&fila, &registro);
        printf("\nRegistro retirado: %d\n", registro);
        imprimeFila(&fila);
    }

}