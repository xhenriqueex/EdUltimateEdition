#ifndef GRAFO_H
#define GRAFO_H

#include "../Lista/lista.h"
#include "../Hash/hashtable.h"

typedef void* Grafo;
typedef void* Info;

Grafo cria_grafo();
void insere_vertice(Grafo G, char *id, double *pos);
void* get_vertice(Grafo G, char *v1);
Posic get_posic_vertice(Grafo G, char *v1);
char *get_id_vertice(void *v1);
double *get_pos_vertice(void *v1);
void insere_aresta(Grafo G, char *v1, char *v2);
int qtd_vertices(Grafo G);
void* get_aresta(Grafo G, char *v1, char *v2);
void define_atributos_aresta(Grafo G, char *v1, char *v2, char *nome, char *ldir, char *lesq, double cmp, double vm);
static void* get_atributos_aresta(Grafo G, char *v1, char *v2);
char *get_nome_aresta(Grafo G, char *v1, char *v2);
char *get_ldir_aresta(Grafo G, char *v1, char *v2);
char *get_lesq_aresta(Grafo G, char *v1, char *v2);
double get_cmp_aresta(Grafo G, char *v1, char *v2);
double get_vm_aresta(Grafo G, char *v1, char *v2);
char *get_id_vertice_aresta(void *a1);
void remove_aresta(Grafo G, char *v1, char *v2);
int adjacente(Grafo G, char *v1, char *v2);
Lista adjacentes(Grafo G, char *v1);
char **dijkstra_distancia(Grafo G, char *v1, char *v2);
char **dijkstra_tempo(Grafo G, char *v1, char *v2);
int minima_distancia(double dist[], int sptSet[], int tam);
void *vertice_mais_proximo(Grafo G, double *pos);
int printar_distancias(double dist[], int n);
void free_atributos_aresta(void *atributos);
void free_aresta(void *a);
void free_vertice(void *v);
void free_grafo(Grafo G);

#endif // GRAFO_H
