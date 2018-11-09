#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../Parâmetros/parametros.h"
#include "../Funções/funçoes.h"
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
#include "../Estruturas/Merge/mergesort.h"
#include "../Funções/parproximo.h"

#define C "circulo"
#define R "retangulo"
#define A "anotaçao"

void executa_comando (void* p)
{
    Parametros* par;
    par = (Parametros*) p;

    //COMANDOS DO ARQUIVO .GEO

    //ALTERA O NÚMERO MÁXIMO DE FIGURAS
    if (!strcmp (*(par->comando_vetor), "nx"))
    {
        caso_nx (par);
    }
    //CRIAR UM CÍRCULO
    if (!strcmp (*(par->comando_vetor), "c"))
    {
        caso_c (par);
    }
    //CRIAR UM RETÂNGULO
    if (!strcmp (*(par->comando_vetor), "r"))
    {
        caso_r (par);
        return;
    }
    //CRIA UMA QUADRA
    if (!strcmp (*(par->comando_vetor), "q"))
    {
        caso_q (par);
        return;
    }
    //CRIA UM HIDRANTE
    if (!strcmp (*(par->comando_vetor), "h"))
    {
        caso_h (par);
        return;
    }
    //CRIA UM SEMÁFORO
    if (!strcmp (*(par->comando_vetor), "s"))
    {
        caso_s (par);
        return;
    }
    //CRIA UMA RADIOBASE
    if (!strcmp (*(par->comando_vetor), "t"))
    {
        caso_t_geo (par);
        return;
    }
    //ALTERA AS CORES DA BORDA E DO PREENCHIMENDO DA QUADRA
    if (!strcmp (*(par->comando_vetor), "cq"))
    {
        caso_cq (par);
        return;
    }
    //ALTERA AS CORES DA BORDA E DO PREENCHIMENDO DO HIDRANTE
    if (!strcmp (*(par->comando_vetor), "ch"))
    {
        caso_ch (par);
        return;
    }
    //ALTERA AS CORES DA BORDA E DO PREENCHIMENDO DA RADIO-BASE
    if (!strcmp (*(par->comando_vetor), "ct"))
    {
        caso_ct (par);
        return;
    }
    //ALTERA AS CORES DA BORDA E DO PREENCHIMENDO DO SEMAFORO
    if (!strcmp (*(par->comando_vetor), "cs"))
    {
        caso_cs (par);
        return;
    }
    //VERIFICAR SE DUAS FIGURAS SE SOBREPOEM
    if (!strcmp (*(par->comando_vetor), "o"))
    {
        caso_o (par);
        return;
    }
    //VERIFICAR SE UM PONTO É INTERNO A FIGURA
    if (!strcmp (*(par->comando_vetor), "i"))
    {
        caso_i (par);
        return;
    }
    //CALCULAR A DISTÂNCIA ENTRE OS CENTROS DE MASSA DE DUAS FIGURAS
    if (!strcmp (*(par->comando_vetor), "d"))
    {
        caso_d (par);
        return;
    }
    //CRIA O ARQUIVO SVG COM O SUFIXO
    if (!strcmp (*(par->comando_vetor), "a"))
    {
        caso_a (par);
        return;
    }
    //FINALIZA O ARQUIVO
    if (!strcmp (*(par->comando_vetor), "#"))
    {
        caso_hashtag (par);
        return;
    }

    //COMANDOS DO ARQUIVO .EC
    
    //DEFINE O TIPO DO ESTABELECIMENTO COMERCIAL
    if (!strcmp (*(par->comando_vetor), "t"))
    {
        caso_t_ec (par);
        return;
    }
    //INSERE UM NOVO ESTABELECIMENTO COMERCIAL DE UM DETERMINADO TIPO
    if (!strcmp (*(par->comando_vetor), "e"))
    {
        caso_e (par);
        return;
    }

    //COMANDOS DO ARQUIVO .PM
    //INSERE UMA PESSOA IDENTIFICADA POR UM CPF
    if (!strcmp (*(par->comando_vetor), "p"))
    {
        caso_p (par);
        return;
    }
    //INFORMA O ENDEREÇO ONDE UMA PESSOA MORA
    if (!strcmp (*(par->comando_vetor), "m"))
    {
        caso_m (par);
        return;
    }
    
    //COMANDOS DO ARQUIVOS .QRY 

    //REPORTA O QUE ESTIVER DENTRO DO RETÂNGULO ESPECIFICADO
    if (!strcmp (*(par->comando_vetor), "q?"))
    {
        caso_q_pergunta (par);
        return;
    }
    //REPORTA O QUE ESTIVER DENTRO DO CÍRCULO ESPECIFICADO
    if (!strcmp (*(par->comando_vetor), "Q?"))
    {
        caso_Q_pergunta (par);
        return;
    }
    //DELETA TODAS AS QUADRAS DENTRO DO RETÂNGULO ESPECIFICADO
    if (!strcmp (*(par->comando_vetor), "dq"))
    {
        caso_dq (par);
        return;
    }
    //DELETA TODOS OS EQUIPAMENTOS DENTRO DO RETÂNGULO ESPECIFICADO
    if (!strcmp (*(par->comando_vetor), "dle"))
    {
        caso_dle (par);
        return;
    }
    //DELETA TODAS AS QUADRAS DENTRO DO CÍRCULO ESPECIFICADO
    if (!strcmp (*(par->comando_vetor), "Dq"))
    {
        caso_Dq (par);
        return;
    }
    //DELETA TODOS OS EQUIPAMENTOS DENTRO DO CÍRCULO ESPECIFICADO
    if (!strcmp (*(par->comando_vetor), "Dle"))
    {
        caso_Dle (par);
        return;
    }
    //MUDA AS CORES DA QUADRA IDENTIFICADA PELO CEP
    if (!strcmp (*(par->comando_vetor), "cc"))
    {
        caso_cc (par);
        return;
    }
    //IMPRIME NO .TXT AS COORDENADAS DE UMA DETERMINADA QUADRA OU EQUIPAMENTO
    if (!strcmp (*(par->comando_vetor), "crd?"))
    {
        caso_crd_pergunta (par);
        return;
    }
    //DETERMINA AS RADIOBASES MAIS PRÓXIMAS
    if (!strcmp (*(par->comando_vetor), "crb?"))
    {
        caso_crb_pergunta (par);
        return;
    }
    //MORADORES DA QUADRA DEFINIDA PELO CEP
    if (!strcmp (*(par->comando_vetor), "m?"))
    {
        caso_m_pergunta (par);
        return;
    }
    //MORADORES DAS QUADRAS DENTRO DO RETÂNGULO
    if (!strcmp (*(par->comando_vetor), "mr?"))
    {
        caso_mr_pergunta (par);
        return;
    }
    //IMPRIME OS DADOS DO MORADOR IDENTIFICADO PELO CPF
    if (!strcmp (*(par->comando_vetor), "dm?"))
    {
        caso_dm_pergunta (par);
        return;
    }
    //IMPRIME OS DADOS DO ESTABELECIMENTO IDENTIFICADO PELO CNPJ
    if (!strcmp (*(par->comando_vetor), "de?"))
    {
        caso_de_pergunta (par);
        return;
    }
    //APAGA TODOS OS DADOS DE UMA PESSOA
    if (!strcmp (*(par->comando_vetor), "rip"))
    {
        caso_rip (par);
        return;
    }
    //LISTA OS ESTABELECIMENTOS DE UMA QUADRA
    if (!strcmp (*(par->comando_vetor), "ecq?"))
    {
        caso_ecq_pergunta (par);
        return;
    }
    //LISTA OS ESTABELECIMeNTOS DE UM DETERMINADO TIPO EM UM RETÂNGULO
    if (!strcmp (*(par->comando_vetor), "ecr?"))
    {
        caso_ecr_pergunta (par);
        return;
    }
    //LISTA OS TIPOS DE ESTABELECIMENTOS DE UMA QUADRA ESPECÍFICA
    if (!strcmp (*(par->comando_vetor), "tecq?"))
    {
        caso_tecq_pergunta (par);
        return;
    }
    //LISTA OS TIPOS DE ESTABELECIMENTOS COMERCIAIS EM UM RETÂNGULO
    if (!strcmp (*(par->comando_vetor), "tecr?"))
    {
        caso_tecr_pergunta (par);
        return;
    }
    //ENCONTRA O HIDRANTE MAIS PRÓXIMO À UM ENDEREÇO ESPECÍFICO
    if (!strcmp (*(par->comando_vetor), "hmpe?"))
    {
        caso_hmpe_pergunta (par);
        return;
    }
    //ENCONTRA O HIDRANTE MAIS PRÓXIMO À UMA RADIOBASE ESPECÍFICA
    if (!strcmp (*(par->comando_vetor), "hmp?"))
    {
        caso_hmp_pergunta (par);
        return;
    }
    //APAGA TODOS OS DADOS DE UM ESTABELECIMENTO
    if (!strcmp (*(par->comando_vetor), "fec"))
    {
        caso_fec (par);
        return;
    }
    //MUDA O ENDEREÇO DA PESSOA E TRAÇA UMA LINHA ENTRE O ENDEREÇO ANTIGO E O NOVO
    if (!strcmp (*(par->comando_vetor), "mud"))
    {
        caso_mud (par);
        return;
    }
    //MUDA O ESTABELECIMENTO DE ENDEREÇO E TRAÇA UMA LINHA ENTRE O ENDEREÇO ANTIGO E O NOVO
    if (!strcmp (*(par->comando_vetor), "mudec"))
    {
        caso_mudec (par);
        return;
    }
    //DESAPROPRIA UMA REGIÃO (DELETA TUDO DENTRO DELA, MAS A PESSOA NÃO MORRE, SÓ DEIXA DE MORAR LÁ)
    if (!strcmp (*(par->comando_vetor), "dpr"))
    {
        caso_dpr (par);
        return;
    }
}

