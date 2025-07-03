#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 30000

int comparacoes, movimentacoes;

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    movimentacoes += 3;
}

void copiarVetor(int *dest, int *src, int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

// Algoritmo de Selecao
void selecao(int *vetor, int n) {
    comparacoes = movimentacoes = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (vetor[j] < vetor[min])
                min = j;
        }
        if (i != min)
            trocar(&vetor[i], &vetor[min]);
    }
}

// Algoritmo de Insercao
void insercao(int *vetor, int n) {
    comparacoes = movimentacoes = 0;
    for (int i = 1; i < n; i++) {
        int chave = vetor[i];
        movimentacoes++; // copiar chave
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            comparacoes++;
            vetor[j + 1] = vetor[j];
            movimentacoes++;
            j--;
        }
        comparacoes++; // ultima comparacao que falha
        vetor[j + 1] = chave;
        movimentacoes++;
    }
}

// Algoritmo de Shellsort
void shellsort(int *vetor, int n) {
    comparacoes = movimentacoes = 0;
    int h;
    for (h = 1; h < n; h = 3 * h + 1);
    while (h > 1) {
        h /= 3;
        for (int i = h; i < n; i++) {
            int chave = vetor[i];
            movimentacoes++;
            int j = i;
            while (j >= h && vetor[j - h] > chave) {
                comparacoes++;
                vetor[j] = vetor[j - h];
                movimentacoes++;
                j -= h;
            }
            comparacoes++; // ultima comparacao que falha
            vetor[j] = chave;
            movimentacoes++;
        }
    }
}

void gerarAleatorio(int *vetor, int n) {
    for (int i = 0; i < n; i++) vetor[i] = rand() % (n * 10);
}

void imprimirTabelaCabecalho(const char *titulo) {
    printf("\n%s\n", titulo);
    printf("+-------------------------------------------------------------------------+\n");
    printf("| Metodo     |   50 |  100 |  500 | 1000 | 5000 |10000 |30000 |\n");
    printf("+-------------------------------------------------------------------------+\n");
}

void imprimirLinha(const char *nomeMetodo, void (*sortFunc)(int *, int), int *base, int tamanhos[], int total) {
    printf("| %-10s", nomeMetodo);
    for (int i = 0; i < total; i++) {
        int vetor[MAX];
        copiarVetor(vetor, base, tamanhos[i]);
        sortFunc(vetor, tamanhos[i]);
        printf("|%5d ", comparacoes); 
    }
    printf("|\n");
}

void parte1() {
    int tamanhos[] = {50, 100, 500, 1000, 5000, 10000, 30000};
    int total = sizeof(tamanhos) / sizeof(tamanhos[0]);
    int base[MAX];
    srand(time(NULL));
    gerarAleatorio(base, MAX);

    imprimirTabelaCabecalho("Numero de COMPARACOES de chaves dos metodos de ordenacao");
    imprimirLinha("Selecao", selecao, base, tamanhos, total);
    imprimirLinha("Insercao", insercao, base, tamanhos, total);
    imprimirLinha("Shellsort", shellsort, base, tamanhos, total);

    imprimirTabelaCabecalho("Numero de MOVIMENTACOES de chaves dos metodos de ordenacao");
    void (*funcoes[])(int *, int) = {selecao, insercao, shellsort};
    const char *nomes[] = {"Selecao", "Insercao", "Shellsort"};

    for (int m = 0; m < 3; m++) {
        printf("| %-10s", nomes[m]);
        for (int i = 0; i < total; i++) {
            int vetor[MAX];
            copiarVetor(vetor, base, tamanhos[i]);
            funcoes[m](vetor, tamanhos[i]);
            printf("|%5d ", movimentacoes);
        }
        printf("|\n");
    }

    printf("+-------------------------------------------------------------------------+\n");
}

void parte2() {
    printf("\nComparacoes Shellsort vs Insercao:\n");
    printf("+---------------------------------------------------------------+\n");
    printf("| Tamanho | Comp. Insercao | Comp. Shellsort |\n");
    printf("+---------------------------------------------------------------+\n");

    int vetor1[MAX], vetor2[MAX];
    int n;

    for (n = 1; n <= MAX; n++) {
        gerarAleatorio(vetor1, n);
        copiarVetor(vetor2, vetor1, n);

        insercao(vetor1, n);
        int compInsercao = comparacoes;
        int movInsercao = movimentacoes;

        shellsort(vetor2, n);
        int compShell = comparacoes;
        int movShell = movimentacoes;

        printf("| %7d | %14d | %15d |\n", n, compInsercao, compShell);

        if (compShell < compInsercao) break;
    }

    printf("+---------------------------------------------------------------+\n");


    printf("\nMovimentacoes Shellsort vs Insercao:\n");
    printf("+------------------------------------------------------------------+\n");
    printf("| Tamanho | Mov. Insercao   | Mov. Shellsort |\n");
    printf("+------------------------------------------------------------------+\n");

    for (int i = 1; i <= n; i++) {
        gerarAleatorio(vetor1, i);
        copiarVetor(vetor2, vetor1, i);

        insercao(vetor1, i);
        int movInsercao = movimentacoes;

        shellsort(vetor2, i);
        int movShell = movimentacoes;

        printf("| %7d | %14d | %15d |\n", i, movInsercao, movShell);

        if (movShell < movInsercao) break;
    }

    printf("+------------------------------------------------------------------+\n");
}

int main() {
    parte1();
    parte2();
    return 0;
}
