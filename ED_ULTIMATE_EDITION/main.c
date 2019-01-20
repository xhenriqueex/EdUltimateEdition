//INCLUSÃO DAS BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estruturas/Item/item.h"
#include "Estruturas/Lista/lista.h"
#include "Estruturas/Arvore/arvore.h" //remover
#include "Estruturas/ArvoreB/arvoreb.h"
#include "Estruturas/Registrador/registrador.h"
#include "Estruturas/ArquivoBin/arquivobin.h"
#include "Funcoes/funcoes.h"
#include "Comando/executa_comando.h"
#include "Parametros/parametros.h"
#include "Objetos/Quadra/quadra.h"
#include "Objetos/Hidrante/hidrante.h"
#include "Objetos/Semaforo/semaforo.h"
#include "Objetos/Radiobase/radiobase.h"
#include "Objetos/Comercio/comercio.h"
#include "Objetos/Pessoa/pessoa.h"
#include "Objetos/Carro/carro.h"
#define TAMBLOCO 2048;

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
    
    //DECLARANDO STRINGS AUXILIARES
    char* aux = NULL;

    //DECLARANDO LISTAS AUXILIARES
    Lista* list;
    
    //DECLARANDO VOID POINTERS AUXILIARES
    void* primeiro;

    //ALOCANDO STRUCT
    p = (Parametros*) calloc (1, sizeof (Parametros));

    //INICIALIZANDO CAMINHOS
    p->caminho_GEO = NULL;
    p->caminho_TXT = NULL;
    p->caminho_SVG = NULL;
    p->caminho_QRY = NULL;
    p->caminho_EC = NULL;
    p->caminho_PM = NULL;
    p->caminho_VIA = NULL;
    p->caminho_banco = NULL;

    //INICIALIZANDO STRING DE COMANDO
    p->comando = NULL;
    
    //INICIALIZANDO NÚMERO MÁXIMO DE FIGURAS //remover
    p->max_figuras = 1000;

    //INICIALIZANDO CONTADOR DE FIGURAS
    p->contador_figuras = 0;

    //INICIALIZANDO CONTROLE DE CRIAÇÃO DE BANCO
    p->criar = 0;

    //INICIALIZANDO FILAS
    p->anotacoes = cria_fila();
    p->resultado = cria_fila();
    p->grafo_f = cria_fila();
    
    //INICIALIZANDO HASHTABLES
    p->hash_comercios = cria_hashtable (100, compare_cnpj_comercio, hashcode_comercio);
    p->hash_pessoas = cria_hashtable (100, compare_cpf_pessoa, hashcode_pessoa); 
    p->hash_quadras = cria_hashtable (100, compare_hash_quadra, hashcode_quadra); 
    p->hash_hidrantes = cria_hashtable (100, compare_hash_hidrante, hashcode_hidrante); 
    p->hash_carros = cria_hashtable (100, compare_hash_carro, hashcode_carro); 
    p->hash_semaforos = cria_hashtable (100, compare_hash_semaforo, hashcode_semaforo); 
    p->hash_radiobases = cria_hashtable (100, compare_hash_radiobase, hashcode_radiobase); 
    p->hash_end_comercios = cria_hashtable (100, compare_hash_endereco_comercio, hashcode_endereco_comercio); 
    p->hash_end_pessoas = cria_hashtable (100, compare_cep_endereco_pessoa, hashcode_endereco_pessoa); 
    p->hash_tipos = cria_hashtable (100, compare_hash_tipo_comercio, hashcode_tipo_comercio); 

    //INICIALIZANDO ÁRVORES
    p->tree_quadras = cria_arvore (compare_quadra, 2); //remover
    p->tree_hidrantes = cria_arvore (compare_hidrante, 2); //remover
    p->tree_semaforos = cria_arvore (compare_semaforo, 2); //remover
    p->tree_radiobases = cria_arvore (compare_radiobase, 2); //remover
    p->tree_carros = cria_arvore (compare_carro, 2); //remover

    //INICIALIZANDO GRAFO
    p->grafo_via = cria_grafo();

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

    //INICIALIZANDO VETOR DE FIGURAS // remover
    p->figuras = (Item*) calloc (p->max_figuras, sizeof(Item));
    for(i=0; i<p->max_figuras; i++)
    {
        *(p->figuras+i) = NULL;
    }

    //INICIALIZANDO REGISTRADORES
    p->regis = (Registrador*) calloc (11, sizeof (Registrador));
    aux = (char *) calloc(5, sizeof(char));
    for (i=0; i<11; i++)
    {
        sprintf(aux, "R%d", i);
        *(p->regis+i) = cria_registrador (aux);
    }
    free(aux);
    aux = NULL;

    //INICIALIZANDO PARÂMETROS DE CHAMADA
    p->diretorio_entrada = NULL;
    p->arquivo_entrada = NULL;
    p->diretorio_saida = NULL;
    p->arquivo_entrada_qry = NULL;
    p->arquivo_entrada_ec = NULL;
    p->arquivo_entrada_pm = NULL;
    p->arquivo_entrada_via = NULL;
    
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
        if (!strcmp (argv[i], "-v"))
        {
            p->arquivo_entrada_via = (char*) calloc (strlen (argv[i+1]) + 1, sizeof (char));
            strcpy (p->arquivo_entrada_via, argv[i+1]);
            i++;
            continue;
        }
        if (!strcmp (argv[i], "-bd"))
        {
            p->arquivo_entrada_banco = (char*) calloc (strlen (argv[i+1]) + 1, sizeof (char));
            strcpy (p->arquivo_entrada_banco, argv[i+1]);
            i++;
            continue;
        }
        if (!strcmp (argv[i], "-criar"))
        {
            p->criar = 1;
            i++;
            continue;
        }
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
        if (p->arquivo_entrada_via != NULL)
        {    
            p->caminho_VIA = (char*) calloc (strlen (p->diretorio_entrada) + strlen (p->arquivo_entrada_via) + 3, sizeof (char));
            strcpy (p->caminho_VIA, p->diretorio_entrada);
            strcat (p->caminho_VIA, "/");
            strcat (p->caminho_VIA, p->arquivo_entrada_via);
        }
        if (p->arquivo_entrada_banco != NULL)
        {
            p->caminho_banco = (char*) calloc (strlen (p->diretorio_entrada) + strlen (p->arquivo_entrada_banco) + 3, sizeof (char));
            strcpy (p->caminho_banco, p->diretorio_entrada);
            strcat (p->caminho_banco, "/");
            strcat (p->caminho_banco, p->arquivo_entrada_banco);
        }
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
        if (p->arquivo_entrada_via != NULL)
        {
            p->caminho_VIA = (char*) calloc (strlen (p->arquivo_entrada_via) + 2, sizeof(char));
            strcpy (p->caminho_VIA, p->arquivo_entrada_via);
        }
        if (p->arquivo_entrada_banco != NULL)
        {
            p->caminho_banco = (char*) calloc (strlen (p->arquivo_entrada_banco) + 2, sizeof (char));
            strcpy (p->caminho_banco, p->arquivo_entrada_banco);
        }
    }

    if (p->criar)
    {
        p->figs = cria_lista ();
        aux = (char*) calloc (55, sizeof (char));
        strcpy (aux, p->caminho_banco);
        strcat (aux, "_quadra.dat");
        p->arvoreB_quadras = cria_banco (2048, aux, get_tamanho_quadra(), compare_quadra, escreve_arquivo_quadra, ler_arquivo_quadra, alloc_quadra);
        strcpy (aux, p->caminho_banco);
        strcat (aux, "_hidrante.dat");
        p->arvoreB_hidrantes = cria_banco (2048, aux, get_tamanho_hidrante(), compare_hidrante, escreve_arquivo_hidrante, ler_arquivo_hidrante, alloc_hidrante);
        strcpy (aux, p->caminho_banco);
        strcat (aux, "_semaforo.dat");
        p->arvoreB_semaforos = cria_banco (2048, aux, get_tamanho_semaforo(), compare_semaforo, escreve_arquivo_semaforo, ler_arquivo_semaforo, alloc_semaforo);
        strcpy (aux, p->caminho_banco);
        strcat (aux, "_radiobase.dat");
        p->arvoreB_radiobases = cria_banco (2048, aux, get_tamanho_radiobase(), compare_radiobase, escreve_arquivo_radiobase, ler_arquivo_radiobase, alloc_radiobase);
        strcpy (aux, p->caminho_banco);
        strcat (aux, "_carro.dat");
        p->arvoreB_carros = cria_banco (2048, aux, get_tamanho_carro(), compare_carro, escreve_arquivo_carro, ler_arquivo_carro, alloc_carro);
        p->max_figuras = 1000;
    }
    else
    {
        aux = (char*) calloc (55, sizeof (char));
        strcpy (aux, p->caminho_banco);
        strcat (aux, "_figuras.dat");
        p->figs = get_todos_arquivo (aux, ler_arquivo_item, alloc_item);
        strcpy (aux, p->caminho_banco);
        strcat (aux, "info.dat");
        arquivo = fopen (aux, "r+b");
        fread (p->max_figuras, sizeof (long int), 1, arquivo);
        //for (i=0; i<55; i++){ fread (&p->arquivo_entrada)}
        strcpy (aux, p->caminho_banco);
        strcat (aux, "_quadra.dat");
        p->arvoreB_quadras = carrega_banco (aux, compare_quadra, escreve_arquivo_quadra, ler_arquivo_quadra, alloc_quadra);
        strcpy (aux, p->caminho_banco);
        strcat (aux, "_hidrante.dat");
        p->arvoreB_hidrantes = carrega_banco (aux, compare_hidrante, escreve_arquivo_hidrante, ler_arquivo_hidrante, alloc_hidrante);
        strcpy (aux, p->caminho_banco);
        strcat (aux, "_semaforo.dat");
        p->arvoreB_semaforos = carrega_banco (aux, compare_semaforo, escreve_arquivo_semaforo, ler_arquivo_semaforo, alloc_semaforo);
        strcpy (aux, p->caminho_banco);
        strcat (aux, "_radiobase.dat");
        p->arvoreB_radiobases = carrega_banco (aux, compare_radiobase, escreve_arquivo_radiobase, ler_arquivo_radiobase, alloc_radiobase);
        strcpy (aux, p->caminho_banco);
        strcat (aux, "_carro.dat");
        p->arvoreB_carros = carrega_banco (aux, compare_carro, escreve_arquivo_carro, ler_arquivo_carro, alloc_carro);
        strcpy (aux, p->caminho_banco);
        strcat (aux, "_quadra.dat");
        list = get_todos_arquivo (aux, ler_arquivo_quadra, alloc_quadra);
        primeiro = get_primeiro_lista (list);
        while (p)
        {
            insere_hashtable (p->hash_quadras, get_valor_lista (p));
            p = get_proximo_lista (list, p);
        }
        strcpy (aux, p->caminho_banco);
        strcat (aux, "_hidrante.dat");
        list = get_todos_arquivo (aux, ler_arquivo_hidrante, alloc_hidrante);
        primeiro = get_primeiro_lista (list);
        while (p)
        {
            insere_hashtable (p->hash_hidrantes, get_valor_lista (p));
            p = get_proximo_lista (list, p);
        }
        strcpy (aux, p->caminho_banco);
        strcat (aux, "_semaforo.dat");
        list = get_todos_arquivo (aux, ler_arquivo_semaforo, alloc_semaforo);
        primeiro = get_primeiro_lista (list);
        while (p)
        {
            insere_hashtable (p->hash_semaforos, get_valor_lista (p));
            p = get_proximo_lista (list, p);
        }
        strcpy (aux, p->caminho_banco);
        strcat (aux, "_radiobase.dat");
        list = get_todos_arquivo (aux, ler_arquivo_radiobase, alloc_radiobase);
        primeiro = get_primeiro_lista (list);
        while (p)
        {
            insere_hashtable (p->hash_radiobases, get_valor_lista (p));
            p = get_proximo_lista (list, p);
        }
        strcpy (aux, p->caminho_banco);
        strcat (aux, "_carro.dat");
        list = get_todos_arquivo (aux, ler_arquivo_carro, alloc_carro);
        primeiro = get_primeiro_lista (list);
        while (p)
        {
            insere_hashtable (p->hash_carros, get_valor_lista (p));
            p = get_proximo_lista (list, p);
        }
        strcpy (aux, p->caminho_banco);
        strcat (aux, "_pessoa.dat");
        list = get_todos_arquivo (aux, ler_arquivo_pessoa, alloc_pessoa);
        primeiro = get_primeiro_lista (list);
        while (p)
        {
            insere_hashtable (p->hash_pessoas, get_valor_lista (p));
            aux = get_endereco_pessoa (get_valor_lista (p));
            if (aux) insere_hashtable (p->hash_end_pessoas, get_endereco_pessoa (get_valor_lista (p)));
            p = get_proximo_lista (list, p);
        }
        strcpy (aux, p->caminho_banco);
        strcat (aux, "_comercio.dat");
        list = get_todos_arquivo (aux, ler_arquivo_comercio, alloc_comercio);
        primeiro = get_primeiro_lista (list);
        while (p)
        {
            insere_hashtable (p->hash_comercios, get_valor_lista (p));
            aux = get_tipo_comercio (get_valor_lista (p));
            if (aux) insere_hashtable (p->hash_tipos, get_tipo_comercio (get_valor_lista (p)));
            aux = get_endereco_comercio (get_valor_lista (p));
            if (aux) insere_hashtable (p->hash_end_comercios, get_endereco_comercio (get_valor_lista (p)));
            p = get_proximo_lista (list, p);
        }
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
            aux = p->comando;
            executa_comando (p);
            free(aux);
            aux = NULL;
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
            aux = p->comando;
            executa_comando (p);
            free(aux);
            aux = NULL;
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
            aux = p->comando;
            executa_comando (p);
            free(aux);
            aux = NULL;
        }

        //FECHANDO O ARQUIVO
        fclose (arquivo);
        free(comandos);
        comandos = NULL;
    }

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
            aux = p->comando;
            executa_comando (p);
            free(aux);
            aux = NULL;
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
            p->comando = NULL;
        }

        //FECHANDO O ARQUIVO .QRY
        fecha_qry (p);

        //FECHANDO O ARQUIVO
        fclose (arquivo);
        free (comandos);
        comandos = NULL;
    }

    //LIBERANDO MEMÓRIA ALOCADA
    free (p->arquivo_entrada);
    p->arquivo_entrada = NULL;
    free (p->arquivo_entrada_ec);
    p->arquivo_entrada_ec = NULL;
    free (p->arquivo_entrada_pm);
    p->arquivo_entrada_pm = NULL;
    free (p->arquivo_entrada_via);
    p->arquivo_entrada_via = NULL;
    free (p->arquivo_entrada_qry);
    p->arquivo_entrada_qry = NULL;
    free (p->caminho_EC);
    p->caminho_EC = NULL;
    free (p->caminho_GEO);
    p->caminho_GEO = NULL;
    free (p->caminho_PM);
    p->caminho_PM = NULL;
    free (p->caminho_VIA);
    p->caminho_VIA = NULL;
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
    free_arvore (p->tree_carros);
    free_hashtable (p->hash_comercios, free_comercio);
    free_hashtable (p->hash_tipos, free_tipo_comercio);
    free_hashtable (p->hash_end_comercios, NULL);
    free_hashtable (p->hash_hidrantes, free_hidrante);
    free_hashtable (p->hash_pessoas, free_pessoa);
    free_hashtable (p->hash_end_pessoas, NULL);
    free_hashtable (p->hash_quadras, free_quadra);
    free_hashtable (p->hash_radiobases, free_radiobase);
    free_hashtable (p->hash_semaforos, free_semaforo);
    free_hashtable (p->hash_carros, free_carro);
    //free_registradores(p->regis);
    for (i = 0; i < p->contador_figuras; i++)
    {
        free_item (p->figuras[i]);
        p->figuras[i] = NULL;
    }
    free(p->figuras);
    p->figuras = NULL;
    free_grafo(p->grafo_via);
    free(p->anotacoes);
    p->anotacoes = NULL;
    free(p->resultado);
    p->resultado = NULL;
    free(p->grafo_f);
    p->grafo_f = NULL;
    free (p);
    p = NULL;

    //FINALIZANDO O PROGRAMA
    return 1;
}