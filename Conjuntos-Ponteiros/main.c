#include <stdio.h>
#include "conjunto.h"

int main(void)
{

    int i, elemento, elemMax = 0, elemMin = 0;
    Conjunto conjunto;

    fazConjuntoVazio(&conjunto);
    imprimeConjunto(conjunto);

    for(i = 10; i<100; i+=10){
        if(insere(i, &conjunto)){
            //printf("Inseriu!\n");
       }else{
           printf("Não Inseriu!\n");
       }
    }

    imprimeConjunto(conjunto);

    elemento = 20;

    if (pertenceAoConjunto(elemento, conjunto))
    {
        printf("Elemento %d existe no conjunto!\n", elemento);
    }
    else
    {
        printf("Elemento %d não existe no conjunto!\n", elemento);
    }

    if (retiraDoConjunto(elemento, &conjunto))
    {
        printf("Retirou elemento!\n");
    }else{
        printf("Não achou para retirar\n");
    }

    imprimeConjunto(conjunto);

    if(maxDoConjunto(&elemMax, conjunto)){
        printf("O maior elemento é: %d\n", elemMax);
    }

    printf("Chamada da funcao maxMin:\n");
    if (maxMinDoConjunto(&elemMax, &elemMin, conjunto)){
        printf("Valor maximo: %d\nValor minimo: %d\n", elemMax, elemMin);
    }

    printf("Chamada da funcao maxMin 2:\n");
    if (maxMinDoConjunto2(&elemMax, &elemMin, conjunto)){
        printf("Valor maximo: %d\nValor minimo: %d\n", elemMax, elemMin);
    }

    return 0;
}
