#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../../Formas/Circulo/circulo.h"

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
    aux->id = (char*) calloc (55, sizeof(char));
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
    sprintf (result, "\n<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"2\" />", aux->x, aux->y, aux->r, aux->cor_preenche, aux->cor_borda);
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
        return (rbB->x - rbA->x);
    }
    else
    {
        return (rbB->y - rbA->y);
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

//LIBERA A MEMÓRIA ALOCADA DA RÁDIOBASE
void free_radiobase (void* radiobase)
{
    Radiobase* rb;
    rb = (Radiobase*) radiobase;
    free (rb->cor_borda);
    rb->cor_borda = NULL;
    free (rb->cor_preenche);
    rb->cor_preenche = NULL;
    free (rb->id);
    rb->id = NULL;
    free (rb);
    rb = NULL;
    return;
}

//ESCREVE A RÁDIOBASE NO ARQUIVO
void escreve_arquivo_radiobase (void* radiobase, int procura, FILE* arq)
{
    int i;
    Radiobase* rb;
    rb = (Radiobase*) radiobase;
    fseek (arq, procura, SEEK_SET);
    fwrite (&rb->r, sizeof (double), 1, arq);
    fwrite (&rb->x, sizeof (double), 1, arq);
    fwrite (&rb->y, sizeof (double), 1, arq);
    for (i=0; i<55; i++)
    {
        fwrite (&rb->id[i], sizeof (char), 1, arq);
    }
    for (i=0; i<55; i++)
    {
        fwrite (&rb->cor_borda[i], sizeof (char), 1, arq);
    }
    for (i=0; i<55; i++)
    {
        fwrite (&rb->cor_preenche[i], sizeof (char), 1, arq);
    }
}

//LÊ A RÁDIOBASE DO ARQUIVO
void ler_arquivo_radiobase (void* radiobase, int procura, FILE* arq)
{
    int i;
    Radiobase* rb;
    rb = (Radiobase*) radiobase;
    fseek (arq, procura, SEEK_SET);
    fread (&rb->r, sizeof (double), 1, arq);
    fread (&rb->x, sizeof (double), 1, arq);
    fread (&rb->y, sizeof (double), 1, arq);
    for (i=0; i<55; i++)
    {
        fread (&rb->id[i], sizeof (char), 1, arq);
    }
    for (i=0; i<55; i++)
    {
        fread (&rb->cor_borda[i], sizeof (char), 1, arq);
    }
    for (i=0; i<55; i++)
    {
        fread (&rb->cor_preenche[i], sizeof (char), 1, arq);
    }
}

//RETORNA O TAMANHO DA RÁDIOBASE
int get_tamanho_radiobase ()
{
    return 3 * sizeof (double) + (3 * 55 * sizeof (char));
}

//FUNÇÃO DE COMPARAÇÃO DA ÁRVORE B DA RÁDIOBASE
double compare_radiobase_arvoreB (void* objA, void* objB)
{
    double result;
    Radiobase* rbA;
    Radiobase* rbB;
    rbA = (Radiobase*) objA;
    rbB = (Radiobase*) objB;
    if (!strcmp (rbA->id, rbB->id)) return 0;
    result = sqrt (pow (rbB->x - rbA->x, 2) + pow (rbB->y - rbA->y, 2));
    if (rbB->x > rbA->x && rbB->y > rbA->x) return result;
    return -result;
}

//ALOCA A MEMÓRIA NECESSÁRIA PARA A RÁDIOBASE
void* alloc_radiobase ()
{
    Radiobase* rb;
    rb = (Radiobase*) calloc (1, sizeof (Radiobase));
    rb->id = (char*) calloc (55, sizeof (char));
    rb->cor_borda = (char*) calloc (55, sizeof (char));
    rb->cor_preenche = (char*) calloc (55, sizeof (char));
    return rb;
}