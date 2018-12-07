//INCLUSÃO DAS BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estruturas/Item/item.h"
#include "Estruturas/Lista/lista.h"
#include "Funções/funcoes.h"
#include "Comando/executa_comando.h"
#include "Parâmetros/parametros.h"
#include "Objetos/Quadra/quadra.h"
#include "Objetos/Hidrante/hidrante.h"
#include "Objetos/Semáforo/semaforo.h"
#include "Objetos/Rádiobase/radiobase.h"
#include "Objetos/Comércio/comercio.h"
#include "Objetos/Pessoa/pessoa.h"

//FUNÇÃO RESPONSÁVEL PELA EXECUÇÃO DO CÓDIGO
int main(int argc, char* argv[])
{
    //DECLARANDO STRUCT
    Parametros* p;
    
    //DECLARANDO A FILA
    Fila comandos;

    //DECLARANDO O ARQUIVO
    FILE* arquivo;

    //DECLARANDO INTS
    int i;

    //ALOCANDO STRUCT
    p = (Parametros*) calloc (1, sizeof (Parametros));

    //INICIALIZANDO CAMINHOS
    p->caminho_GEO = NULL;
    p->caminho_TXT = NULL;
    p->caminho_SVG = NULL;
    p->caminho_QRY = NULL;
    p->caminho_EC = NULL;
    p->caminho_PM = NULL;
    //p->caminho_VIA = NULL;

    //INICIALIZANDO STRING DE COMANDO
    p->comando = NULL;
    
    //INICIALIZANDO NÚMERO MÁXIMO DE FIGURAS
    p->max_figuras = 1000;

    //INICIALIZANDO CONTADOR DE FIGURAS
    p->contador_figuras = 0;

    //INICIALIZANDO FILAS
    p->anotacoes = cria_fila();
    p->resultado = cria_fila();
    
    //INICIALIZANDO HASHTABLES
    p->hash_comercios = cria_hashtable (100, compare_cnpj_comercio, hashcode_comercio);
    p->hash_pessoas = cria_hashtable (100, compare_cpf_pessoa, hashcode_pessoa);
    p->hash_quadras = cria_hashtable (100, compare_hash_quadra, hashcode_quadra);
    p->hash_hidrantes = cria_hashtable (100, compare_hash_hidrante, hashcode_hidrante);
    p->hash_semaforos = cria_hashtable (100, compare_hash_semaforo, hashcode_semaforo);
    p->hash_radiobases = cria_hashtable (100, compare_hash_radiobase, hashcode_radiobase);
    p->hash_end_comercios = cria_hashtable (100, compare_hash_endereco_comercio, hashcode_endereco_comercio);
    p->hash_end_pessoas = cria_hashtable (100, compare_cep_endereco_pessoa, hashcode_endereco_pessoa);
    p->hash_tipos = cria_hashtable (100, compare_hash_tipo_comercio, hashcode_tipo_comercio);

    //INICIALIZANDO ÁRVORES
    p->tree_quadras = cria_arvore (compare_quadra, 2);
    p->tree_hidrantes = cria_arvore (compare_hidrante, 2);
    p->tree_semaforos = cria_arvore (compare_semaforo, 2);
    p->tree_radiobases = cria_arvore (compare_radiobase, 2);

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
    p->figuras = (Item*) calloc (p->max_figuras, sizeof(Item));
    for(i=0;i<p->max_figuras; i++)
    {
        *(p->figuras+i) = NULL;
    }

    //INICIALIZANDO PARÂMETROS DE CHAMADA
    p->diretorio_entrada = NULL;
    p->arquivo_entrada = NULL;
    p->diretorio_saida = NULL;
    p->arquivo_entrada_qry = NULL;
    p->arquivo_entrada_ec = NULL;
    p->arquivo_entrada_pm = NULL;
    //p->arquivo_entrada_via = NULL;
    
    //ALOCANDO MEMÓRIA DO CONTROLE
    p->controle = (char*) calloc (5, sizeof (char));

    //TRATANDO OS CAMINHOS
    for (i=0; i<argc; i++)
    {
        if (!strcmp (argv[i], "-e"))
        {
            p->diretorio_entrada = (char*) calloc (strlen (argv[i+1]) + 1, sizeof (char));
            strcpy (p->diretorio_entrada, argv[i+1]);
            altera_caminho (&p->diretorio_entrada);
            i++;
            continue;
        }
        if (!strcmp (argv[i], "-f"))
        {
            p->arquivo_entrada = (char*) calloc (strlen (argv[i+1]) + 1, sizeof (char));
            strcpy (p->arquivo_entrada, argv[i+1]);
            i++;
            continue;
        }
        if (!strcmp (argv[i], "-o"))
        {
            p->diretorio_saida = (char*) calloc (strlen (argv[i+1]) + 1, sizeof (char));
            strcpy (p->diretorio_saida, argv[i+1]);
            altera_caminho (&p->diretorio_saida);
            i++;
            continue;
        }
        if (!strcmp (argv[i], "-q"))
        {
            p->arquivo_entrada_qry = (char*) calloc (strlen (argv[i+1]) + 1, sizeof (char));
            strcpy (p->arquivo_entrada_qry, argv[i+1]);
            i++;
            continue;
        }
        if (!strcmp (argv[i], "-ec"))
        {
            p->arquivo_entrada_ec = (char*) calloc (strlen (argv[i+1]) + 1, sizeof (char));
            strcpy (p->arquivo_entrada_ec, argv[i+1]);
            i++;
            continue;
        }
        if (!strcmp (argv[i], "-pm"))
        {
            p->arquivo_entrada_pm = (char*) calloc (strlen (argv[i+1]) + 1, sizeof (char));
            strcpy (p->arquivo_entrada_pm, argv[i+1]);
            i++;
            continue;
        }
        /*
        if (!strcmp (argv[i], "-v"))
        {
            p->arquivo_entrada_via = (char*) calloc (strlen (argv[i+1]) + 1, sizeof (char));
            strcpy (p->arquivo_entrada_via, argv[i+1]);
            i++;
            continue;
        }
        */
    }
    if (p->diretorio_entrada != NULL)
    {
        if (p->arquivo_entrada != NULL) 
        {
            p->caminho_GEO = (char*) calloc (strlen (p->diretorio_entrada) + strlen (p->arquivo_entrada) + 3, sizeof (char));
            strcpy (p->caminho_GEO, p->diretorio_entrada);
            strcat (p->caminho_GEO, "/");
            strcat (p->caminho_GEO, p->arquivo_entrada);
        }
        if (p->arquivo_entrada_qry != NULL)
        {    
           p->caminho_QRY = (char*) calloc (strlen (p->diretorio_entrada) + strlen (p->arquivo_entrada_qry) + 3, sizeof (char));
           strcpy (p->caminho_QRY, p->diretorio_entrada);
           strcat (p->caminho_QRY, "/");
           strcat (p->caminho_QRY, p->arquivo_entrada_qry);
        }
        if (p->arquivo_entrada_ec != NULL)
        {
            p->caminho_EC = (char*) calloc (strlen (p->diretorio_entrada) + strlen (p->arquivo_entrada_ec) + 3, sizeof (char));
            strcpy (p->caminho_EC, p->diretorio_entrada);
            strcat (p->caminho_EC, "/");
            strcat (p->caminho_EC, p->arquivo_entrada_ec);
        }
        if (p->arquivo_entrada_pm != NULL)
        {
            p->caminho_PM = (char*) calloc (strlen (p->diretorio_entrada) + strlen (p->arquivo_entrada_pm) + 3, sizeof (char));
            strcpy (p->caminho_PM, p->diretorio_entrada);
            strcat (p->caminho_PM, "/");
            strcat (p->caminho_PM, p->arquivo_entrada_pm);
        }
        /*
        if (p->arquivo_entrada_via != NULL)
        {    
            p->caminho_VIA = (char*) calloc (strlen (p->diretorio_entrada) + strlen (p->arquivo_entrada_via) + 3, sizeof (char));
            strcpy (p->caminho_VIA, p->diretorio_entrada);
            strcat (p->caminho_VIA, "/");
            strcat (p->caminho_VIA, p->arquivo_entrada_via);
        }
        */
    }
    else
    {
        if (p->arquivo_entrada != NULL)
        {
            p->caminho_GEO = (char*) calloc (strlen (p->arquivo_entrada) + 2, sizeof (char));
            strcpy (p->caminho_GEO, p->arquivo_entrada);
        }
        if (p->arquivo_entrada_qry != NULL)
        {
            p->caminho_QRY = (char*) calloc (strlen (p->arquivo_entrada_qry) + 2, sizeof(char));
            strcpy (p->caminho_QRY, p->arquivo_entrada_qry);
        }
        if (p->arquivo_entrada_ec != NULL)
        {
            p->caminho_EC = (char*) calloc (strlen (p->arquivo_entrada_ec) + 2, sizeof(char));
            strcpy (p->caminho_EC, p->arquivo_entrada_ec);
        }
        if (p->arquivo_entrada_pm != NULL)
        {
            p->caminho_PM = (char*) calloc (strlen (p->arquivo_entrada_pm) + 2, sizeof(char));
            strcpy (p->caminho_PM, p->arquivo_entrada_pm);
        }
        /*
        if (p->arquivo_entrada_via != NULL)
        {
            p->caminho_VIA = (char*) calloc (strlen (p->arquivo_entrada_via) + 2, sizeof(char));
            strcpy (p->caminho_VIA, p->arquivo_entrada_via);
        }
        */
    }

    //ABRINDO O ARQUIVO .GEO
    if (p->caminho_GEO != NULL)
    {
        arquivo = fopen (p->caminho_GEO, "r");
        sprintf (p->controle, ".geo");
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
            p->comando = (char*) remove_fila (comandos);
            executa_comando (p);
            //free(p->comando);
            //p->comando = NULL;
        }
        //FECHANDO O ARQUIVO
        fclose (arquivo);
        free(comandos);
        comandos = NULL;
    }
    
    if (p->caminho_EC != NULL)
    {
        //ABRINDO O ARQUIVO .EC
        arquivo = fopen (p->caminho_EC, "r");
        sprintf (p->controle, ".ec");
        if (arquivo == NULL)
        {
            printf ("\nArquivo .ec não encontrado!\n");
            return 0;
        }
        printf ("\nArquivo .ec aberto com sucesso!\n");

        //COLOCANDO TODOS OS COMANDOS DO ARQUIVO EM UMA FILA
        comandos = coloca_comandos_arquivo_fila (arquivo);
    
        //TRATANDO OS COMANDOS PARA VETOR E OS EXECUTANDO
        while (!fila_vazia (comandos))
        {
            p->comando = (char*) remove_fila (comandos);
            executa_comando (p);
            //free (p->comando);
            //p->comando = NULL;
        }

        //FECHANDO O ARQUIVO
        fclose (arquivo);
        free(comandos);
        comandos = NULL;
    }

    if (p->caminho_PM != NULL)
    {
    
        //ABRINDO O ARQUIVO .PM
        arquivo = fopen (p->caminho_PM, "r");
        sprintf (p->controle, ".pm");
        if (arquivo == NULL)
        {
            printf ("\nArquivo .pm não encontrado!\n");
            return 0;
        }
        printf ("\nArquivo .pm aberto com sucesso!\n");

        //COLOCANDO TODOS OS COMANDOS DO ARQUIVO EM UMA FILA
        comandos = coloca_comandos_arquivo_fila (arquivo);
    
        //TRATANDO OS COMANDOS PARA VETOR E OS EXECUTANDO
        while (!fila_vazia (comandos))
        {
            p->comando = (char*) remove_fila (comandos);
            executa_comando (p);
            //free (p->comando);
            //p->comando = NULL;
        }

        //FECHANDO O ARQUIVO
        fclose (arquivo);
        free(comandos);
        comandos = NULL;
    }
    
    if (p->caminho_QRY != NULL)
    {
        //ABRINDO O ARQUIVO .QRY
        arquivo = fopen (p->caminho_QRY, "r");
        sprintf (p->controle, ".qry");
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
            p->comando = (char*) remove_fila (comandos);
            executa_comando (p);
            //free (p->comando);
            p->comando = NULL;
        }

        //FECHANDO O ARQUIVO .QRY
        fecha_qry (p);

        //FECHANDO O ARQUIVO
        fclose (arquivo);
        free (comandos);
        comandos = NULL;
    }

    /*
    if (p->caminho_VIA != NULL)
    {
        //ABRINDO O ARQUIVO .VIA
        arquivo = fopen (p->caminho_VIA, "r");
        sprintf (p->controle, ".via");
        if (arquivo == NULL)
        {
            printf ("\nArquivo .via não encontrado!\n");
            return 0;
        }
        printf ("\nArquivo .via aberto com sucesso!\n");

        //COLOCANDO TODOS OS COMANDOS DO ARQUIVO EM UMA FILA
        comandos = coloca_comandos_arquivo_fila (arquivo);
    
        //TRATANDO OS COMANDOS PARA VETOR E OS EXECUTANDO
        while (!fila_vazia (comandos))
        {
            p->comando = (char*) remove_fila (comandos);
            executa_comando (p);
            //free (p->comando);
            //p->comando = NULL;
        }

        //FECHANDO O ARQUIVO .VIA
        fecha_via (arquivo, p);

        //FECHANDO O ARQUIVO
        fclose (arquivo);
    }
    */

    free (p->arquivo_entrada);
    p->arquivo_entrada = NULL;
    free (p->arquivo_entrada_ec);
    p->arquivo_entrada_ec = NULL;
    free (p->arquivo_entrada_pm);
    p->arquivo_entrada_pm = NULL;
    free (p->arquivo_entrada_qry);
    p->arquivo_entrada_qry = NULL;
    free (p->caminho_EC);
    p->caminho_EC = NULL;
    free (p->caminho_GEO);
    p->caminho_GEO = NULL;
    free (p->caminho_PM);
    p->caminho_PM = NULL;
    free (p->caminho_QRY);
    p->caminho_QRY = NULL;
    free (p->caminho_SVG);
    p->caminho_SVG = NULL;
    free (p->caminho_TXT);
    p->caminho_TXT = NULL;
    free (p->comando);
    p->comando = NULL;
    free (p->controle);
    p->controle = NULL;
    free (p->cor_borda_hidrante);
    p->cor_borda_hidrante = NULL;
    free (p->cor_borda_quadra);
    p->cor_borda_quadra = NULL;
    free (p->cor_borda_radiobase);
    p->cor_borda_radiobase = NULL;
    free (p->cor_borda_semaforo);
    p->cor_borda_semaforo = NULL;
    free (p->cor_preenche_hidrante);
    p->cor_preenche_hidrante = NULL;
    free (p->cor_preenche_quadra);
    p->cor_preenche_quadra = NULL;
    free (p->cor_preenche_radiobase);
    p->cor_preenche_radiobase = NULL;
    free (p->cor_preenche_semaforo);
    p->cor_preenche_semaforo = NULL;
    free (p->diretorio_entrada);
    p->diretorio_entrada = NULL;
    free (p->diretorio_saida);
    p->diretorio_saida = NULL;
    free_arvore (p->tree_hidrantes);
    free_arvore (p->tree_quadras);
    free_arvore (p->tree_radiobases);
    free_arvore (p->tree_semaforos);
    free_hashtable (p->hash_comercios);
    free_hashtable (p->hash_end_comercios);
    free_hashtable (p->hash_end_pessoas);
    free_hashtable (p->hash_hidrantes);
    free_hashtable (p->hash_pessoas);
    free_hashtable (p->hash_quadras);
    free_hashtable (p->hash_radiobases);
    free_hashtable (p->hash_semaforos);
    free_hashtable (p->hash_tipos);
    //for (i=0; i<p->contador_figuras; i++)
    //{
    //    free_item (p->figuras[i]);
    //}
    free(p->anotacoes);
    p->anotacoes = NULL;
    free(p->resultado);
    p->resultado = NULL;
    free (p);
    p = NULL;

    //FINALIZANDO O PROGRAMA
    return 1;
}