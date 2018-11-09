#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../Lista/lista.h"

typedef struct no {
    void* valor;
    struct no* direita;
    struct no* esquerda;
} No;

typedef struct kd {
    int (*compare)(void*, void*, int);
    int dim;
    int tam;
    No* nodulo;
} Arvore;

//CRIA A ÁRVORE
void* cria_arvore (int (*compare)(void*, void*, int), int dim)
{
    Arvore* result;
    result = (Arvore*) calloc (1, sizeof (Arvore));
    result->compare = compare;
    result->dim = dim;
    result->tam = 0;
    result->nodulo = NULL;
    return (void*) result;
}

//INSERE UM NODULO NA ÁRVORE
void insere_nodulo (No* n, Arvore* arv, void* valor, int dim)
{
    if (n->valor == NULL)
    {
        n->valor = valor;
        return;
    }
    if (dim == arv->dim)
    {
        dim = 0;
    }
    if (arv->compare(n->valor, valor, dim) < 0)
    {
        if (n->esquerda == NULL)
        {
            n->esquerda = (No*) calloc (1, sizeof (No));
            n->esquerda->valor = NULL;
            n->esquerda->direita = NULL;
            n->esquerda->esquerda = NULL;
        }
        insere_nodulo (n->esquerda, arv, valor, dim + 1);
        return;
    }
    else
    {
        if (n->direita == NULL)
        {
            n->direita = (No*) calloc (1, sizeof (No));
            n->direita->valor = NULL;
            n->direita->esquerda = NULL;
            n->direita->direita = NULL;
        }
        insere_nodulo (n->direita, arv, valor, dim + 1);
        return;
    }
}

//INSERE UM VALOR NA ÁRVORE
void insere_arvore (void* arv, void* valor)
{
    Arvore* arvore;
    arvore = (Arvore*) arv;
    No* n;
    n = (No*) arvore->nodulo;
    if (n == NULL)
    {
        n = (No*) calloc (1, sizeof (No));
        arvore->nodulo = n;
    }
    insere_nodulo (n, arvore, valor, 0);
    arvore->tam += 1;
}

//LIBERA UM NÓDULO
void free_nodulo (void* nodulo)
{
    No* n;
    n = (No*) nodulo;
    if (n->esquerda != NULL)
    {
        free_nodulo (n->esquerda);
    }
    if (n->direita != NULL)
    {
        free_nodulo (n->direita);
    }
    n->valor = NULL;
    free (n);
}

//LIBERA A ÁRVORE
void free_arvore (void* arvore)
{
    Arvore* arv;
    arv = (Arvore*) arvore;
    free_nodulo (arv->nodulo);
    arv->compare = NULL;
    arv->tam = 0;
    arv->dim = 0;
    free(arv);
}

//RETORNA UMA LISTA COM TODOS OS VALORES DO NÓDULO
Lista get_todos_nodulo (void* nodulo, void* lista)
{
    No* no;
    no = (No*) nodulo;
    if (no == NULL)
    {
        return lista;
    }
    if (no->esquerda != NULL)
    {
        get_todos_nodulo (no->esquerda, lista);
    }
    if (no->valor != NULL)
    {
        insere_lista (lista, no->valor);
    }
    if (no->direita != NULL)
    {
        get_todos_nodulo (no->direita, lista);
    }
    return lista;
}

//RETORNA UMA LISTA COM TODOS OS VALORES DA ÁRVORE
Lista get_todos_arvore (void* arv)
{
    Arvore* arvore;
    arvore = (Arvore*) arv;
    Lista* list;
    list = cria_lista ();
    return get_todos_nodulo (arvore->nodulo, list);
}

//RETORNA UM VALOR DO NÓDULO, COMPARADO COM A REFERÊNCIA
void* get_valor_nodulo (Arvore* arv, No* nodulo, int dim, void* ref)
{
    if (nodulo == NULL)
    {
        return NULL;
    }
    if (dim == arv->dim)
    {
        dim = 0;
    }
    if (arv->compare (nodulo->valor, ref, dim) == 0 && arv->compare (nodulo->valor, ref, dim + 1) == 0)
    {
        return nodulo->valor;
    }
    if (arv->compare (nodulo->valor, ref, dim) < 0)
    {
        return get_valor_nodulo (arv, nodulo->esquerda, dim, ref);
    }
    if (arv->compare (nodulo->valor, ref, dim) >= 0)
    {
        return get_valor_nodulo (arv, nodulo->direita, dim, ref);
    }
}

