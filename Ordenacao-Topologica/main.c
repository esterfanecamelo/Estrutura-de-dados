#include <stdio.h>
#include "lista.h"

#define MAX 100

int matrizAdj[MAX + 1][MAX + 1];
int preRequisito[MAX + 1];
Tipolista lista;

void ordenacaoTopologica(int numTarefas) {
    Tipochave v;
    fazListaVazia(&lista);

    for (int i = 1; i <= numTarefas; i++) {
        if (preRequisito[i] == 0) {
            inserirNaLista(&lista, i);
        }
    }

    while (tamanhoLista(&lista) > 0) {
        removerPrimeiroDaLista(&lista, &v);
        printf("%d ", v);

        for (int i = 1; i <= numTarefas; i++) {
            if (matrizAdj[v][i]) { // Se existe aresta v -> i
                preRequisito[i]--;
                if (preRequisito[i] == 0) {
                    inserirNaLista(&lista, i);
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int numTarefas, numPreRequisitos;
    printf("Digite o número de tarefas: ");
    scanf("%d", &numTarefas);
    printf("Digite o número de pré-requisitos: ");
    scanf("%d", &numPreRequisitos);

    for (int i = 1; i <= numTarefas; i++) {
        preRequisito[i] = 0;
        for (int j = 1; j <= numTarefas; j++) {
            matrizAdj[i][j] = 0;
        }
    }

    printf("Digite os pares de pré-requisitos (u v) indicando que u deve vir antes de v:\n");
    for (int i = 0; i < numPreRequisitos; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (!matrizAdj[u][v]) { // Para não contar duas vezes
            matrizAdj[u][v] = 1;
            preRequisito[v]++;
        }
    }

    printf("Ordenação topológica das tarefas:\n");
    ordenacaoTopologica(numTarefas);

    return 0;
}
