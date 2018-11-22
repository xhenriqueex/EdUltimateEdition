#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../Parâmetros/parametros.h"
#include "../Funções/funcoes.h"
#include "../Formas/Retângulo/retangulo.h"
#include "../Formas/Círculo/circulo.h"
#include "../Objetos/Quadra/quadra.h"
#include "../Objetos/Hidrante/hidrante.h"
#include "../Objetos/Semáforo/semaforo.h"
#include "../Objetos/Rádiobase/radiobase.h"
#include "../Objetos/Pessoa/pessoa.h"
#include "../Objetos/Comércio/comercio.h"
#include "../Formas/Anotação/anotacao.h"
#include "../Estruturas/Item/item.h"
#include "../Estruturas/Fila/fila.h"
#include "../Estruturas/Lista/lista.h"
#include "../Estruturas/Árvore/arvore.h"
#include "../Estruturas/Hash/hashtable.h"
#include "../Estruturas/Merge/mergesort.h"
#include "../Funções/parproximo.h"

#define C "circulo"
#define R "retangulo"
#define A "anotacao"

void caso_nx (Parametros* par);
void caso_c (Parametros* par);
void caso_r (Parametros* par);
void caso_q (Parametros* par);
void caso_s (Parametros* par);
void caso_t_geo (Parametros* par);
void caso_h (Parametros* par);
void caso_cq (Parametros* par);
void caso_ch (Parametros* par);
void caso_ct (Parametros* par);
void caso_cs (Parametros* par);
void caso_o (Parametros* par);
void caso_i (Parametros* par);
void caso_d (Parametros* par);
void caso_a (Parametros* par);
void caso_hashtag (Parametros* par);
void caso_t_ec (Parametros* par);
void caso_e (Parametros* par);
void caso_p (Parametros* par);
void caso_m (Parametros* par);
void caso_q_pergunta (Parametros* par);
void caso_Q_pergunta (Parametros* par);
void caso_dq (Parametros* par);
void caso_dle (Parametros* par);
void caso_Dq (Parametros* par);
void caso_Dle (Parametros* par);
void caso_cc (Parametros* par);
void caso_crd_pergunta (Parametros* par);
void caso_crb_pergunta (Parametros* par);
void caso_m_pergunta (Parametros* par);
void caso_mr_pergunta (Parametros* par);
void caso_dm_pergunta (Parametros* par);
void caso_de_pergunta (Parametros* par);
void caso_rip (Parametros* par);
void caso_ecq_pergunta (Parametros* par);
void caso_ecr_pergunta (Parametros* par);
void caso_tecq_pergunta (Parametros* par);
void caso_tecr_pergunta (Parametros* par);
void caso_hmpe_pergunta (Parametros* par);
void caso_hmp_pergunta (Parametros* par);
void caso_fec (Parametros* par);
void caso_mud (Parametros* par);
void caso_mudec (Parametros* par);
void caso_dpr (Parametros* par);

void executa_comando (void* p)
{
    Parametros* par;
    par = (Parametros*) p;
    char* comando;
    comando = (char*) calloc (10, sizeof (char));
    sscanf (par->comando, "%s ", comando);

    //COMANDOS DO ARQUIVO .GEO

    //ALTERA O NÚMERO MÁXIMO DE FIGURAS
    if (!strcmp (comando, "nx"))
    {
        par->comando += 3;
        caso_nx (par);
        free(comando);
        return;
    }
    //CRIAR UM CÍRCULO
    if (!strcmp (comando, "c"))
    {
        par->comando += 2;
        caso_c (par);
        free(comando);
        return;
    }
    //CRIAR UM RETÂNGULO
    if (!strcmp (comando, "r"))
    {
        par->comando += 2;
        caso_r (par);
        free(comando);
        return;
    }
    //CRIA UMA QUADRA
    if (!strcmp (comando, "q"))
    {
        par->comando += 2;
        caso_q (par);
        free(comando);
        return;
    }
    //CRIA UM HIDRANTE
    if (!strcmp (comando, "h"))
    {
        par->comando += 2;
        caso_h (par);
        free(comando);
        return;
    }
    //CRIA UM SEMÁFORO
    if (!strcmp (comando, "s"))
    {
        par->comando += 2;
        caso_s (par);
        free(comando);
        return;
    }
    //CRIA UMA RADIOBASE
    if (!strcmp (comando, "t"))
    {
        par->comando += 2;
        caso_t_geo (par);
        free(comando);
        return;
    }
    //ALTERA AS CORES DA BORDA E DO PREENCHIMENDO DA QUADRA
    if (!strcmp (comando, "cq"))
    {
        par->comando += 3;
        caso_cq (par);
        free(comando);
        return;
    }
    //ALTERA AS CORES DA BORDA E DO PREENCHIMENDO DO HIDRANTE
    if (!strcmp (comando, "ch"))
    {
        par->comando += 3;
        caso_ch (par);
        free(comando);
        return;
    }
    //ALTERA AS CORES DA BORDA E DO PREENCHIMENDO DA RADIO-BASE
    if (!strcmp (comando, "ct"))
    {
        par->comando += 3;
        caso_ct (par);
        free(comando);
        return;
    }
    //ALTERA AS CORES DA BORDA E DO PREENCHIMENDO DO SEMAFORO
    if (!strcmp (comando, "cs"))
    {
        par->comando += 3;
        caso_cs (par);
        free(comando);
        return;
    }
    //VERIFICAR SE DUAS FIGURAS SE SOBREPOEM
    if (!strcmp (comando, "o"))
    {
        caso_o (par);
        free(comando);
        return;
    }
    //VERIFICAR SE UM PONTO É INTERNO A FIGURA
    if (!strcmp (comando, "i"))
    {
        caso_i (par);
        free(comando);
        return;
    }
    //CALCULAR A DISTÂNCIA ENTRE OS CENTROS DE MASSA DE DUAS FIGURAS
    if (!strcmp (comando, "d"))
    {
        caso_d (par);
        free(comando);
        return;
    }
    //CRIA O ARQUIVO SVG COM O SUFIXO
    if (!strcmp (comando, "a"))
    {
        par->comando += 2;
        caso_a (par);
        free(comando);
        return;
    }
    //FINALIZA O ARQUIVO
    if (!strcmp (comando, "#"))
    {
        par->comando += 2;
        caso_hashtag (par);
        free(comando);
        return;
    }

    //COMANDOS DO ARQUIVO .EC
    
    //DEFINE O TIPO DO ESTABELECIMENTO COMERCIAL
    if (!strcmp (comando, "t"))
    {
        par->comando += 2;
        caso_t_ec (par);
        free(comando);
        return;
    }
    //INSERE UM NOVO ESTABELECIMENTO COMERCIAL DE UM DETERMINADO TIPO
    if (!strcmp (comando, "e"))
    {
        par->comando += 2;
        caso_e (par);
        free(comando);
        return;
    }

    //COMANDOS DO ARQUIVO .PM
    //INSERE UMA PESSOA IDENTIFICADA POR UM CPF
    if (!strcmp (comando, "p"))
    {
        par->comando += 2;
        caso_p (par);
        free(comando);
        return;
    }
    //INFORMA O ENDEREÇO ONDE UMA PESSOA MORA
    if (!strcmp (comando, "m"))
    {
        par->comando += 2;
        caso_m (par);
        free(comando);
        return;
    }
    
    //COMANDOS DO ARQUIVOS .QRY 

    //REPORTA O QUE ESTIVER DENTRO DO RETÂNGULO ESPECIFICADO
    if (!strcmp (comando, "q?"))
    {
        caso_q_pergunta (par);
        free(comando);
        return;
    }
    //REPORTA O QUE ESTIVER DENTRO DO CÍRCULO ESPECIFICADO
    if (!strcmp (comando, "Q?"))
    {
        caso_Q_pergunta (par);
        free(comando);
        return;
    }
    //DELETA TODAS AS QUADRAS DENTRO DO RETÂNGULO ESPECIFICADO
    if (!strcmp (comando, "dq"))
    {
        caso_dq (par);
        free(comando);
        return;
    }
    //DELETA TODOS OS EQUIPAMENTOS DENTRO DO RETÂNGULO ESPECIFICADO
    if (!strcmp (comando, "dle"))
    {
        caso_dle (par);
        free(comando);
        return;
    }
    //DELETA TODAS AS QUADRAS DENTRO DO CÍRCULO ESPECIFICADO
    if (!strcmp (comando, "Dq"))
    {
        caso_Dq (par);
        free(comando);
        return;
    }
    //DELETA TODOS OS EQUIPAMENTOS DENTRO DO CÍRCULO ESPECIFICADO
    if (!strcmp (comando, "Dle"))
    {
        caso_Dle (par);
        free(comando);
        return;
    }
    //MUDA AS CORES DA QUADRA IDENTIFICADA PELO CEP
    if (!strcmp (comando, "cc"))
    {
        par->comando += 3;
        caso_cc (par);
        free(comando);
        return;
    }
    //IMPRIME NO .TXT AS COORDENADAS DE UMA DETERMINADA QUADRA OU EQUIPAMENTO
    if (!strcmp (comando, "crd?"))
    {
        caso_crd_pergunta (par);
        free(comando);
        return;
    }
    //DETERMINA AS RADIOBASES MAIS PRÓXIMAS
    if (!strcmp (comando, "crb?"))
    {
        caso_crb_pergunta (par);
        free(comando);
        return;
    }
    //MORADORES DA QUADRA DEFINIDA PELO CEP
    if (!strcmp (comando, "m?"))
    {
        caso_m_pergunta (par);
        free(comando);
        return;
    }
    //MORADORES DAS QUADRAS DENTRO DO RETÂNGULO
    if (!strcmp (comando, "mr?"))
    {
        caso_mr_pergunta (par);
        free(comando);
        return;
    }
    //IMPRIME OS DADOS DO MORADOR IDENTIFICADO PELO CPF
    if (!strcmp (comando, "dm?"))
    {
        caso_dm_pergunta (par);
        free(comando);
        return;
    }
    //IMPRIME OS DADOS DO ESTABELECIMENTO IDENTIFICADO PELO CNPJ
    if (!strcmp (comando, "de?"))
    {
        caso_de_pergunta (par);
        free(comando);
        return;
    }
    //APAGA TODOS OS DADOS DE UMA PESSOA
    if (!strcmp (comando, "rip"))
    {
        caso_rip (par);
        free(comando);
        return;
    }
    //LISTA OS ESTABELECIMENTOS DE UMA QUADRA
    if (!strcmp (comando, "ecq?"))
    {
        caso_ecq_pergunta (par);
        free(comando);
        return;
    }
    //LISTA OS ESTABELECIMeNTOS DE UM DETERMINADO TIPO EM UM RETÂNGULO
    if (!strcmp (comando, "ecr?"))
    {
        caso_ecr_pergunta (par);
        free(comando);
        return;
    }
    //LISTA OS TIPOS DE ESTABELECIMENTOS DE UMA QUADRA ESPECÍFICA
    if (!strcmp (comando, "tecq?"))
    {
        caso_tecq_pergunta (par);
        free(comando);
        return;
    }
    //LISTA OS TIPOS DE ESTABELECIMENTOS COMERCIAIS EM UM RETÂNGULO
    if (!strcmp (comando, "tecr?"))
    {
        caso_tecr_pergunta (par);
        free(comando);
        return;
    }
    //ENCONTRA O HIDRANTE MAIS PRÓXIMO À UM ENDEREÇO ESPECÍFICO
    if (!strcmp (comando, "hmpe?"))
    {
        caso_hmpe_pergunta (par);
        free(comando);
        return;
    }
    //ENCONTRA O HIDRANTE MAIS PRÓXIMO À UMA RADIOBASE ESPECÍFICA
    if (!strcmp (comando, "hmp?"))
    {
        caso_hmp_pergunta (par);
        free(comando);
        return;
    }
    //APAGA TODOS OS DADOS DE UM ESTABELECIMENTO
    if (!strcmp (comando, "fec"))
    {
        caso_fec (par);
        free(comando);
        return;
    }
    //MUDA O ENDEREÇO DA PESSOA E TRAÇA UMA LINHA ENTRE O ENDEREÇO ANTIGO E O NOVO
    if (!strcmp (comando, "mud"))
    {
        caso_mud (par);
        free(comando);
        return;
    }
    //MUDA O ESTABELECIMENTO DE ENDEREÇO E TRAÇA UMA LINHA ENTRE O ENDEREÇO ANTIGO E O NOVO
    if (!strcmp (comando, "mudec"))
    {
        caso_mudec (par);
        free(comando);
        return;
    }
    //DESAPROPRIA UMA REGIÃO (DELETA TUDO DENTRO DELA, MAS A PESSOA NÃO MORRE, SÓ DEIXA DE MORAR LÁ)
    if (!strcmp (comando, "dpr"))
    {
        caso_dpr (par);
        free(comando);
        return;
    }
}

