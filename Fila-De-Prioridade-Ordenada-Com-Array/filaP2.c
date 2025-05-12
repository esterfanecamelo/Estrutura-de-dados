#include "filaP.h"
#include <stdio.h>
#include <stdlib.h>

// Fila ordenada com array

typedef struct fila{
    int tamanho;
    Registro registros[MAX];
} Fila;

Fila* criaFila(void){
    Fila* fila = (Fila*)malloc(sizeof(Fila));

    if(!fila){
        printf("Erro ao alocar memória");
        //exit();
    }

    fila->tamanho = 0;
    return fila;
}

int tamanhoDaFila(Fila* fila){
    if(fila->tamanho==0){
        printf("Fila vazia!\n");
        return fila->tamanho;
    }

    return fila->tamanho;
}

void imprimeFila(Fila* fila){
    int tamanho = fila->tamanho;

    for(int i=0; i<tamanho; i++){
        printf("%d " , fila->registros[i].chave);
    }
    printf("\n");
}

void insereNaFila(Registro *registro, Fila* fila){

    if(fila->tamanho == MAX){
        printf("Fila cheia!\n");
        return;
    }

    fila->registros[fila->tamanho].chave = registro->chave;
    fila->tamanho++;

    for(int i=0; i<fila->tamanho-1; i++){
        for(int j=i+1; j<fila->tamanho; j++){
            if(fila->registros[j].chave > fila->registros[i].chave){
                Registro aux = fila->registros[j];
                fila->registros[j] = fila->registros[i];
                fila->registros[i] = aux;
            }
        }
    }
}

void retiraMaxDaFila(Registro *registro, Fila* fila){
    if(fila->tamanho==0){
        printf("Fila vazia!\n");
        return;
    }   

    registro->chave = fila->registros[0].chave;

    for(int i=0; i<fila->tamanho; i++){
        fila->registros[i] = fila->registros[i+1];
    }

    fila->tamanho--;

}


