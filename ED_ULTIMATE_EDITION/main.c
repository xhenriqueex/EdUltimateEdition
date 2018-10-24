//INCLUSÃO DAS BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funçoes.h"

//DECLARAÇÃO DA STRUCT DE VARIÁVEIS
typedef struct params {
    char* caminho_GEO;
    char* caminho_TXT;
    char* caminho_SVG;
    char** comando_vetor;
    long int max_figuras;
} Parametros;

//FUNÇÃO RESPONSÁVEL PELA EXECUÇÃO DO CÓDIGO
void main(int argc, char* argv[])
{
    //DECLARANDO STRUCT
    Parametros p;
    
    //DECLARANDO A FILA
    Fila comandos;

    //DECLARANDO O ARQUIVO
    FILE* arquivo;

    //DECLARANDO INTS
    int i;

    //DECLARANDO CHAR POINTERS
    char* comando;
    char* diretorio_entrada;
    char* arquivo_entrada;
    char* diretorio_saida;

    //INICIALIZANDO STRUCT
    p.caminho_GEO = NULL;
    p.caminho_TXT = NULL;
    p.caminho_SVG = NULL;
    p.comando_vetor = NULL;
    p.max_figuras = 1000;

    //INICIALIZANDO A FILA

    //INICIALIZANDO PARÂMETROS DE CHAMADA
    diretorio_entrada = NULL;
    arquivo_entrada = NULL;
    diretorio_saida = NULL;

    //TRATANDO OS CAMINHOS
    for (i=0; i<argc; i++)
    {
        if (strcmp(argv[i], "-e") == 0)
        {
            diretorio_entrada = (char*) calloc(strlen(argv[i+1])+1, sizeof(char));
            strcpy (diretorio_entrada, argv[i+1]);
            altera_caminho (&diretorio_entrada);
            i++;
            continue;
        }
        if (strcmp(argv[i], "-f") == 0)
        {
            arquivo_entrada = (char*) calloc(strlen(argv[i+1])+1, sizeof(char));
            strcpy (arquivo_entrada, argv[i+1]);
            i++;
            continue;
        }
        if (strcmp(argv[i], "-o") == 0)
        {
            diretorio_saida = (char*) calloc(strlen(argv[i+1])+1, sizeof(char));
            strcpy (diretorio_saida, argv[i+1]);
            altera_caminho (&diretorio_saida);
            i++;
            continue;
        }
    }
    if (diretorio_entrada != NULL)
    {
        p.caminho_GEO = (char*) calloc (strlen (diretorio_entrada) + strlen (arquivo_entrada) + 2, sizeof (char));
        strcpy (p.caminho_GEO, diretorio_entrada);
        strcat (p.caminho_GEO, "/");
        strcat (p.caminho_GEO, arquivo_entrada);
        //pathQry = (char*) calloc (strlen(dirEntry) + strlen(entryQry)+2, sizeof(char));
        //strcpy (pathQry, dirEntry);
         //strcat (pathQry, "/");
         //strcat (pathQry, entryQry);
    }
    else
    {
        p.caminho_GEO = (char*) calloc (strlen (arquivo_entrada) + 1, sizeof (char));
        strcpy (p.caminho_GEO, arquivo_entrada);
        //pathQry = (char*) calloc (strlen(entryQry)+1, sizeof(char));
        //strcpy (pathQry, entryQry);
    }

    //ABRINDO O ARQUIVO .GEO
    arquivo = fopen (p.caminho_GEO, "r");
    if (arquivo == NULL)
    {
        printf ("\nArquivo .geo nao encontrado!\n");
        return 0;
    }
    printf ("\nArquivo .geo aberto com sucesso!\n");

    //COLOCANDO TODOS OS COMANDOS DO ARQUIVO EM UMA FILA
    comandos = coloca_comandos_arquivo_fila (arquivo);

    //TRATANDO OS COMANDOS PARA VETOR E OS EXECUTANDO
    while (!fila_vazia (comandos))
    {
        comando = (char*) remove_fila (comandos);
        p.comando_vetor = trata_comando (comando);
        executa_comando (p);
        free (comando);
    }
    //FECHANDO O ARQUIVO
    fclose (arquivo);

    //LIBERANDO A MEMÓRIA ALOCADA
    free (diretorio_entrada);
    free (arquivo_entrada);
    free (diretorio_saida);
    return 1;
}