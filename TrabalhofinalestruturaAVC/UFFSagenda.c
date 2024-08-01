#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "UFFSAgenda.h"


//funcao responsavel por iniciar nossa "arvore"
agenda *_init_tree(){
    return NULL;
}

//função que vai percorrer recursivamente e dara free nos nós
void _clearNo(agenda* no){
    if(no == NULL)
        return;
    _clearNo(no->left);
    _clearNo(no->right);
    free(no);
    no=NULL;
}

//funcao responsavel por limpar totalmente nossa arvore
void _clearTree(agenda* root){
    if (root==NULL)
        return;
    _clearNo(root);
    free(root);
}

void Show_all(agenda *tree, int cod)
{
    if (cod == 1)
    {
        printf("|Codigo: %d\n|Data: %02d/%02d/%04d\n|Hora: %d:%d\n|Duracao: %2.f\n|Descricao: %s\n", tree->codigo, tree->dataevent.dia, tree->dataevent.mes, tree->dataevent.ano, tree->dataevent.hora, tree->dataevent.minuto, tree->duracao, tree->descricao);
        return;
   }else {
        if (tree != NULL){
            printf("-------------------------------\n");
            Show_all(tree->left, cod);
            Show_all(tree->right, cod);
            printf("|Codigo: %d\n|Data: %02d/%02d/%04d\n|Hora: %d:%d\n|Duracao: %2.f\n|Descricao: %s\n", tree->codigo, tree->dataevent.dia, tree->dataevent.mes, tree->dataevent.ano, tree->dataevent.hora, tree->dataevent.minuto, tree->duracao, tree->descricao);
        }
    }
}

agenda *createEvent(){
    agenda *new=(agenda *)malloc(sizeof(agenda));
    if (new==NULL)
    {
        printf("erro de alocação!");
        return NULL;
    }
    
    printf("Digite o codigo do evento:\n");
    fflush(stdin);
    scanf("%d", &new->codigo);
    printf("DIgite a data e hora do evento (dd/mm/aaaa hh:mm)!\n");
    fflush(stdin);
    scanf("%d/%d/%d %d:%d", &new->dataevent.dia, &new->dataevent.mes, &new->dataevent.ano, &new->dataevent.hora, &new->dataevent.minuto);
    printf("Digite a descricao:\n");
    fflush(stdin);
    gets(new->descricao);
    printf("Digite a duracao:\n");
    fflush(stdin);
    scanf("%f", &new->duracao);
    new->left=NULL;
    new->right=NULL;
    return new;
}

agenda *includeEvent(agenda* root, agenda* new){
    if (root == NULL){
        return new;
    }else {
        if (new->dataevent.ano < root->dataevent.ano){
            root->left = includeEvent(root->left, new);//se o ano for menor caminha pra esquerda
        }else if (new->dataevent.ano > root->dataevent.ano){
            root->right = includeEvent(root->right, new);//se o ano for maior caminha pra direita 
            }else {//se nao for nenhum nem outro vamos para outras comparações
                if (new->dataevent.mes < root->dataevent.mes){
                    root->left = includeEvent(root->left, new);
                }else if (new->dataevent.mes > root->dataevent.mes){
                    root->right = includeEvent(root->right, new);        
                }else {
                    if (new->dataevent.dia < root->dataevent.dia){
                        root->left = includeEvent(root->left, new);
                    }else if (new->dataevent.dia > root->dataevent.dia){
                        root->right = includeEvent(root->right, new);
                    } else {
                        if (new->dataevent.hora < root->dataevent.hora){
                            root->left = includeEvent(root->left, new);
                        }else if (new->dataevent.hora > root->dataevent.hora){
                            root->right = includeEvent(root->right, new);
                        }else{
                            if (new->dataevent.minuto <= root->dataevent.minuto){
                                root->left = includeEvent(root->left, new);
                            }else {
                                root->right = includeEvent(root->right, new);
                            }   
                        }    
                    }   
                }   
            }
        }
    return root;
}

agenda *searchbydata_and_hour(agenda *arvore, data busca){
    if (arvore == NULL){
        return NULL; //arvore é NULL portanto está vazia ou nao foi encontrado o elemento e retornara NULL 
    }
    if (arvore->dataevent.ano == busca.ano && arvore->dataevent.mes == busca.mes && arvore->dataevent.dia == busca.dia){
        return arvore;
    }else if (busca.ano > arvore->dataevent.ano){
        return searchbydata_and_hour(arvore->right, busca);
    }else if (busca.ano < arvore->dataevent.ano){
        return searchbydata_and_hour(arvore->left, busca);
    }else {
        if (busca.mes > arvore->dataevent.mes){
            return searchbydata_and_hour(arvore->right, busca);
        }else if (busca.mes < arvore->dataevent.mes){
            return searchbydata_and_hour(arvore->left, busca);
        }else{
            if (busca.dia > arvore->dataevent.dia){
                return searchbydata_and_hour(arvore->right, busca);
            }else if (busca.dia < arvore->dataevent.dia){
                return searchbydata_and_hour(arvore->left, busca);
            }else{
                if (busca.hora > arvore->dataevent.hora)
                {
                    return searchbydata_and_hour(arvore->right, busca);
                }else if (busca.hora < arvore->dataevent.hora){
                    return searchbydata_and_hour(arvore->left, busca);
                }else if (busca.minuto >= arvore->dataevent.minuto){
                    return searchbydata_and_hour(arvore->right, busca);
                }else{
                    return searchbydata_and_hour(arvore->left, busca);
                }  
            }       
        }    
    }    
}