//FUNÇÕES REFERENTES AOS COMANDOS DO ARQUIVO .GEO

void caso_nx (Parametros* par)
{
    int i;
    Valor aux;
    sscanf (par->comando, "%ld ", &par->max_figuras);
    Fila fila;
    fila = cria_fila ();
    for (i=0; i<par->contador_figuras; i++)
    {
        if (par->figuras[i] != NULL)
        {
            aux = (Valor) get_valor_item (par->figuras[i]);
            insere_fila (fila, aux);
        }
    }
    free (par->figuras);
    par->figuras = (Item*) calloc (par->max_figuras, sizeof (Item));
    i = 0;
    par->contador_figuras = 0;
    while (!fila_vazia (fila))
    {
        par->figuras[i] = remove_fila (fila);
        i++;
        par->contador_figuras++;
    }
    return;
}
void caso_c (Parametros* par)
{
    long int id;
    double r, x, y;
    char* cor1;
    char* cor2;
    void* fig;
    Item it;
    if (par->contador_figuras >= par->max_figuras)
    {
        printf ("\nERRO: LIMITE DE FIGURAS ATINGIDO!");
        return;
    }
    cor1 = (char*) calloc (55, sizeof (char));
    cor2 = (char*) calloc (55, sizeof (char));
    sscanf (par->comando, "%ld %s %s %lf %lf %lf", &id, cor1, cor2, &r, &x, &y);
    fig = cria_circulo (id, cor1, cor2, r, x, y);
    it = cria_item (fig, C);
    par->figuras[par->contador_figuras] = it;
    par->contador_figuras++;
    return;
}
void caso_r (Parametros* par)
{
    long int id;
    double w, h, x, y;
    char* cor1;
    char* cor2;
    void* fig;
    Item it;
    if (par->contador_figuras >= par->max_figuras)
    {
        printf ("\nERRO: LIMITE DE FIGURAS ATINGIDO!");
        return;
    }
    cor1 = (char*) calloc (55, sizeof (char));
    cor2 = (char*) calloc (55, sizeof (char));
    sscanf (par->comando, "%ld %s %s %lf %lf %lf %lf", &id, cor1, cor2, &w, &h, &x, &y);
    fig = cria_retangulo (id, cor1, cor2, w, h, x, y);
    it = cria_item (fig, R);
    par->figuras[par->contador_figuras] = it;
    par->contador_figuras++;
    free (cor1);
    free (cor2);
    return;
}

void caso_q (Parametros* par)
{
    double w, h, x, y;
    char* cep;
    Quadra* quadra;
    cep = (char*) calloc (55, sizeof (char));
    sscanf (par->comando, "%s %lf %lf %lf %lf", cep, &x, &y, &w, &h);
    quadra = cria_quadra (cep, x, y, w, h, par->cor_borda_quadra, par->cor_preenche_quadra);
    insere_arvore (par->tree_quadras, quadra);
    insere_hashtable (par->hash_quadras, quadra);
    return;
}

void caso_h (Parametros* par)
{
    char* id;
    double x, y;
    Hidrante* hidrante;
    id = (char*) calloc (55, sizeof (char));
    sscanf (par->comando, "%s %lf %lf", id, &x, &y);
    hidrante = cria_hidrante (id, 5, x, y, par->cor_borda_hidrante, par->cor_preenche_hidrante);
    insere_arvore (par->tree_hidrantes, hidrante);
    insere_hashtable (par->hash_hidrantes, hidrante);
    return;
}

void caso_s (Parametros* par)
{
    char* id;
    double x, y;
    Semaforo* semaforo;
    id = (char*) calloc (55, sizeof (char));
    sscanf (par->comando, "%s %lf %lf", id, &x, &y);
    semaforo = cria_semaforo (id, 5, x, y, par->cor_borda_semaforo, par->cor_preenche_semaforo);
    insere_arvore (par->tree_semaforos, semaforo);
    insere_hashtable (par->hash_semaforos, semaforo);
    return;
    
}

void caso_t_geo (Parametros* par)
{
    char* id;
    double x, y;
    Radiobase* radiobase;
    id = (char*) calloc (55, sizeof (char));
    sscanf (par->comando, "%s %lf %lf", id, &x, &y);
    radiobase = cria_radiobase (id, 5, x, y, par->cor_borda_radiobase, par->cor_preenche_radiobase);
    insere_arvore (par->tree_radiobases, radiobase);
    insere_hashtable (par->hash_radiobases, radiobase);
    return;
}

void caso_cq (Parametros* par)
{
    sscanf (par->comando, "%s %s", par->cor_borda_quadra, par->cor_preenche_quadra);
    return;
}

void caso_ch (Parametros* par)
{
    sscanf (par->comando, "%s %s", par->cor_borda_hidrante, par->cor_preenche_hidrante);
    return;
}

void caso_ct (Parametros* par)
{
    sscanf (par->comando, "%s %s", par->cor_borda_radiobase, par->cor_preenche_radiobase);
    return;
}

void caso_cs (Parametros* par)
{
    sscanf (par->comando, "%s %s", par->cor_borda_semaforo, par->cor_preenche_semaforo);
    return;
}

