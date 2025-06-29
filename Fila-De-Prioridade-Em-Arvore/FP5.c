#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FP.h"

// Estrutura de um nó da árvore binária
typedef struct No {
    tiporegistro reg;
    struct No* esq;
    struct No* dir;
} No;

// Estrutura da Fila de Prioridade
struct FP {
    No* raiz;
    int tamanho;
};

No* novoNo(tiporegistro reg) {
    No* no = (No*)malloc(sizeof(No));
    no->reg = reg;
    no->esq = no->dir = NULL;
    return no;
}

No* insereNo(No* raiz, tiporegistro reg) {
    if (raiz == NULL) return novoNo(reg);

    if (reg.chave < raiz->reg.chave)
        raiz->esq = insereNo(raiz->esq, reg);
    else
        raiz->dir = insereNo(raiz->dir, reg);

    return raiz;
}

No* removeMax(No* raiz, tiporegistro* reg) {
    if (raiz == NULL) return NULL;

    if (raiz->dir == NULL) {
        *reg = raiz->reg;
        No* temp = raiz->esq;
        free(raiz);
        return temp;
    }

    raiz->dir = removeMax(raiz->dir, reg);
    return raiz;
}

void imprimeEmOrdem(No* raiz) {
    if (raiz == NULL) return;
    imprimeEmOrdem(raiz->esq);
    printf("Chave: %d, Nome: %s\n", raiz->reg.chave, raiz->reg.nome);
    imprimeEmOrdem(raiz->dir);
}

// ================= Funções do TAD FP ================= //

tipoFP* criaFP(void) {
    tipoFP* fp = (tipoFP*)malloc(sizeof(tipoFP));
    fp->raiz = NULL;
    fp->tamanho = 0;
    return fp;
}

int tamanhoFP(tipoFP* fp) {
    return fp->tamanho;
}

void insereFP(tipoFP* fp, tiporegistro reg) {
    fp->raiz = insereNo(fp->raiz, reg);
    fp->tamanho++;
}

void retiraMaxFP(tipoFP* fp, tiporegistro* reg) {
    if (fp->raiz == NULL) {
        printf("Fila de prioridade vazia.\n");
        return;
    }
    fp->raiz = removeMax(fp->raiz, reg);
    fp->tamanho--;
}

void imprimeFP(tipoFP* fp) {
    imprimeEmOrdem(fp->raiz);
}