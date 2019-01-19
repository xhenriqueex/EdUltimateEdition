#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//INICIALIZANDO STRUCT RETÂNGULO
typedef struct rectangle{
    long int id;
    char* cor1;
    char* cor2;
    double w;
    double h;
    double x;
    double y;
}Retangulo;

//RETORNA UM PONTEIRO PARA VOID COM AS INFORMAÇÕES DO RETÂNGULO
void* cria_retangulo (long int id, char* cor1, char* cor2, double w, double h, double x, double y)
{
    Retangulo* retangulo;
    retangulo = (Retangulo*) calloc (1, sizeof (Retangulo));
    retangulo->cor1 = (char*) calloc (strlen(cor1) + 2, sizeof(char));
    retangulo->cor2 = (char*) calloc (strlen(cor2) + 2, sizeof(char));
    strcpy(retangulo->cor1, cor1);
    strcpy(retangulo->cor2, cor2);
    retangulo->id = id;
    retangulo->w = w;
    retangulo->h = h;
    retangulo->x = x;
    retangulo->y = y;
    return (void*) retangulo;
}

//RETORNA UMA STRING COM AS INFORMAÇÕES PARA IMPRIMIR O RETÂNGULO NO SVG
char* cria_svg_retangulo (void* rectangle)
{
    Retangulo* retangulo;
    char* result = (char*) calloc (255, sizeof(char));
    retangulo = (Retangulo*) rectangle;
    sprintf (result, "\n<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"2\" style=\"opacity:0.7\"/>", retangulo->x, retangulo->y, retangulo->w, retangulo->h, retangulo->cor2, retangulo->cor1);
    return result;
}

//RETORNA 0 SE UMA COORDENADA(X,Y) NÃO ESTIVER CONTIDA NO RETÂNGULO, OU 1 CASO CONTRÁRIO
int dentro_retangulo (void* rectangle, double x, double y)
{
    Retangulo* aux;
    aux = (Retangulo*) rectangle;
    if (x > aux->x && x < aux->x + aux->w)
    {
        if (y > aux->y && x < aux->y + aux->h)
        {
            return 1;
        }
    }
    return 0;
}

//RETORNA 0 SE UMA COORDENADA(X,Y) NÃO ESTIVER CONTIDA NO RETÂNGULO OU NA BORDA DO MESMO, OU 1 CASO CONTRÁRIO
int dentro_borda_retangulo (void* rectangle, double x, double y)
{
    Retangulo* aux;
    aux = (Retangulo*) rectangle;
    if (x >= aux->x && x <= aux->x + aux->w)
    {
        if (y >= aux->y && x <= aux->y + aux->h)
        {
            return 1;
        }
    }
    return 0;
}

//RETORNA UM DOUBLE POINTER COM AS COORDENADAS DO CENTRO DE MASSA DO RETÂNGULO
double* centro_massa_retangulo (void* rectangle)
{
    double* result;
    Retangulo* aux;
    aux = (Retangulo*) rectangle;
    result = (double*) calloc (2, sizeof(double));
    *result = aux->x + (aux->w / 2);
    *(result+1) = aux->y + (aux->h / 2);
    return result;
}

//PEGA O ID DO RETÂNGULO
long int get_id_retangulo (void* rectangle)
{
    Retangulo* retangulo;
    retangulo = rectangle;
    long int retorno;
    retorno = retangulo->id;
    return retorno;
}

//PEGA O W DO RETÂNGULO
double get_w_retangulo (void* rectangle)
{
    Retangulo* retangulo;
    retangulo = rectangle;
    return retangulo->w;
}

//PEGA O H DO RETÂNGULO
double get_h_retangulo (void* rectangle)
{
    Retangulo* retangulo;
    retangulo = rectangle;
    return retangulo->h;
}

//PEGA O X DO RETÂNGULO
double get_x_retangulo (void* rectangle)
{
    Retangulo* retangulo;
    retangulo = rectangle;
    return retangulo->x;
}

//PEGA O Y DO RETÂNGULO
double get_y_retangulo (void* rectangle)
{
    Retangulo* retangulo;
    retangulo = rectangle;
    return retangulo->y;
}

//PEGA A COR1 DO RETÂNGULO
char* get_cor1_retangulo (void* rectangle)
{
    Retangulo* retangulo;
    retangulo = rectangle;
    return retangulo->cor1;
}

//PEGA A COR2 DO RETÂNGULO
char* get_cor2_retangulo (void* rectangle)
{
    Retangulo* retangulo;
    retangulo = (Retangulo*) rectangle;
    return retangulo->cor2;
}

//FUNÇÃO PARA DAR FREE NA MEMÓRIA ALOCADA DO RETÂNGULO
void free_retangulo (void* rectangle)
{
    Retangulo* retangulo;
    retangulo = (Retangulo*) rectangle;
    free (retangulo->cor1);
    retangulo->cor1 = NULL;
    free (retangulo->cor2);
    retangulo->cor2 = NULL;
    free (retangulo);
    retangulo = NULL;
    return;
}

//ESCREVE O RETÂNGULO NO ARQUIVO
void escreve_arquivo_retangulo (void* retangulo, int procura, FILE* arq)
{
    int i;
    Retangulo* rect;
    rect = (Retangulo*) retangulo;
    fseek (arq, procura, SEEK_SET);
    fwrite (&rect->id, sizeof (long int), 1, arq);
    for (i=0; i<55; i++)
    {
        fwrite (&rect->cor1[i], sizeof (char), 1, arq);
    }
    for (i=0; i<55; i++)
    {
        fwrite (&rect->cor2[i], sizeof (char), 1, arq);
    }
    fwrite (&rect->w, sizeof (double), 1, arq);
    fwrite (&rect->h, sizeof (double), 1, arq);
    fwrite (&rect->x, sizeof (double), 1, arq);
    fwrite (&rect->y, sizeof (double), 1, arq);
}

//LÊ O RETÂNGULO DO ARQUIVO
void ler_arquivo_retangulo (void* retangulo, int procura, FILE* arq)
{
    int i;
    Retangulo* rect;
    rect = (Retangulo*) retangulo;
    fseek (arq, procura, SEEK_SET);
    fread (&rect->id, sizeof (long int), 1, arq);
    for (i=0; i<55; i++)
    {
        fread (&rect->cor1[i], sizeof (char), 1, arq);
    }
    for (i=0; i<55; i++)
    {
        fread (&rect->cor2[i], sizeof (char), 1, arq);
    }
    fread (&rect->w, sizeof (double), 1, arq);
    fread (&rect->h, sizeof (double), 1, arq);
    fread (&rect->x, sizeof (double), 1, arq);
    fread (&rect->y, sizeof (double), 1, arq);
}

//RETORNA O TAMANHO DO RETÂNGULO
int get_tamanho_retangulo ()
{
    return sizeof (long int) + (2 * 55 * sizeof (char)) + 4 * sizeof (double);
}

//FUNÇÃO DE COMPARAÇÃO DA ÁRVORE B DO RETÂNGULO
double compare_retangulo (void* objA, void* objB)
{
    double result;
    Retangulo* rectA;
    Retangulo* rectB;
    rectA = (Retangulo*) objA;
    rectB = (Retangulo*) objB;
    result = sqrt (pow (rectB->x - rectA->x, 2) + pow (rectB->y - rectA->y, 2));
    if (rectB->x > rectA->x && rectB->y > rectA->x) return result;
    return -result;
}
