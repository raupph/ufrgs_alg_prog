/**
 * Problema 3: Brincando com criptografia. Escreva um programa que lê uma string s1 contendo até
MAXTXT caracteres (máximo 30, não precisa verificar) e imprime na tela a string criptografada.
Seu programa deve ter uma função com o seguinte protótipo:
void codifica(char original[], char cripto[]);
que recebe o string lido original e devolve o string criptografado.
A regra para criptografia é a seguinte: as vogais são substituídas pela próxima vogal, exemplo a vira
e, e vira i e assim por diante. Para as consoantes, substitua cada consoante pela letra anterior no
alfabeto, ou seja, b vira a, h vira g e assim sucessivamente.
Abaixo exemplo de execução:
Digite string s1: Eu estudo na UFRGS
String criptografado: Ia irsacu me AEQFR
Observação: Você não pode usar o método força-bruta para as consoantes, o
 */

#include <stdio.h>

enum{
    VOGAL = 0,
    CONSONANT
};


int isConsonant(char ch){
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {

        return VOGAL;
    }
    else if((ch >= 65 && ch <= 90) ||(ch >= 97 && ch <= 122)){
        return CONSONANT;
    }

    return -1;
}

void cypher(char phrase[], int len, char encrypted []){
    char vowels_lower[] = "aeiou";
    char vowels_upper[] = "AEIOU";

    for(int letter = 0; letter < len; letter++){
        int consonatOrVogal;

        consonatOrVogal = isConsonant(phrase[letter]);

        switch (consonatOrVogal)
        {
        case VOGAL:
        {
            int found = 0;
            for(int i = 0; i < 5; i++){
                if(phrase[letter] == vowels_lower[i]){
                    encrypted[letter] = vowels_lower[(i + 1) % 5];
                    found = 1;
                    break;
                }
                if(phrase[letter] == vowels_upper[i]){
                    encrypted[letter] = vowels_upper[(i + 1) % 5];
                    found = 1;
                    break;
                }
            }
            if(!found) encrypted[letter] = phrase[letter];
            break;
        }
        
        case CONSONANT:
            if(phrase[letter] == 'b'){
                encrypted[letter] = 'z';
            }
            else if(phrase[letter] == 'B'){
                encrypted[letter] = 'Z';
            }
            else if(phrase[letter] == 'z'){
                encrypted[letter] = 'b';
            }          
            else if(phrase[letter] == 'Z'){
                encrypted[letter] = 'B';
            }
            else{ 
                encrypted[letter] = phrase[letter] - 1;
            }
            break;

        default:
            encrypted[letter] = phrase[letter];
            break;
        }

    }
}

int main(void){
    char original[31];
    char cripto[31];

    printf("Write your phrase: ");
    fgets(original, sizeof(original), stdin);

    int len = 0;
    while(original[len] != '\0' && original[len] != '\n') {
        len++;
    }
    original[len] = '\0';

    cypher(original, len, cripto);

    printf("String criptografado: ");
    for(int i = 0; i < len; i++) {
        printf("%c", cripto[i]);
    }
    printf("\n");


    return 0;
}