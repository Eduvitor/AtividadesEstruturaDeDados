#include <stdio.h>
int main(){
    int num, soma, i;
    printf("Num:\n");
    scanf("%d", &num);
    for (i = 0; i <= num; i++)
    {
        soma += i;
    }
    printf("Soma: %d\n", soma);
    return 0;
}