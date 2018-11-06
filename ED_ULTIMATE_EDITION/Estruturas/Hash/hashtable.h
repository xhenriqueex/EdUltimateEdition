//BIBLIOTECA PARA ACESSO 

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../Lista/lista.h"

//DEFINE O TIPO DA HASHTABLE
typedef void* hash_table;

//CRIA UMA HASHTABLE DE MODULO N
void* cria_hashtable (int modulo, int (*compare) (void*, void*), int (*hash) (void*, int));

//INSERE UM ITEM NA HASHTABLE
void insere_hashtable (void* hash, void* item);

//REMOVE UM ITEM DA HASHTABLE
void remove_hashtable (void* hash, void* item);

//RETORNA UM ITEM DA HASHTABLE
void* get_hashtable (void* hash, void* ident);

//RETORNA UMA LISTA COM TODOS OS ITENS DA HASHTABLE
Lista get_lista_hashtable (void* hash, void* ident);

//APAGA A HASHTABLE (DEPENDE DO FREE DA LISTA -> NAO IMPLEMENTADO)
Lista get_todos_hashtable (void* hash);

//RETORNA UM LISTA DE ITENS DA HASHTABLE
void free_hashtable (void* hash);

#endif