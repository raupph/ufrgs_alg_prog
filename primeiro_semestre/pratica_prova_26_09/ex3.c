/*

Problema 3 (questão 4 da prova): Escreva um programa que:
a) Leia um string contendo uma frase que tenha letras, digitos e espaços em branco. Assuma
que o string pode ter no máximo 60 caracteres.
b) O programa deve contar o número de letras maiúsculas, letras minúsculas, dígitos e espaços
em branco (ver observação abaixo).
c) O programa deve escrever na saída padrão: o string original, o tamanho do string, e os totais
calculados.
Observações:
1. Você pode usar a biblioteca ctype.h da seguinte forma:
int isdigit(int c)

RETORNA: um valor diferente de zero quando o caractere recebido é um dígito de 0 a 9 ou 0
caso contrário.
RECEBE: um único argumento (caractere) que será convertido para inteiro. Mesmo que isdigit()
receba um inteiro como argumento, o caractere é passado para a função. Internamente, o
caractere é convertido em seu valor ASCII para a verificação.
int isalpha(int c)
RETORNA: 1 caso seja uma letra do alfabeto maiúscula, 2 caso seja minúscula, 0 caso não esteja
no alfabeto.
RECEBE: um único argumento (caractere) que será convertido para inteiro. Mesmo que
isalpha() receba um inteiro como argumento, o caractere é passado para a função.
Internamente, o caractere é convertido em seu valor ASCII para a verificação.
2. As letras maiúsculas têm valor ASCII entre 65 e 90 e as minúsculas, entre 97 e 122.
3. O uso de SWITCH-CASE é bem-vindo nessa solução.

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 60

int main()
{
    char frase[TAM + 2];
    int maiuscula = 0;
    int minuscula = 0;
    int digito = 0;
    int espaco = 0;

    puts("Digite uma string:");
    if (fgets(frase, TAM + 2, stdin) != NULL){ 
        frase[strlen(frase) - 1] = '\0';
        printf("\n\n");
        puts(frase);
        printf("Tamanho da string %ld\n", strlen(frase));
    }
    else
        printf("Problema com o fgets!\n");

    for(int i = 0; i < strlen(frase); i++){
        if(frase[i] == ' '){
            espaco++;
        }else if(isdigit(frase[i]) != 0){
            digito++;
        }else if(frase[i] >= 65 && frase[i] <= 90){
            maiuscula++;
        }else if(frase[i] >= 97 && frase[i] <= 122){
            minuscula++;
        }
    }

    printf("Maiusculas: %d\n", maiuscula);
    printf("Minusculas: %d\n", minuscula);
    printf("Digitos: %d\n", digito);
    printf("Espacos: %d\n", espaco);
    return 0;
}
