//BIBLIOTECA PARA DEFINIR A LISTA DE ELEMENTOS A SEREM IMPRESSOS NO SVG

#ifndef LISTA_H
#define LISTA_H

//DEFINE O TIPO LISTA
typedef void* Lista;

//DEFINE O TIPO POSIC
typedef void* Posic;

//CRIA E RETORNA UMA LISTA VAZIA
Lista cria_lista ();

//VERIFICA O TAMANHO DA LISTA E O RETORNA
int largura_lista (Lista list);

//INSERE UM ELEMENTO NA LISTA E RETORNA SUA POSIÇÃO
Posic insere_lista (Lista list, void* obj);

//REMOVE UM ELEMENTO NA LISTA
Posic remove_lista (Lista list, Posic p);

//RETORNA O VALOR DE UM ELEMENTO DA LISTA
void* get_valor_lista (Posic p);

//INSERE UM ITEM NA POSIÇÃO ANTERIOR AO INDICADO POR POSIC
Posic insere_antes_lista (Lista list, Posic p, void* obj);

//INSERE UM ITEM NA POSIÇÃO POSTERIOR AO INDICADO POR POSIC
Posic insere_depois_lista (Lista list, Posic p, void* obj);

//RETORNA O PRIMEIRO VALOR DA LISTA, CASO LENGTH = 0, RETORNA NULL;
Posic get_primeiro_lista (Lista list);

//RETORNA O PRÓXIMO ELEMENTO APONTADO POR POSIC
Posic get_proximo_lista (Lista list, Posic p);

//RETORNA O ELEMENTO ANTERIOR A POSIC
Posic get_anterior_lista (Lista list, Posic p);

//RETORNA O ÚLTIMO ELEMENTO DA LISTA
Posic get_ultimo_lista (Lista list);

//CONCATENA A SEGUNDA LISTA NA PRIMEIRA
void concat_listas (Lista lista1, Lista lista2);

//RETORNA UMA LISTA DE ELEMENTOS ATÉ UMA POSIÇÃO ESPECÍFICA
Lista divide_lista(Lista list, Posic p);

//MUDA O ELEMENTO DO POSIC PARA O PRIMEIRO DA LISTA
Lista fixa_primeiro_lista(Lista list, Posic p);

//LIBERA A MEMÓRIA ALOCADA DA LISTA
Posic liberar_elemento_lista(Lista list, Posic p);
void liberar_lista(Lista list);

#endif