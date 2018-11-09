#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Lista/lista.h"

//DEFINE A STRUCT HASHTABLE
typedef struct hash {
    int modulo;
    int (*compare) (void*, void*);
    int (*hash) (void*, int);
    void **hashtable;
} Hash_table;

//CRIA UMA HASHTABLE DE MODULO N
void* cria_hashtable (int modulo, int (*compare) (void*, void*), int (*hash) (void*, int))
{
    Hash_table* table;
    table = (Hash_table*) calloc (1, sizeof (Hash_table));
    table->modulo = modulo;
    table->compare = compare;
    table->hash = hash;
    table->hashtable = (Lista*) calloc (modulo, sizeof (Lista));
    int i;
    for(i=0; i<modulo; i++)
    {
        *(table->hashtable + i) = cria_lista();
    }
    return (void*) table;
}

//INSERE UM ITEM NA HASHTABLE
void insere_hashtable (void* hash, void* item)
{
    Hash_table* table;
    table = (Hash_table*) hash;
    int hashcode = table->hash (item, table->modulo);
    insere_lista (*(table->hashtable + hashcode), item);
}

//REMOVE UM ITEM DA HASHTABLE
void remove_hashtable (void* hash, void* item)
{
    Hash_table* table;
    table = (Hash_table*) hash;
    int hashcode = table->hash (item, table->modulo);    
    Lista list = *(table->hashtable + hashcode);
    Posic t;
    t= get_primeiro_lista (list);
    while(t != NULL)
    {
        void* aux;
        aux = get_valor_lista (list,t);
        if(table->compare (aux, item) == 0)
        {
            remove_lista (list, t);
            return;
        }        
        t = get_proximo_lista (list, t);
    }
}

//RETORNA UM ITEM DA HASHTABLE
void* get_hashtable (void* hash, void* ident)
{
    Hash_table* table;
    table = (Hash_table*) hash;
    int hashcode = table->hash (ident, table->modulo);    
    Lista list = *(table->hashtable + hashcode);
    Posic t;
    t = get_primeiro_lista (list);
    while (t != NULL)
    {
        void* aux;
        aux = get_valor_lista (list,t);
        if(table->compare (aux, ident) == 0)
        {
            return aux;
        }        
        t = get_proximo_lista (list, t);
    }
    return NULL;
}

//RETORNA UM LISTA DE ITENS DA HASHTABLE
Lista get_lista_hashtable (void* hash, void* ident)
{
    Hash_table* table;
    table = (Hash_table*) hash;
    int hashcode = table->hash (ident, table->modulo);    
    Lista list = *(table->hashtable + hashcode);
    Lista result = cria_lista();
    Posic t;
    t = get_primeiro_lista (list);
    while (t != NULL)
    {
        void* aux;
        aux = get_valor_lista (list,t);
        if (table->compare (aux, ident) == 0)
        {
            insere_lista (result, aux);
        }        
        t = get_proximo_lista (list, t);
    }
    return result;
}

//RETORNA UMA LISTA COM TODOS OS ITENS DA HASHTABLE
Lista get_todos_hashtable (void* hash)
{
    Hash_table* table;
    table = (Hash_table*) hash;
    Lista list = cria_lista ();
    int i;
    for(i = 0; i < table->modulo; i++)
    {
        concat_listas (list, *(table->hashtable + i));
    }
    return list;
}

//APAGA A HASHTABLE (DEPENDE DO FREE DA LISTA -> NAO IMPLEMENTADO)
void free_hashtable (void* hash)
{
    Hash_table* table;
    table = (Hash_table*) hash;
    Lista list = cria_lista();
    int i;
    for(i = 0; i < table->modulo; i++)
    {
        //Lista_free(*(table->hashtable + i));
        free(*(table->hashtable + i));
    }
    free(table->hashtable);
    free(table);
}
