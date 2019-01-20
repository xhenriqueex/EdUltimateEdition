//BIBLIOTECA DE PARÂMETROS

#ifndef PARAMETROS_H
#define PARAMETROS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Estruturas/Item/item.h"
#include "../Estruturas/Lista/lista.h"
#include "../Estruturas/Fila/fila.h"
#include "../Estruturas/Hash/hashtable.h"
#include "../Estruturas/ArvoreB/arvoreb.h"
#include "../Estruturas/Arvore/arvore.h" //remover dps
#include "../Estruturas/Registrador/registrador.h"
#include "../Estruturas/Grafo/grafo.h"
#include "../Estruturas/ArquivoBin/arquivobin.h"
#include "../Formas/Grafo_Forma/grafo_forma.h"

//DEFINE A STRUCT DE PARAMETROS
typedef struct params {
    char* caminho_GEO;
    char* caminho_TXT;
    char* caminho_SVG;
    char* caminho_QRY;
    char* caminho_EC;
    char* caminho_PM;
    char* caminho_VIA;
    char* caminho_banco;
    char* diretorio_entrada;
    char* arquivo_entrada;
    char* diretorio_saida;
    char* arquivo_entrada_qry;
    char* arquivo_entrada_ec;
    char* arquivo_entrada_pm;
    char* arquivo_entrada_via;
    char* arquivo_entrada_banco;
    char* cor_borda_quadra;
    char* cor_preenche_quadra;
    char* cor_borda_hidrante;
    char* cor_preenche_hidrante;
    char* cor_borda_semaforo;
    char* cor_preenche_semaforo;
    char* cor_borda_radiobase;
    char* cor_preenche_radiobase;
    char* comando;
    char* controle;
    long int max_figuras;
    int contador_figuras;
    int criar;
    Item* figuras; //remover
    Fila* anotacoes;
    Fila* resultado;
    Fila grafo_f;
    Lista* figs;
    Arvore tree_quadras; //remover
    Arvore tree_hidrantes; //remover
    Arvore tree_semaforos; //remover
    Arvore tree_radiobases; //remover
    Arvore tree_carros; //remover
    TreeB arvoreB_quadras;
    TreeB arvoreB_hidrantes;
    TreeB arvoreB_semaforos;
    TreeB arvoreB_radiobases;
    TreeB arvoreB_carros;
    Hashtable hash_quadras;
    Hashtable hash_hidrantes;
    Hashtable hash_semaforos;
    Hashtable hash_radiobases;
    Hashtable hash_carros;
    Hashtable hash_tipos;
    Hashtable hash_comercios;
    Hashtable hash_pessoas;
    Hashtable hash_end_comercios;
    Hashtable hash_end_pessoas;
    Registrador* regis;
    Grafo grafo_via;
} Parametros;

#endif