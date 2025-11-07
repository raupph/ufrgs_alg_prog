/*

Uma das maneiras de calcular o seno de um ângulo (em radianos) é através da Série
de Taylor-Maclaurin:

Na prática, pode-se aproximar o valor da série acima usando os N primeiros termos apenas, onde N
é um valor inteiro positivo. Escreva um programa em C que leia do teclado: o valor de um ângulo
em radianos (x), o número de termos desejado (N), e calcule o valor aproximado de sen(x). Ao
final, o programa deve informar o valor aproximado, juntamente com o valor fornecido pela função
sin, contida na biblioteca math.h. Obs.: O programa deve validar se o valor lido N é realmente
um valor positivo. Se não for, encerra a execução com mensagem de erro ao usuário.
Abaixo você encontra dois exemplos de execução, que você deve usar para testar seu programa:
Entre os valores de x e N: 2.3 5
Valor aproximado de seno de 2.300000 eh: 0.745936
Valor de sin(2.300000) pela funcao C eh: 0.745705
Entre os valores de x e N: 1.5 -5
N não é positivo!
Entre os valores de x e N: 1.57079632679 3
Valor aproximado do seno de 1.570796 eh: 1.004525
Valor de sin(1.570796) pela funcao C eh: 1.000000

*/
#include <stdio.h>
#include <math.h>

long long factorial(int n){
    long long fatorial = n;

    for(int i = n - 1; i >= 1; i--){
        fatorial *= i; 
    }

    return fatorial;
}

int main(void){
    int n = 0;
    float x = 0;
    float sine = 0;
    printf("Write the value of x and n: ");
    scanf("%f %i", &x, &n);

    if(n <= 0){
        printf("N is not positive!\n");
        return 1;
    }

    for(int i = 0; i < n; i++){
        sine += ((pow((-1), i)) * (pow(x, (2 * i + 1)) / factorial((2 * i + 1))));

    }

    printf("Result\n");
    printf("Aproximated sine value: %f\n", sine);
    printf("Sine value by C lib %f\n", sin(x));
    return 0;
}