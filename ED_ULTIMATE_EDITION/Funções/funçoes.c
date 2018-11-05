#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
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

//IDENTIFICA TODOS OS PARAMETROS DO COMANDO LIDO E RETORNA UM VETOR DE PARAMETROS
char** trata_comando(char *leitura)
{
    char** string = NULL;
	char* aux = NULL;
    char* aux2 = NULL;
    char* auxR = NULL;
	int i = 0;
	int n = 0;
	aux = (char *) calloc(strlen(leitura)+1, sizeof(char));
	string = (char **) calloc(1, sizeof(char *));
	strcpy(aux, leitura);
	auxR = aux;
	if(aux[0] == 32) 
    {
		aux++;
	}
	if (aux[strlen(aux)-1] == '\n') 
    {
		aux[strlen(aux)-1] = '\0';
	}
    do 
    {
		string = (char **) realloc(string, (1+i)*sizeof(char *));
		string[i] = NULL;
		n = strcspn(aux, " ");
		aux2 = strtok(aux, " ");
		if(aux2 == NULL) 
        {
            break;
		}
		string[i] = (char *) calloc(strlen(aux2)+1, sizeof(char));
		strcpy(string[i], aux2);
		aux[n] = ' ';
		aux += n+1;
		i++;
	} 
    while (string[i-1] != NULL);
    free(auxR);
	return string;
}

//RETORNA O TAMANHO DO VETOR DE COMANDOS
int tamanho_strings (char** strings)
{
    int n = -1;
    do 
    {
		n++;
	} 
    while(strings[n] != NULL);
	return n;
}

//LIBERA AS STRINGS DO VETOR DE COMANDOS
void free_strings (char** strings)
{
    int i = 0;
	for (i = 0; i < tamanhoStrings(strings); i++)
    {
		free(strings[i]);
	}
	free(strings);
}

//VERIFICA E RETORNA O MAIOR VALOR
double maior (double x1, double x2)
{
    if (x1 > x2)
    {
        return x1;
    }
    return x2;
}

//VERIFICA E RETORNA O MENOR VALOR
double menor (double x1, double x2)
{
    if (x1 < x2)
    {
        return x1;
    }
    return x2;
}