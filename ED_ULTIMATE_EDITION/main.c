//INCLUSÃO DAS BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "lista.h"
#include "funçoes.h"
#include "executa_comando.h"

//DECLARAÇÃO DA STRUCT DE VARIÁVEIS
typedef struct params {
    char* caminho_GEO;
    char* caminho_TXT;
    char* caminho_SVG;
    char* caminho_QRY;
    char* diretorio_entrada;
    char* arquivo_entrada;
    char* diretorio_saida;
    char* arquivo_entrada_qry;
    char* cor_borda_quadra;
    char* cor_preenche_quadra;
    char* cor_borda_hidrante;
    char* cor_preenche_hidrante;
    char* cor_borda_semaforo;
    char* cor_preenche_semaforo;
    char* cor_borda_radiobase;
    char* cor_preenche_radiobase;
    char** comando_vetor;
    long int max_figuras;
    int contador_figuras;
    Item* figuras;
    Fila* anotaçoes;
    Fila* resultado;
    Lista quadras;
    Lista hidrantes;
    Lista semaforos;
    Lista radiobases;
} Parametros;

//FUNÇÃO RESPONSÁVEL PELA EXECUÇÃO DO CÓDIGO
void main(int argc, char* argv[])
{
    //DECLARANDO STRUCT
    Parametros* p;
    
    //DECLARANDO A FILA
    Fila comandos;

    //DECLARANDO O ARQUIVO
    FILE* arquivo;

    //DECLARANDO INTS
    int i;

    //DECLARANDO CHAR POINTERS
    char* comando;

    //ALOCANDO STRUCT
    p = (Parametros*) calloc (1, sizeof(Parametros));

    //INICIALIZANDO STRUCT

    //INICIALIZANDO CAMINHOS
    p->caminho_GEO = NULL;
    p->caminho_TXT = NULL;
    p->caminho_SVG = NULL;
    p->caminho_QRY = NULL;

    //INICIALIZANDO VETOR DE COMANDOS
    p->comando_vetor = NULL;

    //INICIALIZANDO NÚMERO MÁXIMO DE FIGURAS
    p->max_figuras = 1000;

    //INICIALIZANDO CONTADOR DE FIGURAS
    p->contador_figuras = 0;

    //INICIALIZANDO FILAS
    p->anotaçoes = cria_fila();
    p->resultado = cria_fila();

    //INICIALIZANDO LISTAS
    p->quadras = cria_lista();
    p->hidrantes = cria_lista();
    p->semaforos = cria_lista();
    p->radiobases = cria_lista();

    //INICIALIZANDO CORES PADRÃO
    p->cor_borda_quadra = (char*) calloc (155, sizeof(char));
    strcpy (p->cor_borda_quadra, "black");
    p->cor_preenche_quadra = (char*) calloc (155, sizeof(char));
    strcpy (p->cor_preenche_quadra, "red");
    p->cor_borda_hidrante = (char*) calloc (155, sizeof(char));
    strcpy (p->cor_borda_hidrante, "black");
    p->cor_preenche_hidrante = (char*) calloc (155, sizeof(char));
    strcpy (p->cor_preenche_hidrante, "red");
    p->cor_borda_semaforo = (char*) calloc (155, sizeof(char));
    strcpy (p->cor_borda_semaforo, "black");
    p->cor_preenche_semaforo = (char*) calloc (155, sizeof(char));
    strcpy (p->cor_preenche_semaforo, "red");
    p->cor_borda_radiobase = (char*) calloc (155, sizeof(char));
    strcpy (p->cor_borda_radiobase, "black");
    p->cor_preenche_radiobase = (char*) calloc (155, sizeof(char));
    strcpy (p->cor_preenche_radiobase, "red");

    //INICIALIZANDO VETOR DE FIGURAS
    p->figuras = (Item*) calloc (1000, sizeof(Item));
    for(i=0;i<1000; i++)
    {
        *(p->figuras+i) = NULL;
    }

    //INICIALIZANDO PARÂMETROS DE CHAMADA
    p->diretorio_entrada = NULL;
    p->arquivo_entrada = NULL;
    p->diretorio_saida = NULL;
    p->arquivo_entrada_qry = NULL;

    //TRATANDO OS CAMINHOS
    for (i=0; i<argc; i++)
    {
        if (strcmp(argv[i], "-e") == 0)
        {
            p->diretorio_entrada = (char*) calloc(strlen(argv[i+1])+1, sizeof(char));
            strcpy (p->diretorio_entrada, argv[i+1]);
            altera_caminho (&p->diretorio_entrada);
            i++;
            continue;
        }
        if (strcmp(argv[i], "-f") == 0)
        {
            p->arquivo_entrada = (char*) calloc(strlen(argv[i+1])+1, sizeof(char));
            strcpy (p->arquivo_entrada, argv[i+1]);
            i++;
            continue;
        }
        if (strcmp(argv[i], "-o") == 0)
        {
            p->diretorio_saida = (char*) calloc(strlen(argv[i+1])+1, sizeof(char));
            strcpy (p->diretorio_saida, argv[i+1]);
            altera_caminho (&p->diretorio_saida);
            i++;
            continue;
        }
        if (strcmp(argv[i], "-q") == 0)
        {
            p->arquivo_entrada_qry = (char*) calloc(strlen(argv[i+1])+1, sizeof(char));
            strcpy (p->arquivo_entrada_qry, argv[i+1]);
            i++;
            continue;
        }
    }
    if (p->diretorio_entrada != NULL)
    {
        p->caminho_GEO = (char*) calloc (strlen (p->diretorio_entrada) + strlen (p->arquivo_entrada) + 2, sizeof (char));
        strcpy (p->caminho_GEO, p->diretorio_entrada);
        strcat (p->caminho_GEO, "/");
        strcat (p->caminho_GEO, p->arquivo_entrada);
        p->caminho_QRY = (char*) calloc (strlen (p->diretorio_entrada) + strlen (p->arquivo_entrada_qry) + 2, sizeof (char));
        strcpy (p->caminho_QRY, p->diretorio_entrada);
        strcat (p->caminho_QRY, "/");
        strcat (p->caminho_QRY, p->arquivo_entrada_qry);
    }
    else
    {
        p->caminho_GEO = (char*) calloc (strlen (p->arquivo_entrada) + 1, sizeof (char));
        strcpy (p->caminho_GEO, p->arquivo_entrada);
        p->caminho_QRY = (char*) calloc (strlen (p->arquivo_entrada_qry) + 1, sizeof(char));
        strcpy (p->caminho_QRY, p->arquivo_entrada_qry);
    }

    //ABRINDO O ARQUIVO .GEO
    arquivo = fopen (p->caminho_GEO, "r");
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
        p->comando_vetor = trata_comando (comando);
        executa_comando (p);
        free (comando);
    }
    //FECHANDO O ARQUIVO
    fclose (arquivo);

    /*ABRINDO O ARQUIVO .QRY*/
    arquivo = fopen (p->caminho_QRY, "r");
    if (arquivo == NULL)
    {
        printf ("\nArquivo .qry não encontrado!\n");
        return 0;
    }
    printf ("\nArquivo .qry aberto com sucesso!\n");

    //COLOCANDO TODOS OS COMANDOS DO ARQUIVO EM UMA FILA
    comandos = coloca_comandos_arquivo_fila (arquivo);
    
    //TRATANDO OS COMANDOS PARA VETOR E OS EXECUTANDO
    while (!fila_vazia (comandos))
    {
        comando = (char*) remove_fila (comandos);
        p->comando_vetor = trata_comando (comando);
        executa_comando (p);
        free (comando);
    }

    //FECHANDO O ARQUIVO .QRY
    fecha_qry (arquivo, p);

    //FECHANDO O ARQUIVO
    fclose (arquivo);
    
    return 1;
}