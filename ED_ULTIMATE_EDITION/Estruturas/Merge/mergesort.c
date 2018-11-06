#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "mergesort.h"

void Merge (void** lista, int size, int compare (void*, void*));

void merge_sort (void** lista, int inic, int fim, int compare (void*, void*));

void intercala (void** lista, int inic, int meio, int fim, int compare (void*, void*));

//FUNÇÃO PARA ORDENAR OS PONTOS (CHAMADA DO USUÁRIO)
void Merge (void** lista, int size, int compare (void*, void*))
{
    merge_sort (lista, 0, size-1, compare);
}

//FUNÇÃO PARA ORDENAR OS PONTOS (EXECUÇÃO)
void merge_sort (void** lista, int inic, int fim, int compare (void*, void*))
{
    int meio;
    if (inic == fim)
    {
        return;
    }
    meio = (fim-inic)/2 + inic;
    merge_sort (lista, inic, meio, compare);
    merge_sort (lista, meio+1, fim, compare);
    intercala (lista, inic, meio, fim, compare);
}

//FUNÇÃO QUE INTERCALA OS VALORES EM ORDEM
void intercala (void** lista, int inic, int meio, int fim, int compare (void*, void*))
{
    int com1, com2, comAux, tam;
    void** vetAux;
    com1 = inic;
    com2 = meio+1;
    comAux = 0;
    tam = fim-inic+1;
    vetAux = (void**) calloc (tam, sizeof (void*));
    while (com1 <= meio && com2 <= fim)
    {
        if (compare (lista[com1], lista[com2]) < 0) 
        {
            vetAux[comAux] = lista[com1];
            com1++;
        } 
        else 
        {
            vetAux[comAux] = lista[com2];
            com2++;
        }
        comAux++;
    }
    while (com1 <= meio)
    {  
        vetAux[comAux] = lista[com1];
        comAux++;
        com1++;
    }
    while (com2 <= fim) 
    {   
        vetAux[comAux] = lista[com2];
        comAux++;
        com2++;
    }
    for (comAux = inic; comAux <= fim; comAux++)
    {
        lista[comAux] = vetAux[comAux-inic];
    }
    free(vetAux);
}