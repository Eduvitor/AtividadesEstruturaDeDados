
//struct data 
struct _data {
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
};

typedef struct _data Data;
//struct do evento
struct _evento {
    int codigo;
    Data dataEvento;
    float duracao;
    char descricao[100];
    struct _evento* proximo;
};
typedef struct _evento Evento;

Evento* criarEvento(int, Data, float, char*);
Evento* AddEvent(Evento*, Evento*);
void listarEventos(Evento*);
void modificarEvento(Evento *, Data);
Evento* SearchBydata(Evento*, Data);
Evento* DateAndHour(Evento*, Data);
Evento* excluirEvento(Evento*, Data);
void ClearAgenda(Evento*);