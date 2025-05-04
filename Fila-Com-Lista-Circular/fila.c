#include "fila.h"
#include <stdio.h>

void fazFilaVazia(Fila *fila){
    fila->tamanho = 0;
    fila->primeiro = -1;
    fila->ultimo = -1;

    for(int i = 0; i < MAX; i++){
        fila->elementos[i] = 0;
    }    
}

int tamanhoDaFila(Fila *fila){
    return fila->tamanho;
}

void imprimeFila(Fila *fila){
    int posicao = fila->primeiro;
    for(int i = 0; i < fila->tamanho; i++){
        printf("%d ", fila->elementos[posicao]);
        posicao = (posicao + 1) % MAX;
    }
    printf("\n");
}

void enfileira(Fila *fila, TipoRegistro *registro){
    if(fila->tamanho >= MAX){
        printf("fila cheia");
    }else{
        if(fila->tamanho == 0){
            fila->elementos[0] = *registro;
            fila->primeiro = 0;
            fila->ultimo = 0;
            fila->tamanho++;
        }else{
            fila->elementos[(fila->ultimo + 1) % MAX] = *registro;
            fila->tamanho++;
            fila->ultimo = (fila->ultimo + 1) % MAX;
        }
    }
}

void desenfileira(Fila *fila, TipoRegistro *registro){
    if(fila->tamanho == 0){
        printf("fila vazia");
    }else{
        *registro = fila->elementos[fila->primeiro];
        fila->primeiro = (fila->primeiro + 1) % MAX;
        fila->tamanho--;
    }
}
