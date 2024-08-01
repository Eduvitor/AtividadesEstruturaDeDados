#include <stdio.h>
int main(){
    int mult1, mult2, result, cont;
    printf("digite o numero a ser multiplicado:\n");
    scanf("%d", &mult1);
    printf("Digite o outro:\n");
    scanf("%d", &mult2);
    cont = mult1;
    result = 0;
    while (cont != 0)
    {
        result = result + mult2;
        cont--;
    }
    
    printf("Multiplicacao e %d\n", result);
    
    return 0;
}