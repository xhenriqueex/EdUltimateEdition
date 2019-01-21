#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

#define C "circulo"
#define R "retangulo"
#define A "anotacao"

//INICIA STRUCT ITEM
typedef struct it {
    void* valor;
    char* tipo;
} it;

//CRIA UM ITEM E O RETORNA
Item cria_item (void* Valor, char* tipo)
{
    it* aux = NULL;
    aux = (it*) calloc (1, sizeof (it));
    aux->valor = Valor;
    aux->tipo = (char *) calloc (55, sizeof(char));
    strcpy(aux->tipo, tipo);
    return aux;
}

//PEGA O TIPO DO ITEM
char* get_tipo_item (Item item)
{
    it* aux = NULL;
    aux = (it*) item;
    return aux->tipo;
}

//PEGA O VALOR DO ITEM
Valor get_valor_item (Item item)
{
    it* aux = NULL;
    aux = (it*) item;
    return aux->valor;
}

//LIBERA A MEMÓRIA ALOCADA DOS ITENS
void free_item (Item item)
{
    it* aux = NULL;
    aux = (it*) item;

    if(aux != NULL) {
        if(aux->tipo != NULL) {
            free (aux->tipo);
            aux->tipo = NULL;
        }
        aux->valor = NULL;
        free (aux);
    }
    return; 
}

//ESCREVE AS INFORMAÇÕES DO ITEM NO ARQUIVO
void escreve_arquivo_item (Item item, int procura, FILE* arq)
{
    int i;
    it* aux;
    aux = (it*) item;
    fseek (arq, procura, SEEK_SET);
    for (i=0; i<55; i++)
    {
        fwrite (&aux->tipo[i], sizeof (char), 1, arq);
    }
    if (!strcmp (aux->tipo, R))
    {
        escreve_arquivo_retangulo (aux->valor, ftell (arq), arq);
    }
    if (!strcmp (aux->tipo, C))
    {
        escreve_arquivo_circulo (aux->valor, ftell (arq), arq);
    }
}

//LÊ AS INFORMAÇÕES DO ITEM DO ARQUIVO
void ler_arquivo_item (Item item, int procura, FILE* arq)
{
    int i;
    it* aux;
    aux = (it*) item;
    fseek (arq, procura, SEEK_SET);
    for (i=0; i<55; i++)
    {
        fread (&aux->tipo, sizeof (char), 1, arq);
    }
    if (!strcmp (aux->tipo, R))
    {
        ler_arquivo_retangulo (aux->valor, ftell (arq), arq);
    }
    if (!strcmp (aux->tipo, C))
    {
        ler_arquivo_circulo (aux->valor, ftell (arq), arq);
    }
}

//RETORNA O TAMANHO DO ITEM
int get_tamanho_item ()
{
    return sizeof (int) + get_tamanho_retangulo();
}

//ALOCA A MEMÓRIA NECESSÁRIA PARA O ITEM
void* alloc_item ()
{
    it* item;
    item = (it*) calloc (1, sizeof (it));
    item->valor = alloc_retangulo ();
    return item;
}