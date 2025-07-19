#ifndef ORDENACAO_H_INCLUDED
#define ORDENACAO_H_INCLUDED

typedef struct {
    long comparacoes;
    long movimentacoes;
} Contador;

void heapsort(int arr[], int n, Contador *c);
void quicksort(int arr[], int low, int high, Contador *c);
void mergesort(int arr[], int inicio, int fim, Contador *c);

void gerar_array(int arr[], int n, int tipo);
void copiar_array(int origem[], int destino[], int n);
void imprimir_tabela(const char *titulo, long dados[3][7]);


#endif // ORDENACAO_H_INCLUDED