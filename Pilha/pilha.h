#ifndef PILHA_H
#define PILHA_H

typedef struct no
{
    int elemento;
    struct no *prox;
}No;

typedef struct pilha{
    No *topo;
    int max;
    int tamanho;
}Pilha;

void criaPilha(Pilha *pilha, int tamanhoMax);
void empilha(Pilha *pilha, int elemento);
void desempilha(Pilha *pilha, int* elemento);
int tamanhoDaPilha(Pilha* pilha);
void imprime(Pilha* pilha);

#endif