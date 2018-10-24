#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funçoes.h"

//TRATA OS CAMINHOS
void altera_caminho (char** caminho)
{
    int size;
    size = strlen(*caminho);
    if((*caminho)[size-1] == '/')
    {
        (*caminho)[size-1] = '\0';
    }
}

//PEGA TODOS OS COMANDOS DE ENTRADA E OS COLOCA EM UMA FILA
Fila coloca_comandos_arquivo_fila (FILE* entrada)
{
    Fila aux;
    char* linha;
    int i;
    aux = cria_fila ();
    for (i=0; !feof (entrada); i++)
    {
        linha = (char*) calloc (200, sizeof(char));
        if (fgets(linha, 200, entrada) == NULL)
        {
            continue;
        }
        if (linha[strlen(linha)-1] == '\n')
        {
            linha[strlen(linha)-1] = '\0';
        }
        if (linha[strlen(linha)-2] == '\n')
        {
            linha[strlen(linha)-2] = '\0';
        }
        linha[strlen(linha)] = '\0';
        insere_fila (aux, (void*) linha);
        continue;
    }
    return aux;
}