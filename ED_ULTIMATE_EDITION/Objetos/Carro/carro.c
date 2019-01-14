#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Formas/Retângulo/retangulo.h"
#include "../../Formas/Anotação/anotacao.h"
#include "../../Estruturas/Lista/lista.h"

typedef struct car {
    char *placa;
    double x;
    double y;
    double w;
    double h;
} carro;

//CRIA UM RETÂNGULO COM AS INFORMAÇÕES PASSADAS
void* cria_carro (char* placa, double x, double y, double w, double h)
{
    carro *result;
    result = (carro*) calloc (1, sizeof (carro));
    result->placa = (char*) calloc(strlen (placa) + 2, sizeof (char));
    strcpy (result->placa, placa);
    result->x = x;
    result->y = y;
    result->w = w;
    result->h = h;
    return (void*) result;
}

//GERA UMA STRING COM AS INFORMAÇÕES DO CARRO EM SVG
char* cria_svg_carro (void* car)
{
    int len;
    char* ret;
    char* anot;
    char* result;
    carro* c;
    c = (carro*) car;
    Retangulo rt = cria_retangulo (0, "black", "red", c->w, c->h, c->x, c->y);
    Anotacao nt = cria_anotacao (0, 0, (c->x + 5), (c->y + c->h/2 + 5), c->placa);;
    ret = cria_svg_retangulo (rt);
    anot = cria_svg_anotacao (nt);
    len = strlen (ret) + strlen (anot) + 10;
    result = (char*) calloc (len, sizeof (char));
    strcpy (result, ret);
    strcat (result, anot);
    free_retangulo (rt);
    free_anotacao (nt);
    free (ret);
    ret = NULL;
    free (anot);
    anot = NULL;
    return (result);
}

//PEGA A PLACA DO CARRO
char* get_placa_carro (void* car)
{
    carro* c;
    c = (carro*) car;
    return c->placa;
}

//PEGA O X DO CARRO
double get_x_carro (void* car)
{
    carro* c;
    c = (carro*) car;
    return c->x;
}

//PEGA O Y DO CARRO
double get_y_carro (void* car)
{
    carro* c;
    c = (carro*) car;
    return c->y;
}

//RETORNA UM RETÂNGULO
void* get_retangulo_carro (void* car)
{
    carro* c;
    c = (carro*) car;
    return cria_retangulo (0, "black", "red", c->w, c->h, c->x, c->y);
}

//LIBERA A MEMÓRIA ALOCADA DO CARRO
void free_carro (void* car)
{
    carro* c;
    c = (carro*) car;
    free (c->placa);
    c->placa = NULL;
    free (c);
    c = NULL;
}

//GERA UM RELATÓRIO DO CARRO
char* relatorio_carro (void* car)
{
    carro* c;
    c = (carro*) car;
    char* result;
    result = (char*) calloc (55, sizeof (char));
    sprintf (result, "Carro - %s", c->placa);
    return result;
}

//COMPARA DOIS CARROS
int compare_carro (void* carA, void* carB, int dim)
{
    carro *cA;
    carro *cB;
    cA = (carro*) carA;
    cB = (carro*) carB;
    dim = dim % 2;
    if (!strcmp (cA->placa, cB->placa))
    {
        return 0;
    } 
    if (dim == 0)
    {
        return cB->x - cA->x;
    }
    else
    {
        return cB->y - cA->y;
    }
}

//CRIA UM CÓDIGO HASH REFERENTE AO OBJETO CARRO
int hashcode_carro (void* car, int mod)
{
    
    int x;
    int hash = 0;
    char* aux;
    carro *c;
    c = (carro*) car;
    aux = c->placa;
    x = strlen (c->placa);
    while(*aux != 0)
    {
        hash += x*(*aux);
        aux++;
        x--;
    }
    return mod < 0 ? hash : hash % mod;
}

//COMPARADOR DE HASH DO OBJETO CARRO
int compare_hash_carro (void* carA, void* carB)
{
    carro *cA, *cB;
    cA = (carro*) carA;
    cB = (carro*) carB;
    return strcmp (cA->placa, cB->placa);
}

//RETORNA UM CARRO COM A PLACA ESPECÍFICADA
void* get_carro_placa (Lista carros, char* placa)
{
    void* primeiro;
    void* carro;
    Lista list;
    list = carros;
    carro == NULL;
    primeiro = get_primeiro_lista (list);
    do
    {
        if (primeiro == NULL)
        {
            continue;
        }
        carro = get_valor_lista (primeiro);
        if (!strcmp (placa, get_placa_carro (carro)))
        {
            return carro;
        }
    }
    while (primeiro != NULL);
    return carro;
}
