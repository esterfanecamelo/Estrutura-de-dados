#include <stdio.h>
#include <stdlib.h>
#include "dicionario.h"

void CriaDicionario(TipoDicionario* D) {
    D->tamanho = 0;
    D->raiz = NULL;
}

void InsereNoDicionarioRec(TipoApontador* p, TipoRegistro registro , int* sucesso) {
    if (*p == NULL) {
        *p = (TipoApontador)malloc(sizeof(TipoNo));
        (*p)->reg = registro;
        (*p)->esq = NULL;
        (*p)->dir = NULL;
        *sucesso = 1;
    } else if (registro.chave < (*p)->reg.chave) {
        InsereNoDicionarioRec(&(*p)->esq, registro, sucesso);
    } else if (registro.chave > (*p)->reg.chave) {
        InsereNoDicionarioRec(&(*p)->dir, registro, sucesso);
    } else {
        *sucesso = 0; // Chave já existe
        printf("\nChave %d ja existe\n", registro.chave);
    }
}

void InsereNoDicionario(TipoDicionario* D, TipoRegistro registro) {
    int sucesso = 0;
    InsereNoDicionarioRec(&D->raiz, registro, &sucesso);
    if (sucesso) D->tamanho++;
}

void RetiraMinimo(TipoApontador* p, TipoApontador* min) {
    if ((*p)->esq != NULL) {
        RetiraMinimo(&(*p)->esq, min);
    } else {
        *min = *p;
        *p = (*p)->dir;
    }
}

void RetiraDoDicionarioRec(TipoApontador* p, int chave, int* sucesso) {
    if (*p == NULL) {
        *sucesso = 0;
        return;
    }

    if (chave < (*p)->reg.chave) {
        RetiraDoDicionarioRec(&(*p)->esq, chave, sucesso);
    } else if (chave > (*p)->reg.chave) {
        RetiraDoDicionarioRec(&(*p)->dir, chave, sucesso);
    } else {
        TipoApontador temp = *p;
        if ((*p)->esq == NULL) {
            *p = (*p)->dir;
            free(temp);
        } else if ((*p)->dir == NULL) {
            *p = (*p)->esq;
            free(temp);
        } else {
            TipoApontador min;
            RetiraMinimo(&(*p)->dir, &min);
            min->esq = (*p)->esq;
            min->dir = (*p)->dir;
            free(*p);
            *p = min;
        }
        *sucesso = 1;
    }
}

void RetiraDoDicionario(TipoDicionario* D, int chave) {
    int sucesso = 0;
    RetiraDoDicionarioRec(&D->raiz, chave, &sucesso);
    if (sucesso) D->tamanho--;
}

void ImprimeDicionario(TipoApontador p) {
    if (p != NULL) {
        ImprimeDicionario(p->esq);
        printf("%d ", p->reg.chave);
        ImprimeDicionario(p->dir);
    }
}
