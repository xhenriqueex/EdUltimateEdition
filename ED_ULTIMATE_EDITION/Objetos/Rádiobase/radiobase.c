#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Formas/Círculo/circulo.h"

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
void* muda_cor_radiobase (void* radiobase, char* cor_borda, char* cor_preenche)
{
    Radiobase* aux;
    aux = (Radiobase*) radiobase;
    strcpy (aux->cor_borda, cor_borda);
    strcpy (aux->cor_preenche, cor_preenche);
    return (void*) aux;
}

//FUNÇÃO DE COMPARAÇÃO DE ID DE RÁDIOBASE
int compare_radiobase (void* rb1, void* rb2, int dim)
{
    Radiobase* rbA;
    Radiobase* rbB;    
    rbA = (Radiobase*) rb1;
    rbB = (Radiobase*) rb2;
    dim = dim % 2;
    if (!strcmp(rbA->id, rbB->id))
    {
        return 0;
    }
    if (dim == 0)
    {
        return (rbA->x - rbB->x);
    }
    else
    {
        return (rbA->y - rbB->y);
    }
}

//RETORNA O CÓDIGO HASH DA RADIOBASE
int hashcode_radiobase (void* rb, int modulo)
{
    Radiobase* result;
    result = (Radiobase*) rb;
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

//COMPARADOR DE CEP DA RÁDIOBASE PARA HASHTABLE
int compare_hash_radiobase (void* rb, void* id)
{
    Radiobase* rbA;
    Radiobase* rbB;
    rbA = (Radiobase*) rb;
    rbB = (Radiobase*) id;
    return strcmp (rbA->id, rbB->id);
}

//FUNÇÃO QUE RETORNA UM CÍRCULO COM AS INFORMAÇÕES DA RÁDIOBASE
void* get_circulo_radiobase (void* radiobase)
{
    Radiobase* rb;
    rb = (Radiobase*) radiobase;
    return cria_circulo (0, rb->cor_borda, rb->cor_preenche, rb->r, rb->x, rb->y);
}