/*
Num determinada disciplina, uma professora aplica duas provas (P1 e P2) e há um trabalho
final (TF) para compor a nota final (NF), que é calculada como segue:

NF = P1*0,35+P2*0,35+TF*0,30
O(a) aluno(a) é aprovado(a) se sua NF ≥ 6,0. Mas, se tiver alguma nota parcial abaixo de
4,0 terá que fazer recuperação.
Se a NF foi menor que 6,0, o(a) aluno(a) poderá fazer recuperação se, e somente se, todas
as sua notas forem maiores que 4,0.
Caso contrário, estará reprovado(a) sem direito à recuperação.

Exemplos de execução:
Informe as notas do(a) aluno(a):
Prova 1: 4.0
Prova 2: 4.0
Trabalho final: 4.0
O aluno nao tem direito a recuperacao porque ha nota parcial menor
ou igual a 4,0.

Informe as notas do(a) aluno(a):
Prova 1:5
Prova 2:5
Trabalho final:5
O aluno deve fazer a recuperacao porque a media final eh 5.00

Informe as notas do(a) aluno(a):
Prova 1:7.5
Prova 2:8.0
Trabalho final:5.0
O aluno está aprovado com nota final = 6.93
*/


#include <stdio.h>

int main(void){

    float prova1, prova2, trabalhoFinal;
    float notaFinal = 0;

    printf("P1: ");
    scanf("%f", &prova1);
    
    printf("P2: ");
    scanf("%f", &prova2);

    printf("Trabalho final: ");
    scanf("%f", &trabalhoFinal);

    //P1*0,35+P2*0,35+TF*0,30
    notaFinal = (prova1 * 0.35) + (prova2 * 0.35) + (trabalhoFinal * 0.30);

    if((notaFinal < 6) && (prova1 < 4 || prova2 < 4 || trabalhoFinal < 4)){
        printf("Aluno reprovado sem direito a rec\n");
    }
    else if(notaFinal < 6){
        printf("Aluno devera fazer a rec\n NF = %.2f\n", notaFinal);
    }
    else if(notaFinal >= 6 && (prova1 <= 4 || prova2 <= 4 || trabalhoFinal < 4)){
        printf("Aluno devera fazer a rec por ter uma ou mais notas abaixo\n NF = %.2f\n", notaFinal);
    }
    else if (notaFinal >= 6){
        printf("Aluno aprovado\n NF = %.2f\n", notaFinal);
    }

    return 0;
}