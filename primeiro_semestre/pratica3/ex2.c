/*
Suponha um terminal bancário em que uma pessoa pode realizar operações sobre sua conta.
O programa deve simular o terminal, supondo uma pessoa com saldo de conta bancária
inicial de R$ 700,00.
O programa deve mostrar o menu abaixo para que a pessoa escolha a operação desejada.
1 - Depositar
2 - Sacar
3 - Consultar saldo
4 - Sair
O programa deve ler de teclado a opção escolhida pelo usuário e processá-la da seguinte
forma:
• Se escolher 1, o programa deve pedir o valor do depósito e somar ao saldo.
• Se escolher 2, o programa deve pedir o valor do saque e subtrair do saldo (se houver
saldo suficiente).
• Se escolher 3, o programa deve mostrar o saldo atual da conta.
• Se escolher 4, finalizar o programa.
• Caso digite outra opção, mostre "Operação não disponível".
Observação: você pode mostrar o saldo após cada operação
*/

#include <stdio.h>
void imprimeMenu(void){
    printf("1 - Depositar\n2 - Sacar\n3 - Consultar saldo\n4 - Sair\n");
}

int main(void){

    float saldo = 700;
    float deposito = 0;
    float saque = 0;
    
    while(1){
        int option = 0;

        imprimeMenu();
        scanf("%d", &option);

        switch (option){

            case 1:
                printf("Informe o valor a depositar: ");
                scanf("%f", &deposito);

                saldo += deposito;

                break;

            case 2:
                printf("Informe o valor a sacar: ");
                scanf("%f", &saque);

                if(saque > saldo){
                    printf("Saldo insuficiente: %.2f\n", saldo);
                }
                else{
                    saldo -= saque;
                }

                break;
            
            case 3:
                printf("Seu saldo eh: %.2f\n", saldo);
                break;
            
            case 4:
                return 0;
                break;

            default:
                printf("Opcao invalida\n");

                break;
        }
    }
    return 0;
}