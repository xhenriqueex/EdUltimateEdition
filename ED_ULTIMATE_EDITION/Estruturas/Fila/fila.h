//RESPONSÁVEL POR COLOCAR TODOS OS COMANDOS EM UMA FILA

#ifndef FILA_H
#define FILA_H
#include "../../Objetos/Item/item.h"

//DEFINE O TIPO DA FILA
typedef void* Fila;

//CRIA UMA FILA VAZIA
Fila cria_fila ();

//RETORNA 1 SE A FILA ESTIVER VAZIA, 0 CASO CONTRARIO
int fila_vazia (Fila f);

//ADICIONA UM ITEM NA FILA
void insere_fila (Fila f, Valor unidade);

//REMOVE O PRIMEIRO DA FILA E RETORNA SEU VALOR
//A FILA NÃO PODE ESTAR VAZIA
Valor remove_fila (Fila f);

#endif