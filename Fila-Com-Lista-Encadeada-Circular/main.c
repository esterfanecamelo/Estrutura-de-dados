#include "fila.h"
#include <stdio.h>

int main() {
    Fila fila;
    TipoRegistro r;

    fazFilaVazia(&fila);

    for (int i = 1; i <= 5; i++) {
        enfileira(&fila, &i);
    }

    printf("Fila apos insercoes:\n");
    imprimeFila(&fila);

    desenfileira(&fila, &r);
    printf("Valor desenfileirado: %d\n", r);

    printf("Fila apos remocao:\n");
    imprimeFila(&fila);

    desenfileira(&fila, &r);
    printf("Valor desenfileirado: %d\n", r);

    printf("Fila apos remocao:\n");
    imprimeFila(&fila);


    return 0;
}
