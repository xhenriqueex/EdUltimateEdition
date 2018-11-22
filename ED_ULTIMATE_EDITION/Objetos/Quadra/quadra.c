#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Formas/Retângulo/retangulo.h"

//DEFINE A STRUCT QUADRA
typedef struct quadra{
    double x;
    double y;
    double w;
    double h;
    char* cep;
    char* cor_borda;
    char* cor_preenche;
} Quadra;

//RETORNA UM PONTEIRO PARA VOID COM AS INFORMAÇÕES DA QUADRA
void* cria_quadra (char* cep, double x, double y, double w, double h, char* cor_borda, char* cor_preenche)
{
    Quadra* aux;
    aux = (Quadra*) calloc (1, sizeof (Quadra));
    aux->cep = (char*) calloc (strlen (cep) + 2, sizeof (char));
    strcpy (aux->cep, cep);
    aux->cor_borda = (char*) calloc (55, sizeof(char));
    strcpy (aux->cor_borda, cor_borda);
    aux->cor_preenche = (char*) calloc (55, sizeof(char));
    strcpy (aux->cor_preenche, cor_preenche);
    aux->x = x;
    aux->y = y;
    aux->w = w;
    aux->h = h;
    return (void*) aux;
}

//RETORNA UMA STRING COM AS INFORMAÇÕES PARA IMPRIMIR A QUADRA NO SVG
char* cria_svg_quadra (void* quadra)
{
    Quadra* aux;
    char* result = (char*) calloc (255, sizeof(char));
    aux = (Quadra*) quadra;
    sprintf (result, "\n<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"2\" />", aux->x, aux->y, aux->w, aux->h, aux->cor_borda, aux->cor_preenche);
    return result;
}

//PEGA O CEP DA QUADRA
char* get_cep_quadra (void* quadra)
{
    Quadra* aux;
    aux = quadra;
    return aux->cep;   
}

//PEGA A LARGURA DA QUADRA
double get_w_quadra (void* quadra)
{
    Quadra* aux;
    aux = (Quadra*) quadra;
    return aux->w;
}

//PEGA A ALTURA DA QUADRA
double get_h_quadra (void* quadra)
{
    Quadra* aux;
    aux = (Quadra*) quadra;
    return aux->h;
}

//PEGA O X DA QUADRA
double get_x_quadra (void* quadra)
{
    Quadra* aux;
    aux = (Quadra*) quadra;
    return aux->x;
}

//PEGA O Y DA QUADRA
double get_y_quadra (void* quadra)
{
    Quadra* aux;
    aux = (Quadra*) quadra;
    return aux->y;
}

//ALTERA AS CORES DA BORDA E DO PREENCHIMENTO DA QUADRA
void* muda_cor_quadra (void* quadra, char* cor_preenche, char* cor_borda)
{
    Quadra* aux;
    aux = (Quadra*) quadra;
    strcpy (aux->cor_preenche, cor_preenche);
    strcpy (aux->cor_borda, cor_borda);
    return (void*) aux;
}

//RETORNA A COR1 DA QUADRA
char* get_cor1_quadra (void* quadra)
{
    Quadra* aux;
    aux = (Quadra*) quadra;
    return aux->cor_borda;
}

//RETORNA A COR2 DA QUADRA
char* get_cor2_quadra (void* quadra)
{
    Quadra* aux;
    aux = (Quadra*) quadra;
    return aux->cor_preenche;
}

Retangulo get_retangulo_quadra (void* quadra)
{
    Quadra* quad;
    quad = (Quadra*) quadra;
    return cria_retangulo (0, quad->cor_borda, quad->cor_preenche, quad->w, quad->h, quad->x, quad->y);
}

//FUNÇÃO DE COMPARAÇÃO DE CEP DE QUADRA
int compare_quadra (void* quad1, void* quad2, int dim)
{
    Quadra* quadA;
    Quadra* quadB;    
    quadA = (Quadra*) quad1;
    quadB = (Quadra*) quad2;
    dim = dim % 2;
    if (!strcmp(quadA->cep, quadB->cep))
    {
        return 0;
    }
    if (dim == 0)
    {
        return (quadA->x - quadB->x);
    }
    else
    {
        return (quadA->y - quadB->y);
    }
}

//RETORNA O CÓDIGO HASH DA QUADRA
int hashcode_quadra (void* quad, int modulo)
{
    Quadra* result;
    result = (Quadra*) quad;
    int x = strlen (result->cep);
    int hash = 0;
    char* aux = result->cep;
    while (*aux != 0)
    {
        hash += x*(*aux);
        aux++;
        x--;
    }
    return modulo < 0 ? hash : hash % modulo;
}