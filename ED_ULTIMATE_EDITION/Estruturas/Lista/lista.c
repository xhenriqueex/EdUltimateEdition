#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct it
{
    void* valor;
    struct it* ant;
    struct it* prox;
} Item;

typedef struct list
{
    Item* primeiro;
    Item* ultimo;
    int tamanho;
} List;

typedef struct pos
{
    List* lista;
    Item* item;
} Pos;

//CRIA E RETORNA UMA LISTA VAZIA
void* cria_lista ()
{
    List* aux;
    aux = (List*) calloc (1, sizeof(List));
    aux->primeiro = NULL;
    aux->ultimo = NULL;
    aux->tamanho = 0;
    return (void*) aux;
}

//VERIFICA O TAMANHO DA LISTA E O RETORNA
int largura_lista (void* lista)
{
    List* aux;
    aux = (List*) lista;
    return aux->tamanho;
}

//INSERE UM ELEMENTO NA LISTA E RETORNA SUA POSIÇÃO
void* insere_lista (void* lista, void* item)
{
    List* aux;
    Item* insert;
    Pos* retorno;
    aux = (List*) lista;
    insert = (Item*) calloc (1, sizeof(Item));
    retorno = (Pos*) calloc (1, sizeof(Pos));
    retorno->lista = aux;
    retorno->item = insert;
    insert->prox = NULL;
    insert->valor = item;
    if (aux->tamanho == 0)
    {
        aux->primeiro = insert;
        aux->ultimo = insert;
        insert->ant = NULL;
        aux->tamanho++;
        return (void*) retorno;
    }
    aux->tamanho++;
    insert->ant = aux->ultimo;
    aux->ultimo->prox = insert;
    aux->ultimo = insert;
    return (void*) retorno;
}

//REMOVE UM ELEMENTO NA LISTA
void remove_lista (void* lista, void* posic)
{
    List* aux;
    aux = (List*) lista;
    Pos* verif;
    verif = (Pos*) posic;
    if (aux->tamanho == 0)
    {
        return;
    }
    if (aux != verif->lista)
    {
        printf ("\nERRO: LISTAS DIFERENTES!");
        return;
    }
    if (verif->item->prox != NULL)
    {
        verif->item->prox->ant = verif->item->ant;
    }
    else
    {
        aux->ultimo = verif->item->ant;
    }
    if(verif->item->ant != NULL)
    {
        verif->item->ant->prox = verif->item->prox;    
    }
    else
    {
        aux->primeiro = verif->item->prox;
    }
    free (verif->item);
    free (verif);
    aux->tamanho--;
    return;   
}

//RETORNA O VALOR DE UM ELEMENTO DA LISTA
void* get_valor_lista (void* lista, void* posic)
{
    List* aux;
    aux = (List*) lista;
    if (aux->tamanho == 0)
    {
        return NULL;
    }
    Pos* verif;
    verif = (Pos*) posic;
    if (aux != verif->lista)
    {
        printf ("\nERRO: LISTAS DIFERENTES!");
        return NULL;
    }
    return (void*) verif->item->valor;
}

//INSERE UM ITEM NA POSIÇÃO ANTERIOR AO INDICADO POR POSIC
void insere_antes_lista (void* lista, void* posic, void* valor)
{
    List* aux;
    aux = (List*) lista;
    Pos* verif;
    verif = (Pos*) posic;
    if (aux->tamanho == 0)
    {
        return insere_lista (lista, valor);
    }
    if (aux != verif->lista)
    {
        printf ("\nERRO: LISTAS DIFERENTES!");
        return NULL;
    }
    Pos* retorno;
    retorno = (Pos*) calloc (1, sizeof(Pos));
    Item* novo;
    novo = (Item*) calloc (1, sizeof(Item));
    novo->prox = verif->item;
    novo->ant = verif->item->ant;
    novo->ant->prox = novo;
    novo->prox->ant = novo;
    novo->valor = valor;
    retorno->lista = aux;
    retorno->item = novo;
    if (aux->primeiro->ant != NULL)
    {
        aux->primeiro = novo;
    }
    return (void*) retorno;
}

