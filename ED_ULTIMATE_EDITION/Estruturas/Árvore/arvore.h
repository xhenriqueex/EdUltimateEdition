//ESTRUTURA RESPONSÁVEL POR ARMAZENAR AS INFORMAÇÕES

#ifndef ARVORE_H
#define ARVORE_H

typedef void* kd_tree;
typedef void* kd_tree_valor;

//CRIA A ÁRVORE
void* cria_arvore (int (*compara_arvore)(void*, void*, int), int dim);

//INSERE UM VALOR NA ÁRVORE
void insere_arvore (kd_tree arvore, kd_tree_valor valor);

//LIBERA A MEMÓRIA DA ÁRVORE
void free_arvore (kd_tree arvore);

//RETORNA UMA LISTA COM TODOS OS VALORES DA ÁRVORE
void get_todos_arvore (kd_tree arvore);

//RETORNA UM VALOR DA ÁRVORE, COMPARADA COM A REFERÊNCIA
void* get_valor_arvore (kd_tree arvore, kd_tree_valor ref);

//REMOVE UM VALOR DA ÁRVORE, COMPARADA COM A REFERÊNCIA
void remove_valor_arvore (kd_tree arvore, kd_tree_valor ref);

//RETORNA O ITEM MAIS PRÓXIMO À REFERÊNCIA NA ÁRVORE
void* vizinho_proximo_arvore (kd_tree arvore, kd_tree_valor ref);

#endif