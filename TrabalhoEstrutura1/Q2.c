#include <stdio.h>
int main(){
    int metodopag;
    float valorproduto;
    printf("Digite o valor do produto: \n");
    scanf("%f", &valorproduto);
    printf("Metodo de pagamento: (1 para a vista, 2 para a prazo)\n");
    scanf("%d", &metodopag);
    if (metodopag == 1)
    {
        valorproduto = valorproduto * 0.95;
        printf("Valor do produto: %.2f\n", valorproduto);
    }
    if(metodopag == 2)
    {
        valorproduto = valorproduto * 1.10;
        printf("Valor do produto: %.2f\n", valorproduto);
    }
    return 0;
}