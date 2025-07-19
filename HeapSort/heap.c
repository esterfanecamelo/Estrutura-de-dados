#include "heap.h"

long comparacoes = 0;

void DesceEsqNoHeap(TipoIndice Esq, TipoIndice Dir, TipoItem *A) {
    TipoIndice i = Esq;
    int j;
    TipoItem x = A[i];
    j = i * 2;

    while (j <= Dir) {
        if (j < Dir) {
            comparacoes++;
            if (A[j].Chave < A[j + 1].Chave) {
                j++;
            }
        }
        comparacoes++;
        if (x.Chave >= A[j].Chave) {
            break;
        }
        A[i] = A[j];
        i = j;
        j = i * 2;
    }
    A[i] = x;
}

void Constroi(TipoItem *A, TipoIndice n) {
    TipoIndice Esq = n / 2 + 1;
    while (Esq > 1) {
        Esq--;
        DesceEsqNoHeap(Esq, n, A);
    }
}

void Heapsort(TipoItem *A, TipoIndice n) {
    TipoIndice Esq, Dir;
    TipoItem x;

    Constroi(A, n);
    Esq = 1;
    Dir = n;

    while (Dir > 1) {
        x = A[1];
        A[1] = A[Dir];
        A[Dir] = x;
        Dir--;
        DesceEsqNoHeap(Esq, Dir, A);
    }
}