void caso_o (Parametros* par)
{
    double* centro1;
    double* centro2;
    double valor1, valor2, valor3, valor4, dist;
    long int id1, id2;
    int dentro, i;
    char* string;
    Item fig1 = NULL;
    Item fig2 = NULL;
    Anotacao anotacao;
    string = (char*) calloc (strlen (par->comando) + 1, sizeof (char));
    strcpy (string, par->comando);
    insere_fila (par->resultado, string);
    par->comando += 2;
    sscanf (par->comando, "%ld %ld", &id1, &id2);
    for (i=0; i<par->contador_figuras; i++)
    {
        if (fig1 && fig2 != NULL)
        {
            break;
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), R))
        {
            if (get_id_retangulo (get_valor_item (par->figuras[i])) == id1)
            {
                fig1 = par->figuras[i];
                continue;
            }
            if (get_id_retangulo (get_valor_item (par->figuras[i])) == id2)
            {
                fig2 = par->figuras[i];
                continue;
            }
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), C))
        {
            if (get_id_circulo (get_valor_item (par->figuras[i])) == id1)
            {
                fig1 = par->figuras[i];
                continue;
            }
            if (get_id_circulo (get_valor_item (par->figuras[i])) == id2)
            {
                fig2 = par->figuras[i];
                continue;
            }
        }
    }
    if (fig1 == NULL)
    {
        if (fig2 == NULL)
        {
            printf ("\nERRO: AS FIGURAS NAO FORAM ENCONTRADAS!");
            return;
        }
        printf ("\nERRO: UMA DAS FIGURAS NAO FORAM ENCONTRADAS!");
        return;
    }
    if (fig2 == NULL)
    {
        printf ("\nERRO: UMA DAS FIGURAS NAO FORAM ENCONTRADAS!");
        return;
    }
    if (!strcmp (get_tipo_item (fig1), C) && !strcmp (get_tipo_item (fig2), C))
    {
        centro1 = centro_massa_circulo (get_valor_item (fig1));
        centro2 = centro_massa_circulo (get_valor_item (fig2));
        valor1 = (*centro2 - *centro1);
        valor2 = (*(centro2+1) - *(centro1+1));
        free (centro1);
        free (centro2);
        dist = sqrt ((valor1 * valor1) + (valor2 * valor2));
        if (dist <= get_r_circulo (get_valor_item (fig1)) + get_r_circulo (get_valor_item (fig2)))
        {
            insere_fila (par->resultado, (Valor*) "\nSIM\n");
            if (get_x_circulo (get_valor_item (fig1)) > get_x_circulo (get_valor_item (fig2)))
            {
                valor1 = get_x_circulo (get_valor_item (fig2)) - get_r_circulo (get_valor_item (fig2));
                valor3 = get_x_circulo (get_valor_item (fig1)) + get_r_circulo (get_valor_item (fig1));
            }
            else 
            {
                valor1 = get_x_circulo (get_valor_item(fig1)) - get_r_circulo (get_valor_item (fig1));
                valor3 = get_x_circulo (get_valor_item(fig2)) + get_r_circulo (get_valor_item (fig2));
            }
            if (get_y_circulo (get_valor_item (fig1)) > get_y_circulo (get_valor_item (fig2)))
            {
                valor2 = get_y_circulo (get_valor_item (fig2)) - get_r_circulo (get_valor_item (fig2));
                valor4 = get_y_circulo (get_valor_item (fig1)) + get_r_circulo (get_valor_item(fig1));
            }
            else 
            {
                valor2 = get_y_circulo (get_valor_item(fig1)) - get_r_circulo (get_valor_item(fig1));
                valor4 = get_y_circulo (get_valor_item(fig2)) + get_r_circulo (get_valor_item(fig2));
            }
            anotacao = cria_anotacao (abs (valor1 - valor3), abs (valor2 - valor4), valor1, valor2, "SOBREPOE");
            insere_fila(par->anotacoes, (Valor*) anotacao);
            return;
        }
        insere_fila (par->resultado, (Valor*) "\nNAO\n");
        return;
    }
    else if (!strcmp (get_tipo_item (fig1), R) && !strcmp (get_tipo_item (fig2), R))
    {
        dentro = 1;
        valor1 = get_x_retangulo (get_valor_item (fig1)) + get_w_retangulo (get_valor_item (fig1));
        valor2 = get_x_retangulo (get_valor_item (fig2));
        if (valor1 < valor2 && dentro)
        {
            dentro = 0;
        }
        valor1 = get_x_retangulo (get_valor_item (fig1));
        valor2 = get_x_retangulo (get_valor_item (fig2)) + get_w_retangulo (get_valor_item (fig2));
        if (valor1 > valor2 && dentro)
        {
            dentro = 0;
        }
        valor1 = get_y_retangulo (get_valor_item (fig1)) + get_h_retangulo (get_valor_item(fig1));
        valor2 = get_y_retangulo (get_valor_item (fig2));
        if (valor1 < valor2 && dentro)
        {
            dentro = 0;
        }
        valor1 = get_y_retangulo (get_valor_item (fig1));
        valor2 = get_y_retangulo (get_valor_item (fig2)) + get_h_retangulo (get_valor_item (fig2));
        if (valor1 > valor2 && dentro)
        {
            dentro = 0;
        }
        if (dentro == 1)
        {
            insere_fila (par->resultado, (Valor*) "\nSIM\n");
            if (get_x_retangulo (get_valor_item (fig1)) > get_x_retangulo (get_valor_item (fig2)))
            {
                valor1 = get_x_retangulo (get_valor_item (fig2));
            }
            else 
            {
                valor1 = get_x_retangulo (get_valor_item (fig1));
            }
            if (get_x_retangulo (get_valor_item (fig1)) + get_w_retangulo (get_valor_item(fig1)) > get_x_retangulo (get_valor_item (fig2)) + get_w_retangulo (get_valor_item (fig2)))
            {
                valor3 = get_x_retangulo (get_valor_item (fig1)) + get_w_retangulo (get_valor_item (fig1));
            }
            else
            {
                valor3 = get_x_retangulo (get_valor_item (fig2)) + get_w_retangulo (get_valor_item (fig2));
            }
            if (get_y_retangulo (get_valor_item (fig1)) > get_y_retangulo (get_valor_item (fig2)))
            {
                valor2 = get_y_retangulo (get_valor_item (fig2));
            }
            else 
            {
                valor2 = get_y_retangulo (get_valor_item (fig1));
            }
            if (get_y_retangulo (get_valor_item (fig1)) + get_h_retangulo (get_valor_item (fig1)) > get_y_retangulo (get_valor_item (fig2)) + get_h_retangulo (get_valor_item (fig2)))
            {
                valor4 = get_y_retangulo (get_valor_item (fig1)) + get_h_retangulo (get_valor_item (fig1));
            }
            else
            {
                valor4 = get_y_retangulo (get_valor_item (fig2)) + get_h_retangulo (get_valor_item (fig2));
            }
            anotacao = cria_anotacao (abs (valor1 - valor3), abs (valor2 - valor4), valor1, valor2, "SOBREPOE");
            insere_fila (par->anotacoes, anotacao);
            return;
        }
        insere_fila (par->resultado, (Valor*) "\nNAO\n");
        return;
    }
    else if (!strcmp (get_tipo_item (fig1), R))
    {
        valor1 = maior (get_x_retangulo (get_valor_item (fig1)), menor (get_x_circulo (get_valor_item (fig2)), get_x_retangulo (get_valor_item (fig1)) + get_w_retangulo (get_valor_item (fig1))));
        valor2 = maior (get_y_retangulo (get_valor_item (fig1)), menor (get_y_circulo (get_valor_item (fig2)), get_y_retangulo (get_valor_item (fig1)) + get_h_retangulo (get_valor_item (fig1))));
        dentro = dentro_borda_circulo (get_valor_item (fig2), valor1, valor2);
        if (dentro == 1)
        {
            insere_fila (par->resultado, (Valor*) "\nSIM\n");
            if (get_x_retangulo (get_valor_item (fig1)) > get_x_circulo (get_valor_item (fig2)) - get_r_circulo (get_valor_item (fig2)))
            {
                valor1 = get_x_circulo (get_valor_item (fig2)) - get_r_circulo (get_valor_item (fig2));
                valor3 = get_x_retangulo (get_valor_item (fig1));
            }
            else
            {
                valor1 = get_x_retangulo (get_valor_item (fig1));
                valor3 = get_x_circulo (get_valor_item (fig2)) + get_r_circulo (get_valor_item (fig2));
            }
            if (get_y_retangulo (get_valor_item (fig1)) > get_y_circulo (get_valor_item (fig2)) - get_r_circulo (get_valor_item (fig2)))
            {
                valor2 = get_y_circulo (get_valor_item (fig2)) - get_r_circulo (get_valor_item (fig2));
                valor4 = get_y_retangulo (get_valor_item (fig1));
            }
            else
            {
                valor2 = get_y_retangulo (get_valor_item (fig1));
                valor4 = get_y_circulo (get_valor_item (fig2)) + get_r_circulo (get_valor_item (fig2));
            }
            anotacao = cria_anotacao (abs (valor1 - valor3), abs (valor2 - valor4), valor1, valor2, "SOBREPOE");
            insere_fila(par->anotacoes, (Valor*) anotacao);
            return;
        }
        insere_fila (par->resultado, (Valor*) "\nNAO\n");
        return;
    }
    else if (!strcmp (get_tipo_item ((fig1)), C))
    {
        valor1 = maior (get_x_retangulo (get_valor_item (fig2)), menor (get_x_circulo (get_valor_item (fig1)), get_x_retangulo (get_valor_item (fig2)) + get_w_retangulo(get_valor_item(fig2))));
        valor2 = maior (get_y_retangulo (get_valor_item (fig2)), menor (get_y_circulo (get_valor_item (fig1)), get_y_retangulo (get_valor_item (fig2)) + get_h_retangulo(get_valor_item(fig2))));
        dentro = dentro_borda_circulo (get_valor_item (fig1), valor1, valor2);
        if (dentro == 1)
        {
            insere_fila (par->resultado, (Valor*) "\nSIM\n");
            if (get_x_retangulo (get_valor_item (fig2)) > get_x_circulo (get_valor_item (fig1)) - get_r_circulo (get_valor_item (fig1)))
            {
                valor1 = get_x_circulo (get_valor_item (fig1)) - get_r_circulo (get_valor_item (fig1));
                valor3 = get_x_retangulo (get_valor_item (fig2));
            }
            else
            {
                valor1 = get_x_retangulo (get_valor_item (fig2));
                valor3 = get_x_circulo (get_valor_item (fig1)) + get_r_circulo (get_valor_item (fig1));
            }
            if (get_y_retangulo (get_valor_item (fig2)) > get_y_circulo (get_valor_item (fig1)) - get_r_circulo (get_valor_item (fig1)))
            {
                valor2 = get_y_circulo (get_valor_item (fig1)) - get_r_circulo (get_valor_item (fig1));
                valor4 = get_y_retangulo (get_valor_item (fig2));
            }
            else
            {
                valor2 = get_y_retangulo (get_valor_item (fig2));
                valor4 = get_y_circulo (get_valor_item (fig1)) + get_r_circulo (get_valor_item (fig1));
            }
            anotacao = cria_anotacao(abs (valor1 - valor3), abs (valor2 - valor4), valor1, valor2, "SOBREPOE");
            insere_fila(par->anotacoes, (Valor*) anotacao);                   
            return;
        }
        insere_fila (par->resultado, (Valor*) "\nNAO\n");
        return;
    }
}
void caso_i (Parametros* par)
{
    long int id;
    float x, y;
    int i, in1, in2;
    char* string;
    string = (char*) calloc (strlen (par->comando) + 1, sizeof (char));
    strcpy (string, par->comando);
    insere_fila (par->resultado, string);
    par->comando += 2;
    Item fig = NULL;
    sscanf (par->comando, "%ld %f %f", &id, &x, &y);
    for (i=0; i<par->contador_figuras; i++)
    {
        if (fig != NULL)
        {
            break;
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), R))
        {
            if (get_id_retangulo (get_valor_item (par->figuras[i])) == id)
            {
                fig = par->figuras[i];
                continue;
            }
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), C))
        {
            if (get_id_circulo (get_valor_item (par->figuras[i])) == id)
            {
                fig = par->figuras[i];
                continue;
            }
        }
    }
    if (fig == NULL)
    {
        printf ("\nERRO: FIGURA NAO ENCONTRADA!");
        return;
    }
    if (!strcmp (get_tipo_item (fig), R))
    {
        in1 = dentro_retangulo (get_valor_item (fig), x, y);
        if (in1 == 1)
        {
            insere_fila (par->resultado, (Valor*) "\nSIM\n");    
            return;
        }
        insere_fila (par->resultado, (Valor*) "\nNAO\n");
        return;
    }
    if (!strcmp (get_tipo_item (fig), C))
    {
        in1 = dentro_circulo (get_valor_item (fig), x, y);
        if (in1 == 1)
        {
            insere_fila(par->resultado, (Valor*) "\nSIM\n");
            return;
        }
        insere_fila(par->resultado, (Valor*) "\nNAO\n");
        return;
    }
}

