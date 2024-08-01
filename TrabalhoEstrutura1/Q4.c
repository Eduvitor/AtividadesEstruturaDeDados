#include <stdio.h>
int main(){
    int n1, n2, n3, n4, posi, nega;
    posi = 0;
    nega = 0;
    printf("digite numeros: \n");
    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);
    scanf("%d", &n4);
    if (n1 >= 0)
    {
        posi = posi + 1;
    }else{
        nega = nega + 1;
    }
    if (n2 >= 0)
    {
        posi = posi + 1;
    }else{
        nega = nega + 1;
    }
    if (n3 >= 0)
    {
        posi = posi + 1;
    }else{
        nega = nega + 1;
    }
    if (n4 >= 0)
    {
        posi = posi + 1;
    }else{
        nega = nega + 1;
    }
    printf("Sao positivos: %d\n", posi);
    printf("Sao negativos: %d\n", nega);
    
    return 0;
}