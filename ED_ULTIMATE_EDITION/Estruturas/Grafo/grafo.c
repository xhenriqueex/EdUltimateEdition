#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "grafo.h"
#include "../../Funções/funcoes.h"

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
    v->id = (char *) calloc(strlen(id)+1, sizeof(char));
    strcpy(v->id, id);
    v->pos = (double *) calloc(2, sizeof(double));
    v->pos[0] = pos[0];
    v->pos[1] = pos[1];

    insere_lista(G, (void *) v);
}

void* get_vertice(Grafo G, char *v1)
{
    vertice *v = NULL;
    Posic *p = NULL;

    p = get_posic_vertice(G, v1);

    if(p == NULL) {
        return NULL;
    }

    v = (vertice *) get_valor_lista(p);
    
    return (void *) v;
}

Posic get_posic_vertice(Grafo G, char *v1)
{
    vertice *v = NULL;
    Posic *p = NULL;
    int logic = 0;

    p = get_primeiro_lista(G);
    
    while(p != NULL){
        v = (vertice *) get_valor_lista(p);
        if (strcmp(v->id, v1) == 0) {
            logic = 1;
            break;
        }
        p = get_proximo_lista(G, p);
    }
    if (logic == 0) {
        return NULL;
    }
    else {
        return p;
    }
}

char *get_id_vertice(void *v1)
{
    vertice *v = NULL;
    v = (vertice *) v1;
    
    return v->id;
}

double *get_pos_vertice(void *v1)
{
    vertice *v = NULL;
    v = (vertice *) v1;
    
    return v->pos;
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
    
    a->ligado_a = (char *) calloc(strlen(v2)+1, sizeof(char));
    strcpy(a->ligado_a, v2);
    a->atributos = atributos_a;

    insere_lista(v->arestas, (void *) a);
    define_atributos_aresta(G, v1, v2, " ", " ", " ", __INT_MAX__, 0);
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
    int logic = 0;

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
            logic = 1;
            break;
        }

        posic = get_proximo_lista(lista, posic);
    } while(posic != NULL);

    if(logic == 0) {
        return NULL;
    }
    else {
        return (void *) a;
    }
}

void define_atributos_aresta(Grafo G, char *v1, char *v2, char *nome, char *ldir, char *lesq, double cmp, double vm)
{
    atributos_aresta *atributos_a = NULL;
    aresta *a = NULL;

    a = (aresta *) get_aresta(G, v1, v2);

    if(a == NULL) {
        return;
    }

    free_atributos_aresta(a->atributos);
    a->atributos = NULL;
    a->atributos = (atributos_aresta *) calloc(1, sizeof(atributos_aresta));

    atributos_a = a->atributos;
    atributos_a->nome = (char *) calloc(strlen(nome)+1, sizeof(char));
    strcpy(atributos_a->nome, nome);
    atributos_a->ldir = (char *) calloc(strlen(ldir)+1, sizeof(char));
    strcpy(atributos_a->ldir, ldir);
    atributos_a->lesq = (char *) calloc(strlen(lesq)+1, sizeof(char));
    strcpy(atributos_a->lesq, lesq);
    atributos_a->cmp = cmp;
    atributos_a->vm = vm;
}

