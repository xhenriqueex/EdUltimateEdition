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
    Fila* anotaçoes;
    Fila* resultado;
    Lista quadras;
    Lista hidrantes;
    Lista semaforos;
    Lista radiobases;
    //Arvore quadras;
    //Arvore hidrantes;
    //Arvore semaforos;
    //Arvore radiobases;
    Hash_table hash_quadras;
    Hash_table hash_hidrantes;
    Hash_table hash_semaforos;
    Hash_table hash_radiobases;
    Hash_table hash_tipos;
    Hash_table hash_comercios;
    Hash_table hash_pessoas;
    Hash_table hash_end_comercios;
    Hash_table hash_end_pessoas;
} Parametros;

#endif