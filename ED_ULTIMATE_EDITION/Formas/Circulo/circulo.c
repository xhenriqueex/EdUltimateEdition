#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//INICIALIZANDO STRUCT CIRCULO
typedef struct circle {
    long int id;
    char* cor1;
    char* cor2;
    double r;
    double x;
    double y;
} Circulo;

//RETORNA UM PONTEIRO PARA VOID COM AS INFORMAÇÕES DO CÍRCULO
void* cria_circulo (long int id, char* cor1, char* cor2, double r, double x, double y)
{
    Circulo* circulo = NULL;
    circulo = (Circulo*) calloc (1, sizeof (Circulo));
    circulo->cor1 = (char*) calloc (55, sizeof(char));
    circulo->cor2 = (char*) calloc (55, sizeof(char));
    strcpy(circulo->cor1, cor1);
    strcpy(circulo->cor2, cor2);
    circulo->id = id;
    circulo->r = r;
    circulo->x = x;
    circulo->y = y;
    return (void*) circulo;
}

//RETORNA UMA STRING COM AS INFORMAÇÕES PARA IMPRIMIR O CÍRCULO NO SVG
char* cria_svg_circulo (void* circle)
{
    Circulo* circulo = NULL;
    char* result = (char*) calloc (255, sizeof(char));
    circulo = (Circulo*) circle;
    sprintf (result, "\n<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"2\" style=\"opacity:0.7\"/>", circulo->x, circulo->y, circulo->r, circulo->cor2, circulo->cor1);
    return result;
}

//RETORNA 0 SE UMA COORDENADA (X,Y) NÃO ESTIVER CONTIDA NO CÍRCULO, OU 1 CASO CONTRÁRIO
int dentro_circulo (void* circle, double x, double y)
{
    double a = 0;
    double b = 0;
    double c = 0;
    Circulo* aux = NULL;
    aux = (Circulo*) circle;
    a = x - aux->x;
    b = y - aux->y;
    c = sqrt((a*a) + (b*b));
    if (c < aux->r)
    {
        return 1;
    }
    return 0;
}

//RETORNA 0 SE UMA COORDENADA(X,Y) NÃO ESTIVER CONTIDA NO CÍRCULO OU NA BORDA DO MESMO, OU 1 CASO CONTRÁRIO
int dentro_borda_circulo (void* circle, double x, double y)
{
    double a = 0;
    double b = 0;
    double c = 0;
    Circulo* aux = NULL;
    aux = (Circulo*) circle;
    a = x - aux->x;
    b = y - aux->y;
    c = sqrt((a*a) + (b*b));
    if (c <= aux->r)
    {
        return 1;
    }
    return 0;
}

//RETORNA UM DOUBLE POINTER COM AS COORDENADAS DO CENTRO DE MASSA DO CÍRCULO
double* centro_massa_circulo (void* circle)
{
    double* result = NULL;
    Circulo* aux = NULL;
    aux = (Circulo*) circle;
    result = (double*) calloc (2, sizeof(double));
    *result = aux->x;
    *(result+1) = aux->y;
    return result;
}

//PEGA O ID DO CÍRCULO
long int get_id_circulo (void* circle)
{
    Circulo* circulo = NULL;
    circulo = (Circulo*) circle;
    return circulo->id;
}

//PEGA O RAIO DO CÍRCULO
double get_r_circulo (void* circle)
{
    Circulo* circulo = NULL;
    circulo = (Circulo*) circle;
    return circulo->r;
}

//PEGA O X DO CÍRCULO
double get_x_circulo (void* circle)
{
    Circulo* circulo = NULL;
    circulo = (Circulo*) circle;
    return circulo->x;
}

//PEGA O Y DO CÍRCULO
double get_y_circulo (void* circle)
{
    Circulo* circulo = NULL;
    circulo = (Circulo*) circle;
    return circulo->y;
}

//PEGA A COR1 DO CÍRCULO
char* get_cor1_circulo (void* circle)
{
    Circulo* circulo = NULL;
    circulo = (Circulo*) circle;
    return circulo->cor1;
}

//PEGA A COR2 DO CÍRCULO
char* get_cor2_circulo (void* circle)
{
    Circulo* circulo = NULL;
    circulo = (Circulo*) circle;
    return circulo->cor2;
}

//FUNÇÃO PARA DAR FREE NA MEMÓRIA ALOCADA DO CÍRCULO
void free_circulo (void* circle)
{
    Circulo* circulo = NULL;
    circulo = (Circulo*) circle;
    free (circulo->cor1);
    circulo->cor1 = NULL;
    free (circulo->cor2);
    circulo->cor2 = NULL;
    free (circulo);
    circulo = NULL;
    return;
}

//ESCREVE O CÍRCULO NO ARQUIVO
void escreve_arquivo_circulo (void* circulo, int procura, FILE* arq)
{
    int i;
    Circulo* circ;
    circ = (Circulo*) circulo;
    fseek (arq, procura, SEEK_SET);
    fwrite (&circ->id, sizeof (long int), 1, arq);
    for (i=0; i<55; i++)
    {
        fwrite (&circ->cor1[i], sizeof (char), 1, arq);
    }
    for (i=0; i<55; i++)
    {
        fwrite (&circ->cor2[i], sizeof (char), 1, arq);
    }
    fwrite (&circ->r, sizeof (double), 1, arq);
    fwrite (&circ->x, sizeof (double), 1, arq);
    fwrite (&circ->y, sizeof (double), 1, arq);
}

// LÊ O CÍRCULO DO ARQUIVO
void ler_arquivo_circulo (void* circulo, int procura, FILE* arq)
{
    int i;
    Circulo* circ;
    circ = (Circulo*) circulo;
    fseek (arq, procura, SEEK_SET);
    fread (&circ->id, sizeof (long int), 1, arq);
    for (i=0; i<55; i++)
    {
        fread (&circ->cor1[i], sizeof (char), 1, arq);
    }
    for (i=0; i<55; i++)
    {
        fread (&circ->cor2[i], sizeof (char), 1, arq);
    }
    fread (&circ->r, sizeof (double), 1, arq);
    fread (&circ->x, sizeof (double), 1, arq);
    fread (&circ->y, sizeof (double), 1, arq);
}

// RETORNA O TAMANHO DO CÍRCULO
int get_tamanho_circulo ()
{
    return sizeof (long int) + (2 * 55 * sizeof (char)) + 3 * sizeof (double);
}

//FUNÇÃO DE COMPARAÇÃO DA ÁRVORE B DO CÍRCULO
double compare_circulo (void* objA, void* objB)
{
    double result;
    Circulo* circA;
    Circulo* circB;
    circA = (Circulo*) objA;
    circB = (Circulo*) objB;
    result = sqrt (pow (circB->x - circA->x, 2) + pow (circB->y - circA->y, 2));
    if (circB->x > circA->x && circB->y > circA->x) return result;
    return -result;
}