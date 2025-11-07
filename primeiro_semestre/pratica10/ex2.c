#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função que encontra o primeiro elemento comum entre duas matrizes
int *elemento_comum(int mat_A[4][4], int mat_B[3][3]);

// Função genérica para preencher matriz com valores aleatórios
void preencher_matriz(int *matriz, int linhas, int colunas);

// Função genérica para imprimir matriz
void imprimir_matriz(int *matriz, int linhas, int colunas);

int main() {
    int mat_A[4][4];
    int mat_B[3][3];
    int *elemento;
    
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));
    
    // Preenche as matrizes com valores aleatórios
    preencher_matriz((int*)mat_A, 4, 4);
    preencher_matriz((int*)mat_B, 3, 3);
    
    // Imprime as matrizes
    printf("Matriz A\n");
    imprimir_matriz((int*)mat_A, 4, 4);
    
    printf("Matriz B\n");
    imprimir_matriz((int*)mat_B, 3, 3);
    
    // Encontra o primeiro elemento comum
    elemento = elemento_comum(mat_A, mat_B);
    
    if (elemento != NULL) {
        printf("O primeiro elemento encontrado igual nas duas matrizes eh: %d\n", *elemento);
    } else {
        printf("Nenhum elemento comum foi encontrado.\n");
    }
    
    return 0;
}

// Função que encontra o primeiro elemento comum entre as duas matrizes
int *elemento_comum(int mat_A[4][4], int mat_B[3][3]) {
    int i, j, k, l;
    
    // Percorre todos os elementos da matriz A
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            // Para cada elemento de A, verifica se existe em B
            for (k = 0; k < 3; k++) {
                for (l = 0; l < 3; l++) {
                    if (mat_A[i][j] == mat_B[k][l]) {
                        // Retorna o ponteiro para o elemento encontrado em A
                        return &mat_A[i][j];
                    }
                }
            }
        }
    }
    
    // Se não encontrou nenhum elemento comum, retorna NULL
    return NULL;
}

// Função genérica para preencher matriz com valores aleatórios entre 1 e 10
void preencher_matriz(int *matriz, int linhas, int colunas) {
    int i, j;
    
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            *(matriz + i * colunas + j) = rand() % 10 + 1; // Valores entre 1 e 10
        }
    }
}

// Função genérica para imprimir matriz
void imprimir_matriz(int *matriz, int linhas, int colunas) {
    int i, j;
    
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d ", *(matriz + i * colunas + j));
        }
        printf("\n");
    }
}


