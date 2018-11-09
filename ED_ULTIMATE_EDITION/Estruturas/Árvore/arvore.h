//ESTRUTURA RESPONSÁVEL POR ARMAZENAR AS INFORMAÇÕES

#ifndef ARVORE_H
#define ARVORE_H

typedef void* kd_tree;
typedef void* kd_tree_valor;

typedef struct no {
    void* valor;
    struct no* direita;
    struct no* esquerda;
} No;

typedef struct kd {
    int (*compare)(void*, void*, int);
    int dim;
    int tam;
    No* nodulo;
} Arvore;

//CRIA A ÁRVORE
void* cria_arvore (int (*compare)(void*, void*, int), int dim);

//INSERE UM NODULO NA ÁRVORE
void insere_nodulo (No* n, Arvore* arv, void* valor, int dim);

//INSERE UM VALOR NA ÁRVORE
void insere_arvore (void* arv, void* valor);

//LIBERA UM NÓDULO
void free_nodulo (void* nodulo);

//LIBERA A ÁRVORE
void free_arvore (void* arvore);

//RETORNA UMA LISTA COM TODOS OS VALORES DO NÓDULO
Lista get_todos_nodulo (void* nodulo, void* lista);

//RETORNA UMA LISTA COM TODOS OS VALORES DA ÁRVORE
Lista get_todos_arvore (void* arv);

//RETORNA UM VALOR DO NÓDULO, COMPARADO COM A REFERÊNCIA
void* get_valor_nodulo (Arvore* arv, No* nodulo, int dim, void* ref);

//RETORNA UM VALOR DA ÁRVORE, COMPARADO À REFERÊNCIA
void* get_valor_arvore (void* arv, void* ref);

//REMOVE UM VALOR DO NÓDULO, COMPARADO À REFERÊNCIA
Lista remove_valor_nodulo (Arvore* arv, No* nodulo, int dim, void* ref);

//REMOVE UM VALOR DA ÁRVORE
void remove_valor_arvore (Arvore* arv, void* ref);

//RETORNA A DISTÂNCIA ENTRE DOIS VALORES DA ÁRVORE
double dist_arvore (Arvore* arv, void* valor1, void* valor2);

//RETORNA O ITEM MAIS PRÓXIMO À REFERÊNCIA NO NÓDULO
void vizinho_proximo_nodulo (No* n, Arvore* arv, void* ref, void** item, double* dist, int dim);

//RETORNA O VIZINHO MAIS PRÓXIMO À REFERÊNCIA NA ÁRVORE
void* vizinho_proximo_arvore (void* arv, void* ref);

#endif