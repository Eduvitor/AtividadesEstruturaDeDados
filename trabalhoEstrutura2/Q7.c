#include <stdio.h>

int main(){
    int numfilhos, i, gg;
    float salario, s, ff, aa;
    gg=0;
    printf("Digite salario:\n");
    scanf("%f", &salario);
    while (salario > 0)
    {
        s = s + salario;
        printf("Numero de filhos:\n");
        scanf("%d", &numfilhos);
        i++;
        gg = gg + numfilhos;
        printf("Digite salario:\n");
        scanf("%f", &salario);
    }
    ff = s/i;
    aa = gg/i;
    printf("Media de salarios: %.2f\nMedia de filhos: %.2f\n", ff, aa);
    return 0;
}