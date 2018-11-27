#include <stdlib.h>
#include "grafo.h"

#define INFINITO -1

struct _atributos_aresta
{
    int direcao;
    double tamanho;
};

struct _aresta
{
    int ligado_a;
    struct _atributos_aresta *atributos;
};

struct _vertice
{
    struct _aresta *arestas;
};

typedef struct _atributos_aresta atributos_aresta;
typedef struct _aresta aresta;
typedef struct _vertice vertice;

Grafo cria_grafo(int n)
{
    vertice *vertices = NULL;
    int i = 0;
    
    vertices = (vertice *) calloc(n, sizeof(vertice));
    
    for(i = 0; i < n; i++)
    {
        vertices[i].arestas = NULL;
    }

    return (void *) vertices;
}

void insere_aresta(Grafo G, int v1, int v2)
{
    vertice *vertices = NULL;
    aresta *a = NULL;
    atributos_aresta *atributos_a = NULL;

    vertices = (vertice *) G;

    if(vertices[v1].arestas == NULL)
    {
        vertices[v1].arestas = cria_lista();
    }

    a = (aresta *) calloc(1, sizeof(aresta));
    atributos_a = (atributos_aresta *) calloc(1, sizeof(atributos_aresta));

    atributos_a->direcao = 0;
    atributos_a->tamanho = INFINITO;
    a->ligado_a = v2;
    a->atributos = atributos_a;

    insere_lista(vertices[v1].arestas, (void *) a);
}

int qtd_vertices(Grafo G)
{
    vertice *vertices = NULL;
    int qtd = 0;

    vertices = (vertice *) G;

    qtd = (int) sizeof(vertices)/sizeof(vertices[0]);
    
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

void define_atributos_aresta(Grafo G, int v1, int v2, int direcao, double tamanho)
{
    atributos_aresta *atributos_a = NULL;
    aresta *a = NULL;

    a = (aresta *) get_aresta(G, v1, v2);

    if(a == NULL) {
        return;
    }

    atributos_a = a->atributos;

    atributos_a->direcao = direcao;
    atributos_a->tamanho = tamanho;
}

static void* get_atributos_aresta(Grafo G, int v1, int v2)
{
    aresta *a = NULL;

    a = (aresta *) get_aresta(G, v1, v2);

    if(a == NULL) {
        return;
    }

    return (atributos_aresta *) a->atributos;
}

static int get_direcao_aresta(Grafo G, int v1, int v2)
{
    atributos_aresta *atributos_a = NULL;
    
    atributos_a = (atributos_aresta *) get_atributos_aresta(G, v1, v2);

    if(atributos_a == NULL) {
        return;
    }

    return atributos_a->direcao;
}

static int get_tamanho_aresta(Grafo G, int v1, int v2)
{
    atributos_aresta *atributos_a = NULL;
    
    atributos_a = (atributos_aresta *) get_atributos_aresta(G, v1, v2);

    if(atributos_a == NULL) {
        return;
    }

    return atributos_a->tamanho;
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
    vertice *vertices = NULL;
    int qtd = 0;

    qtd = qtd_vertices(G);
    if (v1 > qtd) {
        return NULL;
    }

    return vertices[v1].arestas;
}