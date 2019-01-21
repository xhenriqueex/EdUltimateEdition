#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../../Formas/Circulo/circulo.h"

//INICIA A STRUCT SEMÁFORO
typedef struct semaforo{
    double r;
    double x;
    double y;
    char* id;
    char* cor_borda;
    char* cor_preenche;
} Semaforo;

//RETORNA UM PONTEIRO PARA VOID COM AS INFORMAÇÕES DO SEMÁFORO
void* cria_semaforo (char* id, double r, double x, double y, char* cor_borda, char* cor_preenche)
{
    Semaforo* aux;
    aux = (Semaforo*) calloc (1, sizeof (Semaforo));
    aux->id = (char*) calloc (55, sizeof (char));
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

//RETORNA UMA STRING COM AS INFORMAÇÕES PARA IMPRIMIR O SEMÁFORO NO SVG
char* cria_svg_semaforo (void* semaforo)
{
    Semaforo* aux;
    char* result = (char*) calloc (255, sizeof(char));
    aux = (Semaforo*) semaforo;
    sprintf (result, "\n<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"2\" />", aux->x, aux->y, aux->r, aux->cor_preenche, aux->cor_borda);
    return result;
}

//PEGA O ID DO SEMÁFORO
char* get_id_semaforo (void* semaforo)
{
    Semaforo* sem;
    sem = semaforo;
    return sem->id;
}

//PEGA O RAIO DO SEMÁFORO
double get_r_semaforo (void* semaforo)
{
    Semaforo* sem;
    sem = semaforo;
    return sem->r;
}

//PEGA O X DO SEMÁFORO
double get_x_semaforo (void* semaforo)
{
    Semaforo* sem;
    sem = (Semaforo*) semaforo;
    return sem->x;
}

//PEGA O Y DO SEMÁFORO
double get_y_semaforo (void* semaforo)
{
    Semaforo* sem;
    sem = (Semaforo*) semaforo;
    return sem->y;
}

//PEGA A COR1 DO SEMÁFORO
char* get_cor1_semaforo (void* semaforo)
{
    Semaforo* sem;
    sem = (Semaforo*) semaforo;
    return sem->cor_borda;
}

//PEGA A COR2 DO SEMÁFORO
char* get_cor2_semaforo (void* semaforo)
{
    Semaforo* sem;
    sem = (Semaforo*) semaforo;
    return sem->cor_preenche;
}

//ALTERA AS CORES DA BORDA E DO PREENCHIMENTO DO SEMÁFORO
void* muda_cor_semaforo (void* semaforo, char* cor_borda, char* cor_preenche)
{
    Semaforo* aux;
    aux = (Semaforo*) semaforo;
    strcpy (aux->cor_borda, cor_borda);
    strcpy (aux->cor_preenche, cor_preenche);
    return (void*) aux;
}

//FUNÇÃO DE COMPARAÇÃO DE ID DE SEMÁFORO
int compare_semaforo (void* sem1, void* sem2, int dim)
{
    Semaforo* semA;
    Semaforo* semB;    
    semA = (Semaforo*) sem1;
    semB = (Semaforo*) sem2;
    dim = dim % 2;
    if (!strcmp(semA->id, semB->id))
    {
        return 0;
    }
    if (dim == 0)
    {
        return (semB->x - semA->x);
    }
    else
    {
        return (semB->y - semA->y);
    }
}

//RETORNA O CÓDIGO HASH DO SEMÁFORO
int hashcode_semaforo (void* sem, int modulo)
{
    Semaforo* result;
    result = (Semaforo*) sem;
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

//COMPARADOR DE CEP DO SEMÁFORO PARA HASHTABLE
int compare_hash_semaforo (void* sem, void* id)
{
    Semaforo* semA;
    Semaforo* semB;
    semA = (Semaforo*) sem;
    semB = (Semaforo*) id;
    return strcmp (semA->id, semB->id);
}

//FUNÇÃO QUE RETORNA UM CÍRCULO COM AS INFORMAÇÕES DO SEMÁFORO
void* get_circulo_semaforo (void* semaforo)
{
    Semaforo* sem;
    sem = (Semaforo*) semaforo;
    void* circ;
    circ = cria_circulo (0, sem->cor_borda, sem->cor_preenche, sem->r, sem->x, sem->y);
    return circ;
}

void free_semaforo(void *semaforo)
{
    Semaforo *sem;
    sem = (Semaforo *) semaforo;
    
    if(sem->id != NULL) {
        free(sem->id);
        sem->id = NULL;
    }
    if(sem->cor_borda != NULL) {
        free(sem->cor_borda);
        sem->cor_borda = NULL;
    }
    if(sem->cor_preenche != NULL) {
        free(sem->cor_preenche);
        sem->cor_preenche = NULL;
    }
    free(sem);
    sem = NULL;
}

//ESCREVE O SEMÁFORO NO ARQUIVO
void escreve_arquivo_semaforo (void* semaforo, int procura, FILE* arq)
{
    int i;
    Semaforo* sem;
    sem = (Semaforo*) semaforo;
    fseek (arq, procura, SEEK_SET);
    fwrite (&sem->r, sizeof (double), 1, arq);
    fwrite (&sem->x, sizeof (double), 1, arq);
    fwrite (&sem->y, sizeof (double), 1, arq);
    for (i=0; i<55; i++)
    {
        fwrite (&sem->id[i], sizeof (char), 1, arq);
    }
    for (i=0; i<55; i++)
    {
        fwrite (&sem->cor_borda[i], sizeof (char), 1, arq);
    }
    for (i=0; i<55; i++)
    {
        fwrite (&sem->cor_preenche[i], sizeof (char), 1, arq);
    }
}

//LÊ O SEMÁFORO DO ARQUIVO
void ler_arquivo_semaforo (void* semaforo, int procura, FILE* arq)
{
    int i;
    Semaforo* sem;
    sem = (Semaforo*) semaforo;
    fseek (arq, procura, SEEK_SET);
    fread (&sem->r, sizeof (double), 1, arq);
    fread (&sem->x, sizeof (double), 1, arq);
    fread (&sem->y, sizeof (double), 1, arq);
    for (i=0; i<55; i++)
    {
        fread (&sem->id[i], sizeof (char), 1, arq);
    }
    for (i=0; i<55; i++)
    {
        fread (&sem->cor_borda[i], sizeof (char), 1, arq);
    }
    for (i=0; i<55; i++)
    {
        fread (&sem->cor_preenche[i], sizeof (char), 1, arq);
    }
}

//RETORNA O TAMANHO DO SEMÁFORO
int get_tamanho_semaforo ()
{
    return 3 * sizeof (double) + (3 * 55 * sizeof (char));
}

//FUNÇÃO DE COMPARAÇÃO DA ÁRVORE B DO SEMÁFORO
double compare_semaforo_arvoreB (void* objA, void* objB)
{
    double result;
    Semaforo* semA;
    Semaforo* semB;
    semA = (Semaforo*) objA;
    semB = (Semaforo*) objB;
    if (!strcmp (semA->id, semB->id)) return 0;
    result = sqrt (pow (semB->x - semA->x, 2) + pow (semB->y - semA->y, 2));
    if (semB->x > semA->x && semB->y > semA->x) return result;
    return -result;
}

void* alloc_semaforo ()
{
    Semaforo* sem;
    sem = (Semaforo*) calloc (1, sizeof (Semaforo));
    sem->id   = (char*) calloc (55, sizeof (char));
    sem->cor_borda = (char*) calloc (55, sizeof (char));
    sem->cor_preenche = (char*) calloc (55, sizeof(char));
    return sem;
}