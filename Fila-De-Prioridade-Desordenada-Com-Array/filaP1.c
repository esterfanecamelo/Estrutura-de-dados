#include "filaP.h"
#include <stdio.h>
#include <stdlib.h>

// Fila não ordenada com array

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
}

void retiraMaxDaFila(Registro *registro, Fila* fila){
    int numMax = fila->registros[0].chave;
    int posicao = 0;
    if(fila->tamanho==0){
        printf("Fila vazia!\n");
        return;
    }

    for(int i=0; i<fila->tamanho; i++){
        if(fila->registros[i].chave > numMax){
            numMax = fila->registros[i].chave;
            posicao = i;
        }
    }

    registro->chave = numMax;

    for(int i=posicao; i<fila->tamanho-1; i++){
        fila->registros[i].chave = fila->registros[i+1].chave;
    }

    fila->tamanho--;
}


