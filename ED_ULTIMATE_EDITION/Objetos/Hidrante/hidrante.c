#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Formas/Círculo/circulo.h"

//DEFINE A STRUCT HIDRANTE
typedef struct hidrante {
    double r;
    double x;
    double y;
    char* id;
    char* cor_borda;
    char* cor_preenche;
} Hidrante;

//RETORNA UM PONTEIRO PARA VOID COM AS INFORMAÇÕES DO HIDRANTE
void* cria_hidrante (char* id, double r, double x, double y, char* cor_borda, char* cor_preenche)
{
    Hidrante* aux;
    aux = (Hidrante*) calloc (1, sizeof (Hidrante));
    aux->id = (char*) calloc (strlen (id) + 2, sizeof (char));
    strcpy (aux->id, id);
    aux->cor_borda = (char*) calloc (55, sizeof (char));
    strcpy (aux->cor_borda, cor_borda);
    aux->cor_preenche = (char*) calloc (55, sizeof (char));
    strcpy (aux->cor_preenche, cor_preenche);
    aux->r = r;
    aux->x = x;
    aux->y = y;
    return (void*) aux;
}

//RETORNA UMA STRING COM AS INFORMAÇÕES PARA IMPRIMIR O HIDRANTE NO SVG
char* cria_svg_hidrante (void* hidrante)
{
    Hidrante* aux;
    char* result = (char*) calloc (255, sizeof (char));
    aux = (Hidrante*) hidrante;
    sprintf (result, "\n<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"2\"/>", aux->x, aux->y, aux->r, aux->cor_preenche, aux->cor_borda);
    return result;
}

//PEGA O ID DO HIDRANTE
char* get_id_hidrante (void* hidrante)
{
    Hidrante* hid;
    hid = hidrante;
    return hid->id;
}
//PEGA O RAIO DO HIDRANTE
double get_r_hidrante (void* hidrante)
{
    Hidrante* hid;
    hid = (Hidrante*) hidrante;
    return hid->r;
}

//PEGA O X DO HIDRANTE
double get_x_hidrante (void* hidrante)
{
    Hidrante* hid;
    hid = (Hidrante*) hidrante;
    return hid->x;
}

//PEGA O Y DO HIDRANTE
double get_y_hidrante (void* hidrante)
{
    Hidrante* hid;
    hid = (Hidrante*) hidrante;
    return hid->y;
}

//ALTERA AS CORES DA BORDA E DO PREENCHIMENTO DO HIDRANTE
void* muda_cor_hidrante (void* hidrante, char* cor_borda, char* cor_preenche)
{
    Hidrante* aux;
    aux = (Hidrante*) hidrante;
    strcpy (aux->cor_borda, cor_borda);
    strcpy (aux->cor_preenche, cor_preenche);
    return (void*) aux;
}

//PEGA A COR1 DO HIDRANTE
char* get_cor1_hidrante (void* hidrante)
{
    Hidrante* hid;
    hid = (Hidrante*) hidrante;
    return hid->cor_borda;
}

//PEGA A COR2 DO HIDRANTE
char* get_cor2_hidrante (void* hidrante)
{
    Hidrante* hid;
    hid = (Hidrante*) hidrante;
    return hid->cor_preenche;
}

//FUNÇÃO DE COMPARAÇÃO DE ID DE HIDRANTE
int compare_hidrante (void* hid1, void* hid2, int dim)
{
    Hidrante* hidA;
    Hidrante* hidB;    
    hidA = (Hidrante*) hid1;
    hidB = (Hidrante*) hid2;
    dim = dim % 2;
    if (!strcmp(hidA->id, hidB->id))
    {
        return 0;
    }
    if (dim == 0)
    {
        return (hidB->x - hidA->x);
    }
    else
    {
        return (hidB->y - hidA->y);
    }
}

//RETORNA O CÓDIGO HASH DO HIDRANTE
int hashcode_hidrante (void* hid, int modulo)
{
    Hidrante* result;
    result = (Hidrante*) hid;
    int x = strlen (result->id);
    int hash = 0;
    char* aux = result->id;
    while (*aux != 0)
    {
        hash += x*(*aux);
        aux++;
        x--;
    }
    return modulo < 0 ? hash : hash % modulo;
}

//COMPARADOR DE CEP DO HIDRANTE PARA HASHTABLE
int compare_hash_hidrante (void* hid, void* id)
{
    Hidrante* hidA;
    Hidrante* hidB;
    hidA = (Hidrante*) hid;
    hidB = (Hidrante*) id;
    return strcmp (hidA->id, hidB->id);
}

//FUNÇÃO QUE RETORNA UM CÍRCULO COM AS INFORMAÇÕES DO HIDRANTE
void* get_circulo_hidrante (void* hidrante)
{
    long int id;
    Hidrante* hid;
    hid = (Hidrante*) hidrante;
    return cria_circulo (0, hid->cor_borda, hid->cor_preenche, hid->r, hid->x, hid->y);
}


void free_hidrante(void *hidrante)
{
    Hidrante *hid;
    hid = (Hidrante *) hidrante;
    
    if(hid->id != NULL) {
        free(hid->id);
        hid->id = NULL;
    }
    if(hid->cor_borda != NULL) {
        free(hid->cor_borda);
        hid->cor_borda = NULL;
    }
    if(hid->cor_preenche != NULL) {
        free(hid->cor_preenche);
        hid->cor_preenche = NULL;
    }
    free(hid);
    hid = NULL;
}