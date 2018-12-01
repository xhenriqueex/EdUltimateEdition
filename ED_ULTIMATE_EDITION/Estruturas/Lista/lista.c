#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct tipo_elemento {
	void* forma;
	struct tipo_elemento *proximo;
	struct tipo_elemento *anterior;
};

struct tipo_lista {
	int tamanho;
	struct tipo_elemento *primeiro;
	struct tipo_elemento *ultimo;
};

typedef struct tipo_lista lista;
typedef struct tipo_elemento elemento;

//CRIA E RETORNA UMA LISTA VAZIA
Lista cria_lista ()
{
	lista *l;

	l = (lista *) malloc(sizeof(lista));
	l->primeiro = NULL;
	l->ultimo = NULL;

	l->tamanho = 0;

	return (Lista) l;
}

//VERIFICA O TAMANHO DA LISTA E O RETORNA
int largura_lista (Lista list)
{
	lista *l;
	l = (lista *) list;

	return l->tamanho;
}

//INSERE UM ELEMENTO NA LISTA E RETORNA SUA POSIÇÃO
Posic insere_lista (Lista list, void* obj)
{
    lista *l;
	elemento *novoelemento, *auxiliar;

	l = (lista *) list;

	novoelemento = (elemento *) malloc(sizeof(elemento));
	novoelemento->proximo = NULL;
	novoelemento->anterior = NULL;
	novoelemento->forma = obj;
	
	if(l->tamanho == 0) {
		l->primeiro = novoelemento;
	}
	else {
		auxiliar = l->primeiro;
		while(auxiliar->proximo != NULL) {
			auxiliar = auxiliar->proximo;
		}
		auxiliar->proximo = novoelemento;
		novoelemento->anterior = auxiliar;
	}
	
	l->ultimo = novoelemento;
	l->tamanho++;
	
	return (Posic) novoelemento;
}

//REMOVE UM ELEMENTO NA LISTA
Posic remove_lista (Lista list, Posic p)
{
    lista *l;
	elemento *auxiliar, *auxiliar2;

	l = (lista *) list;

	if (l->primeiro == (elemento *) p) {
		if (largura_lista(list) == 1) {
			//free(l->primeiro);
			l->primeiro = NULL;
			l->ultimo = NULL;
			p = NULL;
		} else {
			auxiliar = (elemento *) p;
			l->primeiro = auxiliar->proximo;
			//free(auxiliar);
			auxiliar = NULL;
			p = (Posic) l->primeiro;
		}
	}
	else {
		if (l->ultimo == (elemento *) p) {
			auxiliar = l->ultimo;
			auxiliar = auxiliar->anterior;
			//free(auxiliar->proximo);
			auxiliar->proximo = NULL;
			l->ultimo = auxiliar;
			p = (Posic) auxiliar;
		}
		else {
			auxiliar = (elemento *) p;
			auxiliar2 = auxiliar->proximo;
			auxiliar = auxiliar->anterior;
			//free(auxiliar->proximo);
			auxiliar->proximo = auxiliar2;
			auxiliar2->anterior = auxiliar;
			p = (Posic) auxiliar;
		}
	}
	l->tamanho--;

	return p;  
}

//RETORNA O VALOR DE UM ELEMENTO DA LISTA
void* get_valor_lista (Posic p)
{
    elemento *auxiliar;
	void* obj;

	if (p != NULL) {
		auxiliar = (elemento *) p;
		obj = auxiliar->forma;
	}
	else {
		obj = NULL;
	}

	return obj;
}

//INSERE UM ITEM NA POSIÇÃO ANTERIOR AO INDICADO POR POSIC
Posic insere_antes_lista (Lista list, Posic p, void* obj)
{
    lista *l;
	elemento *novoelemento, *auxiliar;

	l = (lista *) list;

	if (p == NULL) {
		printf("A posição solicitada não é válida.\n");
	}
	else {
		novoelemento = (elemento *) malloc(sizeof(elemento));
		novoelemento->forma = obj;
		auxiliar = (elemento *) p;
		p = (Posic) novoelemento;

		if(auxiliar == l->primeiro) {
			auxiliar->anterior = novoelemento;
			novoelemento->proximo = auxiliar;
			novoelemento->anterior = NULL;
			l->primeiro = novoelemento;
		}
		else {
			novoelemento->proximo = auxiliar;
			auxiliar = auxiliar->anterior;
			auxiliar->proximo = novoelemento;
			novoelemento->anterior = auxiliar;
			auxiliar = novoelemento->proximo;
			auxiliar->anterior = novoelemento;
		}

		l->tamanho++;
	}

	return p;
}

