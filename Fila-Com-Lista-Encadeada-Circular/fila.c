#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void fazFilaVazia(Fila *fila) {
    fila->cabeca = (Celula *)malloc(sizeof(Celula));
    fila->cabeca->prox = fila->cabeca;
}

int tamanhoDaFila(Fila *fila) {
    int count = 0;
    Celula *atual = fila->cabeca->prox;
    while (atual != fila->cabeca) {
        count++;
        atual = atual->prox;
    }
    return count;
}

void imprimeFila(Fila *fila) {
    Celula *atual = fila->cabeca->prox;
    while (atual != fila->cabeca) {
        printf("%d ", atual->registro);
        atual = atual->prox;
    }
    printf("\n");
}

void enfileira(Fila *fila, TipoRegistro *registro) {
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->registro = *registro;

    Celula *atual = fila->cabeca;
    while (atual->prox != fila->cabeca) {
        atual = atual->prox;
    }

    atual->prox = nova;
    nova->prox = fila->cabeca;
}

void desenfileira(Fila *fila, TipoRegistro *registro) {
    if (fila->cabeca->prox == fila->cabeca) {
        printf("Fila vazia\n");
        return;
    }

    Celula *primeira = fila->cabeca->prox;
    *registro = primeira->registro;
    fila->cabeca->prox = primeira->prox;
    free(primeira);
}
