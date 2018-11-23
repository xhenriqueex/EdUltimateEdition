#include <stdlib.h>
#include "grafo.h"

struct _aresta
{
    int ligado_a;
    Info direcao;
};

struct _vertice
{
    struct _aresta *arestas;
};

struct _grafo
{
    struct _vertice *vertices;
};

typedef struct _aresta aresta;
typedef struct _vertice vertice;
typedef struct _grafo grafo;

Grafo cria_grafo(int n)
{
    grafo *g = NULL;
    vertice *v = NULL;
    int i = 0;
    
    g = (grafo *) calloc(1, sizeof(grafo));
    v = (vertice *) calloc(n, sizeof(vertice));
    
    for(i = 0; i < n; i++)
    {
        v[i].arestas = NULL;
    }
    
    g->vertices = v;

    return (void *) g;
}

void insere_aresta(Grafo G, int v1, int v2)
{
    grafo *g = NULL;
    vertice *v = NULL;
    aresta *a = NULL;

    g = (grafo *) G;

    v = g->vertices;

    if(v[v1].arestas == NULL)
    {
        v[v1].arestas = cria_lista();
    }

    a = (aresta *) calloc(1, sizeof(aresta));

    a->ligado_a = v2;
    a->direcao = NULL;

    insere_lista(v[v1].arestas, (void *) a);
}

int qtd_vertices(Grafo G)
{
    grafo *g = NULL;
    int qtd = 0;

    g = (grafo *) G;

    qtd = (int) sizeof(g->vertices)/sizeof(g->vertices[0]);

    g = (grafo *) G;
    
    return qtd;
}

void* get_aresta(Grafo G, int v1, int v2)
{
    aresta *a = NULL;
    Lista *lista = NULL;
    Posic *posic = NULL;
    int qtd = 0;

    qtd = qtd_vertices(G);

    if (v1 > qtd || v2 > qtd) {
        return NULL;
    }

    lista = adjacentes(G, v1);

    posic = get_primeiro_lista(lista);

    do
    {
        a = (aresta *) get_valor_lista(lista, posic);

        if(a->ligado_a == v2)
        {
            break;
        }

        posic = get_proximo_lista(lista, posic);
    } while(posic != NULL);

    return (void *) a;
}

void define_info(Grafo G, int v1, int v2, Info i)
{
    aresta *a = NULL;

    a = (aresta *) get_aresta(G, v1, v2);

    if(a == NULL) {
        return;
    }

    a->direcao = i;
}

Info get_info(Grafo G, int v1, int v2)
{
    aresta *a = NULL;
    
    a = (aresta *) get_aresta(G, v1, v2);

    if(a == NULL) {
        return;
    }

    return a->direcao;
}

void remove_aresta(Grafo G, int v1, int v2)
{
    aresta *a = NULL;
    Lista *lista = NULL;
    Posic *posic = NULL;
    int qtd = 0;

    qtd = qtd_vertices(G);

    if (v1 > qtd || v2 > qtd) {
        return NULL;
    }

    lista = adjacentes(G, v1);

    posic = get_primeiro_lista(lista);

    do
    {
        a = (aresta *) get_valor_lista(lista, posic);

        if(a->ligado_a == v2)
        {
            remove_lista(lista, posic);
            break;
        }

        posic = get_proximo_lista(lista, posic);
    } while(posic != NULL);
}

int adjacente(Grafo G, int v1, int v2)
{
    aresta *a = NULL;
    int retorno = 0;
    int qtd = 0;

    qtd = qtd_vertices(G);
    if (v1 > qtd || v2 > qtd) {
        return NULL;
    }

    a = get_aresta(G, v1, v2);

    if (a != NULL)
    {
        retorno = 1;
    }

    return retorno;
}

Lista adjacentes(Grafo G, int v1)
{
    grafo *g = NULL;
    vertice *v = NULL;
    int qtd = 0;

    qtd = qtd_vertices(G);
    if (v1 > qtd) {
        return NULL;
    }

    g = (grafo *) G;
    v = g->vertices;

    return v[v1].arestas;
}