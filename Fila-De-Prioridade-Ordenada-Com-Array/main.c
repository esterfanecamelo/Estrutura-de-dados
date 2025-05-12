#include "filaP.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void main(){

    Registro registro;
    Fila* fila = criaFila();

    srand(time(NULL)); 
    int cont = 1;
    while(cont <= MAX){
        registro.chave = rand() % 100;
        insereNaFila(&registro, fila);
        cont++;
    }

    imprimeFila(fila);
    int valor = 0;
    do
    {
        retiraMaxDaFila(&registro, fila);
        printf("numero removido: %d\n", registro.chave);
        imprimeFila(fila);
        valor++;
        
    } while (valor < 4);
    
}