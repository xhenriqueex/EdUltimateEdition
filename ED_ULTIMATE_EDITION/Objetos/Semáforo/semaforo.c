#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//RETORNA UMA STRING COM AS INFORMAÇÕES PARA IMPRIMIR O SEMÁFORO NO SVG
char* cria_svg_semaforo (void* semaforo)
{
    Semaforo* aux;
    char* result = (char*) calloc(255, sizeof(char));
    aux = (Semaforo*) semaforo;
    sprintf (result, "\n<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"2\" />", aux->x, aux->y, aux->r, aux->cor_borda, aux->cor_preenche);
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
    return strcmp (semA->id, semB->id);
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