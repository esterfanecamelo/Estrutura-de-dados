#include <stdio.h>
#include "dicionario.h"

int main() {
    TipoDicionario dicionario;
    TipoRegistro registro;

    CriaDicionario(&dicionario);

    int chaves[] = {50, 30, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        registro.chave = chaves[i];
        InsereNoDicionario(&dicionario, registro);
    }

    printf("Dicionario apos insercoes:\n");
    ImprimeDicionario(dicionario.raiz);
    printf("\nTamanho: %d\n", dicionario.tamanho);

    RetiraDoDicionario(&dicionario, 30);
    printf("\nDicionario apos remover chave 30:\n");
    ImprimeDicionario(dicionario.raiz);
    printf("\nTamanho: %d\n", dicionario.tamanho);

    RetiraDoDicionario(&dicionario, 50);
    printf("\nDicionario apos remover chave 50:\n");
    ImprimeDicionario(dicionario.raiz);
    printf("\nTamanho: %d\n", dicionario.tamanho);

    return 0;
}
