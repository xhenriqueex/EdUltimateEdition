#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//INICIALIZANDO STRUCT ANOTAÇÃO
typedef struct anotacao{
    double w;
    double h;
    double x;
    double y;
    char* texto;
} Anotacao;

/*RETORNA UM PONTEIRO PARA VOID COM AS INFORMAÇÕES DA ANOTAÇÃO*/
void* cria_anotacao (double w, double h, double x, double y, char* text)
{
    Anotacao* anotacao = NULL;
    anotacao = (Anotacao*) calloc (1, sizeof (Anotacao));
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
    Anotacao* anotacao = NULL;
    char* result = (char*) calloc (555, sizeof(char));
    anotacao = anotation;
    if (anotacao->h == 0)
    {
        sprintf (result, "<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"transparent\" stroke=\"purple\" stroke-width=\"2\" stroke-dasharray=\"3, 3\"/>\n", anotacao->x, anotacao->y, anotacao->w);
        return result;
    }
    if (!strcmp (anotacao->texto, "rip"))
    {
        sprintf (result, "<rect x=\"%f\" y=\"%f\" width=\"10\" height=\"20\" fill=\"BLACK\"/>\n<rect x=\"%f\" y=\"%f\" width=\"2\" height=\"12\" fill=\"WHITE\"/>\n<rect x=\"%f\" y=\"%f\" width=\"6\" height=\"2\" fill=\"WHITE\"/>\n", anotacao->x, anotacao->y, anotacao->x + 4, anotacao->y + 4, anotacao->x + 2, anotacao->y + 8);
        return result;
    }
    if (!strcmp (anotacao->texto, "mr"))
    {
        sprintf (result, "<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"transparent\" stroke=\"darkgrey\" stroke-width=\"2\" stroke-dasharray=\"3, 3\"/>", anotacao->x, anotacao->y, anotacao->w, anotacao->h);
        return result;
    }
    if (!strcmp (anotacao->texto, "dm"))
    {
        sprintf (result, "<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"transparent\" stroke=\"lightred\" stroke-width=\"2\" stroke-dasharray=\"3, 3\"/>\n", anotacao->x, anotacao->y, anotacao->w);
        return result;
    }
    if (!strcmp (anotacao->texto, "de"))
    {
        sprintf (result, "<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"transparent\" stroke=\"darkred\" stroke-width=\"2\" stroke-dasharray=\"3, 3\"/>\n", anotacao->x, anotacao->y, anotacao->w);
        return result;
    }
    if (!strcmp (anotacao->texto, "mud"))
    {
        sprintf (result, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"lightblue\" stroke-width=\"4\"/>", anotacao->w, anotacao->h, anotacao->x, anotacao->y);
        return result;
    }
    if (!strcmp (anotacao->texto, "mudec"))
    {
        sprintf (result, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"darkblue\" stroke-width=\"4\"/>", anotacao->w, anotacao->h, anotacao->x, anotacao->y);
        return result;
    }
    if (!strcmp (anotacao->texto, "ecr"))
    {
        sprintf (result, "<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"transparent\" stroke=\"grey\" stroke-width=\"2\" stroke-dasharray=\"3, 3\"/>", anotacao->x, anotacao->y, anotacao->w, anotacao->h);
        return result;
    }
    if (!strcmp (anotacao->texto, "hmpe"))
    {
        sprintf (result, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"ligthgreen\" stroke-width=\"4\"/>", anotacao->w, anotacao->h, anotacao->x, anotacao->y);
        return result;
    }
    if (!strcmp (anotacao->texto, "hmp"))
    {
        sprintf (result, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"darkgreen\" stroke-width=\"4\"/>", anotacao->w, anotacao->h, anotacao->x, anotacao->y);
        return result;
    }
    if (!strcmp (anotacao->texto, "dpr"))
    {
        sprintf (result, "<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"transparent\" stroke=\"blue\" stroke-width=\"2\" stroke-dasharray=\"3, 3\"/>",anotacao->x, anotacao->y, anotacao->w, anotacao->h);
        return result;
    }
    if (!strcmp (anotacao->texto, "tecr"))
    {
        sprintf (result, "<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"transparent\" stroke=\"orange\" stroke-width=\"2\" stroke-dasharray=\"3, 3\"/>", anotacao->x, anotacao->y, anotacao->w, anotacao->h);
        return result;
    }
    sprintf(result, "<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"transparent\" stroke=\"purple\" stroke-width=\"2\" stroke-dasharray=\"3, 3\"/>\n<text x=\"%f\" y=\"%f\" fill=\"purple\">%s</text>",anotacao->x, anotacao->y, anotacao->w, anotacao->h, anotacao->x, anotacao->y, anotacao->texto);
    return result;
}