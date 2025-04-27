#include "busca.h"
#include <stdio.h>

int buscaBinaria(int array[], int tamanho, int elemento, int *comparacoes){

    int inicio = 0, meio, fim = tamanho - 1;

    while(inicio<=fim){

        meio = (inicio + fim) /2;

        (*comparacoes)++;

        if(array[meio] == elemento){
            printf("Elemento %d encontrado \n\n", elemento);
            return 1;
        }else{
            if(array[meio] > elemento){
                fim = meio - 1;
            }else{
                inicio = meio + 1;
            }
        }
    }
        printf("Elemento %d não encontrado \n\n", elemento);
    return 0;
}

int algoritmoSelectionSort(int array[], int tamanho, int *comparacoes){

    int i = 0, j, k, x;

    for (i ; i< tamanho-1; i++){
        k = i;
        for(j=i+1; j < tamanho; j++){
            if (array[j]<array[k]){
                k = j;
            }
            (*comparacoes)++;
        }

        x = array[k];
        array[k] = array[i];
        array[i] = x;
    }

    return 0;
}



