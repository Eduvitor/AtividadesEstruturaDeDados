#include <stdio.h>
int main(){
    int hora1, hora2, duracao;
    printf("Digite a hora de inicio do evento:\n");
    scanf("%d", &hora1);
    printf("Digite a hora de termino do evento:\n");
    scanf("%d", &hora2);
    if (hora1 > hora2)
    {
        duracao = 24 - hora1 + hora2;
        printf("A duracao sera de %d horas.\n", duracao);
    }else{
        duracao = hora2 - hora1;
         printf("A duracao sera de %d horas.\n", duracao);
    }
    return 0;
    
   

}