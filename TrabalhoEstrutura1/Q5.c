#include <stdio.h>

int main(){
    
    int position;

    printf("Digite a posicao do competidor: \n");
    scanf("%d", &position);
    if (position >= 1 && position <= 5)
    {
        printf("Esta no top 5!\n");
    }
    if (position >= 6 && position <= 10)
    {
        printf("Esta no top 10!\n");
    }
    if (position >= 11 && position <=20)
    {
        printf("Esta no top 20!\n");
    }
    if (position >= 21 && position <= 30)
    {
        printf("Esta no top 30!\n");
    }
    if (position > 30)
    {
        printf("Esta no top 100!\n");
    }
    return 0;
}