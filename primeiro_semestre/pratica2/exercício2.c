#include <stdio.h>
#include <math.h>

/*

h = lraizde2
h/raiz2 = l

*/

int main(void){

    float raio; 
    float perimetroQuadrado = 0;
    float areaQuadrado = 0;
    float diametro = 0;
    float ladoQuadrado = 0;

    printf("Entre com um valor para o raio: ");
    scanf("%f", &raio);

    diametro = 2 * raio;
    ladoQuadrado = diametro/sqrt(2);

    perimetroQuadrado = ladoQuadrado * 4;

    areaQuadrado = ladoQuadrado * ladoQuadrado;

    printf("perimetro: %.2f\n", perimetroQuadrado);
    printf("area: %.2f\n", areaQuadrado);

    return 0;
}