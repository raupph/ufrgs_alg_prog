/*
Problema 1: Escreva um programa em C que leia uma quantidade indefinida de valores inteiros
estritamente positivos (um valor negativo é usado para indicar o fim da entrada de dados), e
armazene-os em um arranjo. O número máximo de valores a ser lido é definido por um #define
MAXLIDOS 10, mas o usuário pode digitar menos valores que esse máximo. Após, o programa deve
calcular e imprimir na tela:
a) Escrever o arranjo lido
b) Ordenar o vetor com o algoritmo bubble sort (código está no Moodle, mas deve ser
adaptado para as variáveis de seu programa).
c) Escrever o arranjo ordenado
d) Escrever os valores mínimo e máximo do arranjo
Em casa: Verificar se há valores duplicados no arranjo e informá-los
Exemplos de execução:
Entre com NO MÁXIMO 10 elementos do array:
6 7 8 9 1 2 3 -1
Vetor Original
6 7 8 9 1 2 3
Vetor Ordenado:
1 2 3 6 7 8 9
Valor mínimo do arranjo=1
Valor máximo do arranjo=9*/


#include <stdio.h>

#define ARR_LEN 10

void sort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void){

    int arr[ARR_LEN] = {0};
    int cont = 0;
    int value = 0;

    printf("Entre com NO MÁXIMO 10 elementos do array: \n");
    do{
        scanf("%d", &value);
        if(value >= 0){
            arr[cont] = value;
            cont++;
        }
    }while(value >= 0 && cont < ARR_LEN);


    printf("\nVetor Original\n");
    for(int i = 0; i < cont; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    sort(arr, cont);

    printf("\nVetor Ordenado:\n");
    for(int i = 0; i < cont; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    if(cont > 0){
        printf("Valor mínimo do arranjo=%d\n", arr[0]);
        printf("Valor máximo do arranjo=%d\n", arr[cont-1]);
    }

    return 0;
}