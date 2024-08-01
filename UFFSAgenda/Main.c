#include <stdio.h>
#include <string.h>
#include "UFFSagenda.h"



int main() {
    Evento* agenda = NULL;

    int opcao;
    do {
        printf("\n\t---- Menu ----\n");
        printf("[1] - Incluir evento\n");
        printf("[2] - Consultar eventos por data ou por data e hora\n");
        printf("[3] - Modificar Evento\n");
        printf("[4] - Excluir evento\n");
        printf("[5] - Listar todos os eventos\n");
        printf("[6] - Sair\n");
        printf("\n");
        printf("Escolha uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int codigo;
                Data dataEvento;
                float duracao;
                char descricao[100];

                printf("Codigo do evento: ");
                fflush(stdin);
                scanf("%d", &codigo);
                printf("Data (dd/mm/aaaa): ");
                fflush(stdin);
                scanf("%d/%d/%d", &dataEvento.dia, &dataEvento.mes, &dataEvento.ano);
                printf("Hora (hh:mm): ");
                fflush(stdin);
                scanf("%d:%d", &dataEvento.hora, &dataEvento.minuto);
                printf("Duracao: ");
                scanf("%f", &duracao);
                fflush(stdin); //ou __fpurge(stdin); caso seja linux
                printf("Descricao: ");
                gets(descricao);

                Evento* novoEvento = criarEvento(codigo, dataEvento, duracao, descricao);
                agenda = AddEvent(agenda, novoEvento);

                printf("\tEvento incluido!\n");
                break;
            }
            case 2: {
                Data dataConsulta;
                int tipoConsu;
                if (agenda==NULL)
                {
                    printf("Nenhum evento adicionado!\n");
                    break;
                }
                printf("Escolha o tipo de pequisa: \n[1]-Por data:\n[2]-Por data e hora:\n");
                scanf( "%d", &tipoConsu);
                if (tipoConsu==1)
                {
                    printf("Data para consulta (dd/mm/aaaa): ");
                    scanf(" %d/%d/%d", &dataConsulta.dia, &dataConsulta.mes, &dataConsulta.ano);

                    Evento* busca2 = SearchBydata(agenda, dataConsulta);
                    printf("\n\t--- Eventos na data %02d/%02d/%04d ---\n", dataConsulta.dia, dataConsulta.mes, dataConsulta.ano);
                    listarEventos(busca2);

                    ClearAgenda(busca2);
                }
                if (tipoConsu==2)
                {
                    Data dataHoraConsulta;
                    printf("Data e Hora para consulta (dd/mm/aaaa hh:mm): ");
                    scanf(" %d/%d/%d %d:%d", &dataHoraConsulta.dia, &dataHoraConsulta.mes, &dataHoraConsulta.ano, &dataHoraConsulta.hora, &dataHoraConsulta.minuto);

                    Evento* busca3 = DateAndHour(agenda, dataHoraConsulta);
                    printf("\n\t--- Evento na data e hora %02d/%02d/%04d %02d:%02d ---\n", dataHoraConsulta.dia, dataHoraConsulta.mes, dataHoraConsulta.ano,
                    dataHoraConsulta.hora, dataHoraConsulta.minuto);
                    listarEventos(busca3);
                    ClearAgenda(busca3);
                }else if (tipoConsu != 1 && tipoConsu !=2)
                {
                    printf("Opcao invalida voltando ao menu");
                }
                break;
            }
            case 3: {
                if (agenda==NULL)
                {
                    printf("Nao ha evento para modificar!\n");
                    break;
                }
                Data Tomodify;
                printf("Digite a data e hora do evento (dd/mm/aaaa hh/mm): ");
                scanf("%d/%d/%d %d:%d", &Tomodify.dia, &Tomodify.mes, &Tomodify.ano, &Tomodify.hora, &Tomodify.minuto);
                modificarEvento(agenda, Tomodify);
                break;
            }
            case 4: {
                if (agenda==NULL)
                {
                    printf("nenhum evento adicionado!\n");
                    break;
                }
                Data Excluir;
                printf("Data e Hora do evento a excluir (dd/mm/aaaa hh:mm): ");
                scanf("%d/%d/%d %d:%d", &Excluir.dia, &Excluir.mes, &Excluir.ano, &Excluir.hora, &Excluir.minuto);

                agenda = excluirEvento(agenda, Excluir);
                break;
            }
            case 5: {
                printf("\t\n--- Todos os Eventos ---\n");
                listarEventos(agenda);
                break;
            }
            case 6: {
                printf("Encerrando o programa.\n");
                ClearAgenda(agenda);
                break;
            }
            default: {
                printf("Opção inválida!\n");
                break;
            }
        }
    } while (opcao != 6);

    return 0;
}
