#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "grafo.h"

struct _atributos_aresta
{
    char *nome;
    char *ldir;
    char *lesq;
    double cmp;
    double vm;
};

struct _aresta
{
    char *ligado_a;
    struct _atributos_aresta *atributos;
};

struct _vertice
{
    struct _aresta *arestas;
    char *id;
    double *pos;
};

typedef struct _atributos_aresta atributos_aresta;
typedef struct _aresta aresta;
typedef struct _vertice vertice;

Grafo cria_grafo()
{
    Lista *grafo = NULL;
    
    grafo = cria_lista();

    return grafo;
}

void insere_vertice(Grafo G, char *id, double *pos)
{
    vertice *v = NULL;

    v = (vertice *) calloc(1, sizeof(vertice));

    v->arestas = NULL;
    v->id = id;
    v->pos = pos;

    insere_lista(G, (void *) v);
}

void* get_vertice(Grafo G, char *v1)
{
    vertice *v = NULL;
    Posic *p = NULL;

    p = get_primeiro_lista(G);
    
    while(p != NULL){
        v = (vertice *) get_valor_lista(p);
        if (strcmp(v->id, v1) == 0) {
            break;
        }
        p = get_proximo_lista(G, p);
    }
    
    return (void *) v;
}

char *get_id_vertice(void *v1)
{
    vertice *v = NULL;
    v = (vertice *) v1;
    
    return v->id;
}

void insere_aresta(Grafo G, char *v1, char *v2)
{
    vertice *v = NULL;
    aresta *a = NULL;
    atributos_aresta *atributos_a = NULL;

    v = (vertice *) get_vertice(G, v1);
    if(v->arestas == NULL)
    {
        v->arestas = cria_lista();
    }

    a = (aresta *) calloc(1, sizeof(aresta));
    atributos_a = (atributos_aresta *) calloc(1, sizeof(atributos_aresta));
    
    a->ligado_a = v2;
    a->atributos = atributos_a;

    insere_lista(v->arestas, (void *) a);
    define_atributos_aresta(G, v1, v2, "", "", "", INT_MAX, 0);
}

int qtd_vertices(Grafo G)
{   
    return largura_lista(G);
}

void* get_aresta(Grafo G, char *v1, char *v2)
{
    aresta *a = NULL;
    Lista *lista = NULL;
    Posic *posic = NULL;

    if (get_vertice(G, v1) == NULL || get_vertice(G, v2) == NULL) {
        return NULL;
    }

    lista = adjacentes(G, v1);

    if(lista == NULL)
    {
        return NULL;
    }
    
    posic = get_primeiro_lista(lista);
    do
    {
        a = (aresta *) get_valor_lista(posic);

        if(strcmp(a->ligado_a, v2) == 0)
        {
            break;
        }

        posic = get_proximo_lista(lista, posic);
    } while(posic != NULL);

    return (void *) a;
}

void define_atributos_aresta(Grafo G, char *v1, char *v2, char *nome, char *ldir, char *lesq, double cmp, double vm)
{
    atributos_aresta *atributos_a = NULL;
    aresta *a = NULL;

    a = (aresta *) get_aresta(G, v1, v2);

    if(a == NULL) {
        return;
    }

    atributos_a = a->atributos;
    atributos_a->nome = nome;
    atributos_a->ldir = ldir;
    atributos_a->lesq = lesq;
    atributos_a->cmp = cmp;
    atributos_a->vm = vm;
}

static void* get_atributos_aresta(Grafo G, char *v1, char *v2)
{
    aresta *a = NULL;

    a = (aresta *) get_aresta(G, v1, v2);

    if(a == NULL) {
        printf("\naaaaaa\n");
        return NULL;
    }

    return (atributos_aresta *) a->atributos;
}

char *get_nome_aresta(Grafo G, char *v1, char *v2)
{
    atributos_aresta *atributos_a = NULL;
    
    atributos_a = (atributos_aresta *) get_atributos_aresta(G, v1, v2);

    if(atributos_a == NULL) {
        return 0;
    }

    return atributos_a->nome;
}

char *get_ldir_aresta(Grafo G, char *v1, char *v2)
{
    atributos_aresta *atributos_a = NULL;
    
    atributos_a = (atributos_aresta *) get_atributos_aresta(G, v1, v2);

    if(atributos_a == NULL) {
        return 0;
    }

    return atributos_a->ldir;
}

