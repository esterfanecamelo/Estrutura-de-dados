#ifndef DICIONARIO_H
#define DICIONARIO_H

typedef struct {
    int chave;
} TipoRegistro;

typedef struct TipoNo* TipoApontador;

typedef struct TipoNo {
    TipoRegistro reg;
    TipoApontador esq, dir;
} TipoNo;

typedef struct dicionario {
    int tamanho;
    TipoApontador raiz;
} TipoDicionario;

void CriaDicionario(TipoDicionario* D);
void InsereNoDicionario(TipoDicionario* D, TipoRegistro r);
void RetiraDoDicionario(TipoDicionario* D, int chave);
void ImprimeDicionario(TipoApontador p);

#endif
