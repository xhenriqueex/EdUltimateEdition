//BIBLIOTECA DE ORDENAÇÃO

#ifndef MERGE_H
#define MERGE_H

//FUNÇÃO PARA ORDENAR OS PONTOS (CHAMADA DO USUÁRIO)
void Merge (void** lista, int size, int compare (void*, void*));

//FUNÇÃO PARA ORDENAR OS PONTOS (EXECUÇÃO)
void merge_sort (void** lista, int inic, int fim, int compare (void*, void*));

#endif