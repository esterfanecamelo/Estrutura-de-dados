#include "conjunto.h"
#include <stdio.h>

void imprimeConjunto(Conjunto conjunto){

    if(conjunto.tamanho==0){
        printf("Conjunto Vazio!\n");
    }else{
        printf("Conjunto:\n");
        for(int i=0; i<conjunto.tamanho; i++){
            printf("%d ", conjunto.elementos[i]);
        }
        printf("\n");
    }
}

void fazConjuntoVazio(Conjunto *conjunto){
    conjunto->tamanho=0;
}

bool insere(int i, Conjunto *conjunto){
    if(conjunto->tamanho == MAX_SIZE){
        printf("Limite do array excedido!");
        return false;
    }else{
        conjunto->elementos[conjunto->tamanho] = i;
        conjunto->tamanho++;
        return true;
    }
}


int pertenceAoConjunto(int elemento, Conjunto conjunto){
    for(int i=0; i<conjunto.tamanho; i++){
        if(conjunto.elementos[i] == elemento){
            return 1;
        }
    }
    return 0;
}

int retiraDoConjunto(int elemento, Conjunto *conjunto){
    for(int i=0; i<conjunto->tamanho; i++){
        if(conjunto->elementos[i] == elemento){
            for(int j=i; j<conjunto->tamanho; j++){
                conjunto->elementos[j] = conjunto->elementos[j+1];
            }
            conjunto->tamanho--;
            return 1;
        }
    }
    return 0;
}

int maxDoConjunto(int *elemMax, Conjunto conjunto){
    if (conjunto.tamanho == 0) {
        return 0;
    }

    for(int i=0; i<conjunto.tamanho; i++){
        if(conjunto.elementos[i] > *elemMax){
            *elemMax = conjunto.elementos[i];
        }
    }
    return 1;
}

int maxMinDoConjunto(int *elemMax, int *elemMin, Conjunto conjunto){

    if(conjunto.tamanho == 0){
        return 0;
    }

    *elemMax = conjunto.elementos[0];
    *elemMin = conjunto.elementos[0];

    for(int i=1; i<conjunto.tamanho; i++){
        if (conjunto.elementos[i]>*elemMax){
            *elemMax = conjunto.elementos[i];
        }else if (conjunto.elementos[i] < *elemMin) {
            *elemMin = conjunto.elementos[i];
        }
    }

    return 1;
}

int maxMinDoConjunto2(int *elemMax, int *elemMin, Conjunto conjunto){
    
    int tamanho = conjunto.tamanho;

    if(tamanho == 0){
        return 0;
    }

    int fimDoArray = 0;
    int *elemento = conjunto.elementos;

    if(conjunto.tamanho % 2 != 0){
        elemento[tamanho] = elemento[tamanho- 1];
        fimDoArray = tamanho;
    }else{
        fimDoArray = tamanho - 1;
    }

    if(elemento[0] > elemento[1]){
        *elemMax = elemento[0];
        *elemMin = elemento[1];
    }else{
        *elemMax = elemento[1];
        *elemMin = elemento[0];
    }

    int maior, menor;
    for(int i = 2; i <= fimDoArray; i += 2){
        if(elemento[i] > elemento[i+1]){
            maior = elemento[i];
            menor = elemento[i+1];
        }else{
            maior = elemento[i+1];
            menor = elemento[i];
        }

        if(maior > *elemMax){
            *elemMax = maior;
        }
        if(menor < *elemMin){
            *elemMin = menor;
        }
    }

    return 1;
}