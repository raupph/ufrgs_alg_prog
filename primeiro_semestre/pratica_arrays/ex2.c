/*
Problema 2 (agora sim, com arranjos):
Escreva um programa em C que leia de teclado um conjunto de 5 números inteiros positivos, os quais
devem ser armazenados num arranjo V.
Num outro arranjo, que você pode chamar de VO, o programa deve colocar os números do arranjo
lido em ordem decrescente. No final, o programa deve imprimir o arranjo VO.
Dica: à medida que o programa vai encontrando o maior número em V e colocando na próxima
posição livre de VO, pode-se alterar o valor original no arranjo V para -1, para sinalizar que esse
elemento já foi armazenado no arranjo VO.
Abaixo você encontra três exemplos de execução, que você deve usar para testar seu programa.*/


#include <stdio.h>

#define TAM_V_VO 5

int main(void)
{
    int v[TAM_V_VO];
    int v0[TAM_V_VO];

    for (int i = 0; i < TAM_V_VO; i++)
    {
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < TAM_V_VO; i++)
    {
        int indice_maior = -1;
        int maior = -1;
        for (int j = 0; j < TAM_V_VO; j++)
        {
            if (v[j] > maior)
            {
                maior = v[j];
                indice_maior = j;
            }
        }
        v0[i] = maior;
        v[indice_maior] = -1;
    }

    for (int i = 0; i < TAM_V_VO; i++){
        printf("%d ", v0[i]);
    }
    printf("\n");

    return 0;
}