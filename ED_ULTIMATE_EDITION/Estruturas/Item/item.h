//BIBLIOTECA PARA DEFINIR A LISTA DE FIGURAS A SEREM IMPRIMIDAS NO SVG

#ifndef ITEM_H
#define ITEM_H

//DEFINE O TIPO DO ITEM
typedef void* Item;

//DEFINE O TIPO DO VALOR
typedef void* Valor;

//CRIA UM ITEM E O RETORNA
Item cria_item (void* Value, char* type);

//PEGA O TIPO DO ITEM
char* get_tipo_item (Item item);

//PEGA O VALOR DO ITEM
Valor get_valor_item (Item item);

//LIBERA A MEMÓRIA ALOCADA DOS ITENS
void free_item (Item item);

//ESCREVE AS INFORMAÇÕES DO ITEM NO ARQUIVO
void escreve_arquivo_item (Item item, int procura, FILE* arq);

//LÊ AS INFORMAÇÕES DO ITEM DO ARQUIVO
void ler_arquivo_item (Item item, int procura, FILE* arq);

//RETORNA O TAMANHO DO ITEM
int get_tamanho_item ();

//ALOCA A MEMÓRIA NECESSÁRIA PARA O ITEM
void* alloc_item ();

#endif