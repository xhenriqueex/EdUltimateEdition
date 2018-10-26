#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funçoes.h"
#include "retangulo.h"
#include "circulo.h"

typedef struct params {
    char* caminho_GEO;
    char* caminho_TXT;
    char* caminho_SVG;
    char* diretorio_entrada;
    char* arquivo_entrada;
    char* diretorio_saida;
    char** comando_vetor;
    long int max_figuras;
} Parametros;

void executa_comando (void* p)
{
    long int id;
    int r, w, h, x, y;
    char* cor1;
    char* cor2;
    Parametros* par;
    par = (Parametros*) p;
    if (!strcmp (*(par->comando_vetor), "nx"))
    {
        sscanf(*(par->comando_vetor + 1), "%ld", par->max_figuras);
        return;
    }
    if (!strcmp (*(par->comando_vetor), "c"))
    {
        id = *(par->comando_vetor + 1);
        sscanf (*(par->comando_vetor + 2), "%s", cor1);
        sscanf (*(par->comando_vetor + 3), "%s", cor2);
        r = *(par->comando_vetor + 4);
        x = *(par->comando_vetor + 5);
        y = *(par->comando_vetor + 6);
        cria_circulo (id, cor1, cor2, r, x, y);
        return;
    }
    if (!strcmp (*(par->comando_vetor), "r"))
    {
        id = *(par->comando_vetor + 1);
        sscanf (*(par->comando_vetor + 2), "%s", cor1);
        sscanf (*(par->comando_vetor + 3), "%s", cor2);
        w = *(par->comando_vetor + 4);
        h = *(par->comando_vetor + 5);
        x = *(par->comando_vetor + 6);
        y = *(par->comando_vetor + 7);
        cria_retangulo (id, cor1, cor2, w, h, x, y);
        return;
    }
    if (!strcmp (*(par->comando_vetor), "o"))
    {
        //sobrepoe ();
        return;
    }
    if (!strcmp (*(par->comando_vetor), "i"))
    {
        return;
    }
    if (!strcmp (*(par->comando_vetor), "d"))
    {
        return;
    }
    if (!strcmp (*(par->comando_vetor), "a"))
    {
        return;
    }
    if (!strcmp (*(par->comando_vetor), "#"))
    {
        return;
    }
}