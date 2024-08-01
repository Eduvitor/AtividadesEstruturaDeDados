#include <stdio.h>
int main(){
    int matricula, i, alunos;
    float notas, notamed, notasoma, somamed;
    somamed = alunos = 0;
    printf("Matricula:\n");
    scanf("%d", &matricula);
    while (matricula != 0)
    {
        alunos++;
        notasoma = 0;
        for ( i = 1; i <= 10 ; i++)
        {
            printf("Nota %d:\n", i);
            scanf("%f", &notas);
            notasoma=notasoma + notas;
        }
        notamed = notasoma/10;
        somamed = somamed + notamed;
        printf("%d, %.2f\n", matricula, notamed);
        printf("Matricula:\n");
        scanf("%d", &matricula);
        
    }
    somamed = somamed/alunos;
    printf("Media geral da turma: %.2f\n", somamed);

    
    return 0;
}