#include <stdio.h>
#include "FP.h"

int main() {
    tipoFP* fp = criaFP();

    tiporegistro r1 = {10, "Joao"};
    tiporegistro r2 = {25, "Maria"};
    tiporegistro r3 = {15, "Carlos"};
    tiporegistro r4 = {5, "Ester"};

    insereFP(fp, r1);
    insereFP(fp, r2);
    insereFP(fp, r3);
    insereFP(fp, r4);

    printf("Elementos na Fila de Prioridade (ordem crescente):\n");
    imprimeFP(fp);

    tiporegistro max;
    retiraMaxFP(fp, &max);
    printf("\nMaior elemento removido:\nChave: %d, Nome: %s\n", max.chave, max.nome);

    printf("\nFila de Prioridade apos remocao:\n");
    imprimeFP(fp);

    return 0;
}
