#include <stdio.h>
int main(){
    int num, cont;
    cont=1;
    printf("Digite um numero: \n");
    scanf("%d", &num);
    while (cont <= num){
        printf("%d\n", cont);
        cont++;
        if (cont == (num/2 + 1))
        {
            printf("Metade!\n");
            continue;
        }
        if (cont == (num/2 + 1.5))
        {
            printf("Metade;\n");
            continue;
        }
        
    }
    
    return 0;
}