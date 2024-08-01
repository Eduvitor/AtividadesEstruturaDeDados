#include <stdio.h>
int main(){
    int numeros = 0; 
    float percem = 0, contador = 0, nument = 0;
    printf("digites numeros:\n");
    scanf("%d", &numeros);
    while (numeros > 0)
    {
        contador++;
        if (numeros >= 10 && numeros <= 20)
        {
            nument = nument + 1;
        }
        scanf("%d", &numeros);
        percem = nument/contador*100;
    }
    printf("percentual: %.2f%%", percem);
    return 0;
}