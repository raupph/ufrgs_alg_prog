/*
Faça um programa que lê dois valores, o primeiro servindo de indicador de
operação e o segundo correspondendo ao raio de uma circunferência. Caso
o primeiro valor lido seja igual a 1, calcular e imprimir a área desta
circunferência. Se o valor lido for 2, calcular e imprimir o perímetro da
circunferência. E se o valor lido for diferente destes dois valores, imprimir
uma mensagem dizendo que o indicador de operação foi mal fornecido. 
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

float digitarRaio(void){

    float raio = 0;
    printf("Digite o raio: ");
    scanf("%f", &raio);

    return raio;

}
int main(void){

    int option = 0;
    float area = 0;
    float perimetro = 0;
    float raio = 0;

    printf("Menu: \n 1: Calcular área\n 2: Calcular perimetro\n");
    scanf("%d", &option);
    printf("\n");


    switch (option)
    {
    case 1:
        raio = digitarRaio();
        area = PI * (raio * raio);
        printf("Area = %.3f\n", area);
        break;
    
    case 2:
        raio = digitarRaio();
        perimetro = 2 * PI *raio;
        printf("Raio = %.3f\n", perimetro);
        break;

    default:
        printf("Valor invalido\n");
        break;

    }   

    return 0;
}