//INSERE UM ITEM NA POSIÇÃO POSTERIOR AO INDICADO POR POSIC
Posic insere_depois_lista (Lista list, Posic p, void* obj)
{
    lista *l;
	elemento *novoelemento, *auxiliar;

	l = (lista *) list;

	if (p == NULL) {
		printf("A posição solicitada não é válida.\n");
	}
	else {
		novoelemento = (elemento *) malloc(sizeof(elemento));
		novoelemento->forma = obj;
		auxiliar = (elemento *) p;
		p = (Posic) novoelemento;

		if(auxiliar == l->ultimo) {
			auxiliar->proximo = novoelemento;
			novoelemento->anterior = auxiliar;
			novoelemento->proximo = NULL;
			l->ultimo = novoelemento;
		}
		else {
			novoelemento->anterior = auxiliar;
			auxiliar = auxiliar->proximo;
			novoelemento->proximo = auxiliar;
			auxiliar->anterior = novoelemento;
			auxiliar = novoelemento->anterior;
			auxiliar->proximo = novoelemento;
		}

		l->tamanho++;
	}

	return p;
}

//RETORNA O PRIMEIRO VALOR DA LISTA, CASO LENGTH = 0, RETORNA NULL
Posic get_primeiro_lista (Lista list)
{
    lista *l;
	Posic p;

	l = (lista *) list;

	if (l->tamanho != 0) {
		p = (Posic) l->primeiro;
	}
	else {
		p = NULL;
	}

	return p;
}

//RETORNA O PRÓXIMO ELEMENTO APONTADO POR POSIC
Posic get_proximo_lista (Lista list, Posic p)
{
    lista *l;
	elemento *auxiliar;

	if (p != NULL) {
		l = (lista *) list;
		auxiliar = (elemento *) p;
		auxiliar = auxiliar->proximo;
		p = (Posic) auxiliar;
	}
	else {
		p = NULL;
	}

	return p;
}

//RETORNA O ELEMENTO ANTERIOR A POSIC
Posic get_anterior_lista (Lista list, Posic p)
{
    lista *l;
	elemento *auxiliar;

	l = (lista *) list;
	auxiliar = (elemento *) p;
	auxiliar = auxiliar->anterior;
	p = (Posic) auxiliar;

	return p;
}

//RETORNA O ÚLTIMO ELEMENTO DA LISTA
Posic get_ultimo_lista (Lista list)
{
    lista *l;
	Posic p;

	l = (lista *) list;

	if (l->tamanho != 0) {
		p = (Posic) l->ultimo;
	}
	else {
		p = NULL;
	}

	return p;
}

//CONCATENA A SEGUNDA LISTA NA PRIMEIRA
void concat_listas (Lista lista1, Lista lista2)
{
    lista *list1, *list2;
    elemento *element;

    list1 = (lista*) lista1;
    list2 = (lista*) lista2;

    if (list1->tamanho == 0)
    {
        list1->primeiro = list2->primeiro;
        list1->ultimo = list2->ultimo;
        list1->tamanho = list2->tamanho;
        return;
    }
    if (list2->tamanho == 0)
    {
        return;
    }
    list1->ultimo->proximo = list2->primeiro;
    list2->primeiro->anterior = list1->ultimo;
    list1->ultimo = list2->ultimo;
    list1->tamanho += list2->tamanho;
}

//LIBERA A MEMÓRIA ALOCADA DA LISTA
Posic liberar_elemento_lista(Lista list, Posic p) {
	lista *l = NULL;
	elemento *auxiliar = NULL, *auxiliar2 = NULL;

	l = (lista *) list;
	auxiliar = (elemento *) p;

	l->tamanho--;

	if (l->primeiro != NULL && l->primeiro != l->ultimo) {
		auxiliar2 = auxiliar;
		auxiliar = auxiliar->proximo;
		auxiliar2->proximo = NULL;
		auxiliar2->anterior = NULL;
		auxiliar->anterior = NULL;
		l->primeiro = auxiliar;
		free(auxiliar2);
		auxiliar2 = NULL;
	}
	else {
		if (l->primeiro == l->ultimo) {
			l->primeiro = NULL;
			l->ultimo = NULL;
			free(auxiliar);
			auxiliar = NULL;
		}
	}
	return (Posic) auxiliar;
}

void liberar_lista(Lista list) {
	int i = 0;
	Posic p = NULL;

	for(i = 0; i < largura_lista(list); i++) {
		p = get_primeiro_lista(list);
		liberar_elemento_lista(list, p);
	}
}