/*
Problema 1: Modelando o Crescimento da População Alienígena
Cientistas descobriram um planeta distante com uma população crescente de alienígenas
inteligentes. A população cresce exponencialmente ao longo do tempo, e o crescimento
pode ser modelado usando a fórmula:
𝑃(𝑡) = 𝑃! ∗ 𝑒"#
Onde:
• P(t) é a população após t anos
• P0 é a população inicial (entrada pelo teclado)
• r é a taxa de crescimento em percentual (entrada pelo teclado)
• t é o tempo que passou em anos (entrada pelo teclado)
• e é o número de Euler
Dica: Para o cálculo da exponenciação de e, use a função exp contida na biblioteca
math.h
*/

#include <stdio.h>
#include <math.h>


int main(void){

    int p0, t;
    float r;
    double crescimento = 0;

    printf("Digite a população inicial: ");
    scanf("%d", &p0);
    printf("Digite o tempo em anos: ");
    scanf("%d", &t);
    printf("Digite a taxa de crescimento (em percentual): ");
    scanf("%f", &r);

    r /= 100;

    crescimento = round(p0 * (exp(r * t)));
    

    printf("Apos %d anos, a populacao sera aproximadamente %.0f aliens\n", t, crescimento);

    return 0;
}