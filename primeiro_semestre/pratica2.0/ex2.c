    /*
Escreva um programa que leia do teclado o raio de um círculo, e após calcule (e informe na
tela) o perímetro e a área do maior quadrado inscrito nesse círculo. DICA: veja como o
lado do quadrado está relacionado ao raio do círculo.

h^2 = 2l^2

h/raiz2 = l

*/


#include <stdio.h>
#include <math.h>

int main(void){

    float raio = 0;
    float diametro = 0;
    float ladoQuadrado = 0;
    double area = 0;
    float perimetro = 0;

    // lado quadrado = h/raiz(2)

    printf("Entre com um valor para o raio: ");
    scanf("%f", &raio);

    diametro = raio * 2;
    ladoQuadrado = diametro / sqrt(2);
    area = pow(ladoQuadrado, 2);
    perimetro = ladoQuadrado * 4;

    printf("Perímetro do maior quadrado: %.2f\n", perimetro);
    printf("Área do maior quadrado: %.2f\n", area);
    

    return 0;
}