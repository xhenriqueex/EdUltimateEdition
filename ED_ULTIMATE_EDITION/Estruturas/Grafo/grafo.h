#ifndef GRAFO_H
#define GRAFO_H

#include "../Lista/lista.h"
#include "../Hash/hashtable.h"

typedef void* Grafo;
typedef void* Info;

Grafo cria_grafo(int n);
void insere_aresta(Grafo G, int v1, int v2);
int qtd_vertices(Grafo G);
void* get_aresta(Grafo G, int v1, int v2);
void define_atributos_aresta(Grafo G, int v1, int v2, int direcao, double tamanho);
static void* get_atributos_aresta(Grafo G, int v1, int v2);
static int get_direcao_aresta(Grafo G, int v1, int v2);
static int get_tamanho_aresta(Grafo G, int v1, int v2);
void remove_aresta(Grafo G, int v1, int v2);
int adjacente(Grafo G, int v1, int v2);
Lista adjacentes(Grafo G, int v1);

#endif // GRAFO_H
