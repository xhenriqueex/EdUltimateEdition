#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registrador.h"

struct registrador
{
    double *pos;
    void *tipo;
    char *nome;
};

typedef struct registrador Regis;


Registrador cria_registrador()
{
    Regis *regis = NULL;

    regis = (Regis *) calloc(1, sizeof(Regis));

    regis->pos = NULL;
    regis->tipo = NULL;
    regis->nome = NULL;

    return (Registrador) regis;
}

void insere_pos_registrador(Registrador r, double *pos)
{
    Regis *regis = NULL;

    regis = (Regis *) r;

    regis->pos = pos;

    return;
}

void insere_tipo_registrador(Registrador r, void *tipo)
{
    Regis *regis = NULL;

    regis = (Regis *) r;

    regis->tipo = tipo;

    return;
}

void insere_nome_registrador(Registrador r, char *nome)
{
    Regis *regis = NULL;

    regis = (Regis *) r;

    regis->nome = nome;

    return;
}

double *get_pos_registrador(Registrador r)
{
    Regis *regis = NULL;

    regis = (Regis *) r;

    return regis->pos;
}

void *get_tipo_registrador(Registrador r)
{
    Regis *regis = NULL;

    regis = (Regis *) r;

    return regis->tipo;
}

char *get_nome_registrador(Registrador r)
{
    Regis *regis = NULL;

    regis = (Regis *) r;

    return regis->nome;
}

int busca_registrador(Registrador *registradores, char *nome)
{
    Regis *regis = NULL;
    int i = 0;

    for(i = 0; i < 11; i++)
    {
        regis = (Regis *) registradores[i];

        if (regis == NULL) {
            continue;
        }
        
        if(strcmp(regis->nome, nome) == 0)
        {
            break;
        }
    }
    
    return i;
}
