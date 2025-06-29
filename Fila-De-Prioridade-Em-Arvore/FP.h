#ifndef FP_H
#define FP_H

#include "registro.h"

typedef struct FP tipoFP; 

tipoFP* criaFP(void);

int tamanhoFP(tipoFP* fp);

void insereFP(tipoFP* fp, tiporegistro reg);

void retiraMaxFP(tipoFP* fp, tiporegistro* reg);

void imprimeFP(tipoFP* fp); 

#endif