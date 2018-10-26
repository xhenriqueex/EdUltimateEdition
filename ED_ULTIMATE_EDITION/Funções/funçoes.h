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

#endif