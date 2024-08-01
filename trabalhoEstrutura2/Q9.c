#include <stdio.h>
int main(){
    /*variaveis*/
    int somaA=0, somaB=0, somaC=0, somaD=0;
    char time1, time2;
    int ngols1, ngols2;

    printf("Time1:\n");
    scanf("%c", &time1);

    while (time1 == 'A' || time1 == 'B' || time1 == 'C' || time1 == 'D'){

        printf("Gols1:\n");
        scanf("%d", &ngols1);
        printf("Time2:\n");
        scanf(" %c", &time2);
        printf("gols2:\n");
        scanf("%d", &ngols2);
        /*Testes*/
        if (ngols1 == ngols2){
            if (time1 == 'A' || time2 == 'A'){
                somaA+=1;
            }
            if (time1 == 'B' || time2 == 'B'){
                somaB+=1;
            }
            if (time1 == 'C' || time2 == 'C'){
                somaC+=1;
            }
            if (time1 == 'D' || time2 == 'D'){
                somaD+=1;
            }
        }
        if (ngols1 > ngols2){

            if (time1 == 'A'){
                somaA+=3;
            }

            if (time1 == 'B'){
                somaB+=3;
            }

            if (time1 == 'C'){
                somaC+=3;
            }

            if (time1 == 'D'){
                somaD+=3;
            }
        }
         if (ngols1 < ngols2){

            if (time2 == 'A'){
                somaA+=3;
            }

            if (time2 == 'B'){
                somaB+=3;
            }

            if (time2 == 'C'){
                somaC+=3;
            }

            if (time2 == 'D'){
                somaD+=3;
            }
        }
        printf("Time1:\n");
        scanf(" %c", &time1);
    }

    printf("Pontuacao A:\t%d\n", somaA);
    printf("Pontuacao B:\t%d\n", somaB);
    printf("Pontuacao C:\t%d\n", somaC);
    printf("Pontuacao D:\t%d\n", somaD);

    printf("\n");
    /*Verificaco de campeao ou empate*/
    if (somaA > somaB && somaA > somaC && somaA > somaD){
        printf("A campeao\n");
    } else if (somaB > somaC && somaB > somaD && somaB > somaA) {
        printf("B campeao\n");
    } else if (somaC > somaD && somaC > somaB && somaC > somaA) {
        printf("C campeao\n");
    } else if (somaD > somaA && somaD > somaB && somaD > somaC) {
        printf("D campeao\n");
    } else {
        printf("Sem campeao");
    }
    return 0;
}