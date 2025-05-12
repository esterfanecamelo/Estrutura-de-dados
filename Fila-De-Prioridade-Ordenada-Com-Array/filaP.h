#ifndef FILAP_H
#define FILAP_H

#define MAX 10

typedef struct registro
{
    int chave;
}Registro;

typedef struct fila Fila;

Fila* criaFila(void);
int tamanhoDaFila(Fila *fila);
void imprimeFila(Fila *fila);
void insereNaFila(Registro *registro, Fila *fila);
void retiraMaxDaFila(Registro *registro, Fila *fila);

#endif