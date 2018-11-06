//BIBLIOTECA PARA ACESSO 

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "lista.h"

//DEFINE O TIPO DA HASHTABLE
typedef void* hash_table;

//CRIA UMA HASHTABLE DE MODULO N
hash_table cria_hashtable (int modulo, int (*compare) (void*, void*), int hash (void*, int));

//INSERE UM ITEM NA HASHTABLE
void insere_hashtable (hash_table hash, void* item);

//REMOVE UM ITEM DA HASHTABLE
void remove_hashtable (hash_table hash, void* item);

//RETORNA UM ITEM DA HASHTABLE
void* get_hashtable (hash_table hash, void* ident);

//RETORNA UMA LISTA COM TODOS OS ITENS DA HASHTABLE
Lista get_todos_hashtable (hash_table hash);

//APAGA A HASHTABLE (DEPENDE DO FREE DA LISTA -> NAO IMPLEMENTADO)
void free_hashtable (hash_table hash);

//RETORNA UM LISTA DE ITENS DA HASHTABLE
Lista get_lista_hashtable (void* hash, void* ident);

#endif