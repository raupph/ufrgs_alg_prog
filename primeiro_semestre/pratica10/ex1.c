#include <stdio.h>
#include <math.h>

// Apresenta o menu, lê e retorna a opção do usuário
// Valida a opção do usuario
int menu(void);

// Calcula a média aritmética de 3 valores e retorna
float m_aritmetica(float a, float b, float c);

// Calcula a média harmônica de 3 valores e retorna
float m_harmonica(float a, float b, float c);

// Calcula a média geométrica de 3 valores e retorna
float m_geometrica(float a, float b, float c);

int main() {
    int opcao;
    float a, b, c, resultado;
    
    do {
        opcao = menu();
        
        switch (opcao) {
            case 1:
                printf("Entre com os 3 valores: ");
                scanf("%f %f %f", &a, &b, &c);
                resultado = m_aritmetica(a, b, c);
                printf("A media aritmetica vale %f\n", resultado);
                break;
                
            case 2:
                printf("Entre com os 3 valores: ");
                scanf("%f %f %f", &a, &b, &c);
                resultado = m_harmonica(a, b, c);
                printf("A media harmonica vale %f\n", resultado);
                break;
                
            case 3:
                printf("Entre com os 3 valores: ");
                scanf("%f %f %f", &a, &b, &c);
                resultado = m_geometrica(a, b, c);
                printf("A media geometrica vale %f\n", resultado);
                break;
                
            case 4:
                break;
                
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 4);
    
    return 0;
}

// Função que apresenta o menu e retorna a opção escolhida
int menu(void) {
    int opcao;
    
    printf("Entre com uma das opcoes:\n");
    printf("1 – Calcula a media aritmetica de 3 numeros reais\n");
    printf("2 - Calcula a media harmonica de 3 numeros reais\n");
    printf("3 – Calcula a media geometrica de 3 numeros reais\n");
    printf("4 – Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    
    return opcao;
}

// Função que calcula a média aritmética
float m_aritmetica(float a, float b, float c) {
    return (a + b + c) / 3.0;
}

// Função que calcula a média harmônica
float m_harmonica(float a, float b, float c) {
    return 3.0 / ((1.0/a) + (1.0/b) + (1.0/c));
}

// Função que calcula a média geométrica
float m_geometrica(float a, float b, float c) {
    return pow(a * b * c, 1.0/3.0);
}

