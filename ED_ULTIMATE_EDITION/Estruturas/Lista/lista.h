//BIBLIOTECA PARA DEFINIR A LISTA DE ELEMENTOS A SEREM IMPRESSOS NO SVG

#ifndef LISTA_H
#define LISTA_H

//DEFINE O TIPO LISTA
typedef void* Lista;

//DEFINE O TIPO ITEM
typedef void* It;

//DEFINE O TIPO POSIC
typedef void* Posic;

//CRIA E RETORNA UMA LISTA VAZIA
Lista cria_lista ();

//VERIFICA O TAMANHO DA LISTA E O RETORNA
int largura_lista (void* lista);

//INSERE UM ELEMENTO NA LISTA E RETORNA SUA POSIÇÃO
Posic insere_lista (void* lista, void* item);

//REMOVE UM ELEMENTO NA LISTA
void remove_lista (void* lista, void* posic);

//RETORNA O VALOR DE UM ELEMENTO DA LISTA
void* get_valor_lista (void* lista, void* posic);

//INSERE UM ITEM NA POSIÇÃO ANTERIOR AO INDICADO POR POSIC
void insere_antes_lista (void* lista, void* posic, void* valor);

//INSERE UM ITEM NA POSIÇÃO POSTERIOR AO INDICADO POR POSIC
void* insere_depois_lista (void* lista, void* posic, void* valor);

//RETORNA O PRIMEIRO VALOR DA LISTA, CASO LENGTH = 0, RETORNA NULL;
void* get_primeiro_lista (void* lista);

//RETORNA O PRÓXIMO ELEMENTO APONTADO POR POSIC
void* get_proximo_lista (void* lista, void* posic);

//RETORNA O ELEMENTO ANTERIOR A POSIC
void* get_anterior_lista (void* lista, void* posic);

//RETORNA O ÚLTIMO ELEMENTO DA LISTA
void* get_ultimo_lista (void* lista);

//CONCATENA A SEGUNDA LISTA NA PRIMEIRA
void concat_listas (void* list1, void* list2);

#endif