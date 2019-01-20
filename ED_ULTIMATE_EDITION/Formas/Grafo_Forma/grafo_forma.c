#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo_forma.h"

struct _grafo_forma
{
    Grafo G;
    char **vertices;
    char *nome_arquivo;
    char *cor1;
    char *cor2;
};

typedef struct _grafo_forma grafo_forma;

Grafo_forma cria_grafo_forma(Grafo G, char **vertices, char *nome_arquivo, char *cor1, char *cor2) {
    grafo_forma *grfo = NULL;
    int i = 0, n = 0;

    grfo = (grafo_forma *) calloc(1, sizeof(grafo_forma));

    grfo->G = G;
    i = 0;
    while(vertices[i] != NULL)
    {
        i++;
    }
    grfo->vertices = (char **) calloc(i+2, sizeof(char *));
    n = i;
    for(i = 0; i < n; i++)
    {
        grfo->vertices[i] = (char *) calloc(strlen(vertices[i])+1, sizeof(char));

        strcpy(grfo->vertices[i], vertices[i]);
    }
    grfo->vertices[i] = NULL;
    grfo->vertices[i+1] = NULL;
    grfo->nome_arquivo = (char *) calloc(strlen(nome_arquivo)+1, sizeof(char));
    strcpy(grfo->nome_arquivo, nome_arquivo);
    grfo->cor1 = (char *) calloc(strlen(cor1)+1, sizeof(char));
    strcpy(grfo->cor1, cor1);
    grfo->cor2 = (char *) calloc(strlen(cor2)+1, sizeof(char));
    strcpy(grfo->cor2, cor2);

    return (Grafo_forma) grfo;
}

char *get_nome_arq_grafo_forma(Grafo_forma gf) {
    grafo_forma *grfo = NULL;

    grfo = (grafo_forma *) gf;

    return grfo->nome_arquivo;
}

void escreve_grafo(Grafo_forma gf) {
    grafo_forma *grfo = NULL;
    FILE *arquivo = NULL;
    void *vert1 = NULL, *vert2 = NULL;
    double *pos1 = NULL, *pos2 = NULL;
    char *auxCor = NULL;
    char **vertices = NULL;
    int i = 0;

    grfo = (grafo_forma *) gf;
    vertices = grfo->vertices;
    arquivo = fopen(grfo->nome_arquivo, "a");
    auxCor = grfo->cor1;

    i = 0;
    vert1 = get_vertice(grfo->G, vertices[i]);
    pos1 = get_pos_vertice(vert1);
    fprintf(arquivo,
        "\n<circle cx=\"%lf\" cy=\"%lf\" r=\"5\" fill=\"transparent\" stroke=\"black\" stroke-width=\"2\"/>\n",
        pos1[0], pos1[1]);
    while(vertices[i+1] != NULL)
    {
        vert1 = get_vertice(grfo->G, vertices[i]);
        vert2 = get_vertice(grfo->G, vertices[i+1]);

        pos1 = get_pos_vertice(vert1);
        pos2 = get_pos_vertice(vert2);

        if(strcmp(grfo->cor2, " ") != 0) {
            if(i%2 == 0) {
                auxCor = grfo->cor1;
            }
            else {
                auxCor = grfo->cor2;
            }
        }

        fprintf (arquivo,
            "\n<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"3\"/>",
            pos1[0], pos1[1], pos2[0], pos2[1], auxCor);
        fprintf(arquivo,
            "\n<circle cx=\"%lf\" cy=\"%lf\" r=\"5\" fill=\"transparent\" stroke=\"black\" stroke-width=\"2\"/>",
            pos2[0], pos2[1]);
            
        i++;
    }

    fclose(arquivo);
    arquivo = NULL;
}

void free_grafo_forma(Grafo_forma gf) {
    grafo_forma *grfo = NULL;
    int i = 0;

    grfo = (grafo_forma *) gf;

    if(grfo != NULL) {
        if(grfo->vertices != NULL) {
            i = 0;
            while(grfo->vertices[i] != NULL)
            {
                free(grfo->vertices[i]);
                grfo->vertices[i] = NULL;
            }
            free(grfo->vertices);
        }
        if(grfo->nome_arquivo != NULL) {
            free(grfo->nome_arquivo);
            grfo->nome_arquivo = NULL;
        }
        if(grfo->cor1 != NULL) {
            free(grfo->cor1);
            grfo->cor1 = NULL;
        }
        if(grfo->cor2 != NULL) {
            free(grfo->cor2);
            grfo->cor2 = NULL;
        }
        grfo->G = NULL;
        free(grfo);
    }
}