void caso_d (Parametros* par)
{
    int i;
    long int id1, id2;
    char* string;
    char* result_string;
    double* centro1;
    double* centro2;
    double dx, dy, result;
    string = (char*) calloc (strlen (par->comando) + 1, sizeof (char));
    strcpy (string, par->comando);
    insere_fila (par->resultado, string);
    par->comando += 2;
    sscanf (par->comando, "%ld %ld", &id1, &id2);
    Item fig1 = NULL;
    Item fig2 = NULL;
    for (i=0; i<par->contador_figuras; i++)
    {
        if (fig1 && fig2 != NULL)
        {
            break;
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), R))
        {
            if (get_id_retangulo (get_valor_item (par->figuras[i])) == id1)
            {
                fig1 = par->figuras[i];
            }
            if (get_id_retangulo (get_valor_item (par->figuras[i])) == id2)
            {
                fig2 = par->figuras[i];
            }
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), C))
        {
            if (get_id_circulo (get_valor_item (par->figuras[i])) == id1)
            {
                fig1 = par->figuras[i];
            }
            if (get_id_circulo (get_valor_item (par->figuras[i])) == id2)
            {
                fig2 = par->figuras[i];
            }
        }
    }
    if ((fig1) == NULL)
    {
        if ((fig2) == NULL)
        {
            printf ("\nERRO: AS FIGURAS NAO FORAM ENCONTRADAS!");
            result_string = (char*) calloc (55, sizeof (char));
            sprintf (result_string, "\nAS FIGURAS NÃO FORAM ENCONTRADAS!");
            insere_fila (par->resultado, (Valor*) result_string);
            return;
        }
        printf ("\nERRO: UMA DAS FIGURAS NAO FORAM ENCONTRADAS!");
        result_string = (char*) calloc (55, sizeof (char));
        sprintf (result_string, "\nUMA DAS FIGURAS NÃO FOI ENCONTRADA!");
        insere_fila (par->resultado, (Valor*) result_string);    
        return;
    }
    if ((fig2) == NULL)
    {
        printf ("\nERRO: UMA DAS FIGURAS NAO FORAM ENCONTRADAS!");
        result_string = (char*) calloc (55, sizeof (char));
        sprintf (result_string, "\nUMA DAS FIGURAS NÃO FORAM ENCONTRADAS!");
        insere_fila (par->resultado, (Valor*) result_string);
        return;
    }
    if(!strcmp(get_tipo_item (fig1), R))
    {
        centro1 = centro_massa_retangulo (get_valor_item (fig1));
        if (!strcmp (get_tipo_item (fig2), R))
        {
            centro2 = centro_massa_retangulo (get_valor_item (fig2));
        }
        else
        {
            centro2 = centro_massa_circulo (get_valor_item (fig1));
        }
    }
    else
    {
        centro1 = centro_massa_circulo (get_valor_item (fig1));
        if (!strcmp (get_tipo_item (fig2), R))
        {
            centro2 = centro_massa_retangulo (get_valor_item (fig2));
        }
        else
        {
            centro2 = centro_massa_circulo (get_valor_item (fig2));
        }
    }
    dx = *centro1 - *centro2;
    dy = *(centro1 + 1) - *(centro2 +1);
    free (centro1);
    free (centro2);
    result = sqrt ((dx*dx) + (dy*dy));
    result_string = (char*) calloc (1, sizeof(result));
    sprintf (result_string, "\n%f\n", result);
    insere_fila (par->resultado, (Valor*) result_string);
    return;
}

