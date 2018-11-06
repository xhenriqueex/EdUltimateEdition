#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anotaçao.h"

//INICIALIZANDO STRUCT ANOTAÇÃO
typedef struct anotaçao{
    double w;
    double h;
    double x;
    double y;
    char* texto;
}Anotaçao;

/*RETORNA UM PONTEIRO PARA VOID COM AS INFORMAÇÕES DA ANOTAÇÃO*/
void* cria_anotacao (double w, double h, double x, double y, char* text)
{
    Anotaçao* anotacao;
    anotacao = (Anotaçao*) calloc (1, sizeof (Anotaçao));
    anotacao->w = w;
    anotacao->h = h;
    anotacao->x = x;
    anotacao->y = y;
    anotacao->texto = text;
    return (void*) anotacao;
}

/*RETORNA UMA STRING COM AS INFORMAÇÕES PARA IMPRIMIR A ANOTAÇÃO NO SVG*/
char* cria_svg_anotacao (void* anotation)
{
    Anotaçao* anotacao;
    char* result = (char*) calloc (355, sizeof(char));
    anotacao = anotation;
    if (anotacao->h == 0)
    {
        sprintf (result, "<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"transparent\" stroke=\"purple\" stroke-width=\"2\" stroke-dasharray=\"3, 3\"/>\n", anotacao->x, anotacao->y, anotacao->w);
        return result;
    }
    sprintf(result, "<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"transparent\" stroke=\"purple\" stroke-width=\"2\" stroke-dasharray=\"3, 3\"/>\n<text x=\"%f\" y=\"%f\" fill=\"purple\">%s</text>",anotacao->x, anotacao->y, anotacao->w, anotacao->h, anotacao->x, anotacao->y, anotacao->texto);
    return result;
}