//FUNÇÕES REFERENTES AOS COMANDOS DO ARQUIVO .GEO

void caso_nx (Parametros* par)
{
    sscanf (*(par->comando_vetor + 1), "%ld", par->max_figuras);
    return;
}
void caso_c (Parametros* par)
{
    int id;
    double r, x, y;
    char* radiobase1;
    char* radiobase2;
    void* fig;
    Item it;
    if (par->contador_figuras >= par->max_figuras)
    {
        printf ("\nERRO: LIMITE DE FIGURAS ATINGIDO!");
        return;
    }
    sscanf (*(par->comando_vetor + 1), "%d", id);
    sscanf (*(par->comando_vetor + 2), "%s", radiobase1);
    sscanf (*(par->comando_vetor + 3), "%s", radiobase2);
    sscanf (*(par->comando_vetor + 4), "%ld", r);
    sscanf (*(par->comando_vetor + 5), "%ld", x);
    sscanf (*(par->comando_vetor + 6), "%ld", y);
    fig = cria_circulo (id, radiobase1, radiobase2, r, x, y);
    it = cria_item (fig, C);
    par->figuras[par->contador_figuras] = it;
    par->contador_figuras++;
    return;
}
void caso_r (Parametros* par)
{
    int id;
    double w, h, x, y;
    char* radiobase1;
    char* radiobase2;
    void* fig;
    Item it;
    if (par->contador_figuras >= par->max_figuras)
    {
        printf ("\nERRO: LIMITE DE FIGURAS ATINGIDO!");
        return;
    }
    
    sscanf (*(par->comando_vetor + 1), "%d", id);
    sscanf (*(par->comando_vetor + 2), "%s", radiobase1);
    sscanf (*(par->comando_vetor + 3), "%s", radiobase2);
    sscanf (*(par->comando_vetor + 4), "%ld", w);
    sscanf (*(par->comando_vetor + 5), "%ld", h);
    sscanf (*(par->comando_vetor + 6), "%ld", x);
    sscanf (*(par->comando_vetor + 7), "%ld", y);
    fig = cria_retangulo (id, radiobase1, radiobase2, w, h, x, y);
    it = cria_item (fig, R);
    par->figuras[par->contador_figuras] = it;
    par->contador_figuras++;
    return;
}

