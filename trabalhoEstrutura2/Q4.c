#include <stdio.h>
int mostramenu(){
    printf("Operacao: +, -, /, *\n");
    return 0;
}
int main(){
    float num, num1, result;
    char operacao;
    mostramenu();
    scanf("%c", &operacao);
    while (operacao != '@')
    {
        if (operacao == '+')
        {
            printf("Primeiro num:\n");
            scanf("%f", &num);
            printf("Segundo num:\n");
            scanf("%f", &num1);
            result = num + num1;
            printf("Soma: %.2f\n", result);
        }
        if (operacao == '-')
        {
            printf("Primeiro num:\n");
            scanf("%f", &num);
            printf("Segundo num:\n");
            scanf("%f", &num1);
            result = num - num1;
            printf("Subtracao: %.2f\n", result);
        }
        if (operacao == '*')
        {
            printf("Primeiro num:\n");
            scanf("%f", &num);
            printf("Segundo num:\n");
            scanf("%f", &num1);
            result = num * num1;
            printf("Multiplicacao: %.2f\n", result);
        }
        if (operacao == '/')
        {
            printf("Primeiro num:\n");
            scanf("%f", &num);
            printf("Segundo num:\n");
            scanf("%f", &num1);
            result = num / num1;
            printf("Divisao: %.2f\n", result);
        }
        mostramenu();
        scanf(" %c", &operacao);
        
    }
    return 0;
}