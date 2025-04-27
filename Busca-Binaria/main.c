#include "busca.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_ARRAY 100
#define NUMERO_TESTES 50   

int main(){

    printf("--------------- BUSCA BINARIA ------------------\n");

    int array[TAMANHO_ARRAY];
    int comparacoesTotal = 0, comparacoes;
    int i, elemento;
    double mediaComparacoes;

    for (i = 0; i < TAMANHO_ARRAY; i++)
    {
        array[i] = i + 1;
    }

    srand(time(NULL));

    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("%d - ", array[i]);
    }
    printf("\n");

    for (i = 0; i < NUMERO_TESTES; i++)
    {
        elemento = rand() % TAMANHO_ARRAY + 1;

        comparacoes = 0;

        printf("Elemento para busca: %d\n", elemento);

        buscaBinaria(array, TAMANHO_ARRAY, elemento, &comparacoes);

        comparacoesTotal += comparacoes;
    }

    printf("Comparacoes totais pela Busca Binaria: %d\n\n", comparacoesTotal);

    mediaComparacoes = (double)comparacoesTotal / NUMERO_TESTES;

    printf("Media de comparacoes pela Busca Binaria: %.2f\n\n", mediaComparacoes);

    printf("---------------- Selection Sort----------------\n\n");

    comparacoes = 0;
    
    algoritmoSelectionSort(array,TAMANHO_ARRAY, &comparacoes);

    printf("Comparacoes para ordenar o array: %d\n", comparacoes);

    return 0;
}