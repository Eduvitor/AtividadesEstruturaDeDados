#include <stdio.h>

int main(){
    int fatorial, num;
    printf("Digite o numero a ser fatorado: \n");
    scanf("%d", &num);
    for ( fatorial = 1; num > 1; num --)
    {
        fatorial = fatorial * num;
    }
    printf("\nFatorial e %d\n", fatorial);
    return 0;
}