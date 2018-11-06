#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "circulo.h"

//INICIALIZANDO STRUCT CIRCULO
typedef struct circle {
    long int id;
    char* cor1;
    char* cor2;
    double r;
    double x;
    double y;
}Circulo;

//RETORNA UM PONTEIRO PARA VOID COM AS INFORMAÇÕES DO CÍRCULO
void* cria_circulo (long int id, char* cor1, char* cor2, double r, double x, double y)
{
    Circulo* circulo;
    circulo = (Circulo*) calloc (1, sizeof (Circulo));
    circulo->cor1 = (char*) calloc (strlen(cor1) + 2, sizeof(char));
    circulo->cor2 = (char*) calloc (strlen(cor2) + 2, sizeof(char));
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
    Circulo* circulo;
    char* result = (char*) calloc(255, sizeof(char));
    circulo = (Circulo*) circle;
    sprintf (result, "\n<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"2\"/>", circulo->x, circulo->y, circulo->r, circulo->cor2, circulo->cor1);
    return result;
}

//RETORNA 0 SE UMA COORDENADA (X,Y) NÃO ESTIVER CONTIDA NO CÍRCULO, OU 1 CASO CONTRÁRIO
int dentro_circulo (void* circle, double x, double y)
{
    double a;
    double b;
    double c;
    Circulo* aux;
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
    double a;
    double b;
    double c;
    Circulo* aux;
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
    double* result;
    Circulo* aux;
    aux = (Circulo*) circle;
    result = (double*) calloc (2, sizeof(double));
    *result = aux->x;
    *(result+1) = aux->y;
    return result;
}

//PEGA O ID DO CÍRCULO
long int get_id_circulo (void* circle)
{
    Circulo* circulo;
    circulo = (Circulo*) circle;
    return circulo->id;
}

//PEGA O RAIO DO CÍRCULO
double get_r_circulo (void* circle)
{
    Circulo* circulo;
    circulo = (Circulo*) circle;
    return circulo->r;
}

//PEGA O X DO CÍRCULO
double get_x_circulo (void* circle)
{
    Circulo* circulo;
    circulo = (Circulo*) circle;
    return circulo->x;
}

//PEGA O Y DO CÍRCULO
double get_y_circulo (void* circle)
{
    Circulo* circulo;
    circulo = (Circulo*) circle;
    return circulo->y;
}

//PEGA A COR1 DO CÍRCULO
char* get_cor1_circulo (void* circle)
{
    Circulo* circulo;
    circulo = (Circulo*) circle;
    return circulo->cor1;
}

//PEGA A COR2 DO CÍRCULO
char* get_cor2_circulo (void* circle)
{
    Circulo* circulo;
    circulo = (Circulo*) circle;
    return circulo->cor2;
}

//FUNÇÃO PARA DAR FREE NA MEMÓRIA ALOCADA DO CÍRCULO
void free_circulo (void* circle)
{
    Circulo* circulo;
    circulo = (Circulo*) circle;
    free (circulo->cor1);
    free (circulo->cor2);
    free (circulo);
    return;
}