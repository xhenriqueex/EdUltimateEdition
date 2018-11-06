#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "radiobase.h"

//INICIA A STRUCT RÁDIO-BASE
typedef struct radiobase {
    double r;
    double x;
    double y;
    char* id;
    char* cor_borda;
    char* cor_preenche;
} Radiobase;

//RETORNA UM PONTEIRO PARA VOID COM AS INFORMAÇÕES DA RÁDIO-BASE
void* cria_radiobase (char* id, double r, double x, double y, char* cor_borda, char* cor_preenche)
{
    Radiobase* aux;
    aux = (Radiobase*) calloc (1, sizeof (Radiobase));
    aux->id = (char*) calloc (strlen (id) + 2, sizeof(char));
    strcpy (aux->id, id);
    aux->cor_borda = (char*) calloc (55, sizeof(char));
    strcpy (aux->cor_borda, cor_borda);
    aux->cor_preenche = (char*) calloc (55, sizeof(char));
    strcpy (aux->cor_preenche, cor_preenche);
    aux->r = r;
    aux->x = x;
    aux->y = y;
    return (void*) aux;
}

//RETORNA UMA STRING COM AS INFORMAÇÕES PARA IMPRIMIR O SEMÁFORO NO SVG
char* cria_svg_radiobase (void* radiobase)
{
    Radiobase* aux;
    char* result = (char*) calloc(255, sizeof(char));
    aux = (Radiobase*) radiobase;
    sprintf (result, "\n<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"2\" />", aux->x, aux->y, aux->r, aux->cor_borda, aux->cor_preenche);
    return result;
}

//PEGA O ID DA RÁDIO-BASE
char* get_id_radiobase (void* radiobase)
{
    Radiobase* aux;
    aux = (Radiobase*) radiobase;
    return aux->id;   
}

//PEGA O RAIO DA RÁDIO-BASE
double get_r_radiobase (void* radiobase)
{
    Radiobase* aux;
    aux = (Radiobase*) radiobase;
    return aux->r;
}

//PEGA O X DA RÁDIO-BASE
double get_x_radiobase (void* radiobase)
{
    Radiobase* aux;
    aux = (Radiobase*) radiobase;
    return aux->x;
}

//PEGA O Y DA RÁDIO-BASE
double get_y_radiobase (void* radiobase)
{
    Radiobase* aux;
    aux = (Radiobase*) radiobase;
    return aux->y;
}

//PEGA COR1 DA RÁDIO-BASE
char* get_cor1_radiobase (void* radiobase)
{
    Radiobase* rb;
    rb = (Radiobase*) radiobase;
    return rb->cor_borda;
}

//PEGA COR2 DA RÁDIO-BASE
char* get_cor2_radiobase (void* radiobase)
{
    Radiobase* rb;
    rb = (Radiobase*) radiobase;
    return rb->cor_preenche;
}

//ALTERA AS CORES DA BORDA E DO PREENCHIMENTO DA RÁDIO-BASE
void* troca_cor_radiobase (void* radiobase, char* cor_borda, char* cor_preenche)
{
    Radiobase* aux;
    aux = (Radiobase*) radiobase;
    strcpy (aux->cor_borda, cor_borda);
    strcpy (aux->cor_preenche, cor_preenche);
    return (void*) aux;
}