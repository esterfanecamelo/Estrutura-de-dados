#ifndef HEAP_H
#define HEAP_H

#define MAXTAM 20

typedef int TipoIndice;
typedef long TipoChave;

typedef struct TipoItem {
    TipoChave Chave;
} TipoItem;

typedef TipoItem TipoVetor[MAXTAM + 1];

extern long comparacoes;

void DesceEsqNoHeap(TipoIndice Esq, TipoIndice Dir, TipoItem *A);
void Constroi(TipoItem *A, TipoIndice n);
void Heapsort(TipoItem *A, TipoIndice n);

#endif
