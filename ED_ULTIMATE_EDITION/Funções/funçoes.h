//BIBLIOTECA DE FUNÇÕES PARA UTILIZAÇÃO DURANTE O PROGRAMA

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include "fila.h"

//TRATA OS CAMINHOS
void altera_caminho (char** caminho);

//PEGA TODOS OS COMANDOS DE ENTRADA E OS COLOCA EM UMA FILA
Fila coloca_comandos_arquivo_fila (FILE* entrada);

//VERIFICA SE DUAS FIGURAS SE SOBREPÕEM
int sobrepoe (void* fig1, void* fig2);

//IDENTIFICA TODOS OS PARAMETROS DO COMANDO LIDO E RETORNA UM VETOR DE PARAMETROS
char** trata_comando (char* leitura);

//RETORNA O TAMANHO DO VETOR DE COMANDOS
int tamanho_strings (char** strings);

//LIBERA AS STRINGS DO VETOR DE COMANDOS
void free_strings (char** strings);

#endif