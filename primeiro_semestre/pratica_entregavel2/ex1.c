/*Problema 1: O programa deve ler uma quantidade indeterminada de valores inteiros até que o
usuário digite o valor 0 (zero), que é o sinal de parada de leitura de valores (o 0 não entra no conjunto
a ser testado). Ao encerrar a leitura, o programa deve escrever o maior e o menor valor lidos.
Abaixo você encontra dois exemplos de execução, que você deve usar para testar seu programa:
Digite um valor inteiro: 9
Digite um valor inteiro: -2
Digite um valor inteiro: 18
Digite um valor inteiro: 13
Digite um valor inteiro: -1
Digite um valor inteiro: 20
Digite um valor inteiro: 0
O maior valor vale 20
O menor valor vale -2
Digite um valor inteiro: 10
Digite um valor inteiro: 0
O maior valor vale 10
O menor valor vale 10*/


#include <stdio.h>

int main(void){
    int cmd = 0;
    int biggestNumber = 0;
    int smallestNumber = 0;
    int cont = 0;

    do{
        printf("Write an integer number: ");
        scanf("%i", &cmd);

        if(cont == 0){
            biggestNumber = cmd;
            smallestNumber = cmd;
        }
        
        if(cmd > biggestNumber){
            biggestNumber = cmd;
        }

        if(cmd < smallestNumber){
            smallestNumber = cmd;
        }

        cont++;
    }
    while(cmd != 0);

    printf("Biggest numer: %i\n", biggestNumber);
    printf("Smallest numer: %i\n", smallestNumber);
}