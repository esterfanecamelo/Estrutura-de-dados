#ifndef CONJUNTO_H

#include <stdbool.h>

#define CONJUNTO_H
#define MAX_SIZE 100

typedef struct {
    int elementos[MAX_SIZE];
    int tamanho;
} Conjunto;

void imprimeConjunto(Conjunto conjunto);
void fazConjuntoVazio(Conjunto *conjunto);
bool insere(int i, Conjunto *conjunto);
int pertenceAoConjunto(int elemento, Conjunto conjunto);
int retiraDoConjunto(int elemento, Conjunto *conjunto);
int maxDoConjunto(int *elemMax, Conjunto conjunto);
int maxMinDoConjunto(int *elemMax, int *elemMin, Conjunto conjunto);
int maxMinDoConjunto2(int *elemMax, int *elemMin, Conjunto conjunto);

#endif