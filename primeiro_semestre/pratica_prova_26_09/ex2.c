/*Problema 2 (questão 3 da prova): Observe o programa abaixo, e faça um versão dele que gere as
mesmas saídas, mas que:
a) tenha um laço WHILE-DO ou DO-WHILE (o que você achar mais conveniente) substituindo
o laço FOR e
b) faça consistência da entrada, ou seja, o programa só deve sair do laço de leitura quando a
entrada for um número inteiro positivo.
#include <stdio.h>
int main(void){
 int num, i;
 int result;
 printf("Entre um numero inteiro: ");
 scanf("%d", &num);
 if (num < 0)
 printf("Numero entrado eh negativo\n");
 else{
 result = 1;
 for (i= num; i >= 1; i--){
 result = result * i;
 /* Na prova o printf estava dentro do for
 printf ("Resultado eh = %3d\n",result);
 }
 printf ("Resultado eh = %3d\n",result);
 }
 return 0;
}
*/


#include <stdio.h>

int main(void){
    int num, i;
    int result;
    
    do {
        printf("Entre um numero inteiro: ");
        scanf("%d", &num);
        
        if (num > 0) {
            result = 1;
            i = num;
            
            while (i >= 1) {
                result = result * i;
                i--;
            }
            
            printf("Resultado eh = %3d\n", result);
        }
    } while (num <= 0);
    
    return 0;
}

