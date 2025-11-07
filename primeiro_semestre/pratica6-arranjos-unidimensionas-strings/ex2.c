/*Leia, de teclado, um string de comprimento máximo igual a 60. O usuário pode informar
menos que 60 caracteres incluindo espaços em branco. O programa não precisa validar o tamanho. A
seguir, o programa deve:
a) Calcular o tamanho do string (lembrar da função que devolve esse valor!)
b) Contar e escrever na tela o número de espaços em branco.
c) Contar e escrever na tela o número de vogais (minúsculas ou maiúsculas).
d) Calcular e escrever na tela o número de consoantes
e) Escrever na tela o string invertido.
*/

#include <stdio.h>
#include <string.h>

#define ARR_LEN 60

int main(void){
    int cont = 0;
    int num_vogais = 0;
    int num_consoantes = 0;
    int cont_espacos = 0;
    char frase[ARR_LEN + 2] = {0};

    puts("Digite uma string:");

    if (fgets(frase, ARR_LEN+2, stdin) != NULL){
        frase[strlen(frase)-1] = '\0';
        printf("\n");
        puts(frase);
        printf("Tamanho da string %ld\n", strlen(frase));
    } else printf("Problema com o fgets!\n");

    while(frase[cont] != '\0' && cont < ARR_LEN){

        if(frase[cont] == ' '){
            cont_espacos++;
        }
        else if(frase[cont] == 'A' || frase[cont] == 'a' || 
            frase[cont] == 'E' || frase[cont] == 'e' ||
            frase[cont] == 'I' || frase[cont] == 'i' ||
            frase[cont] == 'O' || frase[cont] == 'o' ||
            frase[cont] == 'U' || frase[cont] == 'u'){

            num_vogais++;
            }
        else {
            num_consoantes++;
            }
        cont++;
    }

    printf("Número de caracteres branco: %d\nNúmero de vogais: %d\nNúmero de consoantes: %d\n", 
        cont_espacos, num_vogais, num_consoantes);

    for(int i = cont; i >= 0; i--){
        printf("%c", frase[i]);
    }
    printf("\n");


    return 0;
}