
#include <stdio.h>

#define TAM_CARROS 3

typedef struct{
    int cod;
    char modelo[45];
    char marca[45];
    float preco;
    int ano;
}CARRO;

enum {
    CADASTRAR = 1,
    CONSULTAR,
    VALOR_MEDIO,
    ESTOQUE,
    FIM
};

int menu(void){

    int opcao;
    printf("\n");
    printf("1 – Cadastro de carro\n");
    printf("2 – Consulta de carro\n");
    printf("3 – Preco médio dos carros\n");
    printf("4 – Imprime estoque revenda\n");
    printf("5 – Fim\n");
    printf("Entre com sua opção: ");
    scanf("%d", &opcao);
    
    return opcao;
}

CARRO le_Carro(void){

    CARRO new_car;

    printf("code: ");
    scanf("%d", &new_car.cod);

    printf("modelo: ");
    scanf("%s", new_car.modelo);

    printf("marca: ");
    scanf("%s", new_car.marca);

    printf("preco: ");
    scanf("%f", &new_car.preco);

    printf("ano: ");
    scanf("%d", &new_car.ano);

    return new_car;

} 

void print_carro(CARRO carros){
    printf("codigo: %d\n", carros.cod);
    printf("modelo: %s\n", carros.modelo);
    printf("marca: %s\n", carros.marca);
    printf("preco: %.2f\n", carros.preco);
    printf("ano: %d\n", carros.ano);
    printf("\n\n");  
}

CARRO procuraCarro(CARRO carros[], int ncarros, int cod){

    CARRO foundedCar;
    foundedCar.cod = -1;

    for(int i = 0; i < ncarros; i++){
        if(carros[i].cod == cod){
            foundedCar = carros[i];
            return foundedCar;
        }
    }

    return foundedCar;
}

float calcMediaPreco(CARRO carros[], int ncarros){

    float media = 0;
    for(int i = 0; i < ncarros; i++){
        media += carros[i].preco;
    }

    return media / ncarros;
}

int main(void){

    CARRO carros[TAM_CARROS];
    int option = 0;
    int ncarros = 0;

    while(1){

        option = menu();
        printf("\n");

        switch (option){

        case CADASTRAR:
            if(ncarros < 3){
                carros[ncarros] = le_Carro();
                ncarros++;
            } 
            else {
                printf("Numero maximo de carros atingido\n");
            }
            break;
        
        case CONSULTAR:
            int cod = -1;

            printf("Digite o codigo: ");
            scanf("%d", &cod);
            CARRO foundedCar = procuraCarro(carros, ncarros, cod);

            if(foundedCar.cod > -1){
                print_carro(foundedCar);
            }
            else{
                printf("Carro nao encontrado\n");
            }
            break;

        case VALOR_MEDIO:
            float media = calcMediaPreco(carros, ncarros);
            printf("Valor medio: R$%.2f\n", media);
            break;

        case ESTOQUE:
            for(int i = 0; i < ncarros; i++){
                printf("CARRO %d\n", i + 1);
                print_carro(carros[i]);
            }
            break;

        default:
            printf("Digite uma opcao valida\n");
            break;
        }
    }
    
    return 0;
}