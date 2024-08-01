//definição struct data 
struct _DATA
{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
};

typedef struct _DATA data;

struct _agenda
{
    int codigo;
    struct _DATA dataevent;
    float duracao;
    char descricao[100];
    struct _agenda *right;
    struct _agenda *left; 
};

typedef struct _agenda agenda;

//functions they are usually for the program


agenda* searchbyData(agenda*, data);
agenda* searchbydata_and_hour(agenda *, data);
agenda*modifyEvent(agenda*);
agenda *TrashEvent(agenda*, data);
agenda *findMax(agenda *);
void Show_all(agenda*, int);
agenda *includeEvent(agenda*, agenda *);
agenda *_init_tree();
agenda createEvent();
void _clearTree(agenda*);
void _clearNo(agenda*);