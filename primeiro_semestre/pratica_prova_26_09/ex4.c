#include <stdio.h>
int main(void)
{
    int x, y, z;
    float k;
    puts("Entre com 3 valores inteiros");
    scanf("%d %d %d", &x, &y, &z);
    k = x / 2 + y / 2 + z / 2;

    printf("Valores originais\nx= %d y=%d z= %d\n", x, y, z);
    printf("\nConversões:\n");
    printf("\nResultado de k= x/2 + y/2 + z/2 = %3.2f\n", k);

    puts("\nVendo os resultados parciais, com formato int:");
    printf("x/2 = %d; y/2 = %d; z/2 = %d\n", x / 2, y / 2, z / 2);

    puts("\nVendo os resultados parciais, com formato float:");
    printf("x/2 = %2.1f; y/2 = %2.1f; z/2 = %2.1f\n", x / 2, y / 2, z / 2);

    puts("\nAgora colocando os denominadores como numeros reais");
    printf("x/2.0 = %2.1f; y/2.0 = %2.1f; z/2.0 = %2.1f\n", x / 2.0, y / 2.0, z / 2.0);

    k = (float)x / 2 + (float)y / 2 + (float)z / 2;
    printf("\nResultado de k = (float)x/2 + (float)y/2 + (float)z/2 = %3.2f\n", k);

    puts("\nConvertendo k para inteiro:");
    printf("Resultado de (int)k = (float)x/2 + (float)y/2 + (float)z/2 = %d\n",(int)k);

    return 0;
}