//INSERE UM ITEM NA POSIÇÃO POSTERIOR AO INDICADO POR POSIC
void* insere_depois_lista (void* lista, void* posic, void* valor)
{
    List* aux;
    aux = (List*) lista;
    Pos* verif;
    verif = (Pos*) posic;
    if (aux->tamanho == 0)
    {
        return insere_lista (lista, valor);
    }
    if (aux != verif->lista)
    {
        printf ("\nERRO: LISTAS DIFERENTES!");
        return NULL;
    }
    Pos* retorno;
    retorno = (Pos*) calloc (1, sizeof(Pos));
    Item* novo;
    novo = (Item*) calloc (1, sizeof(Item));
    novo->prox = verif->item->prox;
    novo->ant = verif->item;
    novo->ant->prox = novo;
    novo->prox->ant = novo;
    novo->valor = valor;
    retorno->lista = aux;
    retorno->item = novo;
    if (aux->ultimo->prox != NULL)
    {
        aux->ultimo = novo;
    }
    return (void*) retorno;
}

//RETORNA O PRIMEIRO VALOR DA LISTA, CASO LENGTH = 0, RETORNA NULL
void* get_primeiro_lista (void* lista)
{
    List* aux;
    aux = (List*) lista;
    if (aux->tamanho == 0)
    {
        return NULL;
    }
    Pos* retorno;
    retorno = (Pos*) calloc (1, sizeof(Pos));
    retorno->item = aux->primeiro;
    retorno->lista = lista;
    return (void*) retorno;
}

//RETORNA O PRÓXIMO ELEMENTO APONTADO POR POSIC
void* get_proximo_lista (void* lista, void* posic)
{
    List* aux;
    aux = (List*) lista;
    if (aux->tamanho == 0)
    {
        return NULL;
    }
    Pos* verif;
    verif = (Pos*) posic;
    Pos* retorno;
    retorno = (Pos*) calloc (1, sizeof(Pos));
    if (verif->lista != aux)
    {
        printf ("\nERRO: LISTAS DIFERENTES!");
        return NULL;
    }
    if (verif->item->prox == NULL)
    {
        return NULL;
    }
    retorno->lista = aux;
    retorno->item = verif->item->prox;
    return (void*) retorno;
}

//RETORNA O ELEMENTO ANTERIOR A POSIC
void* get_anterior_lista (void* lista, void* posic)
{
    List* aux;
    aux = (List*) lista;
    if (aux->tamanho == 0)
    {
        return NULL;
    }
    Pos* verif;
    verif = (Pos*) posic;
    Pos* retorno;
    retorno = (Pos*) calloc (1, sizeof(Pos));
    if (verif->lista != aux)
    {
        printf ("\nERRO: LISTAS DIFERENTES!");
        return NULL;
    }
    if (verif->item->ant == NULL)
    {
        return NULL;
    }
    retorno->lista = aux;
    retorno->item = verif->item->ant;
    return (void*) retorno;
}

//RETORNA O ÚLTIMO ELEMENTO DA LISTA
void* get_ultimo_lista (void* lista)
{
    List* aux;
    aux = (List*) lista;
    if (aux->tamanho == 0)
    {
        return NULL;
    }
    Pos* retorno;
    retorno = (Pos*) calloc (1, sizeof(Pos));
    retorno->item = aux->ultimo;
    retorno->lista = lista;
    return (void*) retorno;
}

//CONCATENA A SEGUNDA LISTA NA PRIMEIRA
void concat_listas (void* lista1, void* lista2)
{
    List* list1;
    list1 = (List*) lista1;
    List* list2;
    list2 = (List*) lista2;
    if (list1->tamanho == 0)
    {
        list1->primeiro = list2->primeiro;
        list1->ultimo = list2->tamanho;
        list1->tamanho = list2->tamanho;
        return;
    }
    if (list2->tamanho == 0)
    {
        return;
    }
    list1->ultimo->prox = list2->primeiro;
    list2->primeiro->ant = list1->ultimo;
    list1->ultimo = list2->ultimo;
    list1->tamanho += list2->tamanho;
}