static void* get_atributos_aresta(Grafo G, char *v1, char *v2)
{
    aresta *a = NULL;

    a = (aresta *) get_aresta(G, v1, v2);

    if(a == NULL) {
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

    if(strcmp(v1, v2) == 0) {
        return 0;
    }
    
    atributos_a = (atributos_aresta *) get_atributos_aresta(G, v1, v2);

    if(atributos_a == NULL) {
        return (double) __INT_MAX__;
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

char **dijkstra_distancia(Grafo G, char *v1, char *v2)
{
    int tam = qtd_vertices(G);
    double dist[tam];
    int sptset[tam];
    Posic p1 = NULL, p2 = NULL;
    char *vertice1 = NULL, *vertice2 = NULL;
    char **vertices = NULL, **aux = NULL;
    double cmp = 0;
    int z = 0;
    
    p1 = get_posic_vertice(G, v1);
    fixa_primeiro_lista(G, p1);

    for (int i = 0; i < tam; i++) {
        dist[i] = __INT_MAX__;
        sptset[i] = 0;
    }

    dist[0] = 0;

    vertices = (char **) calloc(1, sizeof(char *)); 
    vertice1 = get_id_vertice(get_vertice(G, v1));
    vertices[0] = (char *) calloc(strlen(vertice1)+1, sizeof(char));
    strcpy(vertices[0], vertice1);
    z++;

    for(int k = 0; k < tam-1; k++)
    {
        int u = minima_distancia(dist, sptset, tam);

        p1 = get_primeiro_lista(G);
        
        for(int i = 0; i < u; i++)
        {
            p1 = get_proximo_lista(G, p1);
        }
        vertice1 = get_id_vertice(get_valor_lista(p1));
        
        cmp = get_cmp_aresta(G, vertices[z-1], vertice1);
        if (cmp != __INT_MAX__ && cmp != 0) {  
            aux = (char **) calloc(z+1, sizeof(char *));
            for(int a = 0; a < z; a++) {
                aux[a] = (char *) calloc(strlen(vertices[a])+1, sizeof(char));
                strcpy(aux[a], vertices[a]);
                free(vertices[a]);
                vertices[a] = NULL;
            }
            aux[z] = (char *) calloc(strlen(vertice1)+1, sizeof(char));
            strcpy(aux[z], vertice1);
            free(vertices);
            vertices = aux;
            z++;
            if(strcmp(vertice1, v2) == 0) {
                break;
            }
        }
        sptset[u] = 1;

        //printf("u = %d //// %s //// %s\n", u, vertice1, v2);

        //vertices = (char **) realloc(vertices, (k+1)*sizeof(char *));

        p2 = get_primeiro_lista(G);

        int v = 0;
        while(p2 != NULL)
        {
            vertice2 = get_id_vertice(get_valor_lista(p2));
            cmp = get_cmp_aresta(G, vertice1, vertice2);
            if(cmp == __INT_MAX__ || cmp == 0) {
                v++;
                p2 = get_proximo_lista(G, p2);
                continue;
            }

            //printf("Vértice processado? %d\n", sptset[v]);
            //printf("Comprimento aresta de %s a %s: %lf\n", vertice1, vertice2, cmp);
            //printf("Distância processada do vértice %s: %lf\n", vertice1, dist[u]);
            //printf("Distância a ser processada de %s: %lf\n", vertice2, dist[v]);
            if (!sptset[v] && cmp && dist[u] < __INT_MAX__ && dist[u]+cmp < dist[v])
            {
                dist[v] = dist[u] + cmp;
            }
            //printf("Distância processada de %s: %lf\n", vertice2, dist[v]);
            v++;
            p2 = get_proximo_lista(G, p2);
        }
    }

    aux = (char **) calloc(z+2, sizeof(char *));
    for(int a = 0; a < z; a++) {
        aux[a] = (char *) calloc(strlen(vertices[a])+1, sizeof(char));
        strcpy(aux[a], vertices[a]);
        free(vertices[a]);
        vertices[a] = NULL;
    }
    aux[z] = NULL;
    aux[z+1] = NULL;
    free(vertices);
    vertices = aux;

    //printar_distancias(dist, tam);

    return vertices;
}

char **dijkstra_tempo(Grafo G, char *v1, char *v2)
{
    int tam = qtd_vertices(G);
    double dist[tam];
    int sptset[tam];
    Posic p1 = NULL, p2 = NULL;
    char *vertice1 = NULL, *vertice2 = NULL;
    char **vertices = NULL, **aux = NULL;
    double vm = 0, cmp = 0, tempo = 0;
    int z = 0;

    p1 = get_posic_vertice(G, v1);
    fixa_primeiro_lista(G, p1);

    for (int i = 0; i < tam; i++) {
        dist[i] = __INT_MAX__;
        sptset[i] = 0;
    }

    dist[0] = 0;

    vertices = (char **) calloc(1, sizeof(char *)); 
    vertice1 = get_id_vertice(get_vertice(G, v1));
    vertices[0] = (char *) calloc(strlen(vertice1)+1, sizeof(char));
    strcpy(vertices[0], vertice1);
    z++;

    for(int k = 0; k < tam-1; k++)
    {
        int u = minima_distancia(dist, sptset, tam);

        p1 = get_primeiro_lista(G);
        
        for(int i = 0; i < u; i++)
        {
            p1 = get_proximo_lista(G, p1);
        }
        vertice1 = get_id_vertice(get_valor_lista(p1));

        cmp = get_cmp_aresta(G, vertices[z-1], vertice1);
        if (cmp != __INT_MAX__ && cmp != 0) {  
            aux = (char **) calloc(z+1, sizeof(char *));
            for(int a = 0; a < z; a++) {
                aux[a] = (char *) calloc(strlen(vertices[a])+1, sizeof(char));
                strcpy(aux[a], vertices[a]);
                free(vertices[a]);
                vertices[a] = NULL;
            }
            aux[z] = (char *) calloc(strlen(vertice1)+1, sizeof(char));
            strcpy(aux[z], vertice1);
            free(vertices);
            vertices = aux;
            z++;
            if(strcmp(vertice1, v2) == 0) {
                break;
            }
        }
        
        sptset[u] = 1;

        p2 = get_primeiro_lista(G);

        int v = 0;
        while(p2 != NULL)
        {
            vertice2 = get_id_vertice(get_valor_lista(p2));
            cmp = get_cmp_aresta(G, vertice1, vertice2);
            if(cmp == __INT_MAX__ || cmp == 0) {
                v++;
                p2 = get_proximo_lista(G, p2);
                continue;
            }
            vm = get_vm_aresta(G, vertice1, vertice2);
            tempo = cmp/vm;


            //printf("Vértice processado? %d\n", sptset[v]);
            //printf("Comprimento aresta de %s a %s: %lf\n", vertice1, vertice2, vm);
            //printf("Distância processada do vértice %s: %lf\n", vertice1, dist[u]);
            //printf("Distância a ser processada de %s: %lf\n", vertice2, dist[v]);
            if (!sptset[v] && tempo && dist[u] != __INT_MAX__ && dist[u]+tempo < dist[v])
            {
                dist[v] = dist[u] + tempo;
            }
            //printf("Distância processada de %s: %lf\n", vertice2, dist[v]);
            v++;
            p2 = get_proximo_lista(G, p2);
        }
    }

    aux = (char **) calloc(z+2, sizeof(char *));
    for(int a = 0; a < z; a++) {
        aux[a] = (char *) calloc(strlen(vertices[a])+1, sizeof(char));
        strcpy(aux[a], vertices[a]);
        free(vertices[a]);
        vertices[a] = NULL;
    }
    aux[z] = NULL;
    aux[z+1] = NULL;
    free(vertices);
    vertices = aux;
    
    //printar_distancias(dist, tam);

    return vertices;
}

int minima_distancia(double dist[], int sptSet[], int tam)
{
    int min = __INT_MAX__, min_index = 0;

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

void *vertice_mais_proximo(Grafo G, double *pos)
{
    double *posicao = NULL, *distancias = NULL;
    Posic p = NULL;
    void *v = NULL, **vertices = NULL;
    int sptset[qtd_vertices(G)];
    int index = 0, i = 0;

    for (i = 0; i < qtd_vertices(G); i++) {
        sptset[i] = 0;
    }

    distancias = (double *) calloc(qtd_vertices(G), sizeof(double));
    vertices = (void **) calloc(qtd_vertices(G), sizeof(void *));
    
    p = get_primeiro_lista(G);
    
    for(i = 0; i < qtd_vertices(G); i++)
    {
        v = get_valor_lista(p);
        vertices[i] = v;
        posicao = get_pos_vertice(v);
        distancias[i] = distancia(posicao, pos);
        p = get_proximo_lista(G, p);
    }

    index = minima_distancia(distancias, sptset, qtd_vertices(G));

    return vertices[index];
}

int printar_distancias(double dist[], int n)
{
    printf("Vértice   Distância do primeiro\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d tt %lf\n", i, dist[i]);
    }
}

void free_atributos_aresta(void *atributos) {
    atributos_aresta *atri = NULL;

    atri = (atributos_aresta *) atributos;

    if(atri != NULL) {
        if(atri->nome != NULL) {
            free(atri->nome);
            atri->nome = NULL;
        }
        if(atri->ldir != NULL) {
            free(atri->ldir);
            atri->ldir = NULL;
        }
        if(atri->lesq != NULL) {
            free(atri->lesq);
            atri->lesq = NULL;
        }
        free(atri);
    }
}

void free_aresta(void *a) {
    aresta *ares = NULL;
    atributos_aresta *atri = NULL;
    
    ares = (aresta *) a;

    if(ares != NULL) {
        if(ares->ligado_a != NULL) {
            free(ares->ligado_a);
            ares->ligado_a = NULL;
        }
        free_atributos_aresta(ares->atributos);
        ares->atributos = NULL;
        free(ares);
    }
}

void free_vertice(void *v) {
    vertice *vert = NULL;
    Lista l = NULL;
    Posic p = NULL;
    void *a = NULL;

    vert = (vertice *) v;

    if(vert != NULL) {
        if(vert->id != NULL) {
            free(vert->id);
            vert->id = NULL;
        }
        if(vert->pos != NULL) {
            free(vert->pos);
            vert->pos = NULL;
        }
        if (vert->arestas != NULL) {
            l = (Lista) vert->arestas;
            while(largura_lista(l) != 0) {
                p = remove_lista(l, get_primeiro_lista(l));
                a = get_valor_lista(p);
                free_aresta(a);
                a = NULL;
                free_posic(p);
                p = NULL;
            }
            free(l);
            vert->arestas = NULL;
        }
        free(vert);
    }
}

void free_grafo(Grafo G) {
    Lista l = NULL, lAux = NULL;
    Posic p = NULL;
    void *v = NULL;

    l = (Lista *) G;

    while(largura_lista(l) != 0) {
        p = remove_lista(l,get_primeiro_lista(l));
        v = get_valor_lista(p);
        free_posic(p);
        p = NULL;
        free_vertice(v);
        v = NULL;
    }
    free(l);
}