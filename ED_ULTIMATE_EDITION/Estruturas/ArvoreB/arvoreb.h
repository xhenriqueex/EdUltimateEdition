#ifndef ARVOREB_H
#define ARVOREB_H
#include <stdio.h>
#include "../Lista/lista.h"

typedef void* TreeB;

//CRIA UM NOVO BANCO DE DADOS
TreeB* cria_banco (int tam, char* bancoDados, int tamObj, double (*compare)(void*, void*), void (*escritor)(void* obj, int procura, FILE* arq), void (*leitor)(void* obj, int procura, FILE* arq), void* (*alloc)());

//CARREGA UM BANCO EXISTENTE
TreeB* carrega_banco (char* caminho, double (*compare)(void*, void*), void (*escritor)(void* obj, int procura, FILE* arq), void (*leitor)(void* obj, int procura, FILE* arq), void* (*alloc)());

//INSERE UM ITEM NA ÁRVORE B
int insere_arvoreB (TreeB* arvore, double valor, void* objeto);

//DELETA UM ITEM DA ÁRVORE B
int delete_arvoreB (TreeB* arvore, double valor, void* objeto);

//BUSCA UM ITEM NA ÁRVORE B
void* busca_arvoreB (TreeB* arvore, double valor, void* objeto);

//RETORNA O ITEM MAIS PRÓXIMO À REFERÊNCIA
//SE CTR != 0, PERMITE O RETORNO DE UM ITEM COM DISTÂNCIA = 0
void* vizinho_proximo_arvoreB (TreeB* arvore, double ref, void* referencia, int ctr);

//LIMPA A MEMÓRIA ALOCADA DA ÁRVORE B
void free_arvoreB (TreeB* arvore);

//RETORNA TODOS OS ITENS DA ÁRVORE B
Lista* get_todos_arvoreB (TreeB* arvore);

//RETORNA UMA LISTA COM OS ITENS DENTRO DA REFERÊNCIA
Lista get_itens_dentro_area_arvoreB (TreeB* arvore, void* refInic, void* refFin);

//IMPRIME A ÁRVORE B
void imprime_arvoreB (TreeB* arvore);

//RETORNA UMA LISTA COM TODOS OS ITENS DA ÁRVORE B DENTRO DE UMA ÁREA
Lista get_todos_dentro_area_arvoreB (TreeB* arvore, double valorInicial, void* refInicial, double valorFinal, void* refFinal);

#endif

