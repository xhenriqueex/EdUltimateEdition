//BIBLIOTECA PARA FUNÇÕES DO OBJETO COMERCIO

#ifndef COMERCIO_H
#define COMERCIO_H
#include "../../Parâmetros/parametros.h"

typedef void* Tipo;
typedef void* Comercio;

//CRIA UM COMÉRCIO
Comercio cria_comercio (char* cnpj, Tipo tipo, char* cep, char* face, char* num, char* nome);

//DEFINE O TIPO DO COMÉRCIO
Tipo cria_tipo_comercio (char* cod, char* info);

//RETORNA UM SVG CORRESPONDENTE À UMA MUDANÇA DE ENDEREÇO
void* muda_endereco_comercio (Comercio com,  char* cep, char* face, char* num);

//RETORNA O ENDEREÇO DO COMÉRCIO
void* get_endereco_comercio (void* com);

//LIBERA A MEMÓRIA ALOCADA DO COMÉRCIO
void free_comercio (Comercio com);

//FUNÇÃO DE COMPARAÇÃO DE COMÉRCIO
int compare_comercio (Comercio com1, Comercio com2, int dim);

//RETORNA O CÓDIGO HASH DO COMÉRCIO
int hashcode_comercio (Comercio com, int modulo);

//COMPARADOR DE CNPJ DO COMÉRCIO
int compare_cnpj_comercio (void* com, void* cnpj);

//COMPARADOR DE ENDEREÇOS DO COMÉRCIO
int compare_endereco_comercio (void* end1, void* end2, int dim);

//RETORNA O CÓDIGO HASH DO TIPO DO COMÉRCIO
int hashcode_tipo_comercio (void* tip, int modulo);

//COMPARADOR DE HASH DO TIPO DO COMÉRCIO
int compare_hash_tipo_comercio (void* tip, void* cod);

//RETORNA O COMÉRCIO PRESENTE NO ENDEREÇO ESPECÍFICO
void* get_comercio_endereco (void* endereco);

//RETORNA O CÓDIGO HASH DO ENDEREÇO DO COMÉRCIO
int hashcode_endereco_comercio (void* endereco, int modulo);

//COMPARADOR DE HASH DO ENDEREÇO DO COMÉRCIO
int compare_hash_endereco_comercio (void* endereco1, void* endereco2);

//RETORNA AS COORDENADAS DO COMÉRCIO
double* get_xy_comercio (void* comercio, Parametros* par);

//GERA UMA STRING COM AS INFORMAÇÕES DO COMÉRCIO 
char* relatorio_comercio (void* comercio);

//ESTRUTURA DE ENDEREÇO NECESSÁRIA PARA ENCONTRAR O COMÉRCIO NA ÁRVORE
void* identificador_endereco_comercio (char* cep);

//RETORNA O CÓDIGO DO TIPO DO COMÉRCIO
char* get_codigo_tipo_comercio (void* comercio);

//RETORNA O TIPO DO COMÉRCIO
char* get_tipo_comercio (Comercio* comercio);

//RETORNA O NOME DO COMÉRCIO
char* get_nome_comercio(Comercio* comercio);

#endif
