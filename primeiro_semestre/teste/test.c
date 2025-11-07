#include <stdio.h>

void AlteraValor(int *ptr){
    *ptr = 10;
}

int AlteraValor2(int valor){
    return valor = 10;
}


int main(){

    int valor = 0;

    printf("Valor da var: %d\n", valor);

    //AlteraValor(&valor);
    valor = AlteraValor2(valor);

    printf("Valor da var depois: %d", valor);




    return 0;
}