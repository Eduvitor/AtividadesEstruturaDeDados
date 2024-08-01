#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UFFSagenda.h"

//funçao que vai criar um novo evento:
Evento* criarEvento(int codigo, Data dataEvento, float duracao, char* descricao) {
    Evento* novoEvento = (Evento*)malloc(sizeof(Evento));
    novoEvento->codigo = codigo;
    novoEvento->dataEvento = dataEvento;
    novoEvento->duracao = duracao;
    strcpy(novoEvento->descricao, descricao);
    novoEvento->proximo = NULL;
    return novoEvento;
}

Evento *AddEvent(Evento *agenda, Evento *novo){
    Evento* aux = agenda;
    Evento* aux_ant = NULL;

    if (agenda == NULL) {
        agenda = novo;
        return agenda;
    } else if (novo->dataEvento.ano < agenda->dataEvento.ano) {
        novo->proximo = agenda;
        agenda = novo;
    } else if (novo->dataEvento.ano == agenda->dataEvento.ano && novo->dataEvento.mes < agenda->dataEvento.mes) {
        novo->proximo = agenda;
        agenda = novo;
    } else if (novo->dataEvento.ano == agenda->dataEvento.ano && novo->dataEvento.mes == agenda->dataEvento.mes && novo->dataEvento.dia < agenda->dataEvento.dia) {
        novo->proximo = agenda;
        agenda = novo;
    } else if (novo->dataEvento.ano == agenda->dataEvento.ano && novo->dataEvento.mes == agenda->dataEvento.mes && novo->dataEvento.dia == agenda->dataEvento.dia && novo->dataEvento.hora < agenda->dataEvento.hora) {
        novo->proximo = agenda;
        agenda = novo;
    } else if (novo->dataEvento.ano == agenda->dataEvento.ano && novo->dataEvento.mes == agenda->dataEvento.mes && novo->dataEvento.dia == agenda->dataEvento.dia && novo->dataEvento.hora == agenda->dataEvento.hora && novo->dataEvento.minuto < agenda->dataEvento.minuto) {
        novo->proximo = agenda;
        agenda = novo;
    } else {
        while (aux != NULL &&
           (aux->dataEvento.ano < novo->dataEvento.ano ||
            (aux->dataEvento.ano == novo->dataEvento.ano && aux->dataEvento.mes < novo->dataEvento.mes) ||
            (aux->dataEvento.ano == novo->dataEvento.ano && aux->dataEvento.mes == novo->dataEvento.mes && aux->dataEvento.dia < novo->dataEvento.dia) ||
            (aux->dataEvento.ano == novo->dataEvento.ano && aux->dataEvento.mes == novo->dataEvento.mes && aux->dataEvento.dia == novo->dataEvento.dia && aux->dataEvento.hora < novo->dataEvento.hora) ||
            (aux->dataEvento.ano == novo->dataEvento.ano && aux->dataEvento.mes == novo->dataEvento.mes && aux->dataEvento.dia == novo->dataEvento.dia && aux->dataEvento.hora == novo->dataEvento.hora && aux->dataEvento.minuto < novo->dataEvento.minuto))) {
            aux_ant = aux;
            aux = aux->proximo;
        }

    if (aux == NULL) {
        aux_ant->proximo = novo;
    }
    novo->proximo = aux;
    aux_ant->proximo = novo;
    }
    return agenda;
}

void listarEventos(Evento* agenda) {
    if (agenda == NULL) {
        printf("Agenda Vazia\n");
    } else {
        Evento* aux = agenda;
        while (aux != NULL) {
            printf("|Codigo: %d\n", aux->codigo);
            printf("|Data: %02d/%02d/%04d\n", aux->dataEvento.dia, aux->dataEvento.mes, aux->dataEvento.ano);
            printf("|Hora: %02d:%02d\n", aux->dataEvento.hora, aux->dataEvento.minuto);
            printf("|Duracao: %.2f\n", aux->duracao);
            printf("|Descricao: %s\n", aux->descricao);
            printf("---------------------\n");
            aux = aux->proximo;
        }
    }
}

Evento* SearchBydata(Evento* agenda, Data dataConsulta) {
    Evento* resultado = NULL;
    Evento* aux = agenda;
    while (aux != NULL) {
        if (aux->dataEvento.dia == dataConsulta.dia && aux->dataEvento.mes == dataConsulta.mes && aux->dataEvento.ano == dataConsulta.ano) {
            Evento* novoEvento = criarEvento(aux->codigo, aux->dataEvento, aux->duracao, aux->descricao);
            resultado = AddEvent(resultado, novoEvento);
        }
        aux = aux->proximo;
    }
    return resultado;
}

Evento* DateAndHour(Evento* agenda, Data dataHoraConsulta) {
    Evento* resultado = NULL;
    Evento* aux = agenda;
    while (aux != NULL) {
        if (aux->dataEvento.dia == dataHoraConsulta.dia && aux->dataEvento.mes == dataHoraConsulta.mes && aux->dataEvento.ano == dataHoraConsulta.ano &&
            aux->dataEvento.hora == dataHoraConsulta.hora && aux->dataEvento.minuto == dataHoraConsulta.minuto) {
            Evento* novoEvento = criarEvento(aux->codigo, aux->dataEvento, aux->duracao, aux->descricao);
            resultado = AddEvent(resultado, novoEvento);
            break;
        }
        aux = aux->proximo;
    }
    return resultado;
}

void modificarEvento(Evento* agenda, Data data) {
    Evento* aux = agenda;
    char Newdesc[100];
    float newDur;
    while (aux != NULL) {
        if (aux->dataEvento.dia == data.dia &&
            aux->dataEvento.mes == data.mes &&
            aux->dataEvento.ano == data.ano && 
            aux->dataEvento.hora == data.hora &&
            aux->dataEvento.minuto==data.minuto) {
            printf("Nova duracao: ");
            scanf(" %f", &newDur);
            printf("Nova descricao: ");
            fflush(stdin); //ou __fpurge(stdin); para linux
            gets(Newdesc);
            strcpy(aux->descricao, Newdesc);
            aux->duracao = newDur;
            printf("Evento modificado!\n");
            return;
        }
        aux = aux->proximo;
    }
    printf("Evento nao encontrado!\n");
}


Evento* excluirEvento(Evento* agenda, Data Excluir) {
    if (agenda == NULL) {
        return NULL;
    } else if (agenda->dataEvento.dia == Excluir.dia && agenda->dataEvento.mes == Excluir.mes && agenda->dataEvento.ano == Excluir.ano &&
               agenda->dataEvento.hora == Excluir.hora && agenda->dataEvento.minuto == Excluir.minuto) {
            Evento* aux = agenda;
            agenda = agenda->proximo;
            free(aux);
            printf("Evento deletado!\n");
            return agenda;
    } else {
        Evento* aux = agenda;
        Evento* ant = NULL;
        while (aux != NULL) {
            if (aux->dataEvento.dia == Excluir.dia && aux->dataEvento.mes == Excluir.mes && aux->dataEvento.ano == Excluir.ano &&
                aux->dataEvento.hora == Excluir.hora && aux->dataEvento.minuto == Excluir.minuto) {
                ant->proximo = aux->proximo;
                free(aux);
                printf("Evento deletado!\n");
                return agenda;
            }
            ant = aux;
            aux = aux->proximo;
        }
        printf("Compromisso nao encontrado!\n");
        return agenda;
    }
}

void ClearAgenda(Evento* agenda) {
    Evento* aux = agenda;
    while (aux != NULL) {
        Evento* proximo = aux->proximo;
        free(aux);
        aux = proximo;
    }
}