void caso_q (Parametros* par)
{
    double w, h, x, y;
    char* cep;
    Quadra* quadra;
    sscanf (*(par->comando_vetor + 1), "%s", cep);
    sscanf (*(par->comando_vetor + 2), "%ld", x);
    sscanf (*(par->comando_vetor + 3), "%ld", y);
    sscanf (*(par->comando_vetor + 4), "%ld", w);
    sscanf (*(par->comando_vetor + 5), "%ld", h);
    quadra = cria_quadra (cep, x, y, w, h, par->cor_borda_quadra, par->cor_preenche_quadra);
    //REMOVER APÓS TESTES
    insere_lista (par->quadras, quadra);
    //insere_arvore (par->tree_quadras, quadra);
    //insere_hash ();
    return;
}

void caso_h (Parametros* par)
{
    int id;
    double x, y;
    Hidrante* hidrante;
    sscanf (*(par->comando_vetor + 1), "%d", id);
    sscanf (*(par->comando_vetor + 2), "%ld", x);
    sscanf (*(par->comando_vetor + 3), "%ld", y);
    hidrante = create_hidrante (id, 5, x, y, par->cor_borda_hidrante, par->cor_preenche_hidrante);
    //REMOVER APÓS TESTES
    insere_lista (par->hidrantes, hidrante);
    //insere_arvore (par->tree_hidrantes, hidrante);
    //insere_hash ();
    return;
}

void caso_s (Parametros* par)
{
    int id;
    double x, y;
    Semaforo* semaforo;
    sscanf (*(par->comando_vetor + 1), "%d", id);
    sscanf (*(par->comando_vetor + 2), "%ld", x);
    sscanf (*(par->comando_vetor + 3), "%ld", y);
    semaforo = cria_semaforo(id, 5, x, y, par->cor_borda_semaforo, par->cor_preenche_semaforo);
    //REMOVER APÓS TESTES
    insere_lista (par->semaforos, semaforo);
    //insere_arvore (par->tree_semaforos, semaforo);
    //insere_hash ();
    return;
    
}

void caso_t_geo (Parametros* par)
{
    int id;
    double x, y;
    Radiobase* radiobase;
    sscanf (*(par->comando_vetor + 1), "%d", id);
    sscanf (*(par->comando_vetor + 2), "%ld", x);
    sscanf (*(par->comando_vetor + 3), "%ld", y);
    radiobase = cria_radiobase (id, 5, x, y, par->cor_borda_radiobase, par->cor_preenche_radiobase);
    //REMOVER APÓS TESTES
    insere_lista (par->radiobases, radiobase);
    //insere_arvore (par->tree_radiobases, radiobase);
    //insere_hash ();
    return;
}

void caso_cq (Parametros* par)
{
    sscanf (*(par->comando_vetor + 1), "%s", par->cor_borda_quadra);
    sscanf (*(par->comando_vetor + 2), "%s", par->cor_preenche_quadra);
    return;
}

void caso_ch (Parametros* par)
{
    sscanf (*(par->comando_vetor + 1), "%s", par->cor_borda_hidrante);
    sscanf (*(par->comando_vetor + 2), "%s", par->cor_preenche_hidrante);
    return;
}