//RETORNA UM VALOR DA ÁRVORE, COMPARADO À REFERÊNCIA
void* get_valor_arvore (void* arv, void* ref)
{
    Arvore* arvore;
    arvore = (Arvore*) arv;
    int dim = 0;
    return get_valor_nodulo (arvore, arvore->nodulo, dim, ref);
}

//REMOVE UM VALOR DO NÓDULO, COMPARADO À REFERÊNCIA
Lista remove_valor_nodulo (Arvore* arv, No* nodulo, int dim, void* ref)
{
    if (nodulo == NULL)
    {
        return NULL;
    }
    if (nodulo->valor == NULL)
    {
        return NULL;
    }
    if (dim == arv->dim)
    {
        dim = 0;
    }
    int i = arv->compare (nodulo->valor, ref, dim);
    Lista list;
    if (i==0 && arv->compare (nodulo->valor, ref, dim + 1) == 0)
    {
        list = cria_lista();
        get_todos_nodulo (nodulo->esquerda, list);
        get_todos_nodulo (nodulo->direita, list);
        nodulo->valor = NULL;
        nodulo->direita = NULL;
        nodulo->direita = NULL;
        return list;
    }
    if (i<0)
    {
        list = remove_valor_nodulo (arv, nodulo->esquerda, dim + 1, ref);
        if (list == NULL)
        {
            list = remove_valor_nodulo (arv, nodulo->direita, dim + 1, ref);
        }
    }
    if (i>=0)
    {
        list = remove_valor_nodulo (arv, nodulo->direita, dim + 1, ref);
        if (list == NULL)
        {
            list = remove_valor_nodulo (arv, nodulo->esquerda, dim + 1, ref);
        }
    }
    return list;
}

//REMOVE UM VALOR DA ÁRVORE
void remove_valor_arvore (Arvore* arv, void* ref)
{
    Arvore* arvore;
    arvore = (Arvore*) arv;
    int dim = 0;
    Lista list;
    list = remove_valor_nodulo (arv, arvore->nodulo, dim, ref);
    if (list == NULL)
    {
        return;
    }
    void* primeiro;
    void* temp;
    primeiro = get_primeiro_lista (list);
    while (1)
    {
        temp = get_valor_lista (list, primeiro);
        if (temp)
        {
            insere_arvore (arv, temp);
            primeiro = get_proximo_lista (list, primeiro);
        }
        else
        {
            break;
        }
    }
}

//RETORNA A DISTÂNCIA ENTRE DOIS VALORES DA ÁRVORE
double dist_arvore (Arvore* arv, void* valor1, void* valor2)
{
    int i;
    double dist = 0;
    for (i=0; i<arv->dim; i++)
    {
        dist = dist + pow (arv->compare (valor1, valor2, i), 2);
    }
    return sqrt (dist);
}

//RETORNA O ITEM MAIS PRÓXIMO À REFERÊNCIA NO NÓDULO
void vizinho_proximo_nodulo (No* n, Arvore* arv, void* ref, void** item, double* dist, int dim)
{
    if (n = NULL)
    {
        return;
    }
    double dist_atual = dist_arvore (arv, ref, n->valor);
    if (dist_atual < *dist && dist_atual > 0)
    {
        *dist = dist_atual;
        *item = n->valor;
    }
    if (arv->compare (n->valor, ref, dim + 1) < 0)
    {
        vizinho_proximo_nodulo (n->esquerda, arv, ref, item, dist, dim + 1);
        if (abs (arv->compare (n->valor, ref, dim)) < *dist)
        {
            vizinho_proximo_nodulo (n->direita, arv, ref, item, dist, dim + 1);
        }
    }
    else
    {
        vizinho_proximo_nodulo (n->direita, arv, ref, item, dist, dim + 1);
        if (abs (arv->compare (n->valor, ref, dim)) < *dist)
        {
            vizinho_proximo_nodulo (n->esquerda, arv, ref, item, dist, dim + 1);
        }
    }
}

//RETORNA O VIZINHO MAIS PRÓXIMO À REFERÊNCIA NA ÁRVORE
void vizinho_proximo_arvore (void* arv, void* ref)
{
    Arvore* arvore;
    arvore = (Arvore*) arv;
    No* n;
    n = (No*) arvore->nodulo;
    if (n = NULL)
    {
        return NULL;
    }
    void** item;
    item = (void**) calloc (1, sizeof (void*));
    *item = n->valor;
    double* dist;
    dist = (double*) calloc (1, sizeof (double));
    *dist = dist_arvore (arvore, ref, n->valor);
    vizinho_proximo_nodulo (n, arvore, ref, item, dist, 0);
    return *item;
}