#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Formas/Retangulo/retangulo.h"

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
    aux->cep = (char*) calloc (55, sizeof (char));
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
    sprintf (result, "\n<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"2\" style=\"opacity:0.7\"/>", aux->x, aux->y, aux->w, aux->h, aux->cor_preenche, aux->cor_borda);
    return result;
}

//PEGA O CEP DA QUADRA
char* get_cep_quadra (void* quadra)
{
    Quadra* aux;
    aux = (Quadra*) quadra;
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
    if(quadA == NULL) {
        printf("fodei\n");
    }
    if(quadA->cep == NULL) {
        printf("AAAAAAAAAA\n");
    }
    if(quadB->cep == NULL) {
        printf("BBBBBBBBBBB\n");
    }
    if (!strcmp(quadA->cep, quadB->cep))
    {
        return 0;
    }
    if (dim == 0)
    {
        return (quadB->x - quadA->x);
    }
    else
    {
        return (quadB->y - quadA->y);
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

//COMPARADOR DE CEP DA QUADRA PARA HASHTABLE
int compare_hash_quadra (void* quad, void* cep)
{
    Quadra* quadA;
    Quadra* quadB;
    quadA = (Quadra*) quad;
    quadB = (Quadra*) cep;
    return strcmp (quadA->cep, quadB->cep);
}

//LIBERA A MEMÓRIA ALOCADA DA QUADRA
void free_quadra (void* quad)
{
    Quadra* quadra;
    quadra = (Quadra*) quad;
    free (quadra->cep);
    quadra->cep = NULL;
    free (quadra->cor_borda);
    quadra->cor_borda = NULL;
    free (quadra->cor_preenche);
    quadra->cor_preenche = NULL;
    free (quadra);
    quadra = NULL;
    return;
}

//ESCREVE A QUADRA NO ARQUIVO
void escreve_arquivo_quadra (void* quadra, int procura, FILE* arq)
{
    int i;
    Quadra* quad;
    quad = (Quadra*) quadra;
    fseek (arq, procura, SEEK_SET);
    fwrite (&quad->x, sizeof (double), 1, arq);
    fwrite (&quad->y, sizeof (double), 1, arq);
    fwrite (&quad->w, sizeof (double), 1, arq);
    fwrite (&quad->h, sizeof (double), 1, arq);
    for (i=0; i<55; i++)
    {
        fwrite (&quad->cep[i], sizeof (char), 1, arq);
    }
    for (i=0; i<55; i++)
    {
        fwrite (&quad->cor_borda[i], sizeof (char), 1, arq);
    }
    for (i=0; i<55; i++)
    {
        fwrite (&quad->cor_preenche[i], sizeof (char), 1, arq);
    }
}

// LÊ A QUADRA DO ARQUIVO
void ler_arquivo_quadra (void* quadra, int procura, FILE* arq)
{
    int i;
    Quadra* quad;
    quad = (Quadra*) quadra;
    fseek (arq, procura, SEEK_SET);
    fread (&quad->x, sizeof (double), 1, arq);
    fread (&quad->y, sizeof (double), 1, arq);
    fread (&quad->w, sizeof (double), 1, arq);
    fread (&quad->h, sizeof (double), 1, arq);
    for (i=0; i<55; i++)
    {
        fread (&quad->cep[i], sizeof (char), 1, arq);
    }
    for (i=0; i<55; i++)
    {
        fread (&quad->cor_borda[i], sizeof (char), 1, arq);
    }
    for (i=0; i<55; i++)
    {
        fread (&quad->cor_preenche[i], sizeof (char), 1, arq);
    }
}

// RETORNA O TAMANHO DA QUADRA
int get_tamanho_quadra ()
{
    return 4 * sizeof (double) + (3 * 55 * sizeof (char));
}

//FUNÇÃO DE COMPARAÇÃO DA ÁRVORE B DA QUADRA
double compare_quadra (void* objA, void* objB)
{
    double result;
    Quadra* quadA;
    Quadra* quadB;
    quadA = (Quadra*) objA;
    quadB = (Quadra*) objB;
    if (!strcmp (quadA->cep, quadB->cep)) return 0;
    result = sqrt (pow (quadB->x - quadA->x, 2) + pow (quadB->y - quadA->y, 2));
    if (quadB->x > quadA->x && quadB->y > quadA->x) return result;
    return -result;
}

//ALOCA A MEMÓRIA NECESSÁRIA PARA A QUADRA
void* alloc_quadra ()
{
    Quadra *quad;
    quad = (Quadra*) calloc (1, sizeof (Quadra));
    quad->cep = (char*) calloc (55, sizeof (char));
    quad->cor_borda = (char*) calloc (55, sizeof (char));
    quad->cor_preenche = (char*) calloc (55, sizeof (char));
    return quad;
}