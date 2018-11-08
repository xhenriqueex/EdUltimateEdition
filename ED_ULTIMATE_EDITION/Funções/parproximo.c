#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include "../Estruturas/Merge/mergesort.h"

//DEFINE A STRUCT PONTO
typedef struct ponto
{
    char* id;
    int x;
    int y;
}Ponto;

int compare_x (void* a, void* b);

int compare_y (void* a, void* b);

float dist_points (Ponto p1, Ponto p2);

float brute_force (Ponto** P, int n, char* saida);

float menor (float x, float y);

float closest_pair (Ponto** vetor, int size, char* saida);

float closest_dist (Ponto** vetor, int inicial, int final, char* saida);

double strip_closest (Ponto** vetor, int inicial, int final, float mindist, char* result);

//FUNÇÃO NECESSÁRIA PARA ORDENAR OS PONTOS DE ACORDO COM X
int compare_x (void* a, void* b)
{
    Ponto* p1 = (Ponto*) a;
    Ponto* p2 = (Ponto*) b;
    return (p1->x - p2->x);
}

//FUNÇÃO NECESSÁRIA PARA ORDENAR OS PONTOS DE ACORDO COM Y
int compare_y (void* a, void* b)
{
    Ponto* p1 = (Ponto*) a;
    Ponto* p2 = (Ponto*) b;
    return (p1->y - p2->y);
}

//FUNÇÃO PARA ACHAR A DISTÂNCIA ENTRE DOIS PONTOS
float dist_points (Ponto p1, Ponto p2)
{
    return sqrt ( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) );
}

//RETORNA A MENOR DISTÂNCIA ENTRE DOIS PONTOS EM P[] DE TAMANHO N
float brute_force (Ponto** P, int n, char* saida)
{
    int i, j;
    float min;
    min = FLT_MAX;
    for (i=0; i<n; ++i)
    {
        for (j=i+1; j<n; ++j)
        {
            if ( dist_points (*(P[i]), *(P[j])) < min)
            {
                min = dist_points (*(P[i]), *(P[j]));
                sprintf (saida, "%s %s", P[i]->id, P[j]->id);
            }
        }
    }
    return min;
}

//FUNÇÃO PARA ACHAR O MENOR VALOR ENTRE DOIS FLOATS
float menor (float x, float y)
{
    return (x < y)? x : y;
}

//FUNÇÃO PARA ENCONTRAR O PAR MAIS PRÓXIMO
float closest_pair (Ponto** vetor, int size, char* saida)
{
    Merge ((void**) vetor, size, compare_x);
    return closest_dist (vetor, 0, size, saida);
}

//FUNÇÃO PARA RETORNAR A DISTÂNCIA DO PAR
float closest_dist (Ponto** vetor, int inicial, int final, char* saida)
{
    if (final - inicial <= 3)
    {
        return brute_force (vetor, final - inicial, saida);
    }
    int mid, i, j;
    float half1, half2, mindist;
    char* result1;
    char* result2;
    double result;
    result1 = (char*) calloc (55, sizeof(char));
    result2 = (char*) calloc (55, sizeof(char));
    mid = (final - inicial)/2 + inicial;
    half1 = closest_dist (vetor, inicial, mid, result1);
    half2 = closest_dist (vetor, mid + 1, final, result2);
    if (half1 <= half2)
    {
        mindist = half1;
        strcpy (saida, result1);
    }
    else
    {
        mindist = half2;
        strcpy (saida, result2);
    }
    free (result1);
    free (result2);
    Ponto* strip[final - inicial];
    Ponto mid_point = *vetor[mid];
    j = 0;
    for (i=inicial; i<final; i++)
    {
        if (abs(vetor[i]->x - mid_point.x) < mindist)
        {
            strip[j] = vetor[i];
            j++;
        }
    }
    result1 = (char*) calloc (55, sizeof(char));
    result = strip_closest (vetor, 0, j, mindist, result1);
    if (result < mindist)
    {
        strcpy (saida, result1);
        mindist = result;
    }
    free (result1);
    return mindist;
}

//PERCORRE O VETOR PROCURANDO OS PONTOS NA STRIP E VERIFICA SE EXISTE DISTÂNCIA MENOR QUE A MÍNIMA
double strip_closest (Ponto** vetor, int inicial, int final, float mindist, char* result)
{
    merge_sort ((void**) vetor, inicial, final, compare_y);
    int i, j;
    for (i=inicial; i<final; ++i)
    {
        for (j=i+1; j<final && (vetor[j]->y - vetor[i]->y)<mindist; ++j)
        {
            if (dist_points (*(vetor[j]), *(vetor[i])) < mindist)
            {
                mindist = dist_points (*(vetor[j]), *(vetor[i]));
                sprintf (result, "%s %s", vetor[j]->id, vetor[i]->id);
            }
        }
    }
    return mindist;
}