#include <stdio.h>
int main(){
    float horas, valorhoras, salario;
    printf("Digite as horas trabalhadas:\n");
    scanf("%f", &horas);
    printf("Digite o valor da hora:\n");
    scanf("%f", &valorhoras);
    if (horas > 200)
    {
        salario = horas * valorhoras;
        salario = salario + (salario*0.05);
        printf("Horas Trabalhadas:%.2f\nValor da hora:%.2f\nSalario final: %.2f\n", horas, valorhoras, salario);
    }else{
        salario = horas * valorhoras;
        printf("Horas Trabalhadas:%.2f\nValor da hora:%.2f\nSalario final: %.2f\n", horas, valorhoras, salario);
    }
    return 0;
}