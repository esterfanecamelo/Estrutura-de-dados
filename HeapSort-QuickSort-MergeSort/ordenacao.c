#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

// Swap
void swap(int *a, int *b, Contador *c) {
    int temp = *a;
    *a = *b;
    *b = temp;
    c->movimentacoes += 3;
}

// ======== HEAPSORT =========
void heapify(int arr[], int n, int i, Contador *c) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && (++c->comparacoes && arr[esq] > arr[maior]))
        maior = esq;

    if (dir < n && (++c->comparacoes && arr[dir] > arr[maior]))
        maior = dir;

    if (maior != i) {
        swap(&arr[i], &arr[maior], c);
        heapify(arr, n, maior, c);
    }
}

void heapsort(int arr[], int n, Contador *c) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, c);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i], c);
        heapify(arr, i, 0, c);
    }
}

// ======== QUICKSORT =========
int partition(int arr[], int low, int high, Contador *c) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        c->comparacoes++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j], c);
        }
    }
    swap(&arr[i + 1], &arr[high], c);
    return i + 1;
}

void quicksort(int arr[], int low, int high, Contador *c) {
    if (low < high) {
        int pi = partition(arr, low, high, c);
        quicksort(arr, low, pi - 1, c);
        quicksort(arr, pi + 1, high, c);
    }
}

// ======== MERGESORT =========
void merge(int A[], int inicio, int meio, int fim, Contador *c) {
    int n = fim - inicio + 1;
    int *temp = malloc(n * sizeof(int));
    int i = inicio, j = meio + 1, k = 0;

    while (i <= meio && j <= fim) {
        c->comparacoes++;
        if (A[i] <= A[j])
            temp[k++] = A[i++], c->movimentacoes++;
        else
            temp[k++] = A[j++], c->movimentacoes++;
    }

    while (i <= meio)
        temp[k++] = A[i++], c->movimentacoes++;
    while (j <= fim)
        temp[k++] = A[j++], c->movimentacoes++;

    for (i = inicio, k = 0; i <= fim; i++, k++) {
        A[i] = temp[k];
        c->movimentacoes++;
    }

    free(temp);
}

void mergesort(int A[], int inicio, int fim, Contador *c) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergesort(A, inicio, meio, c);
        mergesort(A, meio + 1, fim, c);
        merge(A, inicio, meio, fim, c);
    }
}

// ======== FUN  ES AUXILIARES =========
void gerar_array(int arr[], int n, int tipo) {
    if (tipo == 0)
        for (int i = 0; i < n; i++) arr[i] = rand();
    else if (tipo == 1)
        for (int i = 0; i < n; i++) arr[i] = i;
    else
        for (int i = 0; i < n; i++) arr[i] = n - i;
}

void copiar_array(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++)
        destino[i] = origem[i];
}

void imprimir_tabela(const char *titulo, long dados[3][7]) {
    const char *metodos[] = {"Heapsort", "Quicksort", "Mergesort"};
    int tamanhos[] = {50, 100, 500, 1000, 5000, 10000, 30000};

    printf("\n%s\n", titulo);
    printf("+--------------------------------------------------------------------------------------+\n");
    printf("| M todo     ");
    for (int i = 0; i < 7; i++)
        printf("%6d ", tamanhos[i]);
    printf("|\n+--------------------------------------------------------------------------------------+\n");

    for (int i = 0; i < 3; i++) {
        printf("| %-10s", metodos[i]);
        for (int j = 0; j < 7; j++)
            printf("%6ld ", dados[i][j]);
        printf("|\n");
    }

    printf("+--------------------------------------------------------------------------------------+\n");
}
