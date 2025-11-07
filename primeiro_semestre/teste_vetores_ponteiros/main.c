#include <stdio.h>

int omaior(int vetor[], int num_elem, int *posicao){
    int maior = vetor[0];

    printf("Vetor:\n");

    for(int i = 0; i < num_elem; i++){
        printf("%d ", vetor[i]);
        if(vetor[i] > maior){
            maior = vetor[i];
            *posicao = i;
        }
    }

    printf("\n\n");
    return maior;
}

int main(void){

    int vetor[] = {1, -2, 1000, 5000, 5};
    
    int posicao = 0;
    int maior = 0;

    maior = omaior(vetor, 5, &posicao);

    printf("Maior valor: %d\nPosicao: %d\n", maior, posicao);


    return 0;
}