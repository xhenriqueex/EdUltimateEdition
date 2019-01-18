#ifndef GRAFO_FORMA_H
#define GRAFO_FORMA_H

#include "../../Estruturas/Grafo/grafo.h"

typedef void* Grafo_forma;

Grafo_forma cria_grafo_forma(Grafo G, char **vertices, char *sufixo, char *cor1, char *cor2);

void escreve_grafo(Grafo_forma gf);

void free_grafo_forma(Grafo_forma gf);

#endif