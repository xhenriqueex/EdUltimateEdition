#ifndef GRAFO_H
#define GRAFO_H

#include "../Lista/lista.h"
#include "../Hash/hashtable.h"

typedef void* Grafo;
typedef void* Info;

Grafo cria_grafo();
void insere_vertice(Grafo G, char *id, double *pos);
static void* get_vertice(Grafo G, char *v1);
void insere_aresta(Grafo G, char *v1, char *v2);
int qtd_vertices(Grafo G);
void* get_aresta(Grafo G, char *v1, char *v2);
void define_atributos_aresta(Grafo G, char *v1, char *v2, char *nome, char *ldir, char *lesq, double cmp, double vm);
static void* get_atributos_aresta(Grafo G, char *v1, char *v2);
static char *get_nome_aresta(Grafo G, char *v1, char *v2);
static char *get_ldir_aresta(Grafo G, char *v1, char *v2);
static char *get_lesq_aresta(Grafo G, char *v1, char *v2);
static double get_cmp_aresta(Grafo G, char *v1, char *v2);
static double get_vm_aresta(Grafo G, char *v1, char *v2);
void remove_aresta(Grafo G, char *v1, char *v2);
int adjacente(Grafo G, char *v1, char *v2);
Lista adjacentes(Grafo G, char *v1);
void dijkstra(Grafo G, int src);
int minima_distancia(int dist[], int sptSet[], int tam);
int printar_distancias(int dist[], int n);

#endif // GRAFO_H
