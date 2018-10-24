#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

//INICIA SRUCT ITEM
typedef struct it {
    void* valor;
    char* tipo;
}it;

//DEFINE O TIPO DO ITEM
typedef void* Item;

//DEFINE O TIPO DO VALOR
typedef void* Valor;

//CRIA UM ITEM E O RETORNA
Item cria_item (void* Valor, char* tipo)
{
    it* aux;
    aux = (it*) calloc (1, sizeof(it));
    aux->valor = Valor;
    aux->tipo = tipo;
    return aux;
}

//PEGA O TIPO DO ITEM
char* get_tipo_item (Item item)
{
    it* aux;
    aux = (it*) item;
    return aux->type;
}

//PEGA O VALOR DO ITEM
Valor get_valor_item (Item item)
{
    it* aux;
    aux = (it*) item;
    return aux->value;
}

//LIBERA A MEMÓRIA ALOCADA DOS ITENS
void free_item (Item item)
{
    it* aux;
    aux = (it*) item;
    free (aux->type);
    free (aux);
    return; 
}