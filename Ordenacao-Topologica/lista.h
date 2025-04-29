#ifndef LISTA_H
#define LISTA_H
#define MAX 100

typedef int Tipochave;

typedef struct tipolista {
    Tipochave elementos[MAX];
    int tamanho;
} Tipolista;

void fazListaVazia(Tipolista *lista);
int inserirNaLista(Tipolista *lista, Tipochave chave);
int removerNalista(Tipolista *lista, Tipochave chave);
int tamanhoLista(Tipolista *lista);
int removerPrimeiroDaLista(Tipolista *lista, Tipochave *chave);

#endif