void caso_a (Parametros* par)
{
    long int id;
    int i;
    char* percorre = NULL;
    char* conteudo_svg;
    char* sufixo;
    char* corB;
    double* centro1;
    double* centro2;
    void* fila_linha;
    double x1, x2, y1, y2, dx, dy, result;
    Fila aux;
    FILE* saida_SVG;
    Item fig;
    Lista quadras;
    Lista hidrantes;
    Lista semaforos;
    Lista radiobases;
    sufixo = (char*) calloc (55, sizeof (char));
    sscanf (par->comando,"%ld %s", &id, sufixo);
    fig = NULL;
    for (i=0; i<par->contador_figuras; i++)
    {
        if (fig != NULL)
        {
            break;
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), R))
        {
            if (get_id_retangulo (get_valor_item (par->figuras[i])) == id)
            {
                fig = par->figuras[i];
                continue;
            }
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), C))
        {
            if (get_id_circulo (get_valor_item (par->figuras[i])) == id)
            {
                fig = par->figuras[i];
                continue;
            }
        }
    }
    if (fig == NULL)
    {
        printf ("\nERRO: FIGURA NAO ENCONTRADA!");
        return;
    }
    par->caminho_SVG = (char*) calloc (255, sizeof(char));
    strcpy(par->caminho_SVG, par->diretorio_saida);
    strcat(par->caminho_SVG, "/");
    strcat (par->caminho_SVG, par->arquivo_entrada);
    percorre = par->caminho_SVG;
    percorre = percorre + strlen (percorre) - 1;
    while (*percorre != '.')
    {
        percorre--;
    }
    *percorre = '\0';
    percorre = par->caminho_SVG;
    par->caminho_SVG = (char*) calloc (255, sizeof(char));
    sprintf (par->caminho_SVG, "%s-%s.svg", percorre, sufixo);
    saida_SVG = fopen (par->caminho_SVG, "w");
    
    free (par->caminho_SVG);
    
    fprintf (saida_SVG, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"100000\" height=\"100000\">");
    for (i=0; i<par->contador_figuras; i++)
    {
        if (par->figuras[i] == NULL)
        {
            continue;
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), R))
        {
            conteudo_svg = cria_svg_retangulo (get_valor_item (par->figuras[i]));
            fprintf (saida_SVG, conteudo_svg);
            continue;
        }
        else
        {
            conteudo_svg = cria_svg_circulo (get_valor_item (par->figuras[i]));
            fprintf (saida_SVG, conteudo_svg);
            continue;
        }
    }
    aux = cria_fila();
    while (!fila_vazia (par->anotacoes))
    {
        fila_linha = remove_fila (par->anotacoes);
        conteudo_svg = cria_svg_anotacao (fila_linha);
        fprintf (saida_SVG, conteudo_svg);
        insere_fila (aux, fila_linha);
        continue;
    }
    while (!fila_vazia(aux))
    {
        insere_fila (par->anotacoes, remove_fila(aux));
    }
    free (aux);
    if(!strcmp (get_tipo_item (fig), R))
    {
        centro1 = centro_massa_retangulo (get_valor_item (fig));
        corB = get_cor1_retangulo (get_valor_item (fig));
    }
    else
    {
        centro1 = centro_massa_circulo (get_valor_item (fig));
        corB = get_cor1_circulo (get_valor_item (fig));
    }
    x1 = *centro1;
    y1 = *(centro1 + 1);
    free (centro1);
    for (i=0; i<par->contador_figuras; i++)
    {
        if (par->figuras[i] == NULL || i == id)
        {
            continue;
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), R))
        {
            centro2 = centro_massa_retangulo (get_valor_item (par->figuras[i]));
        }
        else
        {
            centro2 = centro_massa_circulo (get_valor_item(par->figuras[i]));
        }
        x2 = *centro2;
        y2 =*(centro2 + 1);
        dx = x2 - x1;
        dy = y2 - y1;
        free (centro2);
        result = sqrt ((dx*dx) + (dy*dy));
        fprintf (saida_SVG, "\n<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke=\"%s\" stroke-width=\"2\"/>", x1, y1, x2, y2, corB);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">%.2f</text>", (x1 + dx/2), (y1+dy/2), result);
    }
    void* primeiro;
    quadras = get_todos_arvore (par->tree_quadras);
    primeiro = get_primeiro_lista (quadras);
    do
    {
        if (get_valor_lista (quadras, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (quadras, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_quadra (get_valor_lista (quadras, primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">%s</text>", get_x_quadra (get_valor_lista (quadras, primeiro)), get_y_quadra (get_valor_lista (quadras, primeiro)), get_cep_quadra (get_valor_lista (quadras, primeiro)));
        primeiro = get_proximo_lista (quadras, primeiro);
    }
    while (primeiro != NULL);
    hidrantes = get_todos_arvore (par->tree_hidrantes);
    primeiro = get_primeiro_lista (hidrantes);
    do
    {
        if (get_valor_lista (hidrantes, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (hidrantes, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_hidrante (get_valor_lista (hidrantes, primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">H</text>", get_x_hidrante (get_valor_lista (hidrantes, primeiro)), get_y_hidrante (get_valor_lista (hidrantes, primeiro)));
        primeiro = get_proximo_lista (hidrantes, primeiro);
    }
    while (primeiro != NULL);
    semaforos = get_todos_arvore (par->tree_semaforos);
    primeiro = get_primeiro_lista (semaforos);
    do
    {
        if (get_valor_lista (semaforos, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (semaforos, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_semaforo (get_valor_lista (semaforos, primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">S</text>", get_x_semaforo (get_valor_lista (semaforos, primeiro)), get_y_semaforo (get_valor_lista (semaforos, primeiro)));
        primeiro = get_proximo_lista (semaforos, primeiro);
    }
    while (primeiro != NULL);
    radiobases = get_todos_arvore (par->tree_radiobases);
    primeiro = get_primeiro_lista (radiobases);
    do
    {
        if (get_valor_lista (radiobases, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (radiobases, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_radiobase (get_valor_lista (radiobases, primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">R</text>", get_x_radiobase (get_valor_lista (radiobases, primeiro)), get_y_radiobase(get_valor_lista (radiobases, primeiro)));
        primeiro = get_proximo_lista (radiobases, primeiro);
    }
    while (primeiro != NULL);
    free(conteudo_svg);
    fprintf (saida_SVG, "\n</svg>");
    fclose (saida_SVG);
    return;
}

void caso_hashtag (Parametros* par)
{
    int i;
    char* percorre;
    char* conteudo_svg;
    void* fila_linha;
    Fila aux;
    FILE* saida_svg;
    FILE* saida_txt;
    Lista quadras;
    Lista hidrantes;
    Lista semaforos;
    Lista radiobases;
    par->caminho_SVG = (char*) calloc (255, sizeof(char));
    strcpy(par->caminho_SVG, par->diretorio_saida);
    strcat(par->caminho_SVG, "/");
    strcat (par->caminho_SVG, par->arquivo_entrada);
    percorre = par->caminho_SVG + strlen (par->caminho_SVG) - 1;
    while (*percorre != '.')
    {
        percorre--;
    }
    strcpy (percorre, ".svg");
    saida_svg = fopen (par->caminho_SVG, "w");
    fprintf (saida_svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"100000\" height=\"100000\">");
    for (i=0; i<par->contador_figuras; i++)
    {
        if (par->figuras[i] == NULL)
        {
            continue;
        }
        if (!strcmp(get_tipo_item (par->figuras[i]), R))
        {

            conteudo_svg = cria_svg_retangulo (get_valor_item (par->figuras[i]));
            fprintf (saida_svg, conteudo_svg);
            continue;
        }
        else
        {
            conteudo_svg = cria_svg_circulo (get_valor_item (par->figuras[i]));
            fprintf (saida_svg, conteudo_svg);
            continue;
        }
        free (conteudo_svg);
    }
    void* primeiro;
    quadras = get_todos_arvore (par->tree_quadras);
    primeiro = get_primeiro_lista (quadras);
    do
    {
        if (get_valor_lista (quadras, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (quadras, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_quadra (get_valor_lista (quadras, primeiro));
        fprintf (saida_svg, conteudo_svg);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">%s</text>", get_x_quadra (get_valor_lista (quadras, primeiro)) + 3, get_y_quadra (get_valor_lista (quadras, primeiro)) + (get_h_quadra (get_valor_lista (quadras, primeiro))) - 3, get_cep_quadra (get_valor_lista (quadras, primeiro)));
        primeiro = get_proximo_lista (quadras, primeiro);
    }
    while (primeiro != NULL);
    hidrantes = get_todos_arvore (par->tree_hidrantes);
    primeiro = get_primeiro_lista (hidrantes);
    do
    {
        if (get_valor_lista (hidrantes, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (hidrantes, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_hidrante (get_valor_lista (hidrantes, primeiro));
        fprintf (saida_svg, conteudo_svg);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">H</text>", get_x_hidrante (get_valor_lista (hidrantes, primeiro)), get_y_hidrante (get_valor_lista (hidrantes, primeiro)));
        primeiro = get_proximo_lista (hidrantes, primeiro);
    }
    while (primeiro != NULL);
    semaforos = get_todos_arvore (par->tree_semaforos);
    primeiro = get_primeiro_lista (semaforos);
    do
    {
        if (get_valor_lista (semaforos, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (semaforos, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_semaforo (get_valor_lista (semaforos, primeiro));
        fprintf (saida_svg, conteudo_svg);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">S</text>", get_x_semaforo (get_valor_lista (semaforos, primeiro)), get_y_semaforo (get_valor_lista (semaforos, primeiro)));
        primeiro = get_proximo_lista (semaforos, primeiro);
    }
    while (primeiro != NULL);
    radiobases = get_todos_arvore (par->tree_radiobases);
    primeiro = get_primeiro_lista (radiobases);
    do
    {
        if (get_valor_lista (radiobases, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (radiobases, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_radiobase (get_valor_lista (radiobases, primeiro));
        fprintf (saida_svg, conteudo_svg);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">R</text>", get_x_radiobase (get_valor_lista (radiobases, primeiro)), get_y_radiobase (get_valor_lista (radiobases, primeiro)));
        primeiro = get_proximo_lista (radiobases, primeiro);
    }
    while (primeiro != NULL);
    free(conteudo_svg);
    aux = cria_fila ();
    while (!fila_vazia (par->anotacoes))
    {
        fila_linha = remove_fila (par->anotacoes);
        conteudo_svg = cria_svg_anotacao (fila_linha);
        fprintf (saida_svg, conteudo_svg);
        insere_fila (aux, fila_linha);
        continue;
    }
    while(!fila_vazia (aux))
    {
        insere_fila (par->anotacoes, remove_fila (aux));
    }
    free (aux);
    fprintf (saida_svg, "\n</svg>");
    fclose (saida_svg);
    par->caminho_TXT = (char *) calloc(strlen(par->caminho_SVG)+1, sizeof(char));
    strcpy (par->caminho_TXT, par->caminho_SVG);
    percorre = par->caminho_TXT + strlen(par->caminho_TXT) - 1;
    while (*percorre != '.')
    {
        percorre--;
    }
    strcpy (percorre, ".txt");
    saida_txt = fopen (par->caminho_TXT, "a");
    free (par->caminho_TXT);
    fprintf (saida_txt, "\nARQUIVO: %s\n\n", par->arquivo_entrada);
    while (!fila_vazia (par->resultado))
    {
        conteudo_svg = remove_fila (par->resultado);
        fprintf (saida_txt, conteudo_svg);
        continue;
    }
    fclose (saida_txt);
    printf ("\n");
    return;
}

//FUNÇÕES REFERENTES AOS COMANDOS DO ARQUIVO .QRY

void caso_q_pergunta (Parametros* par)
{
    double w, h, x, y;
    char* aux;
    Lista quadras;
    Lista hidrantes;
    Lista semaforos;
    Lista radiobases;
    Anotacao anot;
    aux = (char*) calloc (155, sizeof (char));
    strcpy (aux, par->comando);
    par->comando += 3;
    sscanf (par->comando, "%lf %lf %lf %lf", &x, &y, &w, &h);
    insere_fila (par->resultado, aux);
    anot = cria_anotacao (w, h, x, y, "");
    insere_fila (par->anotacoes, (Valor*) anot);
    quadras = get_todos_arvore (par->tree_quadras);
    hidrantes = get_todos_arvore (par->tree_hidrantes);
    semaforos = get_todos_arvore (par->tree_semaforos);
    radiobases = get_todos_arvore (par->tree_radiobases);
    reporta_dentro_retangulo (par->resultado, quadras, hidrantes, semaforos, radiobases, x, y, w, h);
    insere_fila (par->resultado, "\n");
    return;
}

void caso_Q_pergunta (Parametros* par)
{
    double r, x, y;
    char* aux;
    Lista quadras;
    Lista hidrantes;
    Lista semaforos;
    Lista radiobases;
    Anotacao* anot;
    aux = (char*) calloc (155, sizeof (char));
    strcpy (aux,par->comando);
    par->comando += 3;
    sscanf (par->comando, "%lf %lf %lf", &r, &x, &y);
    insere_fila (par->resultado, aux);
    anot = cria_anotacao (r, 0, x, y, "");
    insere_fila (par->anotacoes, (Valor*) anot);
    quadras = get_todos_arvore (par->tree_quadras);
    hidrantes = get_todos_arvore (par->tree_hidrantes);
    semaforos = get_todos_arvore (par->tree_semaforos);
    radiobases = get_todos_arvore (par->tree_radiobases);
    reporta_dentro_circulo (par->resultado, quadras, hidrantes, semaforos, radiobases, x, y, r);
    insere_fila (par->resultado, "\n");
    return;
}

void caso_dq (Parametros* par)
{
    double x, y, w, h;
    char* aux;
    Lista quadras;
    Anotacao anot;
    aux = (char*) calloc (155, sizeof (char));
    strcpy (aux, par->comando);
    par->comando += 3;
    sscanf (par->comando, "%lf %lf %lf %lf", &x, &y, &w, &h);
    insere_fila (par->resultado, aux);
    anot = cria_anotacao (w, h, x, y, "");
    insere_fila (par->anotacoes, (Valor*) anot);
    quadras = get_todos_arvore (par->tree_quadras);
    delete_quadra_dentro_retangulo (par->resultado, quadras, x, y, w, h);
    insere_fila (par->resultado, "\n");
    return;
}

void caso_dle (Parametros* par)
{
    double w, h, x, y;
    char* aux;
    char* tipo;
    Lista hidrantes;
    Lista semaforos;
    Lista radiobases;
    Anotacao anot;
    aux = (char*) calloc (155, sizeof (char));
    tipo = (char*) calloc (55, sizeof (char));
    strcpy (aux, par->comando);
    par->comando += 4;
    sscanf (par->comando, "%s %lf %lf %lf %lf", tipo, &x, &y, &w, &h);
    insere_fila (par->resultado, aux);
    anot = cria_anotacao (w, h, x, y, "");
    insere_fila (par->anotacoes, (Valor*) anot);
    hidrantes = get_todos_arvore (par->tree_hidrantes);
    semaforos = get_todos_arvore (par->tree_semaforos);
    radiobases = get_todos_arvore (par->tree_radiobases);
    delete_equipamento_dentro_retangulo (par->resultado, tipo, hidrantes, semaforos, radiobases, x, y, w, h);
    insere_fila (par->resultado, "\n");
    return;
}

void caso_Dq (Parametros* par)
{
    double r, x, y;
    char* aux;
    Lista quadras;
    Anotacao* anot;
    aux = (char*) calloc (155, sizeof (char));
    strcpy (aux, par->comando);
    par->comando += 3;
    sscanf (par->comando, "%lf %lf %lf", &r, &x, &y);
    insere_fila (par->resultado, aux);
    anot = cria_anotacao (r, 0, x, y, "");
    insere_fila (par->anotacoes, (Valor*) anot);
    quadras = get_todos_arvore (par->tree_quadras);
    delete_quadra_dentro_circulo (par->resultado, quadras, x, y, r);
    insere_fila (par->resultado, "\n");
    return;
}

void caso_Dle (Parametros* par)
{
    double r, x, y;
    char* aux;
    char* tipo;
    Lista hidrantes;
    Lista semaforos;
    Lista radiobases;
    Anotacao* anot;
    aux = (char*) calloc (155, sizeof (char));
    tipo = (char*) calloc (55, sizeof (char));
    strcpy (aux, par->comando);
    par->comando += 4;
    sscanf (par->comando, "%s %lf %lf %lf", tipo, &r, &x, &y);
    insere_fila (par->resultado, aux);
    anot = cria_anotacao (r, 0, x, y, "");
    insere_fila (par->anotacoes, (Valor*) anot);
    hidrantes = get_todos_arvore (par->tree_hidrantes);
    semaforos = get_todos_arvore (par->tree_semaforos);
    radiobases = get_todos_arvore (par->tree_radiobases);
    delete_equipamento_dentro_circulo (par->resultado, tipo, hidrantes, semaforos, radiobases, x, y, r);
    insere_fila (par->resultado, "\n");
    return;
}

void caso_cc (Parametros* par)
{
    char* aux;
    char* cor_borda;
    char* cor_preenche;
    Lista quadras;
    Lista hidrantes;
    Lista semaforos;
    Lista radiobases;
    aux = (char*) calloc (155, sizeof (char));
    cor_borda = (char*) calloc (55, sizeof (char));
    cor_preenche = (char*) calloc (55, sizeof (char));
    sscanf (par->comando, "%s %s %s", aux, cor_borda, cor_preenche);
    quadras = get_todos_arvore (par->tree_quadras);
    hidrantes = get_todos_arvore (par->tree_hidrantes);
    semaforos = get_todos_arvore (par->tree_semaforos);
    radiobases = get_todos_arvore (par->tree_radiobases);
    void* primeiro;
    Quadra* compare;
    primeiro = get_primeiro_lista (quadras);
    do
    {
        compare = get_valor_lista (quadras, primeiro);
        if (!strcmp (get_cep_quadra (compare), aux))
        {
            compare = muda_cor_quadra (compare, cor_borda, cor_preenche);
            break;
        }
        primeiro = get_proximo_lista (quadras, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (hidrantes);
    do
    {
        compare = get_valor_lista (hidrantes, primeiro);
        if (!strcmp(get_id_hidrante (compare), aux))
        {
            compare = muda_cor_hidrante (compare, cor_borda, cor_preenche);
            break;
        }
        primeiro = get_proximo_lista (hidrantes, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (semaforos);
    do
    {
        compare = get_valor_lista (semaforos, primeiro);
        if (!strcmp (get_id_semaforo (compare), aux))
        {
            compare = muda_cor_semaforo (compare, cor_borda, cor_preenche);
            break;
        }
        primeiro = get_proximo_lista (semaforos, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (radiobases);
    do
    {
        compare = get_valor_lista (radiobases, primeiro);
        if (!strcmp(get_id_radiobase (compare), aux))
        {
            compare = muda_cor_radiobase (compare, cor_borda, cor_preenche);
            break;
        }
        primeiro = get_proximo_lista (radiobases, primeiro);
    }
    while (primeiro != NULL);
    return;
}

void caso_crd_pergunta (Parametros* par)
{
    char* aux;
    Lista quadras;
    Lista hidrantes;
    Lista semaforos;
    Lista radiobases;
    quadras = get_todos_arvore (par->tree_quadras);
    hidrantes = get_todos_arvore (par->tree_hidrantes);
    semaforos = get_todos_arvore (par->tree_semaforos);
    radiobases = get_todos_arvore (par->tree_radiobases);
    insere_fila (par->resultado, par->comando);
    par->comando += 4;
    aux = (char*) calloc (155, sizeof (char));
    strcpy (aux, par->comando);
    void* primeiro;
    Quadra *compare;
    primeiro = get_primeiro_lista (quadras);
    do
    {
        if (primeiro == NULL)
        {
            continue;
        }
        compare = get_valor_lista (quadras, primeiro);
        if (!strcmp(get_cep_quadra (compare), aux))
        {
            escreve_crd_quadra (par->resultado, compare);
            break;
        }
        primeiro = get_proximo_lista (quadras, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (hidrantes);
    do
    {
        if (primeiro == NULL)
        {
            continue;
        }
        compare = get_valor_lista (hidrantes, primeiro);
        if (strcmp(get_id_hidrante(compare), aux) == 0)
        {
            escreve_crd_hidrante (par->resultado, compare);
            break;
        }
        primeiro = get_proximo_lista (hidrantes, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (semaforos);
    do
    {
        if (primeiro == NULL)
        {
            continue;
        }
        compare = get_valor_lista (semaforos, primeiro);
        if (strcmp(get_id_semaforo(compare), aux) == 0)
        {
            escreve_crd_semaforo (par->resultado, compare);
            break;
        }
        primeiro = get_proximo_lista (semaforos, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (radiobases);
    do
    {
        if (primeiro == NULL)
        {
            continue;
        }
        compare = get_valor_lista (radiobases, primeiro);
        if (!strcmp (get_id_radiobase (compare), aux))
        {
            escreve_crd_radiobase (par->resultado, compare);
            break;
        }
        primeiro = get_proximo_lista (radiobases, primeiro);
    }
    while (primeiro != NULL);
    return;
}

void caso_crb_pergunta (Parametros* par)
{
    double dist, distAux;
    char* string;
    char* saida;
    void* aux;
    void* auxR;
    void* auxB;
    Radiobase rbA;
    Radiobase rbB;
    Lista radiobases;
    string = (char*) calloc (155, sizeof (char));
    sscanf (par->comando, "%s", string);
    insere_fila (par->resultado, string);
    radiobases = get_todos_arvore (par->tree_radiobases);
    aux = get_primeiro_lista (radiobases);
    rbA = get_valor_lista (radiobases, aux);
    rbB = vizinho_proximo_arvore (par->tree_radiobases, rbA);
    dist = dist_arvore (par->tree_radiobases, rbA, rbB);
    do
    {
        auxR = get_valor_lista (radiobases, aux);
        if (auxR != NULL)
        {
            auxB = vizinho_proximo_arvore (par->tree_radiobases, auxR);
            distAux = dist_arvore (par->tree_radiobases, auxR, auxB);   
            if (distAux < dist && auxR != auxB)
            {
                dist = distAux;
                rbA = auxR;
                rbB = auxB;
            }
        }
        aux = get_proximo_lista (radiobases, aux);
    }
    while (aux != NULL);
    saida = (char*) calloc (155, sizeof (char));
    sprintf (saida, "\nRbs - ID = %s \nRbs - ID = %s \nDISTÂNCIA = %lf\n", get_id_radiobase (rbA), get_id_radiobase (rbB), dist);
    insere_fila (par->resultado, saida);
    Anotacao* anot;
    anot = cria_anotacao (10, 0, get_x_radiobase (rbA), get_y_radiobase (rbA), "");
    insere_fila (par->anotacoes, anot);
    anot = cria_anotacao (10, 0, get_x_radiobase (rbB), get_y_radiobase (rbB), "");
    insere_fila (par->anotacoes, anot);
    return;
}

void caso_m_pergunta (Parametros* par)
{
    char* aux;
    char* cep;
    char* relatorio;
    void* endereco;
    void* primeiro;
    void* morador;
    Lista enderecos;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 3;
    cep = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    sscanf (par->comando, "%s", cep);
    relatorio = (char*) calloc (555, sizeof (char));
    endereco = identificador_endereco_pessoa (cep);
    enderecos = get_lista_hashtable (par->hash_end_pessoas, endereco);
    primeiro = get_primeiro_lista (enderecos);
    do
    {
        morador = get_pessoa_endereco (get_valor_lista (enderecos, primeiro));
        relatorio = relatorio_endereco_pessoa (morador);
        insere_lista (par->resultado, relatorio);
        primeiro = get_proximo_lista (enderecos, primeiro);
    }
    while (primeiro != NULL);
    return;
}

void caso_mr_pergunta (Parametros* par)
{
    double w, h, x, y;
    char* aux;
    char* relatorio;
    void* primeiro;
    void* endereco;
    void* morador;
    void* percorre;
    Lista quadras;
    Lista report;
    Lista enderecos;
    Quadra quadra;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    relatorio = (char*) calloc (555, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 4;
    sscanf (par->comando, "%lf %lf %lf %lf", &w, &h, &x, &y);
    quadras = get_todos_arvore (par->tree_quadras);
    report = reporta_quadra_dentro_retangulo (quadras, w, h, x, y);
    primeiro = get_primeiro_lista (report);
    do
    {
        quadra = get_valor_lista (report, primeiro);
        endereco = identificador_endereco_pessoa (get_cep_quadra (quadra));
        sprintf (relatorio, "\nQuad - CEP - %s", get_cep_quadra (quadra));
        insere_fila (par->resultado, relatorio);
        enderecos = get_lista_hashtable (par->hash_end_pessoas, endereco);
        percorre = get_primeiro_lista (enderecos);
        do
        {
            morador = get_pessoa_endereco (get_valor_lista (enderecos, percorre));
            relatorio = relatorio_endereco_pessoa (morador);
            insere_lista (par->resultado, relatorio);
            percorre = get_proximo_lista (enderecos, percorre);
        }
        while (percorre != NULL);
    }
    while (primeiro != NULL);
    return;
}

void caso_dm_pergunta (Parametros* par)
{
    double* coord;
    char* aux;
    char* result;
    char* cpf;
    Pessoa* pessoa;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof(char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 4;
    cpf = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    sscanf (par->comando, "%s", cpf);
    pessoa = get_hashtable (par->hash_pessoas, cpf);
    result = (char*) calloc (555, sizeof (char));
    result = relatorio_endereco_pessoa (pessoa);
    coord = get_xy_pessoa (pessoa, par);
    insere_fila (par->resultado, result);
    sprintf (result, "\nX - %lf Y - %lf", *coord, *(coord + 1));
    insere_fila (par->resultado, result);
    return;
}

void caso_de_pergunta (Parametros* par)
{
    double* coord;
    char* aux;
    char* result;
    char* cnpj;
    Comercio* comercio;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof(char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 4;
    cnpj = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    sscanf (par->comando, "%s", cnpj);
    comercio = get_hashtable (par->hash_comercios, cnpj);
    result = (char*) calloc (555, sizeof (char));
    result = relatorio_comercio (comercio);
    coord = get_xy_comercio (comercio, par);
    insere_fila (par->resultado, result);
    sprintf (result, "\nX - %lf Y - %lf", *coord, *(coord + 1));
    insere_fila (par->resultado, result);
    return;
}

void caso_rip (Parametros* par)
{
    double* coord;
    char* aux;
    char* cpf;
    char* relatorio;
    Pessoa* pessoa;
    Endereco* end;
    Anotacao anot;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 4;
    cpf = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    sscanf (par->comando, "%s", cpf);
    pessoa = get_hashtable (par->hash_pessoas, cpf);
    relatorio = (char*) calloc (555, sizeof (char));
    relatorio = relatorio_morte_pessoa (pessoa);
    coord = get_xy_pessoa (pessoa, par);
    insere_fila (par->resultado, relatorio);
    anot = cria_anotacao (0, 10, *coord, *(coord + 1), "");
    insere_fila (par->anotacoes, relatorio);
    end = get_endereco_pessoa (pessoa);
    remove_hashtable (par->hash_end_pessoas, end);
    remove_hashtable (par->hash_pessoas, pessoa);
    free_pessoa (pessoa);
    return;
}

void caso_ecq_pergunta (Parametros* par)
{
    char* aux;
    char* cep;
    char* relatorio;
    void* endereco;
    void* primeiro;
    void* comercio;
    Lista enderecos;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 5;
    cep = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    sscanf (par->comando, "%s", cep);
    relatorio = (char*) calloc (555, sizeof (char));
    endereco = identificador_endereco_comercio (cep);
    enderecos = get_lista_hashtable (par->hash_end_comercios, endereco);
    primeiro = get_primeiro_lista (enderecos);
    do
    {
        comercio = get_comercio_endereco (get_valor_lista (enderecos, primeiro));
        sprintf (relatorio, "\nCNPJ: %s", get_cnpj_comercio (comercio));
        insere_fila (par->resultado, relatorio);
        relatorio = relatorio_comercio (comercio);
        insere_lista (par->resultado, relatorio);
        primeiro = get_proximo_lista (enderecos, primeiro);
    }
    while (primeiro != NULL);
    return;
}

void caso_ecr_pergunta (Parametros* par)
{
    double w, h, x, y;
    char* aux;
    char* tipo;
    char* relatorio;
    void* primeiro;
    void* endereco;
    void* comercio;
    void* percorre;
    Lista quadras;
    Lista report;
    Lista enderecos;
    Quadra quadra;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    relatorio = (char*) calloc (555, sizeof (char));
    tipo = (char*) calloc (55, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 5;
    sscanf (par->comando, "%s %lf %lf %lf %lf", tipo, &w, &h, &x, &y);
    quadras = get_todos_arvore (par->tree_quadras);
    report = reporta_quadra_dentro_retangulo (quadras, w, h, x, y);
    primeiro = get_primeiro_lista (report);
    do
    {
        quadra = get_valor_lista (report, primeiro);
        endereco = identificador_endereco_comercio (get_cep_quadra (quadra));
        sprintf (relatorio, "\nQuad - CEP - %s", get_cep_quadra (quadra));
        insere_fila (par->resultado, relatorio);
        enderecos = get_lista_hashtable (par->hash_end_comercios, endereco);
        percorre = get_primeiro_lista (enderecos);
        do
        {
            comercio = get_comercio_endereco (get_valor_lista (enderecos, percorre));
            if (!strcmp (get_tipo_comercio (comercio), tipo))
            {
                relatorio = relatorio_comercio (comercio);
                insere_lista (par->resultado, relatorio);
            }
            percorre = get_proximo_lista (enderecos, percorre);
        }
        while (percorre != NULL);
    }
    while (primeiro != NULL);
    return;
}

void caso_tecq_pergunta (Parametros* par)
{
    char* aux;
    char* cep;
    char* relatorio;
    char* tipo;
    void* endereco;
    void* primeiro;
    void* auxA;
    Comercio* comercio;
    Quadra* quadra;
    Endereco* end;
    Lista comercios;
    Lista enderecos;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 6;
    cep = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (cep, par->comando);
    relatorio = (char*) calloc (155, sizeof (char));
    quadra = get_hashtable (par->hash_quadras, cep);
    if (quadra == NULL)
    {
        sprintf (relatorio, "\nERRO: QUADRA NÃO ENCONTRADA!");
        insere_lista (par->resultado, relatorio);
        printf ("\nERRO: QUADRA NÃO ENCONTRADA!");
        free (quadra);
        return;
    }
    free (quadra);
    end = identificador_endereco_comercio (cep);
    enderecos = get_lista_hashtable (par->hash_end_comercios, end);
    comercios = cria_lista ();
    primeiro = get_primeiro_lista (enderecos);
    do
    {
        auxA = get_valor_lista (enderecos, primeiro);
        insere_lista (comercios, get_comercio_endereco (auxA));
        primeiro = get_proximo_lista (enderecos, primeiro);
    }
    while (primeiro != NULL);
    sprintf (relatorio, "\nQuad - CEP - %s", cep);
    insere_fila (par->resultado, relatorio);
    relatorio = imprime_tipos_comercios_quadra (comercios);
    insere_fila (par->resultado, relatorio);
    return;
}

void caso_tecr_pergunta (Parametros* par)
{
    double w, h, x, y;
    char* aux;
    char* relatorio;
    void* primeiro;
    void* endereco;
    void* comercio;
    void* percorre;
    void* auxA;
    Lista quadras;
    Lista report;
    Lista enderecos;
    Lista comercios;
    Quadra quadra;
    Endereco* end;
    Comercio* com;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    relatorio = (char*) calloc (555, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 6;
    sscanf (par->comando, "%lf %lf %lf %lf", &w, &h, &x, &y);
    quadras = get_todos_arvore (par->tree_quadras);
    report = reporta_quadra_dentro_retangulo (quadras, w, h, x, y);
    primeiro = get_primeiro_lista (report);
    do
    {
        sprintf (relatorio, "\nQuad - CEP - %s", get_cep_quadra (get_valor_lista (report, primeiro)));
        insere_fila (par->resultado, relatorio);
        end = identificador_endereco_comercio (get_cep_quadra (get_valor_lista (report, primeiro)));
        enderecos = get_lista_hashtable (par->hash_end_comercios, end);
        comercios = cria_lista ();
        percorre = get_primeiro_lista (enderecos);
        do
        {
            auxA = get_valor_lista (enderecos, percorre);
            insere_lista (comercios, get_comercio_endereco (auxA));
            percorre = get_proximo_lista (enderecos, percorre);
        }
        while (percorre != NULL);
        relatorio = imprime_tipos_quadra (comercios);
        insere_fila (par->resultado, relatorio);
        primeiro = get_proximo_lista (report, primeiro);
    }
    while (primeiro != NULL);
    return;
}

void caso_hmpe_pergunta (Parametros* par)
{
    double dist;
    double* coord;
    char* aux;
    char* cep;
    char* face;
    char* num;
    char* saida;
    Hidrante hidA;
    Hidrante hidB;
    Pessoa pes;
    Anotacao* anot;
    aux = (char*) calloc (55, sizeof (char));
    strcpy (aux, par->comando);
    par->comando += 6;
    sscanf (par->comando, "%s %s %s", cep, face, num);
    pes = cria_pessoa ("-1", "", "", "", "");
    set_endereco_pessoa (pes, cep, face, num, "");
    coord = get_xy_pessoa (pes, par);
    free_pessoa (pes);
    hidA = cria_hidrante (cep, 0, *coord, *(coord + 1), "", "");
    hidB = vizinho_proximo_arvore (par->tree_hidrantes, hidA);
    dist = dist_arvore (par->tree_hidrantes, hidA, hidB);
    saida = (char*) calloc (155, sizeof (char));
    sprintf (saida, "\nEndereço - CEP = %s Face = %s Num = %s\nHid - ID = %s \nDISTÂNCIA = %lf\n", cep, face, num, get_id_hidrante (hidB), dist);
    insere_fila (par->resultado, saida);
    anot = cria_anotacao (get_x_hidrante (hidA), get_y_hidrante (hidA), get_x_hidrante (hidB), get_y_hidrante (hidB), "hmp");
    insere_fila (par->anotacoes, anot);
    return;
}
void caso_hmp_pergunta (Parametros* par)
{
    double dist, r, x, y;
    char* aux;
    char* id;
    char* saida;
    Radiobase rb;
    Hidrante hidA;
    Hidrante hidB;
    Anotacao* anot;
    aux = (char*) calloc (55, sizeof (char));
    strcpy (aux, par->comando);
    par->comando += 5;
    sscanf (par->comando, "%s", id);
    rb = get_valor_arvore (par->hash_radiobases, id);
    if (rb == NULL)
    {
        sprintf (aux, "\nRÁDIOBASE NÃO ENCONTRADA!");
        insere_fila (par->resultado, aux);
        printf ("\nERRO: RADIOBASE NAO ENCONTRADA!");
        return;
    }
    id = get_id_radiobase (rb);
    r = get_r_radiobase (rb);
    x = get_x_radiobase (rb);
    y = get_y_radiobase (rb);
    hidA = cria_hidrante (id, r, x, y, "", "");
    hidB = vizinho_proximo_arvore (par->tree_hidrantes, hidA);
    dist = dist_arvore (par->tree_hidrantes, hidA, hidB);
    saida = (char*) calloc (155, sizeof (char));
    sprintf (saida, "\nRbs - ID = %s \nHid - ID = %s \nDISTÂNCIA = %lf\n", get_id_hidrante (hidA), get_id_hidrante (hidB), dist);
    insere_fila (par->resultado, saida);
    anot = cria_anotacao (get_x_hidrante (hidA), get_y_hidrante (hidA), get_x_hidrante (hidB), get_y_hidrante (hidB), "hmp");
    insere_fila (par->anotacoes, anot);
    return;
}
void caso_fec (Parametros* par)
{
    double* coord;
    char* aux;
    char* cnpj;
    char* relatorio;
    Comercio* comercio;
    Endereco* end;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 4;
    cnpj = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    sscanf (par->comando, "%s", cnpj);
    comercio = get_hashtable (par->hash_comercios, cnpj);
    relatorio = (char*) calloc (555, sizeof (char));
    relatorio = relatorio_comercio (comercio);
    coord = get_xy_comercio (comercio, par);
    insere_fila (par->resultado, relatorio);
    end = get_endereco_comercio (comercio);
    remove_hashtable (par->hash_end_comercios, end);
    remove_hashtable (par->hash_comercios, comercio);
    free_comercio (comercio);
    return;
}
void caso_mud (Parametros* par)
{
    double* coordAntiga;
    double* coordNova;
    char* aux;
    char* cpf;
    char* cep;
    char* face;
    char* num;
    char* comp;
    char* linha;
    Pessoa* pes;
    Endereco* endAntigo;
    Endereco* endNovo;
    Anotacao* anot;
    aux = (char*) calloc (55, sizeof (char));
    linha = (char*) calloc (55, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 4;
    sscanf (par->comando, "%s %s %s %s %s", cpf, cep, face, num, comp);
    pes = get_hashtable (par->hash_pessoas, cpf);
    endAntigo = get_endereco_pessoa (pes);
    coordAntiga = get_xy_pessoa (pes, par);
    remove_hashtable (par->hash_end_pessoas, endAntigo);
    endNovo = set_endereco_pessoa (pes, cep, face, num, comp);
    coordNova = get_xy_pessoa (pes, par); 
    insere_hashtable (par->hash_end_pessoas, endNovo);
    aux = relatorio_mud_pessoa (pes, endAntigo, endNovo);
    insere_fila (par->resultado, aux);
    anot = cria_anotacao (*coordAntiga, *(coordAntiga + 1), *coordNova, *(coordNova + 1), "mud");
    insere_fila (par->anotacoes, anot);
    return;
}

void caso_mudec (Parametros* par)
{
    double* coordAntiga;
    double* coordNova;
    char* aux;
    char* cnpj;
    char* cep;
    char* face;
    char* num;
    char* linha;
    Comercio* com;
    Endereco* endAntigo;
    Endereco* endNovo;
    Anotacao* anot;
    aux = (char*) calloc (55, sizeof (char));
    linha = (char*) calloc (55, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 4;
    sscanf (par->comando, "%s %s %s %s", cnpj, cep, face, num);
    com = get_hashtable (par->hash_comercios, cnpj);
    endAntigo = get_endereco_comercio (com);
    coordAntiga = get_xy_comercio (com, par);
    remove_hashtable (par->hash_end_comercios, endAntigo);
    endNovo = set_endereco_comercio (com, cep, face, num);
    coordNova = get_xy_comercio (com, par); 
    insere_hashtable (par->hash_end_comercios, endNovo);
    aux = relatorio_mud_comercio (com, endAntigo, endNovo);
    insere_fila (par->resultado, aux);
    anot = cria_anotacao (*coordAntiga, *(coordAntiga + 1), *coordNova, *(coordNova + 1), "mudec");
    insere_fila (par->anotacoes, linha);
    return;
}

void caso_dpr (Parametros* par)
{
    char* aux;
    double x, y, w, h;
    aux = (char*) calloc (55, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 4;
    sscanf (par->comando, "%lf %lf %lf %lf", x, y, w, h);
    return;
}

//COMANDOS REFERENTES AO ARQUIVO .EC

void caso_t_ec (Parametros* par)
{
    char* cod;
    char* info;
    cod = (char*) calloc (155, sizeof (char));
    info = (char*) calloc (155, sizeof (char));
    sscanf (par->comando, "%s %s", cod, info);
    void* tipo = cria_tipo_comercio (cod, info);
    insere_hashtable (par->hash_tipos, tipo);
    return;
}

void caso_e (Parametros* par)
{
    char* cnpj;
    char* cod;
    char* cep;
    char* face;
    char* num;
    char* nome;
    void* comercio;
    void* end;
    cnpj = (char*) calloc (155, sizeof (char));
    cod = (char*) calloc (155, sizeof (char));
    cep = (char*) calloc (155, sizeof (char));
    face = (char*) calloc (155, sizeof (char));
    num = (char*) calloc (155, sizeof (char));
    nome = (char*) calloc (155, sizeof (char));
    sscanf (par->comando, "%s %s %s %s %s %s", cnpj, cod, cep, face, num, nome);
    comercio = cria_comercio (cnpj, cod, cep, face, num, nome);
    insere_hashtable (par->hash_comercios, comercio);
    end = get_endereco_comercio (comercio);
    insere_hashtable (par->hash_end_comercios, end);
    return;
}

//COMANDOS REFERENTES AO ARQUIVO .PM

void caso_p (Parametros* par)
{
    char* cpf;
    char* nome;
    char* sobrenome;
    char* sexo;
    char* nascimento;
    void* pessoa;
    cpf = (char*) calloc (155, sizeof (char));
    nome = (char*) calloc (155, sizeof (char));
    sobrenome = (char*) calloc (155, sizeof (char));
    sexo = (char*) calloc (155, sizeof (char));
    nascimento = (char*) calloc (155, sizeof (char));
    sscanf (par->comando, "%s %s %s %s %s", cpf, nome, sobrenome, sexo, nascimento);
    pessoa = cria_pessoa (cpf, nome, sobrenome, sexo, nascimento);
    insere_hashtable (par->hash_pessoas, pessoa);
    return;
}

void caso_m (Parametros* par)
{
    char* cpf;
    char* cep;
    char* face;
    char* num;
    char* comp;
    void* end;
    void* pessoa;
    cpf = (char*) calloc (155, sizeof (char));
    cep = (char*) calloc (155, sizeof (char));
    face = (char*) calloc (155, sizeof (char));
    num = (char*) calloc (155, sizeof (char));
    comp = (char*) calloc (155, sizeof (char));
    sscanf (par->comando, "%s %s %s %s %s", cpf, cep, face, num, comp);
    pessoa = get_hashtable (par->hash_pessoas, cpf);
    set_endereco_pessoa (pessoa, cep, face, num, comp);
    insere_hashtable (par->hash_end_pessoas, end);
    return;
}
