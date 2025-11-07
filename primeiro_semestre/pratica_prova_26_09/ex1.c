/*
Problema 1 (questão 2 da prova): Escreva um programa que leia da entrada padrão um número
inteiro positivo n e calcule o valor da seguinte série:
O programa deve testar se a entrada é válida e, se for, escrever na saída padrão o número lido e o
resultado calculado. Se a entrada não for válida, escrever uma mensagem de erro.

S = 1-1/2+1/3-1/4+...
*/

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double soma = 0.0;
    
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Erro: o número deve ser positivo.\n");
        return 1;
    }
    
    for (int i = 1; i <= n; i++) {
        soma += pow(-1, i + 1) * (1.0 / i);
    }
    
    printf("Número lido: %d\n", n);
    printf("Resultado da série: %.6f\n", soma);
    
    return 0;
}

