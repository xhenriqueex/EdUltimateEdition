//BIBLIOTECA DE PARÂMETROS

#ifndef PARAMETROS_H
#define PARAMETROS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Estruturas/Item/item.h"
#include "../Estruturas/Lista/lista.h"
#include "../Estruturas/Fila/fila.h"
#include "../Estruturas/Árvore/arvore.h"
#include "../Hash/hashtable.h"

//DEFINE A STRUCT DE PARAMETROS
typedef struct params {
    char* caminho_GEO;
    char* caminho_TXT;
    char* caminho_SVG;
    char* caminho_QRY;
    char* caminho_EC;
    char* caminho_PM;
    //char* caminho_VIA;
    char* diretorio_entrada;
    char* arquivo_entrada;
    char* diretorio_saida;
    char* arquivo_entrada_qry;
    char* arquivo_entrada_ec;
    char* arquivo_entrada_pm;
    //char* arquivo_entrada_via;
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
    Fila* anotacoes;
    Fila* resultado;
    Lista quadras;
    Lista hidrantes;
    Lista semaforos;
    Lista radiobases;
    Arvore tree_quadras;
    Arvore tree_hidrantes;
    Arvore tree_semaforos;
    Arvore tree_radiobases;
    Hashtable hash_quadras;
    Hashtable hash_hidrantes;
    Hashtable hash_semaforos;
    Hashtable hash_radiobases;
    Hashtable hash_tipos;
    Hashtable hash_comercios;
    Hashtable hash_pessoas;
    Hashtable hash_end_comercios;
    Hashtable hash_end_pessoas;
} Parametros;

#endif