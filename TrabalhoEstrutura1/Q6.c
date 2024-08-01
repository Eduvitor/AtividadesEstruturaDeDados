#include <stdio.h>
int main(){
    int idade;
    printf("Digite a idade: \n");
    scanf("%d", &idade);
    if (idade>=18 && idade<=70)
    {
        printf("Voto Obrigatorio!\n");
    }
    if ((idade>=16 && idade<18) || idade>70)
    {
        printf("Voto facultativo!\n");
    }
    if (idade < 16)
    {
        printf("Nao pode votar!");
    }
    return 0;
}