void caso_ct (Parametros* par)
{
    sscanf (*(par->comando_vetor + 1), "%s", par->cor_borda_radiobase);
    sscanf (*(par->comando_vetor + 2), "%s", par->cor_preenche_radiobase);
    return;
}

void caso_cs (Parametros* par)
{
    sscanf (*(par->comando_vetor + 1), "%s", par->cor_borda_semaforo);
    sscanf (*(par->comando_vetor + 2), "%s", par->cor_preenche_semaforo);
    return;
}

void caso_o (Parametros* par)
{
    double* centro1;
    double* centro2;
    double valor1, valor2, valor3, valor4, dist;
    int dentro, id1, id2, i;
    char* string;
    Item fig1 = NULL;
    Item fig2 = NULL;
    Anotaçao anotacao;
    id1 = *(par->comando_vetor + 1);
    id2 = *(par->comando_vetor + 2);
    string = (char*) calloc (strlen(par->comando_vetor) + 1 + strlen(par->comando_vetor + 1) + 1 + strlen(par->comando_vetor + 2) + 1, sizeof(char));
    strcpy (string, *(par->comando_vetor));
    strcat (string, " ");
    strcat (string, *(par->comando_vetor + 1));
    strcat (string, " ");
    strcat (string, *(par->comando_vetor + 2));
    insere_fila(par->resultado, string);
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
        insert_fila (par->resultado, (Valor*) "\nNAO\n");
        return;
    }
    else if (!strcmp (get_tipo_item ((fig1)), C))
    {
        valor1 = maior (get_x_retangulo (get_valor_item (fig2)), menor (get_x_circulo (get_valor_item (fig1)), get_x_retangulo (get_valor_item (fig2)) + get_w_retangulo(get_valor_item(fig2))));
        valor2 = maior (get_y_retangulo (get_valor_item (fig2)), menor (get_y_circulo (get_valor_item (fig1)), get_y_retangulo (get_valor_item (fig2)) + get_h_retangulo(get_valor_item(fig2))));
        dentro = dentro_borda_circle (get_valor_item (fig1), valor1, valor2);
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
    int id, x, y, i, in1, in2;
    char* string;
    string = (char*) calloc (strlen(par->comando_vetor) + 1 + strlen (par->comando_vetor + 1) + 1 + strlen (par->comando_vetor + 2) + 1 + strlen (par->comando_vetor + 3) + 1, sizeof(char));
    strcpy (string, *(par->comando_vetor));
    strcat (string, " ");
    strcat (string, *(par->comando_vetor + 1));
    strcat (string, " ");
    strcat (string, *(par->comando_vetor + 2));
    strcat (string, " ");
    strcat (string, *(par->comando_vetor + 3));
    insert_fila (par->resultado, string);
    Item fig = NULL;
    id = *(par->comando_vetor + 1);
    x = *(par->comando_vetor + 2);
    y = *(par->comando_vetor + 3);
    for (i=0; i<par->contador_figuras; i++)
    {
        if (fig != NULL)
        {
            break;
        }
        if (!strcmp (get_valor_item (par->figuras[i]), R))
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
            insert_fila(par->resultado, (Valor*) "\nSIM\n");
            return;
        }
        insert_fila(par->resultado, (Valor*) "\nNAO\n");
        return;
    }
}

