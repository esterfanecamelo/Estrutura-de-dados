#ifndef FILA_H
#define FILA_H

typedef int TipoRegistro;

typedef struct celula
{
    TipoRegistro registro;
    struct celula *prox;

} Celula;

typedef struct fila
{
    Celula *cabeca;
} Fila;

void fazFilaVazia(Fila *fila);
int tamanhoDaFila(Fila *fila);
void imprimeFila(Fila *fila);
void enfileira(Fila *fila, TipoRegistro *registro);
void desenfileira(Fila *fila, TipoRegistro *registro);

#endif