#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct _elemento
{
    Valor valor;
    struct _elemento *proximo;
};

struct _fila
{
    struct _elemento *comeco;
    struct _elemento *fim;
};

typedef struct _elemento elemento;
typedef struct _fila fila;


Fila cria_fila ()
{
    fila *f = NULL;

    f = (fila *) calloc(1, sizeof(fila));

    f->comeco = NULL;
    f->fim = NULL;

    return (void *) f;
}

int fila_vazia (Fila f)
{
    fila *f0 = NULL;

    f0 = (fila *) f;

    if(f0->comeco == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insere_fila (Fila f, Valor unidade)
{
    fila *f0 = NULL;
    elemento *e0 = NULL, *e1 = NULL;

    f0 = (fila *) f;

    e1 = (elemento *) calloc(1, sizeof(elemento));
    e1->valor = unidade;
    e1->proximo = NULL;
    
    if (!fila_vazia(f))
    {
        e0 = f0->fim;
        e0->proximo = e1;
    }
    else
    {
        f0->comeco = e1;
    }

    f0->fim = e1;
}

Valor remove_fila (Fila f)
{
    fila *f0 = NULL;
    elemento *e0 = NULL;

    f0 = (fila *) f;
    
    if (!fila_vazia(f))
    {
        e0 = f0->comeco;
        f0->comeco = e0->proximo;
        return e0->valor;
    }
    else
    {
        return NULL;
    }
}