agenda* searchbyData(agenda *arvore, data busca){
    agenda *aux=arvore;
    
    if (arvore == NULL){
        return NULL; //arvore é NULL portanto está vazia ou nao foi encontrado o elemento e retornara NULL 
    }
    if (arvore->dataevent.ano == busca.ano && arvore->dataevent.mes == busca.mes && arvore->dataevent.dia == busca.dia){
        return arvore;
    }else if (busca.ano > arvore->dataevent.ano){
        return searchbyData(arvore->right, busca);
    }else if (busca.ano < arvore->dataevent.ano){
        return searchbyData(arvore->left, busca);
    }else {
        if (busca.mes > arvore->dataevent.mes){
            return searchbyData(arvore->right, busca);
        }else if (busca.mes < arvore->dataevent.mes){
            return searchbyData(arvore->left, busca);
        }else{
            if (busca.dia >= arvore->dataevent.dia){
                return searchbyData(arvore->right, busca);
            }else {
                return searchbyData(arvore->left, busca);
            }   
        }    
    }    
}

agenda *TrashEvent(agenda *arvore, data busca){
    if (arvore==NULL)
    {
        return NULL;
    }else {
        if (arvore->dataevent.ano==busca.ano && arvore->dataevent.mes==busca.mes && arvore->dataevent.dia==busca.dia && arvore->dataevent.hora==busca.hora && arvore->dataevent.minuto==busca.minuto)
        {
            if (arvore->left==NULL && arvore->right==NULL) //se o no n tem filhos remove.
            {
                free(arvore);
                printf("Evento excluido sem filhos!\n");
                return NULL;
            }else
            {
                if (arvore->left!=NULL && arvore->right!=NULL)
                {
                    //no com dois filhos
                    agenda *aux=arvore->left;
                    while (aux->right!=NULL)
                    {
                        aux=aux->right;
                    }
                    arvore->codigo=aux->codigo;
                    arvore->dataevent.ano=aux->dataevent.ano;
                    arvore->dataevent.mes=aux->dataevent.mes;
                    arvore->dataevent.dia=aux->dataevent.dia;
                    arvore->dataevent.hora=aux->dataevent.hora;
                    arvore->dataevent.minuto=aux->dataevent.minuto;
                    strcpy(arvore->descricao, aux->descricao);
                    arvore->duracao=aux->duracao;
                    aux->codigo=arvore->codigo;
                    aux->dataevent.ano=arvore->dataevent.ano;
                    aux->dataevent.mes=arvore->dataevent.mes;
                    aux->dataevent.dia=arvore->dataevent.dia;
                    aux->dataevent.hora=arvore->dataevent.hora;
                    aux->dataevent.minuto=arvore->dataevent.minuto;
                    strcpy(aux->descricao, arvore->descricao);
                    aux->duracao=arvore->duracao;
                    arvore->left=TrashEvent(arvore->left, busca);
                    return arvore;
                }else
                {
                    //no com um filho
                    agenda *aux;
                    if (arvore->left != NULL)
                    {
                        aux=arvore->left;
                    }else {
                        aux=arvore->right;
                    }
                    free(arvore);
                    printf("Evento deletado com 1 filho,!\n");
                    return aux;
                }
            }
        }
        else 
        {
        if (busca.ano < arvore->dataevent.ano){
            arvore->left = TrashEvent(arvore->left, busca);//se o ano for menor caminha pra esquerda
        }else if (busca.ano > arvore->dataevent.ano){
            arvore->right = TrashEvent(arvore->right, busca);//se o ano for maior caminha pra direita 
            }else {//se nao for nenhum nem outro vamos para outras comparações
                if (busca.mes < arvore->dataevent.mes){
                    arvore->left = TrashEvent(arvore->left, busca);
                }else if (busca.mes > arvore->dataevent.mes){
                    arvore->right = TrashEvent(arvore->right, busca);        
                }else {
                    if (busca.dia < arvore->dataevent.dia){
                        arvore->left = TrashEvent(arvore->left, busca);
                    }else if (busca.dia > arvore->dataevent.dia){
                        arvore->right = TrashEvent(arvore->right, busca);
                    } else {
                        if (busca.hora < arvore->dataevent.hora){
                            arvore->left = TrashEvent(arvore->left, busca);
                        }else if (busca.hora > arvore->dataevent.hora){
                            arvore->right = TrashEvent(arvore->right, busca);
                        }else{
                            if (busca.minuto <= arvore->dataevent.minuto){
                                arvore->left = TrashEvent(arvore->left, busca);
                            }else {
                                arvore->right = TrashEvent(arvore->right, busca);
                            }   
                        }    
                    }   
                }   
            }
        return arvore;
        }   
    }
    return NULL;
}