char *get_lesq_aresta(Grafo G, char *v1, char *v2)
{
    atributos_aresta *atributos_a = NULL;
    
    atributos_a = (atributos_aresta *) get_atributos_aresta(G, v1, v2);

    if(atributos_a == NULL) {
        return 0;
    }

    return atributos_a->lesq;
}

double get_cmp_aresta(Grafo G, char *v1, char *v2)
{
    atributos_aresta *atributos_a = NULL;
    
    atributos_a = (atributos_aresta *) get_atributos_aresta(G, v1, v2);

    if(atributos_a == NULL) {
        printf("abcde\n");
        return 0;
    }

    return atributos_a->cmp;
}

double get_vm_aresta(Grafo G, char *v1, char *v2)
{
    atributos_aresta *atributos_a = NULL;
    
    atributos_a = (atributos_aresta *) get_atributos_aresta(G, v1, v2);

    if(atributos_a == NULL) {
        return 0;
    }

    return atributos_a->vm;
}

char *get_id_vertice_aresta(void *a1)
{
    aresta *a = NULL;

    a = (aresta *) a1;

    return a->ligado_a;
}

void remove_aresta(Grafo G, char *v1, char *v2)
{
    aresta *a = NULL;
    Lista *lista = NULL;
    Posic *posic = NULL;

    if (get_vertice(G, v1) == NULL || get_vertice(G, v2) == NULL) {
        return;
    }

    lista = adjacentes(G, v1);

    posic = get_primeiro_lista(lista);

    do
    {
        a = (aresta *) get_valor_lista(posic);

        if(strcmp(a->ligado_a, v2) == 0)
        {
            remove_lista(lista, posic);
            break;
        }

        posic = get_proximo_lista(lista, posic);
    } while(posic != NULL);
}

int adjacente(Grafo G, char *v1, char *v2)
{
    aresta *a = NULL;
    int retorno = 0;

    if (get_vertice(G, v1) == NULL || get_vertice(G, v2) == NULL) {
        return 0;
    }

    a = get_aresta(G, v1, v2);

    if (a != NULL)
    {
        retorno = 1;
    }

    return retorno;
}

Lista adjacentes(Grafo G, char *v1)
{
    vertice *v = NULL;

    v = get_vertice(G, v1);
    if (v == NULL) {
        return NULL;
    }

    return v->arestas;
}

void dijkstra(Grafo G, int src)
{
    int tam = qtd_vertices(G);
    double dist[tam];
    int sptset[tam];
    Posic p1 = NULL, p2 = NULL;
    char *vertice1 = NULL, *vertice2 = NULL;
    double cmp = 0;

    for (int i = 0; i < tam; i++) {
        dist[i] = INT_MAX;
        sptset[i] = 0;
    }

    dist[src] = 0;

    p1 = get_primeiro_lista(G);

    while(get_proximo_lista(G, p1) != NULL)
    {
        vertice1 = get_id_vertice(get_valor_lista(p1));
        int u = minima_distancia(dist, sptset, tam);

        sptset[u] = 1;

        printf("u = %d\n", u);

        p2 = get_primeiro_lista(G);

        int v = 0;
        while(p2 != NULL)
        {
            vertice2 = get_id_vertice(get_valor_lista(p2));
            cmp = get_cmp_aresta(G, vertice1, vertice2);

            printf("Vértice processado? %d\n", sptset[v]);
            printf("Comprimento aresta de %s a %s: %lf\n", vertice1, vertice2, cmp);
            printf("Distância processada do vértice %s: %lf\n", vertice1, dist[u]);
            printf("Distância a ser processada de %s: %lf\n", vertice2, dist[v]);
            if (!sptset[v] && cmp && dist[u] != INT_MAX && dist[u]+cmp < dist[v])
            {
                dist[v] = dist[u] + cmp;
            }
            v++;
            p2 = get_proximo_lista(G, p2);
        }
        p1 = get_proximo_lista(G, p1);
    }

    printar_distancias(dist, tam);
}

int minima_distancia(double dist[], int sptSet[], int tam)
{
    int min = INT_MAX, min_index = 0;

    for (int v = 0; v < tam; v++)
    {
        if (!sptSet[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

int printar_distancias(double dist[], int n)
{
    printf("Vértice   Distância do primeiro\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d tt %lf\n", i, dist[i]);
    }
}