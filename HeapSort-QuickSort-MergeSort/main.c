#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

void executar_testes(int tipo_entrada, const char *nome_tipo) {
    int tamanhos[] = {50, 100, 500, 1000, 5000, 10000, 30000};
    long comparacoes[3][7] = {0};
    long movimentacoes[3][7] = {0};

    printf("\n=============================\n");
    printf("Tipo de entrada: %s\n", nome_tipo);
    printf("=============================\n");

    for (int t = 0; t < 7; t++) {
        int n = tamanhos[t];
        int *original = malloc(n * sizeof(int));
        gerar_array(original, n, tipo_entrada);

        int *copia = malloc(n * sizeof(int));
        Contador c;

        // Heapsort
        copiar_array(original, copia, n);
        c.comparacoes = c.movimentacoes = 0;
        heapsort(copia, n, &c);
        comparacoes[0][t] = c.comparacoes;
        movimentacoes[0][t] = c.movimentacoes;

        // Quicksort
        copiar_array(original, copia, n);
        c.comparacoes = c.movimentacoes = 0;
        quicksort(copia, 0, n - 1, &c);
        comparacoes[1][t] = c.comparacoes;
        movimentacoes[1][t] = c.movimentacoes;

        // Mergesort
        copiar_array(original, copia, n);
        c.comparacoes = c.movimentacoes = 0;
        mergesort(copia, 0, n - 1, &c);
        comparacoes[2][t] = c.comparacoes;
        movimentacoes[2][t] = c.movimentacoes;

        free(original);
        free(copia);
    }

    const char *titulosComp[] = {
        "1.a. Comparacoes (Array Aleatorio)",
        "2.a. Comparacoes (Array Crescente)",
        "3.a. Comparacoes (Array Decrescente)"
    };

    const char *titulosMov[] = {
        "1.b. Movimentacoes (Array Aleatorio)",
        "2.b. Movimentacoes (Array Crescente)",
        "3.b. Movimentacoes (Array Decrescente)"
    };

    imprimir_tabela(titulosComp[tipo_entrada], comparacoes);
    imprimir_tabela(titulosMov[tipo_entrada], movimentacoes);
}

int main() {
    srand(time(NULL));

    executar_testes(0, "Aleatorio");
    executar_testes(1, "Crescente");
    executar_testes(2, "Decrescente");

    return 0;
}
