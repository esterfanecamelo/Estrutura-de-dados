#ifndef Fila_H

#define Fila_H
#define MAX 10

typedef int TipoRegistro;

typedef struct 
{ 
    int elementos[MAX];
    int tamanho;
    int primeiro;
    int ultimo;

} Fila;

void fazFilaVazia(Fila *fila);
int tamanhoDaFila(Fila *fila);
void imprimeFila(Fila *fila);
void enfileira(Fila *fila, TipoRegistro *registro);
void desenfileira(Fila *fila, TipoRegistro *registro);

#endif