void caso_d (Parametros* par)
{
    int i, id1, id2;
    char* string;
    char* result_string;
    double* centro1;
    double* centro2;
    double dx, dy, result;
    string = (char*) calloc (strlen (par->comando_vetor) + 1 + strlen (par->comando_vetor + 1) + 1 + strlen (par->comando_vetor + 2) + 1, sizeof (char));
    strcpy (string, *(par->comando_vetor));
    strcat (string, " ");
    strcat (string, *(par->comando_vetor + 1));
    strcat (string, " ");
    strcat (string, *(par->comando_vetor + 2));
    insere_fila (par->resultado, string);
    Item fig1 = NULL;
    Item fig2 = NULL;
    for (i=0; i<=par->contador_figuras; i++)
    {
        if (fig2 && fig2 != NULL)
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
    if ((fig1) == NULL)
    {
        if ((fig2) == NULL)
        {
            printf ("\nERRO: AS FIGURAS NAO FORAM ENCONTRADAS!");
            return;
        }
        printf ("\nERRO: UMA DAS FIGURAS NAO FORAM ENCONTRADAS!");
        return;
    }
    if ((fig2) == NULL)
    {
        printf ("\nERRO: UMA DAS FIGURAS NAO FORAM ENCONTRADAS!");
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
    int id, i;
    char* percorre;
    char* conteudo_svg;
    char* sufixo;
    char* corB;
    char* saida_svg;
    double* centro1;
    double* centro2;
    void* fila_linha;
    double x1, x2, y1, y2, dx, dy, result;
    Fila aux;
    FILE* saida_SVG;
    Item fig;
    id = *(par->comando_vetor + 1);
    fig = NULL;
    for (i=0; i<=par->contador_figuras; i++)
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
    sufixo = (char*) calloc (255, sizeof(char));
    strcpy (sufixo, *(par->comando_vetor + 2));
    par->caminho_SVG = (char*) calloc (255, sizeof(char));
    strcpy(par->caminho_SVG, par->diretorio_saida);
    strcat(par->caminho_SVG, "/");
    strcat (par->caminho_SVG, par->arquivo_entrada);
    percorre = par->caminho_SVG + strlen (par->caminho_SVG) - 1;
    while (*percorre != '.')
    {
        percorre--;
    }
    strcpy(percorre, "-");
    strcat(percorre, sufixo);
    strcat(percorre, ".svg");
    saida_svg = fopen (par->caminho_SVG, "w");
    free (par->caminho_SVG);
    fprintf (saida_svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"100000\" height=\"100000\">");
    for (i=0; i<=par->contador_figuras; i++)
    {
        if (par->figuras[i] == NULL)
        {
            continue;
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), R))
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
    }
    aux = cria_fila();
    while (!fila_vazia (par->anotacoes))
    {
        fila_linha = remove_fila (par->anotacoes);
        conteudo_svg = cria_anotacao_svg (fila_linha);
        fprintf (saida_svg, conteudo_svg);
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
        corB = get_radiobase1_retangulo (get_valor_item (fig));
    }
    else
    {
        centro1 = centro_massa_circulo (get_valor_item (fig));
        corB = get_radiobase1_circulo (get_valor_item (fig));
    }
    x1 = *centro1;
    y1 = *(centro1 + 1);
    free (centro1);
    for (i=0; i<=par->contador_figuras; i++)
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
        fprintf (saida_svg, "\n<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke=\"%s\" stroke-width=\"2\"/>", x1, y1, x2, y2, corB);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">%.2f</text>", (x1 + dx/2), (y1+dy/2), result);
    }
    //fprintf (saida_svg, "\n</svg>");
    //fclose (saida_svg);
    //return;
    void* primeiro;
    primeiro = get_primeiro_lista (par->quadras);
    do
    {
        if (get_valor_lista (par->quadras, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (par->quadras, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_quadra (get_valor_lista (par->quadras, primeiro));
        fprintf (saida_svg, conteudo_svg);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">%s</text>", get_x_quadra (get_valor_lista (par->quadras, primeiro)), get_y_quadra (get_valor_lista (par->quadras, primeiro)), get_cep_quadra (get_valor_lista (par->quadras, primeiro)));
        primeiro = get_proximo_lista (par->quadras, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (par->hidrantes);
    do
    {
        if (get_valor_lista (par->hidrantes, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (par->hidrantes, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_hidrante (get_valor_lista (par->hidrantes, primeiro));
        fprintf (saida_svg, conteudo_svg);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">H</text>", get_x_hidrante (get_valor_lista (par->hidrantes, primeiro)), get_y_hidrante (get_valor_lista (par->hidrantes, primeiro)));
        primeiro = get_proximo_lista (par->hidrantes, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (par->semaforos);
    do
    {
        if (get_valor_lista (par->semaforos, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (par->semaforos, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_semaforo (get_valor_lista (par->semaforos, primeiro));
        fprintf (saida_svg, conteudo_svg);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">S</text>", get_x_semaforo (get_valor_lista (par->semaforos, primeiro)), get_y_semaforo (get_valor_lista (par->semaforos, primeiro)));
        primeiro = get_proximo_lista (par->semaforos, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (par->radiobases);
    do
    {
        if (get_valor_lista (par->radiobases, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (par->radiobases, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_radiobase (get_valor_lista (par->radiobases, primeiro));
        fprintf (saida_svg, conteudo_svg);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">R</text>", get_x_radiobase (get_valor_lista (par->radiobases, primeiro)), get_y_radiobase(get_valor_lista (par->radiobases, primeiro)));
        primeiro = get_proximo_lista (par->radiobases, primeiro);
    }
    while (primeiro != NULL);
    free(conteudo_svg);
    fprintf (saida_svg, "\n</svg>");
    fclose (saida_svg);
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
    par->caminho_SVG = (char*) calloc (255, sizeof(char));
    strcpy(par->caminho_SVG, par->diretorio_saida);
    strcat(par->caminho_SVG, "/");
    strcat (par->caminho_SVG, par->arquivo_entrada);
    percorre = par->caminho_SVG + strlen(par->caminho_SVG)-1;
    while (*percorre != '.')
    {
        percorre--;
    }
    strcpy (percorre, ".svg");
    saida_svg = fopen (par->caminho_SVG, "w");
    fprintf (saida_svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"100000\" height=\"100000\">");
    for (i=0; i<=par->contador_figuras; i++)
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
    primeiro = get_primeiro_lista (par->quadras);
    do
    {
        if (get_valor_lista (par->quadras, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (par->quadras, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_quadra (get_valor_lista (par->quadras, primeiro));
        fprintf (saida_svg, conteudo_svg);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">%s</text>", get_x_quadra (get_valor_lista (par->quadras, primeiro)) + 3, get_y_quadra (get_valor_lista (par->quadras, primeiro)) + (get_h_quadra (get_valor_lista (par->quadras, primeiro))) - 3, get_cep_quadra (get_valor_lista (par->quadras, primeiro)));
        primeiro = get_proximo_lista (par->quadras, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (par->hidrantes);
    do
    {
        if (get_valor_lista (par->hidrantes, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (par->hidrantes, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_hidrante (get_valor_lista (par->hidrantes, primeiro));
        fprintf (saida_svg, conteudo_svg);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">H</text>", get_x_hidrante (get_valor_lista (par->hidrantes, primeiro)), get_y_hidrante (get_valor_lista (par->hidrantes, primeiro)));
        primeiro = get_proximo_lista (par->hidrantes, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (par->semaforos);
    do
    {
        if (get_valor_lista (par->semaforos, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (par->semaforos, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_semaforo (get_valor_lista (par->semaforos, primeiro));
        fprintf (saida_svg, conteudo_svg);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">S</text>", get_x_semaforo (get_valor_lista (par->semaforos, primeiro)), get_y_semaforo (get_valor_lista (par->semaforos, primeiro)));
        primeiro = get_proximo_lista (par->semaforos, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (par->radiobases);
    do
    {
        if (get_valor_lista (par->radiobases, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (par->radiobases, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_radiobase (get_valor_lista (par->radiobases, primeiro));
        fprintf (saida_svg, conteudo_svg);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">R</text>", get_x_radiobase (get_valor_lista (par->radiobases, primeiro)), get_y_radiobase (get_valor_lista (par->radiobases, primeiro)));
        primeiro = get_proximo_lista (par->radiobases, primeiro);
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
    Anotaçao anot;
    sscanf (*par->comando_vetor, "%s", aux);
    sscanf (*(par->comando_vetor + 1), "%ld", x);
    sscanf (*(par->comando_vetor + 2), "%ld", y);
    sscanf (*(par->comando_vetor + 3), "%ld", w);
    sscanf (*(par->comando_vetor + 4), "%ld", h);
    insere_fila (par->resultado, aux);
    anot = cria_anotacao (w, h, x, y, "");
    insere_fila (par->anotacoes, (Valor*) anot);
    reporta_dentro_retangulo (par->resultado, par->quadras, par->hidrantes, par->semaforos, par->radiobases, x, y, w, h);
    insere_fila (par->resultado, "\n");
    return;
}

void caso_Q_pergunta (Parametros* par)
{
    double r, x, y;
    Anotaçao* anot;
    char* aux;
    sscanf (*par->comando_vetor, "%s", aux);
    sscanf (*(par->comando_vetor + 1), "%ld", r);
    sscanf (*(par->comando_vetor + 2), "%ld", x);
    sscanf (*(par->comando_vetor + 3), "%ld", y);
    insere_fila (par->resultado, aux);
    anot = cria_anotacao (r, 0, x, y, "");
    insere_fila (par->anotacoes, (Valor*) anot);
    reporta_dentro_circulo (par->resultado, par->quadras, par->hidrantes, par->semaforos, par->radiobases, x, y, r);
    insere_fila (par->resultado, "\n");
    return;
}

void caso_dq (Parametros* par)
{
    double x, y, w, h;
    char* aux;
    Anotaçao anot;
    sscanf (*par->comando_vetor, "%s", aux);
    sscanf (*(par->comando_vetor + 1), "%ld", x);
    sscanf (*(par->comando_vetor + 2), "%ld", y);
    sscanf (*(par->comando_vetor + 3), "%ld", w);
    sscanf (*(par->comando_vetor + 4), "%ld", h);
    insere_fila (par->resultado, aux);
    anot = cria_anotacao (w, h, x, y, "");
    insere_fila (par->anotacoes, (Valor*) anot);
    delete_quadra_dentro_retangulo (par->resultado, par->quadras, x, y, w, h);
    insere_fila (par->resultado, "\n");
    return;
}

void caso_dle (Parametros* par)
{
    double w, h, x, y;
    Anotaçao anot;
    char* aux;
    char* tipo;
    sscanf (*par->comando_vetor, "%s", aux);
    sscanf (*(par->comando_vetor + 1), "%s", tipo);
    sscanf (*(par->comando_vetor + 2), "%ld", x);
    sscanf (*(par->comando_vetor + 3), "%ld", y);
    sscanf (*(par->comando_vetor + 4), "%ld", w);
    sscanf (*(par->comando_vetor + 5), "%ld", h);
    insere_fila (par->resultado, aux);
    anot = cria_anotacao (w, h, x, y, "");
    insere_fila (par->anotacoes, (Valor*) anot);
    delete_equipamento_dentro_retangulo (par->resultado, tipo, par->hidrantes, par->semaforos, par->radiobases, x, y, w, h);
    insere_fila (par->resultado, "\n");
    return;
}

void caso_Dq (Parametros* par)
{
    double r, x, y;
    char* aux;
    Anotaçao* anot;
    sscanf (*par->comando_vetor, "%s", aux);
    sscanf (*(par->comando_vetor + 1), "%ld", r);
    sscanf (*(par->comando_vetor + 2), "%ld", x);
    sscanf (*(par->comando_vetor + 3), "%ld", y);
    insere_fila (par->resultado, aux);
    anot = cria_anotacao (r, 0, x, y, "");
    insere_fila (par->anotacoes, (Valor*) anot);
    delete_quadra_dentro_circulo (par->resultado, par->quadras, x, y, r);
    insere_fila (par->resultado, "\n");
    return;
}

void caso_Dle (Parametros* par)
{
    double r, x, y;
    char* aux;
    char* tipo;
    Anotaçao* anot;
    sscanf (*par->comando_vetor, "%s", aux);
    sscanf (*(par->comando_vetor + 1), "%s", tipo);
    sscanf (*(par->comando_vetor + 2), "%ld", r);
    sscanf (*(par->comando_vetor + 3), "%ld", x);
    sscanf (*(par->comando_vetor + 4), "%ld", y);
    insere_fila (par->resultado, aux);
    anot = cria_anotacao (r, 0, x, y, "");
    insere_fila (par->anotacoes, (Valor*) anot);
    delete_equipamento_dentro_circulo (par->resultado, tipo, par->hidrantes, par->semaforos, par->radiobases, x, y, r);
    insere_fila (par->resultado, "\n");
    return;
}

void caso_cc (Parametros* par)
{
    char* aux;
    char* cor_borda;
    char* cor_preenche;
    sscanf (*par->comando_vetor, "%s", aux);
    sscanf (*(par->comando_vetor + 1), "%s", cor_borda);
    sscanf (*(par->comando_vetor + 2), "%s", cor_preenche);
    void* primeiro;
    Quadra *compare;
    primeiro = get_primeiro_lista (par->quadras);
    do
    {
        compare = get_valor_lista (par->quadras, primeiro);
        if (!strcmp (get_cep_quadra (compare), aux))
        {
            compare = troca_cor_quadra (compare, cor_borda, cor_preenche);
            break;
        }
        primeiro = get_proximo_lista (par->quadras, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (par->hidrantes);
    do
    {
        compare = get_valor_lista (par->hidrantes, primeiro);
        if (!strcmp(get_id_hidrante (compare), aux))
        {
            compare = muda_cor_hidrante (compare, cor_borda, cor_preenche);
            break;
        }
        primeiro = get_proximo_lista (par->hidrantes, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (par->semaforos);
    do
    {
        compare = get_valor_lista (par->semaforos, primeiro);
        if (!strcmp (get_id_semaforo (compare), aux))
        {
            compare = muda_cor_semaforo (compare, cor_borda, cor_preenche);
            break;
        }
        primeiro = get_proximo_lista (par->semaforos, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (par->radiobases);
    do
    {
        compare = get_valor_lista (par->radiobases, primeiro);
        if (!strcmp(get_id_radiobase (compare), aux))
        {
            compare = muda_cor_radiobase (compare, cor_borda, cor_preenche);
            break;
        }
        primeiro = get_proximo_lista (par->radiobases, primeiro);
    }
    while (primeiro != NULL);
    return;
}

void caso_crd_pergunta (Parametros* par)
{
    char* aux;
    sscanf (*par->comando_vetor, "%s", aux);
    insere_fila(par->resultado, "crd? ");
    insere_fila(par->resultado, aux);
    void* primeiro;
    Quadra *compare;
    primeiro = get_primeiro_lista (par->quadras);
    do
    {
        if (primeiro == NULL)
        {
            continue;
        }
        compare = get_valor_lista (par->quadras, primeiro);
        if (!strcmp(get_cep_quadra (compare), aux))
        {
            escreve_crd_quadra (par->resultado, compare);
            break;
        }
        primeiro = get_proximo_lista (par->quadras, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (par->hidrantes);
    do
    {
        if (primeiro == NULL)
        {
            continue;
        }
        compare = get_valor_lista (par->hidrantes, primeiro);
        if (strcmp(get_id_hidrante(compare), aux) == 0)
        {
            escreve_crd_hidrante (par->resultado, compare);
            break;
        }
        primeiro = get_proximo_lista (par->hidrantes, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (par->semaforos);
    do
    {
        if (primeiro == NULL)
        {
            continue;
        }
        compare = get_valor_lista (par->semaforos, primeiro);
        if (strcmp(get_id_semaforo(compare), aux) == 0)
        {
            escreve_crd_semaforo (par->resultado, compare);
            break;
        }
        primeiro = get_proximo_lista (par->semaforos, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (par->radiobases);
    do
    {
        if (primeiro == NULL)
        {
            continue;
        }
        compare = get_valor_lista (par->radiobases, primeiro);
        if (!strcmp (get_id_radiobase (compare), aux))
        {
            escreve_crd_radiobase (par->resultado, compare);
            break;
        }
        primeiro = get_proximo_lista (par->radiobases, primeiro);
    }
    while (primeiro != NULL);
    return;
}

void caso_crb_pergunta (Parametros* par)
{
    int i;
    double dist;
    char* radiobase1;
    char* radiobase2;
    char* cor_preenche;
    char* aux;
    char* saida;
    char* saida_crb;
    void* primeiro;
    void* aux_crb;
    void* rb1 = NULL;
    void* rb2 = NULL;
    Ponto** vetor_lista;
    sscanf (par->comando_vetor, "%s", aux);
    insere_fila (par->resultado, aux);
    vetor_lista = (Ponto**) calloc (largura_lista (par->radiobases), sizeof (Ponto*));
    primeiro = get_primeiro_lista (par->radiobases);
    for (i=0; i<largura_lista (par->radiobases); i++)
    {
        aux_crb = get_valor_lista (par->radiobases, primeiro);
        vetor_lista[i] = (Ponto*) calloc (1, sizeof (Ponto));
        vetor_lista[i]->id = get_id_radiobase (aux_crb);
        vetor_lista[i]->x = get_x_radiobase (aux_crb);
        vetor_lista[i]->y = get_y_radiobase (aux_crb);
        primeiro = get_proximo_lista (par->radiobases, primeiro);
    }
    saida_crb = (char*) calloc (155, sizeof(char));
    //CHAMA A FUNÇÃO CLOSEST_PAIR
    dist = closest_pair (vetor_lista, largura_lista (par->radiobases), saida_crb);
    sscanf (saida_crb, "%s %s", radiobase1, radiobase2);
    saida = (char*) calloc (155, sizeof(char));
    sprintf (saida, "\nRbs - ID = %s \nRbs - ID = %s \nDISTÂNCIA = %f\n", radiobase1, radiobase2, dist); 
    insere_fila (par->resultado, saida);
    primeiro = get_primeiro_lista (par->radiobases);
    do
    {
        if (!strcmp (get_id_radiobase (get_valor_lista (par->radiobases, primeiro)), radiobase1))
        {
            rb1 = get_valor_lista (par->radiobases, primeiro);
        }
        if (!strcmp (get_id_radiobase (get_valor_lista (par->radiobases, primeiro)), radiobase2))
        {
            rb2 = get_valor_lista(par->radiobases, primeiro);
        }
        if (rb1 != NULL && rb2 != NULL)
        {
            break;
        }
        primeiro = get_proximo_lista (par->radiobases, primeiro);
    }
    while (primeiro != NULL);
    Anotaçao* anot;
    anot = cria_anotacao (10, 0, get_x_radiobase (rb1), get_y_radiobase (rb1), "");
    insere_fila (par->anotacoes, anot);
    anot = cria_anotacao (10, 0, get_x_radiobase (rb2), get_y_radiobase (rb2), "");
    insere_fila (par->anotacoes, anot);
    return;
}

void caso_m_pergunta (Parametros* par)
{
    return;
}

void caso_mr_pergunta (Parametros* par)
{
    return;
}

void caso_dm_pergunta (Parametros* par)
{
    return;
}

void caso_de_pergunta (Parametros* par)
{
    return;
}

void caso_rip (Parametros* par)
{
    return;
}

void caso_ecq_pergunta (Parametros* par)
{
    return;
}

void caso_ecr_pergunta (Parametros* par)
{
    return;
}

void caso_tecq_pergunta (Parametros* par)
{
    return;
}

void caso_tecr_pergunta (Parametros* par)
{
    return;
}

void caso_hmpe_pergunta (Parametros* par)
{
    return;
}
void caso_hmp_pergunta (Parametros* par)
{
    return;
}
void caso_fec (Parametros* par)
{
    return;
}
void caso_mud (Parametros* par)
{
    return;
}

void caso_mudec (Parametros* par)
{
    return;
}

void caso_dpr (Parametros* par)
{
    return;
}

//COMANDOS REFERENTES AO ARQUIVO .EC

void caso_t_ec (Parametros* par)
{
    char* cod;
    char* info;
    sscanf (*(par->comando_vetor + 1), "%s", cod);
    sscanf (*(par->comando_vetor + 2), "%s", info);
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
    sscanf (*(par->comando_vetor + 1), "%s", cnpj);
    sscanf (*(par->comando_vetor + 2), "%s", cod);
    sscanf (*(par->comando_vetor + 3), "%s", cep);
    sscanf (*(par->comando_vetor + 4), "%s", face);
    sscanf (*(par->comando_vetor + 5), "%s", num);
    sscanf (*(par->comando_vetor + 6), "%s", nome);
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
    sscanf (*(par->comando_vetor + 1), "%s", cpf);
    sscanf (*(par->comando_vetor + 2), "%s", nome);
    sscanf (*(par->comando_vetor + 3), "%s", sobrenome);
    sscanf (*(par->comando_vetor + 4), "%s", sexo);
    sscanf (*(par->comando_vetor + 5), "%s", nascimento);
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
    sscanf (*(par->comando_vetor + 1), "%s", cpf);
    sscanf (*(par->comando_vetor + 2), "%s", cep);
    sscanf (*(par->comando_vetor + 3), "%s", face);
    sscanf (*(par->comando_vetor + 4), "%s", num);
    sscanf (*(par->comando_vetor + 5), "%s", comp);
    pessoa = get_hashtable (par->hash_pessoas, cpf);
    set_endereco_pessoa (pessoa, cep, face, num, comp);
    insere_hashtable (par->hash_end_pessoas, end);
    return;
}