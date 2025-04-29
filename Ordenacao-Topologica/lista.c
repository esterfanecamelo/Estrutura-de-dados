#include "lista.h"

void fazListaVazia(Tipolista *lista) {
    lista->tamanho = 0;
}

int tamanhoLista(Tipolista *lista) {
    return lista->tamanho;
}

int inserirNaLista(Tipolista *lista, Tipochave chave) {
    if (lista->tamanho >= MAX) {
        return 0; 
    }
    lista->elementos[lista->tamanho++] = chave;
    return 1;
}

int removerNalista(Tipolista *lista, Tipochave chave) {
    int i;
    for (i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] == chave) {
            for (int j = i; j < lista->tamanho - 1; j++) {
                lista->elementos[j] = lista->elementos[j + 1];
            }
            lista->tamanho--;
            return 1;
        }
    }
    return 0;
}

int removerPrimeiroDaLista(Tipolista *lista, Tipochave *chave) {
    if (lista->tamanho == 0) {
        return 0; 
    }
    *chave = lista->elementos[0];
    for (int i = 0; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }
    lista->tamanho--;
    return 1;
}
