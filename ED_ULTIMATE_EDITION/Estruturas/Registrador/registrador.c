#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registrador.h"

typedef struct registrador
{
    double* pos;
    char* nome;
    void* tipo;
} Regis;

//CRIA E RETORNA UM REGISTRADOR
Registrador cria_registrador (char *nome)
{
    Regis* regis = NULL;

    regis = (Regis*) calloc (1, sizeof (Regis));
    regis->pos = NULL;
    regis->tipo = NULL;
    regis->nome = (char *) calloc(5, sizeof(char));
    strcpy(regis->nome, nome);

    return (Registrador) regis;
}

//INSERE A COORDENADA NO REGISTRADOR
void insere_pos_registrador (Registrador r, double* pos)
{
    Regis* regis = NULL;
    regis = (Regis*) r;
    regis->pos = pos;
    return;
}

//INSERE O TIPO NO REGISTRADOR
void insere_tipo_registrador (Registrador r, void* tipo)
{
    Regis* regis = NULL;
    regis = (Regis*) r;
    regis->tipo = tipo;
    return;
}

//INSERE O NOME NO REGISTRADOR
void insere_nome_registrador (Registrador r, char* nome)
{
    Regis* regis = NULL;
    regis = (Regis *) r;
    regis->nome = nome;
    return;
}

//RETORNA A COORDENADA PRESENTE NO REGISTRADOR
double* get_pos_registrador (Registrador r)
{
    Regis* regis = NULL;
    regis = (Regis*) r;
    return regis->pos;
}

//RETORNA O TIPO PRESENTE NO REGISTRADOR
void* get_tipo_registrador (Registrador r)
{
    Regis*regis = NULL;
    regis = (Regis*) r;
    return regis->tipo;
}

//RETORNA O NOME PRESENTE NO REGISTRADOR
char* get_nome_registrador (Registrador r)
{
    Regis* regis = NULL;
    regis = (Regis*) r;
    return regis->nome;
}

//BUSCA UM REGISTRADOR ESPECÍFICADO PELO NOME
int busca_registrador (Registrador* registradores, char* nome)
{
    Regis* regis = NULL;
    int i = 0;
    for(i = 0; i < 11; i++)
    {
        regis = (Regis*) registradores[i];
        if (regis == NULL) 
        {
            continue;
        }

        if (!strcmp (regis->nome, nome))
        {
            break;
        }
    }
    
    if (i == 11) {
        i = -1;
    }

    return i;
}

void free_registrador(Registrador registrador) {
    Regis *regis = NULL;

    regis = (Regis *) registrador;

    if (regis->nome != NULL) {
        free(regis->nome);
    }
    if (regis->pos != NULL) {
        free(regis->pos);
    }
    if (regis->tipo != NULL) {
        free(regis->tipo);
    }
    free(regis);
}

void free_registradores(Registrador *registradores) {
    Regis **regis = NULL;
    int i = 0;

    regis = (Regis **) registradores;
    
    for(i = 0; i < 11; i++)
    {
        free_registrador(regis[i]);
    }
    free(regis);
}