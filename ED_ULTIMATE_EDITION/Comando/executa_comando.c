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
#include "../Objetos/Carro/carro.h"
#include "../Formas/Anotação/anotacao.h"
#include "../Estruturas/Item/item.h"
#include "../Estruturas/Fila/fila.h"
#include "../Estruturas/Lista/lista.h"
#include "../Estruturas/Árvore/arvore.h"
#include "../Estruturas/Hash/hashtable.h"
#include "../Estruturas/Merge/mergesort.h"
#include "../Estruturas/Registrador/registrador.h"
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
void caso_e_ec (Parametros* par);
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
void caso_v (Parametros* par);
void caso_e_via (Parametros* par);
void caso_arroba_m_pergunta (Parametros* par);
void caso_arroba_e_pergunta (Parametros* par);
void caso_arroba_g_pergunta (Parametros* par);
void caso_arroba_xy (Parametros* par);
void caso_arroba_tp_pergunta (Parametros* par);
void caso_p_pergunta (Parametros* par);
void caso_sp_pergunta (Parametros* par);
void caso_au (Parametros* par);
void caso_dc (Parametros* par);
void caso_rau (Parametros* par);

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
        comando = NULL;
        return;
    }
    //CRIAR UM CÍRCULO
    if (!strcmp (comando, "c"))
    {
        par->comando += 2;
        caso_c (par);
        free(comando);
        comando = NULL;
        return;
    }
    //CRIAR UM RETÂNGULO
    if (!strcmp (comando, "r"))
    {
        par->comando += 2;
        caso_r (par);
        free(comando);
        comando = NULL;
        return;
    }
    //CRIA UMA QUADRA
    if (!strcmp (comando, "q"))
    {
        par->comando += 2;
        caso_q (par);
        free(comando);
        comando = NULL;
        return;
    }
    //CRIA UM HIDRANTE
    if (!strcmp (comando, "h"))
    {
        par->comando += 2;
        caso_h (par);
        free(comando);
        comando = NULL;
        return;
    }
    //CRIA UM SEMÁFORO
    if (!strcmp (comando, "s"))
    {
        par->comando += 2;
        caso_s (par);
        free(comando);
        comando = NULL;
        return;
    }
    //CRIA UMA RADIOBASE
    if (!strcmp (comando, "t"))
    {
        if (!strcmp (par->controle, ".geo"))
        {
            par->comando += 2;
            caso_t_geo (par);
            free(comando);
            comando = NULL;
            return;    
        }
    }
    //ALTERA AS CORES DA BORDA E DO PREENCHIMENDO DA QUADRA
    if (!strcmp (comando, "cq"))
    {
        par->comando += 3;
        caso_cq (par);
        free(comando);
        comando = NULL;
        return;
    }
    //ALTERA AS CORES DA BORDA E DO PREENCHIMENDO DO HIDRANTE
    if (!strcmp (comando, "ch"))
    {
        par->comando += 3;
        caso_ch (par);
        free(comando);
        comando = NULL;
        return;
    }
    //ALTERA AS CORES DA BORDA E DO PREENCHIMENDO DA RADIO-BASE
    if (!strcmp (comando, "ct"))
    {
        par->comando += 3;
        caso_ct (par);
        free(comando);
        comando = NULL;
        return;
    }
    //ALTERA AS CORES DA BORDA E DO PREENCHIMENDO DO SEMAFORO
    if (!strcmp (comando, "cs"))
    {
        par->comando += 3;
        caso_cs (par);
        free(comando);
        comando = NULL;
        return;
    }
    //VERIFICAR SE DUAS FIGURAS SE SOBREPOEM
    if (!strcmp (comando, "o"))
    {
        caso_o (par);
        free(comando);
        comando = NULL;
        return;
    }
    //VERIFICAR SE UM PONTO É INTERNO A FIGURA
    if (!strcmp (comando, "i"))
    {
        caso_i (par);
        free(comando);
        comando = NULL;
        return;
    }
    //CALCULAR A DISTÂNCIA ENTRE OS CENTROS DE MASSA DE DUAS FIGURAS
    if (!strcmp (comando, "d"))
    {
        caso_d (par);
        free(comando);
        comando = NULL;
        return;
    }
    //CRIA O ARQUIVO SVG COM O SUFIXO
    if (!strcmp (comando, "a"))
    {
        par->comando += 2;
        caso_a (par);
        free(comando);
        comando = NULL;
        return;
    }
    //FINALIZA O ARQUIVO
    if (!strcmp (comando, "#"))
    {
        par->comando += 2;
        caso_hashtag (par);
        free(comando);
        comando = NULL;
        return;
    }

    //COMANDOS DO ARQUIVO .EC
    
    //DEFINE O TIPO DO ESTABELECIMENTO COMERCIAL
    if (!strcmp (comando, "t"))
    {
        if (!strcmp (par->controle, ".ec"))
        {
            par->comando += 2;
            caso_t_ec (par);
            free(comando);
            comando = NULL;
            return;
        }
    }
    //INSERE UM NOVO ESTABELECIMENTO COMERCIAL DE UM DETERMINADO TIPO
    if (!strcmp (comando, "e"))
    {
        if (!strcmp (par->controle, ".ec"))
        {
            par->comando += 2;
            caso_e_ec (par);
            free(comando);
            comando = NULL;
            return;
        }
    }

    //COMANDOS DO ARQUIVO .PM
    //INSERE UMA PESSOA IDENTIFICADA POR UM CPF
    if (!strcmp (comando, "p"))
    {
        par->comando += 2;
        caso_p (par);
        free(comando);
        comando = NULL;
        return;
    }
    //INFORMA O ENDEREÇO ONDE UMA PESSOA MORA
    if (!strcmp (comando, "m"))
    {
        par->comando += 2;
        caso_m (par);
        free(comando);
        comando = NULL;
        return;
    }
    
    //COMANDOS DO ARQUIVO .VIA
    //CRIA UM VÉRTICE POSICIONADO NAS COORDENADAS
    if (!strcmp (comando, "v"))
    {
        par->comando += 2;
        caso_v (par);
        free (comando);
        comando = NULL;
        return;
    }

    //CRIA UMA ARESTA E ASSOCIA INFORMAÇÕES
    if (!strcmp (comando, "e"))
    {
        if (!strcmp (par->controle, ".via"))
        {
            par->comando += 2;
            caso_e_via (par);
            free (comando);
            comando = NULL;
            return;
        }
    }

    //COMANDOS DO ARQUIVOS .QRY 

    //REPORTA O QUE ESTIVER DENTRO DO RETÂNGULO ESPECIFICADO
    if (!strcmp (comando, "q?"))
    {
        caso_q_pergunta (par);
        free(comando);
        comando = NULL;
        return;
    }
    //REPORTA O QUE ESTIVER DENTRO DO CÍRCULO ESPECIFICADO
    if (!strcmp (comando, "Q?"))
    {
        caso_Q_pergunta (par);
        free(comando);
        comando = NULL;
        return;
    }
    //DELETA TODAS AS QUADRAS DENTRO DO RETÂNGULO ESPECIFICADO
    if (!strcmp (comando, "dq"))
    {
        caso_dq (par);
        free(comando);
        comando = NULL;
        return;
    }
    //DELETA TODOS OS EQUIPAMENTOS DENTRO DO RETÂNGULO ESPECIFICADO
    if (!strcmp (comando, "dle"))
    {
        caso_dle (par);
        free(comando);
        comando = NULL;
        return;
    }
    //DELETA TODAS AS QUADRAS DENTRO DO CÍRCULO ESPECIFICADO
    if (!strcmp (comando, "Dq"))
    {
        caso_Dq (par);
        free(comando);
        comando = NULL;
        return;
    }
    //DELETA TODOS OS EQUIPAMENTOS DENTRO DO CÍRCULO ESPECIFICADO
    if (!strcmp (comando, "Dle"))
    {
        caso_Dle (par);
        free(comando);
        comando = NULL;
        return;
    }
    //MUDA AS CORES DA QUADRA IDENTIFICADA PELO CEP
    if (!strcmp (comando, "cc"))
    {
        par->comando += 3;
        caso_cc (par);
        free(comando);
        comando = NULL;
        return;
    }
    //IMPRIME NO .TXT AS COORDENADAS DE UMA DETERMINADA QUADRA OU EQUIPAMENTO
    if (!strcmp (comando, "crd?"))
    {
        caso_crd_pergunta (par);
        free(comando);
        comando = NULL;
        return;
    }
    //DETERMINA AS RADIOBASES MAIS PRÓXIMAS
    if (!strcmp (comando, "crb?"))
    {
        caso_crb_pergunta (par);
        free(comando);
        comando = NULL;
        return;
    }
    //MORADORES DA QUADRA DEFINIDA PELO CEP
    if (!strcmp (comando, "m?"))
    {
        caso_m_pergunta (par);
        free(comando);
        comando = NULL;
        return;
    }
    //MORADORES DAS QUADRAS DENTRO DO RETÂNGULO
    if (!strcmp (comando, "mr?"))
    {
        caso_mr_pergunta (par);
        free(comando);
        comando = NULL;
        return;
    }
    //IMPRIME OS DADOS DO MORADOR IDENTIFICADO PELO CPF
    if (!strcmp (comando, "dm?"))
    {
        caso_dm_pergunta (par);
        free(comando);
        comando = NULL;
        return;
    }
    //IMPRIME OS DADOS DO ESTABELECIMENTO IDENTIFICADO PELO CNPJ
    if (!strcmp (comando, "de?"))
    {
        caso_de_pergunta (par);
        free(comando);
        comando = NULL;
        return;
    }
    //APAGA TODOS OS DADOS DE UMA PESSOA
    if (!strcmp (comando, "rip"))
    {
        caso_rip (par);
        free(comando);
        comando = NULL;
        return;
    }
    //LISTA OS ESTABELECIMENTOS DE UMA QUADRA
    if (!strcmp (comando, "ecq?"))
    {
        caso_ecq_pergunta (par);
        free(comando);
        comando = NULL;
        return;
    }
    //LISTA OS ESTABELECIMeNTOS DE UM DETERMINADO TIPO EM UM RETÂNGULO
    if (!strcmp (comando, "ecr?"))
    {
        caso_ecr_pergunta (par);
        free(comando);
        comando = NULL;
        return;
    }
    //LISTA OS TIPOS DE ESTABELECIMENTOS DE UMA QUADRA ESPECÍFICA
    if (!strcmp (comando, "tecq?"))
    {
        caso_tecq_pergunta (par);
        free(comando);
        comando = NULL;
        return;
    }
    //LISTA OS TIPOS DE ESTABELECIMENTOS COMERCIAIS EM UM RETÂNGULO
    if (!strcmp (comando, "tecr?"))
    {
        caso_tecr_pergunta (par);
        free(comando);
        comando = NULL;
        return;
    }
    //ENCONTRA O HIDRANTE MAIS PRÓXIMO À UM ENDEREÇO ESPECÍFICO
    if (!strcmp (comando, "hmpe?"))
    {
        caso_hmpe_pergunta (par);
        free(comando);
        comando = NULL;
        return;
    }
    //ENCONTRA O HIDRANTE MAIS PRÓXIMO À UMA RADIOBASE ESPECÍFICA
    if (!strcmp (comando, "hmp?"))
    {
        caso_hmp_pergunta (par);
        free(comando);
        comando = NULL;
        return;
    }
    //APAGA TODOS OS DADOS DE UM ESTABELECIMENTO
    if (!strcmp (comando, "fec"))
    {
        caso_fec (par);
        free(comando);
        comando = NULL;
        return;
    }
    //MUDA O ENDEREÇO DA PESSOA E TRAÇA UMA LINHA ENTRE O ENDEREÇO ANTIGO E O NOVO
    if (!strcmp (comando, "mud"))
    {
        caso_mud (par);
        free(comando);
        comando = NULL;
        return;
    }
    //MUDA O ESTABELECIMENTO DE ENDEREÇO E TRAÇA UMA LINHA ENTRE O ENDEREÇO ANTIGO E O NOVO
    if (!strcmp (comando, "mudec"))
    {
        caso_mudec (par);
        free(comando);
        comando = NULL;
        return;
    }
    //DESAPROPRIA UMA REGIÃO (DELETA TUDO DENTRO DELA, MAS A PESSOA NÃO MORRE, SÓ DEIXA DE MORAR LÁ)
    if (!strcmp (comando, "dpr"))
    {
        caso_dpr (par);
        free(comando);
        comando = NULL;
        return;
    }
    //ARMAZENA NO REGISTRADOR A POSIÇÃO GEOGRÁFICA DO MORADOR DE TAL CPF
    if (!strcmp (comando, "@m?"))
    {
        caso_arroba_m_pergunta (par);
        free (comando);
        comando = NULL;
        return;
    }
    //ARMAZENA NO REGISTRADOR A POSIÇÃO GEOGRÁFICA DO ENDEREÇO
    if (!strcmp (comando, "@e?"))
    {
        caso_arroba_e_pergunta (par);
        free (comando);
        comando = NULL;
        return;
    }
    //ARMAZENA NO REGISTRADOR A POSIÇÃO GEOGRÁFICA DO EQUIPAMENTO URBANO
    if (!strcmp (comando, "@g?"))
    {
        caso_arroba_g_pergunta (par);
        free (comando);
        comando = NULL;
        return;
    }
    //ARMAZENA NO REGISTRADOR A POSIÇÃO GEOGRÁFICA (X,Y)
    if (!strcmp (comando, "@xy"))
    {
        caso_arroba_xy (par);
        free (comando);
        comando = NULL;
        return;
    }
    //ARMAZENA NO REGISTRADOR 1 O ESTABELECIMENTO DO TIPO ESPECIFICADO MAIS PRÓXIMO DO REGISTRADOR 2
    if (!strcmp (comando, "@tp?"))
    {
        caso_arroba_tp_pergunta (par);
        free (comando);
        comando = NULL;
        return;
    }
    //MELHOR TRAJETO ENTRE A ORIGEM (REGISTRADOR 1) E O DESTINO (REGISTRADOR 2)
    if (!strcmp (comando, "p?"))
    {
        caso_p_pergunta (par);
        free (comando);
        comando = NULL;
        return;
    }
    //MELHOR TRAJETO ENTRE A ORIGEM (REGISTRADOR 1) E O DESTINO (REGISTRADOR N) PASSANDO POR TODOS OS OUTROS  REGISTRADORES PEDIDOS
    if (!strcmp (comando, "sp?"))
    {
        caso_sp_pergunta (par);
        free (comando);
        comando = NULL;
        return;
    }
    //POSICIONA O CARRO EM ALGUM LUGAR DA CIDADE
    if (!strcmp (comando, "au"))
    {
        caso_au (par);
        free (comando);
        comando = NULL;
        return;
    }
    //DETECTA COLISÃO E INTERDITA TRECHO DA RUA
    if (!strcmp (comando, "dc"))
    {
        caso_dc (par);
        free (comando);
        comando = NULL;
        return;
    }
    //REMOVE CARRO IDENTIFICADO PELA PLACA
    if (!strcmp (comando, "rau"))
    {
        caso_rau (par);
        free (comando);
        comando = NULL;
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
    par->figuras = NULL;
    par->figuras = (Item*) calloc (par->max_figuras, sizeof (Item));
    i = 0;
    par->contador_figuras = 0;
    while (!fila_vazia (fila))
    {
        par->figuras[i] = remove_fila (fila);
        i++;
        par->contador_figuras++;
    }
    free(fila);
    fila = NULL;
    return;
}
void caso_c (Parametros* par)
{
    long int id;
    int i;
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
    free (cor1);
    cor1 = NULL;
    free (cor2);
    cor2 = NULL;
    it = cria_item (fig, C);
    par->figuras[par->contador_figuras] = it;
    par->contador_figuras++;
    return;
}
void caso_r (Parametros* par)
{
    long int id;
    int i;
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
    free (cor1);
    cor1 = NULL;
    free (cor2);
    cor2 = NULL;
    it = cria_item (fig, R);
    par->figuras[par->contador_figuras] = it;
    par->contador_figuras++;
    free (cor1);
    cor1 = NULL;
    free (cor2);
    cor2 = NULL;
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
    free (cep);
    cep = NULL;
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
    free (id);
    id = NULL;
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
    free (id);
    id = NULL;
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
    free (id);
    id = NULL;
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
        centro1 = NULL;
        free (centro2);
        centro2 = NULL;
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
    centro1 = NULL;
    free (centro2);
    centro2 = NULL;
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
    par->caminho_SVG = NULL;
    
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
            free (conteudo_svg);
            conteudo_svg = NULL;
            continue;
        }
        else
        {
            conteudo_svg = cria_svg_circulo (get_valor_item (par->figuras[i]));
            fprintf (saida_SVG, conteudo_svg);
            free (conteudo_svg);
            conteudo_svg = NULL;
            continue;
        }
    }
    aux = cria_fila();
    while (!fila_vazia (par->anotacoes))
    {
        fila_linha = remove_fila (par->anotacoes);
        conteudo_svg = cria_svg_anotacao (fila_linha);
        fprintf (saida_SVG, conteudo_svg);
        free (conteudo_svg);
        conteudo_svg = NULL;
        insere_fila (aux, fila_linha);
        continue;
    }
    while (!fila_vazia(aux))
    {
        insere_fila (par->anotacoes, remove_fila(aux));
    }
    free (aux);
    aux = NULL;
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
    centro1 = NULL;
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
        centro2 = NULL;
        result = sqrt ((dx*dx) + (dy*dy));
        fprintf (saida_SVG, "\n<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke=\"%s\" stroke-width=\"2\"/>", x1, y1, x2, y2, corB);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">%.2f</text>", (x1 + dx/2), (y1+dy/2), result);
    }
    void* primeiro;
    quadras = get_todos_arvore (par->tree_quadras);
    primeiro = get_primeiro_lista (quadras);
    do
    {
        if (get_valor_lista (primeiro) == NULL)
        {
            primeiro = get_proximo_lista (quadras, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_quadra (get_valor_lista (primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">%s</text>", get_x_quadra (get_valor_lista (primeiro)), get_y_quadra (get_valor_lista (primeiro)), get_cep_quadra (get_valor_lista (primeiro)));
        free (conteudo_svg);
        conteudo_svg = NULL;
        primeiro = get_proximo_lista (quadras, primeiro);
    }
    while (primeiro != NULL);
    hidrantes = get_todos_arvore (par->tree_hidrantes);
    primeiro = get_primeiro_lista (hidrantes);
    do
    {
        if (get_valor_lista (primeiro) == NULL)
        {
            primeiro = get_proximo_lista (hidrantes, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_hidrante (get_valor_lista (primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">H</text>", get_x_hidrante (get_valor_lista (primeiro)), get_y_hidrante (get_valor_lista (primeiro)));
        free (conteudo_svg);
        conteudo_svg = NULL;
        primeiro = get_proximo_lista (hidrantes, primeiro);
    }
    while (primeiro != NULL);
    semaforos = get_todos_arvore (par->tree_semaforos);
    primeiro = get_primeiro_lista (semaforos);
    do
    {
        if (get_valor_lista (primeiro) == NULL)
        {
            primeiro = get_proximo_lista (semaforos, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_semaforo (get_valor_lista (primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">S</text>", get_x_semaforo (get_valor_lista (primeiro)), get_y_semaforo (get_valor_lista (primeiro)));
        free (conteudo_svg);
        conteudo_svg = NULL;
        primeiro = get_proximo_lista (semaforos, primeiro);
    }
    while (primeiro != NULL);
    radiobases = get_todos_arvore (par->tree_radiobases);
    primeiro = get_primeiro_lista (radiobases);
    do
    {
        if (get_valor_lista (primeiro) == NULL)
        {
            primeiro = get_proximo_lista (radiobases, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_radiobase (get_valor_lista (primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">R</text>", get_x_radiobase (get_valor_lista (primeiro)), get_y_radiobase(get_valor_lista (primeiro)));
        free (conteudo_svg);
        conteudo_svg = NULL;
        primeiro = get_proximo_lista (radiobases, primeiro);
    }
    while (primeiro != NULL);
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
            free (conteudo_svg);
            conteudo_svg = NULL;
            continue;
        }
        else
        {
            conteudo_svg = cria_svg_circulo (get_valor_item (par->figuras[i]));
            fprintf (saida_svg, conteudo_svg);
            free (conteudo_svg);
            conteudo_svg = NULL;
            continue;
        }
    }
    void* primeiro;
    quadras = get_todos_arvore (par->tree_quadras);
    primeiro = get_primeiro_lista (quadras);
    do
    {
        if (get_valor_lista (primeiro) == NULL)
        {
            primeiro = get_proximo_lista (quadras, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_quadra (get_valor_lista (primeiro));
        fprintf (saida_svg, conteudo_svg);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">%s</text>", get_x_quadra (get_valor_lista (primeiro)) + 3, get_y_quadra (get_valor_lista (primeiro)) + (get_h_quadra (get_valor_lista (primeiro))) - 3, get_cep_quadra (get_valor_lista (primeiro)));
        free (conteudo_svg);
        conteudo_svg = NULL;
        primeiro = get_proximo_lista (quadras, primeiro);
    }
    while (primeiro != NULL);
    
    for(size_t i = 0; i < largura_lista(quadras); i++)
    {
        remove_lista(quadras, get_primeiro_lista(quadras));
    }
    free(quadras);
    quadras = NULL;

    hidrantes = get_todos_arvore (par->tree_hidrantes);
    primeiro = get_primeiro_lista (hidrantes);
    do
    {
        if (get_valor_lista (primeiro) == NULL)
        {
            primeiro = get_proximo_lista (hidrantes, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_hidrante (get_valor_lista (primeiro));
        fprintf (saida_svg, conteudo_svg);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">H</text>", get_x_hidrante (get_valor_lista (primeiro)), get_y_hidrante (get_valor_lista (primeiro)));
        free (conteudo_svg);
        conteudo_svg = NULL;
        primeiro = get_proximo_lista (hidrantes, primeiro);
    }
    while (primeiro != NULL);
    
    for(size_t i = 0; i < largura_lista(hidrantes); i++)
    {
        remove_lista(hidrantes, get_primeiro_lista(hidrantes));
    }
    free(hidrantes);
    hidrantes = NULL;
    
    semaforos = get_todos_arvore (par->tree_semaforos);
    primeiro = get_primeiro_lista (semaforos);
    do
    {
        if (get_valor_lista (primeiro) == NULL)
        {
            primeiro = get_proximo_lista (semaforos, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_semaforo (get_valor_lista (primeiro));
        fprintf (saida_svg, conteudo_svg);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">S</text>", get_x_semaforo (get_valor_lista (primeiro)), get_y_semaforo (get_valor_lista (primeiro)));
        free (conteudo_svg);
        conteudo_svg = NULL;
        primeiro = get_proximo_lista (semaforos, primeiro);
    }
    while (primeiro != NULL);

    for(size_t i = 0; i < largura_lista(semaforos); i++)
    {
        remove_lista(semaforos, get_primeiro_lista(semaforos));
    }
    free(semaforos);
    semaforos = NULL;

    radiobases = get_todos_arvore (par->tree_radiobases);
    primeiro = get_primeiro_lista (radiobases);
    do
    {
        if (get_valor_lista (primeiro) == NULL)
        {
            primeiro = get_proximo_lista (radiobases, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_radiobase (get_valor_lista (primeiro));
        fprintf (saida_svg, conteudo_svg);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">R</text>", get_x_radiobase (get_valor_lista (primeiro)), get_y_radiobase (get_valor_lista (primeiro)));
        free (conteudo_svg);
        conteudo_svg = NULL;
        primeiro = get_proximo_lista (radiobases, primeiro);
    }
    while (primeiro != NULL);
    
    for(size_t i = 0; i < largura_lista(radiobases); i++)
    {
        remove_lista(radiobases, get_primeiro_lista(radiobases));
    }
    free(radiobases);
    radiobases = NULL;

    aux = cria_fila ();
    while (!fila_vazia (par->anotacoes))
    {
        fila_linha = remove_fila (par->anotacoes);
        conteudo_svg = cria_svg_anotacao (fila_linha);
        fprintf (saida_svg, conteudo_svg);
        free (conteudo_svg);
        conteudo_svg = NULL;
        insere_fila (aux, fila_linha);
        continue;
    }
    while(!fila_vazia (aux))
    {
        insere_fila (par->anotacoes, remove_fila (aux));
    }
    free (aux);
    aux = NULL;
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
    par->caminho_TXT = NULL;
    fprintf (saida_txt, "\nARQUIVO: %s\n\n", par->arquivo_entrada);
    while (!fila_vazia (par->resultado))
    {
        conteudo_svg = remove_fila (par->resultado);
        fprintf (saida_txt, conteudo_svg);
        free (conteudo_svg);
        conteudo_svg = NULL;
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
    free (tipo);
    tipo = NULL;
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
    free (tipo);
    tipo = NULL;
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
        compare = get_valor_lista (primeiro);
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
        compare = get_valor_lista (primeiro);
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
        compare = get_valor_lista (primeiro);
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
        compare = get_valor_lista (primeiro);
        if (!strcmp(get_id_radiobase (compare), aux))
        {
            compare = muda_cor_radiobase (compare, cor_borda, cor_preenche);
            break;
        }
        primeiro = get_proximo_lista (radiobases, primeiro);
    }
    while (primeiro != NULL);
    free (aux);
    aux = NULL;
    free (cor_borda);
    cor_borda = NULL;
    free (cor_preenche);
    cor_preenche = NULL;
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
        compare = get_valor_lista (primeiro);
        if (compare == NULL)
        {
            primeiro = get_proximo_lista (quadras, primeiro);
            continue;
        }
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
        compare = get_valor_lista (primeiro);
        if (!strcmp(get_id_hidrante(compare), aux))
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
        compare = get_valor_lista (primeiro);
        if (!strcmp(get_id_semaforo(compare), aux))
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
        compare = get_valor_lista (primeiro);
        if (!strcmp (get_id_radiobase (compare), aux))
        {
            escreve_crd_radiobase (par->resultado, compare);
            break;
        }
        primeiro = get_proximo_lista (radiobases, primeiro);
    }
    while (primeiro != NULL);
    free (aux);
    aux = NULL;
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
    rbA = get_valor_lista (aux);
    rbB = vizinho_proximo_arvore (par->tree_radiobases, rbA);
    dist = dist_arvore (par->tree_radiobases, rbA, rbB);
    do
    {
        auxR = get_valor_lista (aux);
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
    char* result;
    void* endereco;
    void* primeiro;
    void* morador;
    void* valor;
    Quadra* quad;
    Quadra* quadAux;
    Lista enderecos;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 3;
    cep = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    sscanf (par->comando, "%s", cep);
    quad = cria_quadra (cep, 0, 0, 0, 0, "", "");
    quadAux = get_hashtable (par->hash_quadras, quad);
    if (quadAux == NULL)
    {
        result = (char*) calloc (55, sizeof (char));
        sprintf (result, "\nQUADRA NÃO ENCONTRADA!\n\n");
        insere_fila (par->resultado, result);
        free(cep);
        cep = NULL;
        free_quadra (quad);
        return;
    }
    free_quadra (quad);
    //relatorio = (char*) calloc (555, sizeof (char));
    endereco = identificador_endereco_pessoa (cep);
    enderecos = get_lista_hashtable (par->hash_end_pessoas, endereco);
    free (endereco);
    endereco = NULL;
    if (!largura_lista (enderecos))
    {
        result = (char*) calloc (55, sizeof (char));
        sprintf (result, "\nNENHUM MORADOR ENCONTRADO NESSA QUADRA!\n\n");
        insere_fila (par->resultado, result);
        free(enderecos);
        enderecos = NULL;
        free(cep);
        cep = NULL;
        return;
    }
    primeiro = get_primeiro_lista (enderecos);
    do
    {
        valor = get_valor_lista (primeiro);
        if (valor == NULL)
        {
            primeiro = get_proximo_lista (enderecos, primeiro);
            continue;
        }
        morador = get_pessoa_endereco (valor);
        relatorio = relatorio_endereco_pessoa (morador);
        insere_fila (par->resultado, relatorio);
        primeiro = get_proximo_lista (enderecos, primeiro);
    }
    while (primeiro != NULL);
    
    for(size_t i = 0; i < largura_lista(enderecos); i++)
    {
        remove_lista(enderecos, get_primeiro_lista(enderecos));
    }
    free(enderecos);
    enderecos = NULL;
    
    free (cep);
    cep = NULL;
    return;
}

void caso_mr_pergunta (Parametros* par)
{
    double w, h, x, y;
    char* aux;
    char* relatorio;
    char* relatorioQuad;
    void* primeiro;
    void* endereco;
    void* morador;
    void* percorre;
    void* valor;
    Lista quadras;
    Lista report;
    Lista enderecos;
    Quadra quadra;
    Anotacao* anot;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 4;
    sscanf (par->comando, "%lf %lf %lf %lf", &x, &y, &w, &h);
    quadras = get_todos_hashtable (par->hash_quadras);
    report = reporta_quadra_dentro_retangulo (quadras, w, h, x, y);

    
    for(size_t i = 0; i < largura_lista(quadras); i++)
    {
        remove_lista(quadras, get_primeiro_lista(quadras));
    }
    free(quadras);
    quadras = NULL;

    if (!largura_lista (report))
    {
        relatorio = (char*) calloc (55, sizeof (char));
        sprintf (relatorio, "\nNENHUMA QUADRA INTEIRAMENTE DENTRO DA ÁREA PEDIDA!\n\n");
        insere_fila (par->resultado, relatorio);
        anot = cria_anotacao (w, h, x, y, "mr");
        insere_fila (par->anotacoes, anot);
        return;
    }
    primeiro = get_primeiro_lista (report);
    do
    {
        quadra = get_valor_lista (primeiro);
        if (quadra == NULL)
        {
            primeiro = get_proximo_lista (report, primeiro);
            continue;
        }
        endereco = identificador_endereco_pessoa (get_cep_quadra (quadra));
        relatorio = (char*) calloc (55, sizeof (char));
        sprintf (relatorio, "\nQuad - CEP - %s", get_cep_quadra (quadra));
        insere_fila (par->resultado, relatorio);
        enderecos = get_lista_hashtable (par->hash_end_pessoas, endereco);
        free_endereco (endereco);
        if (!largura_lista (enderecos))
        {
            primeiro = get_proximo_lista (report, primeiro);
            relatorio = (char*) calloc (55, sizeof (char));
            sprintf (relatorio, "\nNENHUM MORADOR REGISTRADO NESSA QUADRA!\n");
            insere_fila (par->resultado, relatorio);    

            free(enderecos);
            enderecos = NULL;
            continue;
        }
        percorre = get_primeiro_lista (enderecos);
        do
        {
            valor = get_valor_lista (percorre);
            if (valor == NULL)
            {
                percorre = get_proximo_lista (enderecos, percorre);
                continue;
            }
            morador = get_pessoa_endereco (valor);
            relatorioQuad = relatorio_endereco_pessoa (morador);
            insere_fila (par->resultado, relatorioQuad);
            percorre = get_proximo_lista (enderecos, percorre);
        }
        while (percorre != NULL);
        primeiro = get_proximo_lista (report, primeiro);

        for(size_t i = 0; i < largura_lista(enderecos); i++)
        {
            remove_lista(enderecos, get_primeiro_lista(enderecos));
        }
        free(enderecos);
        enderecos = NULL;
    }
    while (primeiro != NULL);
    
    
    anot = cria_anotacao (w, h, x, y, "mr");
    insere_fila (par->anotacoes, anot);
    relatorio = (char*) calloc (5, sizeof (char));
    sprintf (relatorio, "\n");
    insere_fila (par->resultado, relatorio);
    return;
}

void caso_dm_pergunta (Parametros* par)
{
    double* coord;
    char* aux;
    char* cpf;
    char* result;
    char* relatorio;
    Pessoa* pessoa;
    Pessoa* auxPes;
    Anotacao* anot;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof(char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 4;
    cpf = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    sscanf (par->comando, "%s", cpf);
    auxPes = cria_pessoa ("", "", cpf, "", "");
    pessoa = get_hashtable (par->hash_pessoas, auxPes);
    free_pessoa (auxPes);
    auxPes = NULL;
    free(cpf);
    cpf = NULL;
    if (pessoa == NULL)
    {
        result = (char*) calloc (55, sizeof (char));
        sprintf (result, "\nMORADOR NÃO ENCONTRADO!\n\n");
        insere_fila (par->resultado, result);
        return;
    }
    relatorio = relatorio_endereco_pessoa (pessoa);
    insere_fila (par->resultado, relatorio);
    coord = get_xy_pessoa (pessoa, par);
    result = (char*) calloc (55, sizeof (char));
    sprintf (result, "X - %lf Y - %lf\n", *coord, *(coord + 1));
    insere_fila (par->resultado, result);
    anot = cria_anotacao (10, 10, *coord, *(coord + 1), "dm");
    insere_fila (par->anotacoes, anot);
    result = (char*) calloc (5, sizeof (char));
    sprintf (result, "\n");
    insere_fila (par->resultado, result);
    free(coord);
    coord = NULL;
    free (cpf);
    cpf = NULL;
    return;
}

void caso_de_pergunta (Parametros* par)
{
    double* coord;
    char* aux;
    char* cnpj;
    char* result;
    char* relatorio;
    Comercio* comercio;
    Comercio* auxCom;
    Anotacao* anot;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof(char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 4;
    cnpj = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    sscanf (par->comando, "%s", cnpj);
    auxCom = cria_comercio (cnpj, "", "", "", "", "");
    comercio = get_hashtable (par->hash_comercios, auxCom);
    free_comercio (auxCom);
    auxCom = NULL;
    if (comercio == NULL)
    {
        result = (char*) calloc (55, sizeof (char));
        sprintf (result, "\nCOMÉRCIO NÃO ENCONTRADO!\n\n");
        insere_fila (par->resultado, result);
        return;
    }
    relatorio = relatorio_comercio (comercio);
    insere_fila (par->resultado, relatorio);
    coord = get_xy_comercio (comercio, par);
    result = (char*) calloc (55, sizeof (char));
    sprintf (result, "X - %lf Y - %lf\n", *coord, *(coord + 1));
    insere_fila (par->resultado, result);
    anot = cria_anotacao (10, 0, *coord, *(coord + 1), "de");
    insere_fila (par->anotacoes, anot);
    result = (char*) calloc (5, sizeof (char));
    sprintf (result, "\n");
    insere_fila (par->resultado, result);
    free(coord);
    coord = NULL;
    free (cnpj);
    cnpj = NULL;
    free(coord);
    coord = NULL;
    return;
}

void caso_rip (Parametros* par)
{
    double* coord;
    char* aux;
    char* cpf;
    char* result;
    char* relatorio;
    Pessoa* pessoa;
    Pessoa* auxPes;
    Endereco* end;
    Anotacao anot;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 4;
    cpf = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    sscanf (par->comando, "%s", cpf);
    auxPes = cria_pessoa ("", "", cpf, "", "");
    pessoa = get_hashtable (par->hash_pessoas, auxPes);
    free_pessoa (auxPes);
    auxPes = NULL;
    if (pessoa == NULL)
    {
        result = (char*) calloc (55, sizeof (char));
        sprintf (result, "\nPESSOA NÃO ENCONTRADA!\n\n");
        insere_fila (par->resultado, result);
        return;
    }
    relatorio = relatorio_morte_pessoa (pessoa);
    insere_fila (par->resultado, relatorio);
    coord = get_xy_pessoa (pessoa, par);
    anot = cria_anotacao (10, 10, *coord, *(coord + 1), "rip");
    insere_fila (par->anotacoes, anot);
    end = get_endereco_pessoa (pessoa);
    if (end != NULL)
    {
        remove_hashtable (par->hash_end_pessoas, end);
    }
    remove_hashtable (par->hash_pessoas, pessoa);
    //free_pessoa (pessoa);
    result = (char*) calloc (5, sizeof (char));
    sprintf (result, "\n");
    insere_fila (par->resultado, result);
    free(coord);
    coord = NULL;
    free (cpf);
    cpf = NULL;
    return;
}

void caso_ecq_pergunta (Parametros* par)
{
    char* aux;
    char* cep;
    char* result;
    char* relatorio;
    void* endereco;
    void* primeiro;
    void* comercio;
    void* valor;
    Lista enderecos;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 5;
    cep = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    sscanf (par->comando, "%s", cep);
    endereco = identificador_endereco_comercio (cep);
    enderecos = get_lista_hashtable (par->hash_end_comercios, endereco);
    free (endereco);
    endereco = NULL;
    if (!largura_lista (enderecos))
    {
        result = (char*) calloc (55, sizeof (char));
        sprintf (result, "\nNENHUM COMÉRCIO ENCONTRADO NESSA QUADRA!\n\n");
        insere_fila (par->resultado, result);
        free(cep);
        cep = NULL;
        free(enderecos);
        enderecos = NULL;
        return;
    }
    primeiro = get_primeiro_lista (enderecos);
    do
    {
        valor = get_valor_lista (primeiro);
        if (valor == NULL)
        {
            primeiro = get_proximo_lista (enderecos, primeiro);
            continue;
        }
        comercio = get_comercio_endereco (valor);
        result = (char*) calloc (55, sizeof (char));
        sprintf (result, "\nCNPJ: %s", get_cnpj_comercio (comercio));
        insere_fila (par->resultado, result);
        relatorio = relatorio_comercio (comercio);
        insere_fila (par->resultado, relatorio);
        primeiro = get_proximo_lista (enderecos, primeiro);
    }
    while (primeiro != NULL);

    for(size_t i = 0; i < largura_lista(enderecos); i++)
    {
        remove_lista(enderecos, get_primeiro_lista(enderecos));
    }
    free(enderecos);
    enderecos = NULL;

    result = (char*) calloc (5, sizeof (char));
    sprintf (result, "\n");
    insere_fila (par->resultado, result);
    free (cep);
    cep = NULL;
    return;
}

void caso_ecr_pergunta (Parametros* par)
{
    int i;
    double w, h, x, y;
    char* aux;
    char* tipo;
    char* result;
    char* relatorio;
    char* relatorioCom;
    void* primeiro;
    void* percorre;
    void* endereco;
    void* comercio;
    void* valor;
    Lista quadras;
    Lista report;
    Lista enderecos;
    Quadra quadra;
    Anotacao* anot;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 5;
    tipo = (char*) calloc (55, sizeof (char));
    sscanf (par->comando, "%s", tipo);
    par->comando += strlen (tipo);
    i = strlen (par->comando);
    if (i <= 1)
    {
        i = 0;
        report = get_todos_hashtable (par->hash_quadras);
        if (!largura_lista (report))
        {
            result = (char*) calloc (55, sizeof (char));
            sprintf (result, "\nNENHUMA QUADRA ENCONTRADA!");
            insere_fila (par->resultado, result);
            return;
        }
        primeiro = get_primeiro_lista (report);
        do
        {
            quadra = get_valor_lista (primeiro);
            if (quadra == NULL)
            {
                primeiro = get_proximo_lista (report, primeiro);
                continue;
            }
            endereco = identificador_endereco_comercio (get_cep_quadra (quadra));
            enderecos = get_lista_hashtable (par->hash_end_comercios, endereco);
            free (endereco);
            endereco = NULL;
            if (!largura_lista (enderecos))
            {
                primeiro = get_proximo_lista (report, primeiro);
                continue;
            }
            percorre = get_primeiro_lista (enderecos);
            do
            {
                valor = get_valor_lista (percorre);
                if (valor == NULL)
                {
                    percorre = get_proximo_lista (enderecos, percorre);
                    continue;
                }    
                comercio = get_comercio_endereco (valor);
                if (!strcmp (get_codigo_tipo_comercio (comercio), tipo))
                {
                    relatorioCom = relatorio_comercio (comercio);
                    insere_fila (par->resultado, relatorioCom);
                    i++;
                }
                percorre = get_proximo_lista (enderecos, percorre);
                continue;
            }
            while (percorre != NULL);
            primeiro = get_proximo_lista (report, primeiro);
            continue;
        }
        while (primeiro != NULL);
        if (i == 0)
        {
            result = (char*) calloc (55, sizeof (char));
            sprintf (result, "\nNENHUM COMÉRCIO DO TIPO ESPECIFICADO FOI ENCONTRADO!\n");
            insere_fila (par->resultado, result);
        }
        return;
    }
    sscanf (par->comando, "%lf %lf %lf %lf", &x, &y, &w, &h);
    quadras = get_todos_hashtable (par->hash_quadras);
    report = reporta_quadra_dentro_retangulo (quadras, w, h, x, y);
    
    for(size_t i = 0; i < largura_lista(quadras); i++)
    {
        remove_lista(quadras, get_primeiro_lista(quadras));
    }
    free(quadras);
    quadras = NULL;
    
    if (!largura_lista (report))
    {
        result = (char*) calloc (75, sizeof (char));
        sprintf (result, "\nNENHUMA QUADRA ENCONTRADA DENTRO DO RETÂNGULO ESPECIFICADO!");
        insere_fila (par->resultado, result);
        anot = cria_anotacao (w, h, x, y, "ecr");
        insere_fila (par->anotacoes, anot);

        free(report);
        report = NULL;
        return;
    }
    primeiro = get_primeiro_lista (report);
    do
    {
        quadra = get_valor_lista (primeiro);
        if (quadra == NULL)
        {
            primeiro = get_proximo_lista (report, primeiro);
            continue;
        }
        result = (char*) calloc (55, sizeof (char));
        sprintf (result, "\nQuad - CEP = %s", get_cep_quadra (quadra));
        insere_fila (par->resultado, result);
        endereco = identificador_endereco_comercio (get_cep_quadra (quadra));
        enderecos = get_lista_hashtable (par->hash_end_comercios, endereco);
        free_endereco (endereco);
        endereco = NULL;
        if (!largura_lista (enderecos))
        {
            result = (char*) calloc (55, sizeof (char));
            sprintf (result, "\nNENHUM COMÉRCIO DO TIPO ESPECIFICADO NESSA QUADRA!");
            insere_fila (par->resultado, result);
            primeiro = get_proximo_lista (report, primeiro);

            free(enderecos);
            enderecos = NULL;
            continue;
        }
        percorre = get_primeiro_lista (enderecos);
        do
        {
            valor = get_valor_lista (percorre);
            if (valor == NULL)
            {
                percorre = get_proximo_lista (enderecos, percorre);
                continue;
            }    
            comercio = get_comercio_endereco (valor);
            if (!strcmp (get_codigo_tipo_comercio (comercio), tipo))
            {
                relatorioCom = relatorio_comercio (comercio);
                insere_fila (par->resultado, relatorioCom);
            }
            percorre = get_proximo_lista (enderecos, percorre);
        }
        while (percorre != NULL);
        primeiro = get_proximo_lista (report, primeiro);

        for(size_t i = 0; i < largura_lista(enderecos); i++)
        {
            remove_lista(enderecos, get_primeiro_lista(enderecos));
        }
        free(enderecos);
        enderecos = NULL;
        
    }
    while (primeiro != NULL);
    
    for(size_t i = 0; i < largura_lista(report); i++)
    {
        remove_lista(report, get_primeiro_lista(report));
    }
    free(report);
    report = NULL;
    
    anot = cria_anotacao (w, h, x, y, "ecr");
    insere_fila (par->anotacoes, anot);
    result = (char*) calloc (5, sizeof (char));
    sprintf (result, "\n");
    insere_fila (par->resultado, result);
    free (tipo);
    tipo = NULL;
    return;
}

void caso_tecq_pergunta (Parametros* par)
{
    char* aux;
    char* cep;
    char* relatorio;
    char* relatorioCom;
    void* endereco;
    void* primeiro;
    void* auxA;
    Comercio* comercio;
    Quadra* quadra;
    Quadra* quadraAux;
    Endereco* end;
    Lista comercios;
    Lista enderecos;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 6;
    cep = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (cep, par->comando);
    quadraAux = cria_quadra (cep, 0, 0, 0, 0, "", "");
    quadra = get_hashtable (par->hash_quadras, quadraAux);
    free_quadra (quadraAux);
    quadraAux = NULL;
    if (quadra == NULL)
    {
        relatorio = (char*) calloc (55, sizeof (char));
        sprintf (relatorio, "\nERRO: QUADRA NÃO ENCONTRADA!\n\n");
        insere_fila (par->resultado, relatorio);
        free(cep);
        cep = NULL;
        return;
    }
    end = identificador_endereco_comercio (cep);
    enderecos = get_lista_hashtable (par->hash_end_comercios, end);
    free (end);
    end = NULL;
    if (!largura_lista (enderecos))
    {
        relatorio = (char*) calloc (55, sizeof (char));
        sprintf (relatorio, "\nNENHUM COMÉRCIO ENCONTRADO NESSA QUADRA!");
        insere_fila (par->resultado, relatorio);
        free(cep);
        cep = NULL;
        return;
    }
    comercios = cria_lista ();
    primeiro = get_primeiro_lista (enderecos);
    do
    {
        auxA = get_valor_lista (primeiro);
        if (auxA == NULL)
        {
            primeiro = get_proximo_lista (enderecos, primeiro);
            continue;
        }
        insere_lista (comercios, get_comercio_endereco (auxA));
        primeiro = get_proximo_lista (enderecos, primeiro);
    }
    while (primeiro != NULL);

    for(size_t i = 0; i < largura_lista(enderecos); i++)
    {
        remove_lista(enderecos, get_primeiro_lista(enderecos));
    }
    free(enderecos);
    enderecos = NULL;

    relatorio = (char*) calloc (55, sizeof (char));
    sprintf (relatorio, "\nQuad - CEP - %s", cep);
    insere_fila (par->resultado, relatorio);
    relatorioCom = imprime_tipos_comercios_quadra (comercios);
    insere_fila (par->resultado, relatorioCom);
    relatorio = (char*) calloc (5, sizeof (char));
    sprintf (relatorio, "\n");
    insere_fila (par->resultado, relatorio);
    free (cep);
    cep = NULL;
    free(comercios);
    comercios = NULL;
    return;
}

void caso_tecr_pergunta (Parametros* par)
{
    double w, h, x, y;
    char* aux;
    char* relatorio;
    char* relatorioQuad;
    void* valor;
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
    Anotacao* anot;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 6;
    sscanf (par->comando, "%lf %lf %lf %lf", &x, &y, &w, &h);
    quadras = get_todos_hashtable (par->hash_quadras);
    report = reporta_quadra_dentro_retangulo (quadras, w, h, x, y);

    for(size_t i = 0; i < largura_lista(quadras); i++)
    {
        remove_lista(quadras, get_primeiro_lista(quadras));
    }
    free(quadras);
    quadras = NULL;

    if (!largura_lista (report))
    {
        relatorio = (char*) calloc (155, sizeof (char));
        sprintf (relatorio, "\nNENHUMA QUADRA INTEIRAMENTE DENTRO DA ÁREA PEDIDA!\n\n");
        insere_fila (par->resultado, relatorio);
        anot = cria_anotacao (w, h, x, y, "tecr");
        insere_fila (par->anotacoes, anot);
        return;
    }
    primeiro = get_primeiro_lista (report);
    do
    {
        valor = get_valor_lista (primeiro);
        if (valor == NULL)
        {
            primeiro = get_proximo_lista (report, primeiro);
            continue;
        }
        relatorio = (char*) calloc (155, sizeof (char));
        sprintf (relatorio, "\nQuad - CEP - %s", get_cep_quadra (valor));
        insere_fila (par->resultado, relatorio);
        end = identificador_endereco_comercio (get_cep_quadra (valor));
        enderecos = get_lista_hashtable (par->hash_end_comercios, end);
        free_endereco (end);
        if (!largura_lista (enderecos))
        {
            relatorioQuad = (char*) calloc (55, sizeof (char));
            sprintf (relatorioQuad, "\nNENHUM COMÉRCIO NESSA QUADRA!\n");
            insere_fila (par->resultado, relatorioQuad);
            primeiro = get_proximo_lista (report, primeiro);

            free(enderecos);
            enderecos = NULL;
            continue;
        }
        comercios = cria_lista ();
        percorre = get_primeiro_lista (enderecos);
        do
        {
            auxA = get_valor_lista (percorre);
            if (auxA == NULL)
            {
                percorre = get_proximo_lista (enderecos, percorre);
                continue;
            }
            insere_lista (comercios, get_comercio_endereco (auxA));
            percorre = get_proximo_lista (enderecos, percorre);
        }
        while (percorre != NULL);
        relatorioQuad = imprime_tipos_quadra (comercios);
        insere_fila (par->resultado, relatorioQuad);
        primeiro = get_proximo_lista (report, primeiro);

        for(size_t i = 0; i < largura_lista(enderecos); i++)
        {
            remove_lista(enderecos, get_primeiro_lista(enderecos));
        }
        free(enderecos);
        enderecos = NULL;
        
        for(size_t i = 0; i < largura_lista(comercios); i++)
        {
            remove_lista(comercios, get_primeiro_lista(comercios));
        }
        free(comercios);
        comercios = NULL;
    }
    while (primeiro != NULL);
    
    for(size_t i = 0; i < largura_lista(report); i++)
    {
        remove_lista(report, get_primeiro_lista(report));
    }
    free(report);
    report = NULL;
    
    anot = cria_anotacao (w, h, x, y, "tecr");
    insere_fila (par->anotacoes, anot);
    relatorio = (char*) calloc (5, sizeof (char));
    sprintf (relatorio, "\n");
    insere_fila (par->resultado, relatorio);
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
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    cep = (char*) calloc (55, sizeof (char));
    face = (char*) calloc (55, sizeof (char));
    num = (char*) calloc (55, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 6;
    sscanf (par->comando, "%s %s %s", cep, face, num);
    pes = cria_pessoa ("", "", "", "", "");
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
    free (cep);
    cep = NULL;
    free (face);
    face = NULL;
    free (num);
    num = NULL;
    return;
}
void caso_hmp_pergunta (Parametros* par)
{
    double dist, r, x, y;
    char* aux;
    char* id;
    char* saida;
    Radiobase auxRb;
    Radiobase rb;
    Hidrante hidA;
    Hidrante hidB;
    Anotacao* anot;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 5;
    id = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (id, par->comando);
    auxRb = cria_radiobase (id, 0, 0, 0, "", "");
    rb = get_hashtable (par->hash_radiobases, auxRb);
    free_radiobase (auxRb);
    if (rb == NULL)
    {
        saida = (char*) calloc (55, sizeof (char));
        sprintf (saida, "\nRÁDIOBASE NÃO ENCONTRADA!\n");
        insere_fila (par->resultado, saida);
        return;
    }
    r = get_r_radiobase (rb);
    x = get_x_radiobase (rb);
    y = get_y_radiobase (rb);
    hidA = cria_hidrante (id, r, x, y, "", "");
    hidB = vizinho_proximo_arvore (par->tree_hidrantes, hidA);
    dist = dist_arvore (par->tree_hidrantes, hidA, hidB);
    saida = (char*) calloc (155, sizeof (char));
    sprintf (saida, "\nRbs - ID = %s \nHid - ID = %s \nDISTÂNCIA = %lf\n", id, get_id_hidrante (hidB), dist);
    insere_fila (par->resultado, saida);
    anot = cria_anotacao (get_x_hidrante (hidA), get_y_hidrante (hidA), get_x_hidrante (hidB), get_y_hidrante (hidB), "hmp");
    insere_fila (par->anotacoes, anot);
    free (id);
    id = NULL;
    return;
}
void caso_fec (Parametros* par)
{
    char* aux;
    char* cnpj;
    char* relatorio;
    Comercio* comercio;
    Comercio* comercioAux;
    Endereco* end;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 4;
    cnpj = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    sscanf (par->comando, "%s", cnpj);
    comercioAux = cria_comercio (cnpj, "", "", "", "", "");
    comercio = get_hashtable (par->hash_comercios, comercioAux);
    free_comercio (comercioAux);
    if (comercio == NULL)
    {
        relatorio = (char*) calloc (155, sizeof (char));
        sprintf (relatorio, "\nCOMÉRCIO NÃO ENCONTRADO!\n");
        insere_fila (par->resultado, relatorio);
        return;
    }
    relatorio = relatorio_comercio (comercio);
    insere_fila (par->resultado, relatorio);
    end = get_endereco_comercio (comercio);
    remove_hashtable (par->hash_end_comercios, end);
    remove_hashtable (par->hash_comercios, comercio);
    free_comercio (comercio);
    free (cnpj);
    cnpj = NULL;
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
    char* result;
    Pessoa* pes;
    Pessoa* pesAux;
    Endereco* endAntigo;
    Endereco* endNovo;
    Anotacao* anot;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 4;
    cpf = (char*) calloc (25, sizeof (char));
    cep = (char*) calloc (25, sizeof (char));
    face = (char*) calloc (25, sizeof (char));
    num = (char*) calloc (25, sizeof (char));
    comp = (char*) calloc (25, sizeof (char)); 
    sscanf (par->comando, "%s %s %s %s %s", cpf, cep, face, num, comp);
    pesAux = cria_pessoa ("", "", cpf, "", "");
    pes = get_hashtable (par->hash_pessoas, pesAux);
    free_pessoa (pesAux);
    if (pes == NULL)
    {
        result = (char*) calloc (55, sizeof (char));
        sprintf (result, "\nMORADOR NÃO ENCONTRADO!\n\n");
        insere_fila (par->resultado, result);
        return;
    }
    endAntigo = get_endereco_pessoa (pes);
    coordAntiga = get_xy_pessoa (pes, par);
    linha = relatorio_mud_pessoa (pes, endAntigo, NULL);
    remove_hashtable (par->hash_end_pessoas, endAntigo);
    endNovo = set_endereco_pessoa (pes, cep, face, num, comp);
    coordNova = get_xy_pessoa (pes, par); 
    strcat (linha, relatorio_mud_pessoa (pes, NULL, endNovo));
    insere_hashtable (par->hash_end_pessoas, endNovo);
    insere_fila (par->resultado, linha);
    anot = cria_anotacao (*coordAntiga, *(coordAntiga + 1), *coordNova, *(coordNova + 1), "mud");
    insere_fila (par->anotacoes, anot);
    result = (char*) calloc (5, sizeof (char));
    sprintf (result, "\n");
    insere_fila (par->resultado, result);
    free (cpf);
    cpf = NULL;
    free (cep);
    cep = NULL;
    free (face);
    face = NULL;
    free (num);
    num = NULL;
    free (comp);
    comp = NULL;
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
    char* result;
    Comercio* com;
    Comercio* comAux;
    Endereco* endAntigo;
    Endereco* endNovo;
    Anotacao* anot;
    aux = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 6;
    cnpj = (char*) calloc (55, sizeof (char));
    cep = (char*) calloc (55, sizeof (char));
    face = (char*) calloc (55, sizeof (char));
    num = (char*) calloc (55, sizeof (char));
    sscanf (par->comando, "%s %s %s %s", cnpj, cep, face, num);
    comAux = cria_comercio (cnpj, "", "", "", "", "");
    com = get_hashtable (par->hash_comercios, comAux);
    free_comercio (comAux);
    if (com == NULL)
    {
        result = (char*) calloc (55, sizeof (char));
        sprintf (result, "\nCOMÉRCIO NÃO ENCONTRADO!\n\n");
        insere_fila (par->resultado, result);
        return;
    }
    endAntigo = get_endereco_comercio (com);
    coordAntiga = get_xy_comercio (com, par);
    linha = relatorio_mud_comercio (com, endAntigo, NULL);
    remove_hashtable (par->hash_end_comercios, endAntigo);
    endNovo = set_endereco_comercio (com, cep, face, num);
    coordNova = get_xy_comercio (com, par);
    strcat (linha, relatorio_mud_comercio (com, NULL, endNovo));
    insere_hashtable (par->hash_end_comercios, endNovo);
    insere_fila (par->resultado, linha);
    anot = cria_anotacao (*coordAntiga, *(coordAntiga + 1), *coordNova, *(coordNova + 1), "mudec");
    insere_fila (par->anotacoes, anot);
    free (cnpj);
    cnpj = NULL;
    free (cep);
    cep = NULL;
    free (face);
    face = NULL;
    free (num);
    num = NULL;
    return;
}

void caso_dpr (Parametros* par)
{
    double x, y, w, h, xi, xf, yi, yf;
    char* aux;
    char* tempChar;
    void* primeiro;
    void* ident;
    void* auxA; 
    void* rc;
    void* cont;
    void* temp;
    void* temp2;
    void* com;
    void* pes;
    void* circ;
    Anotacao* anot;
    Endereco* endAux;
    Lista quadras;
    Lista hidrantes;
    Lista semaforos;
    Lista radiobases;
    Lista enderecos;
    aux = (char*) calloc (55, sizeof (char));
    strcpy (aux, par->comando);
    insere_fila (par->resultado, aux);
    par->comando += 4;
    sscanf (par->comando, "%lf %lf %lf %lf", &x, &y, &w, &h);
    anot = cria_anotacao (w, h, x, y, "dpr");
    insere_fila (par->anotacoes, anot);
    quadras = get_todos_hashtable (par->hash_quadras);
    primeiro = get_primeiro_lista (quadras);
    do
    {
        cont = get_valor_lista (primeiro);
        if (cont == NULL)
        {
            primeiro = get_proximo_lista (quadras, primeiro);
            continue;
        }
        rc = get_retangulo_quadra (cont);
        xi = get_x_retangulo (rc);
        xf = xi + get_w_retangulo (rc);
        yi = get_y_retangulo (rc);
        yf = yi + get_h_retangulo (rc);
        free_retangulo (rc);
        if (xi >= x && yi >= y && xf <= x + w && yf <= y + h)
        {
            tempChar = (char*) calloc (55, sizeof (char));
            sprintf (tempChar, "\nQuad - CEP = %s", get_cep_quadra (cont));
            insere_fila (par->resultado, tempChar);
            ident = identificador_endereco_comercio (get_cep_quadra (cont));
            enderecos = get_lista_hashtable (par->hash_end_comercios, ident);
            free_endereco (ident);
            if (!largura_lista (enderecos))
            {
                tempChar = (char*) calloc (55, sizeof (char));
                sprintf (tempChar, "\nNENHUM COMÉRCIO ENCONTRADO NESSA QUADRA!\n");
                insere_fila (par->resultado, tempChar);
            }
            else
            {
                auxA = get_primeiro_lista (enderecos);
                do
                {
                    temp = get_valor_lista (auxA);
                    if (temp == NULL)
                    {
                        auxA = get_proximo_lista (enderecos, auxA);
                        continue;
                    }
                    com = get_comercio_endereco (temp);
                    tempChar = relatorio_comercio (com);
                    insere_fila (par->resultado, tempChar);
                    endAux = get_endereco_comercio (com);
                    temp2 = get_proximo_lista (enderecos, auxA);
                    remove_hashtable (par->hash_end_comercios, endAux);
                    remove_hashtable (par->hash_comercios, com);
                    remove_lista (enderecos, auxA);
                    // free (endAux);
                    // endAux = NULL;
                    free_comercio (com);    
                    auxA = temp2;
                }
                while (auxA != NULL);
            }
            free(enderecos);
            enderecos = NULL;

            char* auxCep = get_cep_quadra (cont);
            ident = identificador_endereco_pessoa (auxCep);
            enderecos = get_lista_hashtable (par->hash_end_pessoas, ident);
            free_endereco (ident);
            if (largura_lista (enderecos) == 0)
            {
                tempChar = (char*) calloc (55, sizeof (char));
                sprintf (tempChar, "\nNENHUMA PESSOA ENCONTRADA NESSA QUADRA!\n");
                insere_fila (par->resultado, tempChar);
            }
            else
            {
                auxA = get_primeiro_lista (enderecos);
                do
                {
                    temp = get_valor_lista (auxA);
                    if (temp == NULL)
                    {
                        auxA = get_proximo_lista (enderecos, auxA);
                        continue;
                    }
                    pes = get_pessoa_endereco (temp);
                    tempChar = relatorio_endereco_pessoa (pes);
                    insere_fila (par->resultado, tempChar);
                    endAux = get_endereco_pessoa (pes);
                    temp2 = get_proximo_lista (enderecos, auxA);
                    remove_hashtable (par->hash_end_pessoas, endAux);
                    remove_hashtable (par->hash_pessoas, pes);
                    //free (endAux);
                    //endAux = NULL;
                    remove_lista (enderecos, auxA);
                    free_pessoa (pes);
                    auxA = temp2;
                }
                while (auxA != NULL);
            }
            
            for(size_t i = 0; i < largura_lista(enderecos); i++)
            {
                remove_lista(enderecos, get_primeiro_lista(enderecos));
            }
            free(enderecos);
            enderecos = NULL;
            
            temp2 = get_proximo_lista (quadras, primeiro);
            remove_valor_arvore (par->tree_quadras, cont);
            remove_hashtable (par->hash_quadras, cont);
            remove_lista (quadras, primeiro);
            //free_quadra (cont);
            primeiro = temp2;
        }
        else
        {
            primeiro = get_proximo_lista (quadras, primeiro);
        }
    }
    while (primeiro != NULL);
    free (quadras);
    quadras = NULL;
    tempChar = (char*) calloc (5, sizeof (char));
    sprintf (tempChar, "\n");
    insere_fila (par->resultado, tempChar);
    hidrantes = get_todos_hashtable (par->hash_hidrantes);
    primeiro = get_primeiro_lista (hidrantes);
    do
    {
        cont = get_valor_lista (primeiro);
        if (cont == NULL)
        {
            primeiro = get_proximo_lista (hidrantes, primeiro);
            continue;
        }
        circ = get_circulo_hidrante (cont);
        xi = get_x_circulo (circ) - get_r_circulo (circ);
        xf = get_x_circulo (circ) + get_r_circulo (circ);
        yi = get_y_circulo (circ) - get_r_circulo (circ);
        yf = get_y_circulo (circ) + get_r_circulo (circ);
        free_circulo (circ);
        if(xi >= x && yi >= y && xf <= x + w && yf <= y + h)
        {
            tempChar = (char*) calloc (155, sizeof (char));
            sprintf (tempChar, "Hid - ID = %s   X - %lf   Y - %lf", get_id_hidrante (cont), get_x_hidrante (cont), get_y_hidrante (cont));
            insere_fila (par->resultado, tempChar);
            tempChar = (char*) calloc (5, sizeof (char));
            sprintf (tempChar, "\n");
            insere_fila (par->resultado, tempChar);
            temp2 = get_proximo_lista (hidrantes, primeiro);
            remove_lista (hidrantes, primeiro);
            remove_valor_arvore (par->tree_hidrantes, cont);
            remove_hashtable (par->hash_hidrantes, cont);
            primeiro = temp2;
        }
        else
        {
            primeiro = get_proximo_lista (hidrantes, primeiro);
        }
    }   
    while (primeiro != NULL);
    free (hidrantes);
    hidrantes = NULL;
    tempChar = (char*) calloc (5, sizeof (char));
    sprintf (tempChar, "\n");
    insere_fila (par->resultado, tempChar);
    semaforos = get_todos_hashtable (par->hash_semaforos);
    primeiro = get_primeiro_lista (semaforos);
    do
    {
        cont = get_valor_lista (primeiro);
        if (cont == NULL)
        {
            primeiro = get_proximo_lista (semaforos, primeiro);
            continue;
        }
        circ = get_circulo_semaforo (cont);
        xi = get_x_circulo (circ) - get_r_circulo (circ);
        xf = get_x_circulo (circ) + get_r_circulo (circ);
        yi = get_y_circulo (circ) - get_r_circulo (circ);
        yf = get_y_circulo (circ) + get_r_circulo (circ);
        free_circulo (circ);
        if(xi >= x && yi >= y && xf <= x + w && yf <= y + h)
        {
            tempChar = (char*) calloc (155, sizeof (char));
            sprintf (tempChar, "Sem - ID = %s   X - %lf   Y - %lf", get_id_semaforo (cont), get_x_semaforo (cont), get_y_semaforo (cont));
            insere_fila (par->resultado, tempChar);
            tempChar = (char*) calloc (5, sizeof (char));
            sprintf (tempChar, "\n");
            insere_fila (par->resultado, tempChar);
            temp2 = get_proximo_lista (semaforos, primeiro);
            remove_lista (semaforos, primeiro);
            remove_valor_arvore (par->tree_semaforos, cont);
            remove_hashtable (par->hash_semaforos, cont);
            primeiro = temp2;
        }
        else
        {
            primeiro = get_proximo_lista (semaforos, primeiro);
        }
    }
    while (primeiro != NULL);
    free (semaforos);
    semaforos = NULL;
    tempChar = (char*) calloc (5, sizeof (char));
    sprintf (tempChar, "\n");
    insere_fila (par->resultado, tempChar);
    radiobases = get_todos_hashtable (par->hash_radiobases);
    primeiro = get_primeiro_lista (radiobases);
    do
    {
        cont = get_valor_lista (primeiro);
        if (cont == NULL)
        {
            primeiro = get_proximo_lista (radiobases, primeiro);
            continue;
        }
        circ = get_circulo_radiobase (cont);
        xi = get_x_circulo (circ) - get_r_circulo (circ);
        xf = get_x_circulo (circ) + get_r_circulo (circ);
        yi = get_y_circulo (circ) - get_r_circulo (circ);
        yf = get_y_circulo (circ) + get_r_circulo (circ);
        free_circulo (circ);
        if(xi >= x && yi >= y && xf <= x + w && yf <= y + h)
        {
            tempChar = (char*) calloc (155, sizeof (char));
            sprintf (tempChar, "Rbs - ID = %s   X - %lf   Y - %lf", get_id_radiobase (cont), get_x_radiobase (cont), get_y_radiobase (cont));
            insere_fila (par->resultado, tempChar);
            tempChar = (char*) calloc (5, sizeof (char));
            sprintf (tempChar, "\n");
            insere_fila (par->resultado, tempChar);
            temp2 = get_proximo_lista (radiobases, primeiro);
            remove_lista (radiobases, primeiro);
            remove_valor_arvore (par->tree_radiobases, cont);
            remove_hashtable (par->hash_radiobases, cont);
            primeiro = temp2;
        }
        else
        {
            primeiro = get_proximo_lista (radiobases, primeiro);
        }
    }
    while (primeiro != NULL);
    free (radiobases);
    radiobases = NULL;
    tempChar = (char*) calloc (5, sizeof (char));
    sprintf (tempChar, "\n");
    insere_fila (par->resultado, tempChar);
    return;
}

void caso_arroba_m_pergunta (Parametros* par) 
{
    char* registrador = NULL;
    char* cpf = NULL;
    double* pos_pessoa = NULL;
    Pessoa pessoa = NULL;
    Pessoa auxPes = NULL;
    int r = 0;
    registrador = (char*) calloc (5, sizeof (char));
    cpf = (char*) calloc (25, sizeof (char));
    sscanf (par->comando, "%s %s", registrador, cpf);
    auxPes = cria_pessoa ("", "", cpf, "", "");
    pessoa = get_hashtable (par->hash_pessoas, auxPes);
    pos_pessoa = get_xy_pessoa (pessoa, par);
    r = busca_registrador (par->regis, registrador);
    insere_pos_registrador (par->regis[r], pos_pessoa);
    free (registrador);
    registrador = NULL;
    free (cpf);
    cpf = NULL;
    r = 0;
    return;
}

void caso_arroba_e_pergunta (Parametros* par)
{
    char* registrador = NULL;
    char* cep = NULL;
    char* face = NULL;
    char* num = NULL;
    double *pos_comercio = NULL;
    Comercio auxCom = NULL;
    int r = 0;
    registrador = (char*) calloc (5, sizeof (char));
    cep = (char*) calloc (255, sizeof (char));
    face = (char*) calloc (255, sizeof (char));
    num = (char*) calloc (255, sizeof (char));
    sscanf (par->comando, "%s %s %s %s", registrador, cep, face, num);
    auxCom = cria_comercio ("", NULL, cep, face, num, "");
    pos_comercio = get_xy_comercio (auxCom, par);
    r = busca_registrador (par->regis, registrador);
    insere_pos_registrador (par->regis[r], pos_comercio);
    free (registrador);
    registrador = NULL;
    free (cep);
    cep = NULL;
    free (face);
    face = NULL;
    free (num);
    num = NULL;
    r = 0;
    return;
}

void caso_arroba_g_pergunta (Parametros* par)
{
    char* registrador = NULL;
    char* id = NULL;
    int r = 0;
    void* auxEquip = NULL;
    void* equipamento = NULL;
    double* pos_equipamento = NULL;
    registrador = (char*) calloc (5, sizeof (char));
    id = (char*) calloc (255, sizeof (char));
    sscanf (par->comando, "%s %s", registrador, id);
    auxEquip = cria_hidrante (id, 0, 0, 0, "", "");
    equipamento = get_hashtable (par->hash_hidrantes, auxEquip);
    if (equipamento == NULL)
    {
        auxEquip = cria_radiobase (id, 0, 0, 0, "", "");
        equipamento = get_hashtable (par->hash_radiobases, auxEquip);
        
        if (equipamento == NULL) 
        {
            auxEquip = cria_semaforo(id, 0, 0, 0, "", "");
            equipamento = get_hashtable(par->hash_semaforos, auxEquip);
            if (equipamento == NULL) 
            {
                return;
            }
        }
    }
    r = busca_registrador (par->regis, registrador);
    insere_pos_registrador (par->regis[r], pos_equipamento);
    free (registrador);
    registrador = NULL;
    free (id);
    id = NULL;
    r = 0;
    return;
}

void caso_arroba_xy (Parametros* par)
{
    char* registrador = NULL;
    double* pos = NULL;
    int r = 0;
    registrador = (char*) calloc (5, sizeof (char));
    pos = (double*) calloc (2, sizeof (double));
    sscanf (par->comando, "%s %lf %lf", registrador, pos[0], pos[1]);
    r = busca_registrador (par->regis, registrador);
    insere_pos_registrador (par->regis[r], pos);
    free (registrador);
    registrador = NULL;
    r = 0;
    return;
}

void caso_arroba_tp_pergunta (Parametros* par)
{
    char* r1;
    char* r2;
    char* tipo;
    char* nome;
    double* coord;
    void* comercio;
    int i;
    Registrador reg1;
    Registrador reg2;
    r1 = (char*) calloc (55, sizeof (char));
    r2 = (char*) calloc (55, sizeof (char));
    tipo = (char*) calloc (55, sizeof (char));
    par->comando += 5;
    sscanf (par->comando, "%s %s %s", r1, tipo, r2);
    i = busca_registrador (par->regis, r1);
    reg1 = *(par->regis+i);
    i = busca_registrador (par->regis, r2);
    reg2 = *(par->regis+i);
    coord = get_pos_registrador (reg2);
    comercio = comercio_proximo_coordenada (coord, tipo, par);
    nome = get_nome_comercio (comercio);
    insere_nome_registrador (reg1, nome);
    coord = get_xy_comercio (comercio, par);
    insere_pos_registrador (reg1, coord);
    insere_tipo_registrador (reg1, comercio);
    free (r1);
    r1 = NULL;
    free (r2);
    r2 = NULL;
    free (tipo);
    tipo = NULL;
    return;
}

void caso_p_pergunta(Parametros *par)
{
    char *registrador1 = NULL, *registrador2 = NULL, *cor = NULL;
    double *pos1 = NULL, *pos2 = NULL;
    int r1 = 0, r2 = 0;
    void *v1 = NULL, *v2 = NULL;
    Lista *l = NULL;
    char **vertices = NULL;
    char *cor1 = NULL, *cor2 = NULL;
    Anotacao anot = NULL;
    char *anotTexto = NULL;

    registrador1 = (char *) calloc(5, sizeof(char));
    registrador2 = (char *) calloc(5, sizeof(char));
    cor = (char *) calloc(255, sizeof(char));

    sscanf(par->comando, "%s %s %s", registrador1, registrador2, cor);

    anotTexto = (char *) calloc(60, sizeof(char));

    vertices = melhor_trajeto_registradores(par->regis, registrador1, registrador2, par->grafo_via);

    
    for(size_t i = 0; i < qtd_vertices(par->grafo_via); i++)
    {
        v1 = get_vertice(par->grafo_via, vertices[i]);
        v2 = get_vertice(par->grafo_via, vertices[i+1]);

        pos1 = get_pos_vertice(v1);
        pos2 = get_pos_vertice(v2);
        
        sprintf(anotTexto, "p %s", cor);
        anot = cria_anotacao(pos1[0], pos1[1], pos2[0], pos2[1], anotTexto);

        insere_fila(par->anotacoes, anot);
    }
    ////////////////
}

void caso_sp_pergunta(Parametros *par)
{
    char **registradores = NULL, *cor1 = NULL, *cor2 = NULL;
    char *auxCor = NULL;
    double *pos1 = NULL, *pos2 = NULL;
    int r1 = 0, r2 = 0;
    int n = 0;
    void *v1 = NULL, *v2 = NULL;
    Lista *l = NULL;
    char **vertices = NULL, **auxVertices = NULL;
    Anotacao anot = NULL;
    char *anotTexto = NULL;

    cor1 = (char *) calloc(255, sizeof(char));
    cor2 = (char *) calloc(255, sizeof(char));
    anotTexto = (char *) calloc(60, sizeof(char));

    sscanf(par->comando, "%d", &n);
    registradores = (char **) calloc(n, sizeof(char *));

    for(size_t i = 0; i < n; i++)
    {
        sscanf(par->comando, "%s", registradores[i]);
    }
    
    sscanf(par->comando, "%s %s", cor1, cor2);

    vertices = (char **) calloc (1000, sizeof(char *));
    
    for(size_t i = 0; i < n-1; i++)
    {
        auxVertices = melhor_trajeto_registradores(par->regis, registradores[i], registradores[i+1], par->grafo_via);
        strcat(vertices, auxVertices);
    }
    
    
    for(size_t i = 0; i < qtd_vertices(par->grafo_via); i++)
    {
        v1 = get_vertice(par->grafo_via, vertices[i]);
        v2 = get_vertice(par->grafo_via, vertices[i+1]);

        pos1 = get_pos_vertice(v1);
        pos2 = get_pos_vertice(v2);

        if(i%2 == 0) {
            auxCor = cor1;
        }
        else {
            auxCor = cor2;
        }

        sprintf(anotTexto, "p %s", auxCor);
        anot = cria_anotacao(pos1[0], pos1[1], pos2[0], pos2[1], anotTexto);

        insere_fila(par->anotacoes, anot);
    }
}

void caso_au (Parametros* par)
{
    char* placa;
    double x, y, w, h;
    Carro* carro;
    par->comando += 3;
    placa = (char*) calloc (55, sizeof (char));
    sscanf (par->comando, "%s %lf %lf %lf %lf", placa, &x, &y, &w, &h);
    carro = cria_carro (placa, x, y, w, h);
    free (placa);
    placa = NULL;
    insere_arvore (par->tree_carros, carro);
    insere_hashtable (par->hash_carros, carro);
    return;
}

void caso_dc (Parametros* par)
{
    char* comando;
    char* sufixo;
    char* colisao;
    char* placa1;
    char* placa2;
    char* info;
    char** colisoes;
    void* primeiro;
    void* percorre;
    int i, j, k;
    double x1, x2, y1, y2;
    Lista carros;
    Carro carro1;
    Carro carro2;
    Anotacao anot;
    comando = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (comando, par->comando);
    insere_fila (par->resultado, comando);
    par->comando += 3;
    sufixo = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (sufixo, par->comando);
    carros = get_todos_arvore (par->tree_carros);
    colisoes = detectar_colisoes (carros);
    for (i=0; *(colisoes+i) != NULL; i++)
    {
        colisao = (char*) calloc (strlen (*(colisoes+i)) + 2, sizeof (char));
        strcpy (colisao, *(colisoes+i));
        for (j=0; j<strlen (colisao); j++)
        {
            if (*colisao == "+")
            {
                j++;
                for (k=0; k<strlen (colisao) - j; k++)
                {
                    *(placa2+k) = *(colisao+j+k); 
                }
                break;
            }
            *(placa1+j) = *(colisao+j);
        }
        info = (char*) calloc (strlen (placa1) + strlen (placa2) + 3, sizeof (char));
        sprintf (info, "Colisão - %s e %s", placa1, placa2);
        insere_fila (par->resultado, info);
        carro1 = get_carro_placa (carros, placa1);
        carro2 = get_carro_placa (carros, placa2);
        x1 = get_x_carro (carro1);
        x2 = get_x_carro (carro2);
        y1 = get_y_carro (carro1);
        y2 = get_y_carro (carro2);
        anot = cria_anotacao (x1+x2+1, y1+y2+1, x1-1, y1-1, "colisao");
        insere_fila (par->anotacoes, anot);
    }
    fecha_colisao (par, sufixo);
    return;
}

void caso_rau (Parametros* par)
{
    void* primeiro;
    void* pontAux;
    char* placa;
    char* comando;
    char* info;
    Lista carros;
    Carro* aux;
    comando = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (comando, par->comando);
    insere_fila (par->resultado, comando);
    par->comando += 4;
    placa = (char*) calloc (strlen (par->comando) + 2, sizeof (char));
    strcpy (placa, par->comando);
    carros = get_todos_arvore (par->tree_carros);
    primeiro = get_primeiro_lista (carros);
    do
    {
        if (primeiro == NULL)
        {
            continue;
        }
        aux = get_valor_lista (primeiro);
        if (!strcmp (placa, get_placa_carro))
        {
            info = (char*) calloc (155, sizeof (char));
            sprintf (info, "Carro - PLACA = %s", placa);
            insere_fila (par->resultado, info);
            remove_valor_arvore (par->tree_carros, aux);
            remove_hashtable (par->hash_carros, aux);
            pontAux = get_proximo_lista (carros, primeiro);
            remove_lista (carros, aux);
            primeiro = pontAux;
        }
        primeiro = get_proximo_lista (carros, primeiro);
    }
    while (primeiro != NULL);
}

//COMANDOS REFERENTES AO ARQUIVO .EC

void caso_t_ec (Parametros* par)
{
    char* cod;
    char* info;
    void* tipo;
    cod = (char*) calloc (155, sizeof (char));
    info = (char*) calloc (155, sizeof (char));
    sscanf (par->comando, "%s %s", cod, info);
    tipo = cria_tipo_comercio (cod, info);
    free (cod);
    cod = NULL;
    free (info);
    info = NULL;
    insere_hashtable (par->hash_tipos, tipo);
    return;
}

void caso_e_ec (Parametros* par)
{
    char* cnpj;
    char* cod;
    char* cep;
    char* face;
    char* num;
    char* nome;
    void* comercio;
    void* end;
    Tipo t;
    Tipo tAux;
    cnpj = (char*) calloc (155, sizeof (char));
    cod = (char*) calloc (155, sizeof (char));
    cep = (char*) calloc (155, sizeof (char));
    face = (char*) calloc (155, sizeof (char));
    num = (char*) calloc (155, sizeof (char));
    nome = (char*) calloc (155, sizeof (char));
    sscanf (par->comando, "%s %s %s %s %s %s", cnpj, cod, cep, face, num, nome);
    tAux = cria_tipo_comercio (cod, "");
    t = get_hashtable (par->hash_tipos, tAux);
    free_tipo_comercio (tAux);
    comercio = cria_comercio (cnpj, t, cep, face, num, nome);
    free (cod);
    cod = NULL;
    free (cnpj);
    cnpj = NULL;
    free (cep);
    cep = NULL;
    free (face);
    face = NULL;
    free (num);
    num = NULL;
    free (nome);
    nome = NULL;
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
    pessoa = cria_pessoa (nome, sobrenome, cpf, sexo, nascimento);
    free (cpf);
    cpf = NULL;
    free (nome);
    nome = NULL;
    free (sobrenome);
    sobrenome = NULL;
    free (sexo);
    sexo = NULL;
    free (nascimento);
    nascimento = NULL;
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
    void* auxPes;
    cpf = (char*) calloc (155, sizeof (char));
    cep = (char*) calloc (155, sizeof (char));
    face = (char*) calloc (155, sizeof (char));
    num = (char*) calloc (155, sizeof (char));
    comp = (char*) calloc (155, sizeof (char));
    sscanf (par->comando, "%s %s %s %s %s", cpf, cep, face, num, comp);
    auxPes = cria_pessoa ("", "", cpf, "", "");
    pessoa = get_hashtable (par->hash_pessoas, auxPes);
    free_pessoa (auxPes);
    free (cpf);
    cpf = NULL;
    if (pessoa == NULL)
    {
        printf ("\nERRO: MORADOR NAO ENCONTRADO!");
        free (cep);
        cep = NULL;
        free (face);
        face = NULL;
        free (num);
        num = NULL;
        free (comp);
        comp = NULL;
        return;
    }
    end = set_endereco_pessoa (pessoa, cep, face, num, comp);
    free (cep);
    cep = NULL;
    free (face);
    face = NULL;
    free (num);
    num = NULL;
    free (comp);
    comp = NULL;
    insere_hashtable (par->hash_end_pessoas, end);
    return;
}

//COMANDOS DO ARQUIVO .VIA

void caso_v (Parametros* par)
{
    char* id = NULL;
    double x = 0;
    double y = 0; 
    double* pos = NULL;
    id = (char*) calloc (255, sizeof (char));
    pos = (double*) calloc (2, sizeof (double));
    sscanf (par->comando, "%s %lf %lf", id, x, y);
    pos[0] = x;
    pos[1] = y;
    insere_vertice (par->grafo_via, id, pos);
    return;
}

void caso_e_via (Parametros* par)
{
    char* i = NULL;
    char* j = NULL;
    char* ldir = NULL;
    char* lesq = NULL;
    char* nome = NULL;
    double cmp = 0;
    double vm = 0;
    i = (char*) calloc (5, sizeof (char));
    j = (char*) calloc (5, sizeof (char));
    ldir = (char*) calloc (255, sizeof (char));
    lesq = (char*) calloc (255, sizeof (char));
    nome = (char*) calloc (255, sizeof (char));
    sscanf (par->comando, "%s %s %s %s %lf %lf %s", i, j, ldir, lesq, cmp, vm, nome);
    insere_aresta (par->grafo_via, i, j);
    define_atributos_aresta (par->grafo_via, i, j, nome, ldir, lesq, cmp, vm);
    return;
}