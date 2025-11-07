/*
Escreva um programa com as seguintes funções:
a) uma função que receba dois parâmetros inteiros e troque seus valores (já
implementada)
b) uma função que receba três inteiros como argumentos e faça um ajuste tal que,
após a execução, o menor valor esteja no primeiro parâmetro e o maior no terceiro.
Use a função definida na letra a) acima, como função auxiliar
*/


#include <stdio.h>

void TrocaValores (int *a, int *b){
    int memoria = 0;
    memoria = *a;
    *a = *b;
    *b = memoria;
}

void OrdenaValores(int *a, int *b, int *c){
    if(*a > *b){
        TrocaValores(a, b);
    }
    
    if(*b > *c){
        TrocaValores(b, c);
    }
    
    if(*a > *b){
        TrocaValores(a, b);
    }
}

int main(void){
    int a = 1, b = 2;
    int a2 = -2, b2 = -1000, c2 = 12;

    printf("\t[ANTES] da Funcao\n\nValor de a: %d\nValor de b: %d\n", a, b);

    TrocaValores(&a, &b);
    printf("\n\t[DEPOIS] da Funcao\n\nValor de a: %d\nValor de b: %d\n", a, b);
    printf("\n\n");

    printf("\n\t[ANTES] da Funcao\nValor de a2: %d\nValor de b2: %d\nValor de c2: %d\n", a2, b2, c2);
    OrdenaValores(&a2, &b2, &c2);
    printf("\n\t[DEPOIS] da Funcao\nValor de a2: %d\nValor de b2: %d\nValor de c2: %d\n", a2, b2, c2);


    return 0;
}