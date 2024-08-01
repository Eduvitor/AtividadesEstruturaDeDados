#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "UFFSAgenda.h"


int main(){

    int op, pesq;
    int printa=1;
    data date; //variavel data para pesquisa
    agenda *aux;

    agenda *raiz =_init_tree();

    do
    {
        printf("\t----Menu----\n");
        printf("|[1]-Adicionar!|\n|[2]-Consultar|\n|[3]-Alterar|\n|[4]-Excluir|\n|[5]-Listar Todos|\n|[6]-Sair do programa|\n");
        scanf("%d", &op);
        fflush(stdin);
        switch (op)
        {
        case 1:
            aux=createEvent();
            raiz=includeEvent(raiz, aux);
            break;
        case 2:
            if (raiz==NULL)
            {
                printf("Nao ha eventos para excluir!\n");
            }
            printa=1;
            printf("Selecione o metodo de pesquisa!\n[1]-Pesquisar por data.\n[2]-pesquisar por data e hora");
            scanf("%d", &pesq);
            if (pesq == 1)
            {
                printf("Data (dd/mm/aaaa): ");
                scanf("%d/%d/%d", &date.dia, &date.mes, &date.ano);
                agenda *final=searchbyData(raiz, date);
                if (final != NULL)
                {
                    Show_all(final, printa);
                }else {
                    printf("O evento que voce procura nao foi encontrado!\n");
                }
            }
            if (pesq == 2)
            {
                printf("Digite a data e hora (dd/mm/aaaa hh:mm):\n");
                scanf("%d/%d/%d %d:%d", &date.dia, &date.mes, &date.ano, &date.hora, &date.minuto);
            }
            break;
        case 3:
            break;
        case 4:
            if (raiz==NULL)
            {
                printf("Não há evento para excluir!\n");
                break;
            }
            printf("Digite a data e hora do evento a ser excluido! (dd/mm/aaaa hh:mm):\n");
            scanf("%d/%d/%d %d:%d", &date.dia, &date.mes, &date.ano, &date.hora, &date.minuto);
            agenda *exclude=TrashEvent(raiz, date);
            if (exclude==NULL)
            {
                printf("Evento não encontrado!\n");
            }
            break;
        case 5:
            printa=0;
            Show_all(raiz, printa);
            break;
        case 6:
            printf("Obrigado por utilizar o programa!\n");
            _clearTree(raiz);
            break;
        default:
            printf("OPCAO INVALIDA!");
            break;
        }
    } while (op!=6);
    


    return 1;
}