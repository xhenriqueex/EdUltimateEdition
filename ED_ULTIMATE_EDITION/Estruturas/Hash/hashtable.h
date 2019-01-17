//BIBLIOTECA PARA ACESSO 

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "../Lista/lista.h"

//DEFINE O TIPO DA HASHTABLE
typedef void* Hashtable;

//CRIA UMA HASHTABLE DE MODULO N
Hashtable cria_hashtable (int modulo, int (*compare) (void*, void*), int hash (void*, int));

//INSERE UM ITEM NA HASHTABLE
void insere_hashtable (Hashtable hash, void* item);

//REMOVE UM ITEM DA HASHTABLE
void remove_hashtable (Hashtable hash, void* item);

//RETORNA UM ITEM DA HASHTABLE
void* get_hashtable (Hashtable hash, void* ident);

//RETORNA UMA LISTA COM TODOS OS ITENS DA HASHTABLE
Lista get_todos_hashtable (Hashtable hash);

//APAGA A HASHTABLE (DEPENDE DO FREE DA LISTA -> NAO IMPLEMENTADO)
void free_hashtable (void* hash, void (*free_generalizado)(void *));

//RETORNA UM LISTA DE ITENS DA HASHTABLE
Lista get_lista_hashtable (void* hash, void* ident);

#endif