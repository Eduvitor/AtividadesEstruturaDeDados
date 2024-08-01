#include <stdio.h>

int main() {
    int an = 150, ca = 110, anos = 0;
    while (ca < an) {
        an += 2;
        ca += 3;
        anos++;
        printf("%d | %d\n", an, ca);
    }
    printf("Em %d anos Carlos tera a mesma altura que Antonio\n", anos);
    return 0;
}
