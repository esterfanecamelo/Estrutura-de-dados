#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "heap.h"

void PreencheCrescente(TipoItem *A, int n)
{
    for (int i = 1; i <= n; i++)
    {
        A[i].Chave = i;
    }
}

void PreencheDecrescente(TipoItem *A, int n)
{
    for (int i = 1; i <= n; i++)
    {
        A[i].Chave = n - i + 1;
    }
}

void PreencheAleatorio(TipoItem *A, int n)
{
    for (int i = 1; i <= n; i++)
    {
        A[i].Chave = rand() % 100;
    }
}

void ImprimeHeapComoArvore(TipoItem *A, int n)
{
    int nivel = 0;
    int index = 1;
    int elementosNivel = 1;

    printf("\nRepresentacao do Heap como árvore (formato hierárquico):\n\n");

    while (index <= n)
    {
        // Espaçamento inicial para o nível
        int espacos = (1 << (5 - nivel)); // ajusta largura da indentação (5 é a altura máxima para 31 elementos)
        for (int i = 0; i < espacos; i++)
        {
            printf("  ");
        }

        // Imprime todos os elementos do nível atual
        for (int i = 0; i < elementosNivel && index <= n; i++)
        {
            printf("%5ld", A[index++].Chave);

            // Espaço entre os elementos do mesmo nível
            for (int s = 0; s < espacos * 2 - 1; s++)
            {
                printf("  ");
            }
        }

        printf("\n\n"); // nova linha entre os níveis
        nivel++;
        elementosNivel *= 2;
    }
}

int main()
{
    TipoVetor A;
    srand(time(NULL));
    long comparacoesCresc, comparacoesDesc, comparacoesAlea;

    // 1. Crescente
    PreencheCrescente(A, MAXTAM);
    comparacoes = 0;
    Heapsort(A, MAXTAM);
    comparacoesCresc = comparacoes;
    ImprimeHeapComoArvore(A, 15); // Exibe 31 primeiros itens

    // 2. Decrescente
    PreencheDecrescente(A, MAXTAM);
    comparacoes = 0;
    Heapsort(A, MAXTAM);
    comparacoesDesc = comparacoes;
    ImprimeHeapComoArvore(A, 15);

    // 3. Aleatório
    PreencheAleatorio(A, MAXTAM);
    comparacoes = 0;
    Heapsort(A, MAXTAM);
    comparacoesAlea = comparacoes;
    ImprimeHeapComoArvore(A, 15);

    // Resultado final
    printf("Heapsort com array de 10000 itens ordenados fez %ld comparacoes de chave\n", comparacoesCresc);
    printf("Heapsort com array de 10000 itens ordenados inversamente fez %ld comparacoes de chave\n", comparacoesDesc);
    printf("Heapsort com array de 10000 itens aleatórios fez %ld comparacoes de chave\n", comparacoesAlea);

    return 0;
}
