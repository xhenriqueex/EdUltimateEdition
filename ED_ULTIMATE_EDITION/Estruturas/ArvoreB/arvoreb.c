#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../ArquivoBin/arquivobin.h"
#include "../Lista/lista.h"
#include "arvoreb.h"
// #include "../Grafos/GrafoD.h"

typedef struct nob {
    int pai;
	int TotalElementoNo;
	int maxElementos;
	int totalFilhos;
	int maxFilhos;
    int posAtual;
    double* elementos;
	int* indexElemento;
	int* filhos;
} NoB;

typedef struct arvoreb {
    double (*compare)(void*, void*);
    int tamBloco;
    NoB* raiz;
    FILE* arq;
    char* caminho;
	long int tamHeader;
	void (*escritor)(void* obj, int procura, FILE* arq);
	void (*leitor)(void* obj, int procura, FILE* arq);
	void* (*alloc)();
} ArvoreB;

typedef struct header {
    int tamBloco;
    int raiz;
    char* caminho;
} Header;

typedef struct Info {
	double chave;
	int data;
}Info;

///// FUNÇÕES NECESSÁRIAS PARA A FUNÇÃO CRIA_BANCO

TreeB* cria_banco (int tam, char* bancoDados, int tamObj, double (*compare)(void*, void*), void (*escritor)(void* obj, int procura, FILE* arq), void (*leitor)(void* obj, int procura, FILE* arq), void* (*alloc)())
{
	int i;
	char* caminho;
	ArvoreB* arvore;
	Header* header;
	arvore = (ArvoreB*) malloc (sizeof (ArvoreB));
    arvore->compare = compare;
	arvore->tamBloco = 0;
    arvore->tamBloco = tam;
	arvore->raiz = NULL;
	arvore->arq = NULL;
	arvore->arq = fopen (bancoDados, "w+b");
	arvore->escritor = escritor;
	arvore->leitor = leitor;
	arvore->alloc = alloc;
    caminho = (char*) malloc (sizeof (char) * 55);
    strcpy (caminho, bancoDados);
	for (i=0; i<strlen (caminho); i++)
	{
		if (*(caminho+i) == '.') *(caminho+i) = 0;
	}
	strcat (caminho, "_data.dat");
    arvore->caminho = caminho;
	cria_arquivo (caminho, tamObj);
    header = (Header*) malloc (sizeof (Header));
	header->tamBloco = 0;
    header->tamBloco = tam;
    header->raiz = -1;
    header->caminho = caminho;
	fwrite (&header->tamBloco, sizeof (int), 1, arvore->arq);
	fwrite (&header->raiz, sizeof (int), 1, arvore->arq);
	for (i=0; i<55; i++)
	{
		fwrite (&header->caminho[i], sizeof (char), 1, arvore->arq);
	}
	arvore->tamHeader = ftell (arvore->arq);
	fclose (arvore->arq);
	arvore->arq = fopen (bancoDados, "r+b");
    return (void *) arvore;
}

///// FIM DAS FUNÇÕES NECESSÁRIAS DE CRIA_BANCO

///// FUNÇÕES NECESÁRIAS PARA A FUNÇÂO CARREGA_BANCO

// FUNÇÃO QUE LÊ UM NÓ DO DISCO A PARTIR DE UM PONTO DE PROCURA E INICIALIZA A FOLHA COM ESSE NÓ
int leitura_disco (ArvoreB* arvore, int seek, NoB *folha)
{
	int tamFolha, i;
	if (fseek (arvore->arq, seek, SEEK_SET) == -1) return 0;
	tamFolha = sizeof (folha);
	fread (folha, tamFolha, 1, arvore->arq);
	for (i=0; i<folha->maxElementos; i++)
	{
		fread (&folha->elementos[i], sizeof(double), 1, arvore->arq);
	}
	for (i=0; i<folha->maxElementos; i++)
	{
		fread (&folha->indexElemento[i], sizeof(int), 1, arvore->arq);
	}
	for (i=0; i<folha->maxFilhos; i++)
	{
		fread(&folha->filhos[i], sizeof(int), 1, arvore->arq);
	}
	folha->posAtual = seek;
	return 1;
}

// CALCULA E RETORNA QUANTOS ELEMENTOS PODEM HAVER NA FOLHA
int calcula_max_elementos (int bloco)
{
    int result;
	bloco -= 6 * sizeof (int);
    result = bloco / (2 * sizeof (int) + sizeof (double));
    return result;
}

// INICIALIZA OS DADOS DA FOLHA
NoB* inicializa_folha (int bloco) 
{
    int tam, i;
	tam = calcula_max_elementos (bloco);
	NoB* folha = (NoB*) malloc (sizeof (NoB));
	folha->maxElementos = 2 * tam - 1;
	folha->pai = -1;
	folha->TotalElementoNo = 0;
	folha->totalFilhos = 0;
	folha->posAtual = -1;
	folha->maxFilhos = 2 * tam;
	folha->elementos = (double*) malloc (sizeof (double) * (2 * tam - 1));
    folha->indexElemento = (int*) malloc (sizeof (int) * (2 * tam -1));
	folha->filhos = (int*) malloc (sizeof (int) * 2 * tam);
	for (i=0; i<folha->maxElementos; i++)
	{
		folha->elementos[i] = -1;
        folha->indexElemento[i] = -1;
    }
	for (i=0; i<folha->maxFilhos; i++)
	{	
		folha->filhos[i] = -1;
	}
	return folha;
}

// CARREGA UM BANCO EXISTENTE
TreeB* carrega_banco (char* caminho, double (*compare)(void*, void*), void (*escritor)(void* obj, int procura, FILE* arq), void (*leitor)(void* obj, int procura, FILE* arq), void* (*alloc)())
{
	int i;
	FILE* arq;
	Header* header;
	ArvoreB* result;
	arq = fopen (caminho, "r+b");
	header = (Header*) malloc (sizeof (Header));
	header->caminho = malloc (55 * sizeof (char));
	fread (&header->tamBloco, sizeof (int), 1, arq);
	fread (&header->raiz, sizeof (int), 1, arq);
	for (i=0; i<55; i++)
	{
		fread (&header->caminho[i], sizeof (char), 1, arq);
	}
	fclose (arq);
	result = (ArvoreB*) malloc (sizeof (ArvoreB));
	result->compare = compare;
	result->tamBloco = header->tamBloco;
	result->caminho = header->caminho;
	result->arq = fopen (caminho, "r+b");
	result->raiz = inicializa_folha (header->tamBloco);
	result->escritor = escritor;
	result->leitor = leitor;
	result->alloc = alloc;
	leitura_disco (result, header->raiz, result->raiz);
	result->tamHeader = result->raiz->posAtual;
	return (void *) result;
}

///// FIM DAS FUNÇÕES NECESÁRIAS PARA A FUNÇÂO CARREGA_BANCO

///// FUNÇÕES NECESSÁRIAS PARA A FUNÇÃO INSERE_ARVOREB

// ADICIONA UM ELEMENTO ORDENADAMENTE EM UM NÓ
void adicionar_elemento (ArvoreB* arvore,  NoB* folha, double elemento, int objeto) 
{
	int filho, i, cAux, dAux;
	double elemAux;
	filho = -1;
	for (i=0; i<folha->maxElementos; i++) 
	{
		if (elemento < folha->elementos[i]) 
		{
			elemAux = folha->elementos[i];
			dAux = folha->indexElemento[i];
			cAux = folha->filhos[i+1];
			folha->elementos[i] = elemento;
            folha->indexElemento[i] = objeto;
			folha->filhos[i+1] = filho;
			elemento = elemAux;
			objeto = dAux;
			filho = cAux;
		}
		if(folha->elementos[i] == -1)
		{
			elemAux = folha->elementos[i];
			dAux = folha->indexElemento[i];
			cAux = folha->filhos[i+1];
			folha->elementos[i] = elemento;
            folha->indexElemento[i] = objeto;
			folha->filhos[i+1] = filho;
			elemento = elemAux;
			objeto = dAux;
			filho = cAux;
			break;
		}
	}
	folha->TotalElementoNo++;
}

// ESCREVE AS INFORMAÇÕES DE UM NÓ NO DISCO
int escrita_disco (ArvoreB* arvore, int seek, NoB *folha)
{
    int tamFolha, i;
	if (fseek (arvore->arq, seek, SEEK_SET) == -1) return 0;
	if (folha->posAtual == -1) folha->posAtual = ftell(arvore->arq);
	tamFolha = sizeof(folha);
	fwrite ((void*) folha, tamFolha, 1, arvore->arq);
	for(i=0; i<folha->maxElementos; i++)
	{	
		fwrite (&folha->elementos[i], sizeof (double), 1, arvore->arq);
	}
	for(i=0; i<folha->maxElementos; i++)
	{
		fwrite (&folha->indexElemento[i], sizeof (int), 1, arvore->arq);
	}
	for(i=0; i<folha->maxFilhos; i++)
	{
		fwrite (&folha->filhos[i], sizeof (int), 1, arvore->arq);
	}
	return 1;
}

//RETORNA A QUANTIDADE DE ELEMENTOS PRESENTES NO NÓ
int total_elemento_no (NoB* folha)
{
	int total, i;
	total = 0;
	for (i=0; i<folha->maxElementos; i++)
	{
		if (folha->elementos[i] != -1) total++;
	}
	return total;
}

//RETORNA O ÍNDICE DO ELEMENTO QUE ESTÁ NA FOLHA
int busca_indice (ArvoreB* arvore, NoB* folha, double valor, double objeto)
{
	int i;
	for (i=0; i<folha->maxElementos; i++)
	{
		if (folha->elementos[i] == valor)
		{
            if (folha->indexElemento[i] == objeto) return i;
		}
	}
	return -1;
}

// SEPARA A RAÍZ EM 2 E CRIA UMA NOVA RAÍZ
int separa (ArvoreB* arvore, NoB* pai, double valor, int objeto)
{
	int i, j, meio, posA, posB, dataAux, datas[pai->maxElementos+1];
	double valAux, valores[pai->maxElementos+1];
	NoB* filho1;
	NoB* filho2;
	for(i=0; i<pai->maxElementos; i++)
	{
		valores[i] = pai->elementos[i];
		datas[i] = pai->indexElemento[i];
	}
	valores[pai->maxElementos] = valor;
	datas[pai->maxElementos] = objeto;
	for (i=0; i<=pai->maxElementos; i++)
	{
		for (j=i; j<=pai->maxElementos; j++)
		{
			if (valores[i] > valores[j])
			{
				valAux = valores[i];
				dataAux = datas[i];
				valores[i] = valores[j];
				datas[i] = datas[j];
				valores[j] = valAux;
				datas[j] = dataAux;
			}
		}
	}
	meio = pai->maxElementos / 2;
	filho1 = inicializa_folha (arvore->tamBloco);
	filho2 = inicializa_folha (arvore->tamBloco);
	filho1->TotalElementoNo = 0;
	for (i=0; i<meio; i++)
	{
		filho1->elementos[i] = valores[i];
		filho1->indexElemento[i] = datas[i];
		filho1->TotalElementoNo++;
	}
	filho2->TotalElementoNo = 0;
	for (i=meio+1; i<=pai->maxElementos; i++)
	{
		filho2->elementos[i-(meio+1)] = valores[i];
		filho2->indexElemento[i-(meio+1)] = datas[i];
		filho2->TotalElementoNo++;
	}
	for (i=0; i<meio; i++)
	{	
		filho1->filhos[i] = pai->filhos[i];
	}
	for (i=meio+1; i<pai->maxFilhos; i++)
	{
		filho2->filhos[i-(meio+1)] = pai->filhos[i];
	}
	filho1->pai = pai->posAtual;
	fseek (arvore->arq, 0, SEEK_END);
	posA = ftell (arvore->arq);
	escrita_disco (arvore, posA, filho1);
	filho2->pai = pai->posAtual;
	posB = ftell (arvore->arq);
	escrita_disco (arvore, posB, filho2);
	for (i=0; i<pai->maxElementos; i++)
	{
		pai->elementos[i] = -1;
		pai->indexElemento[i] = -1;
	}
	for(i = 0; i<pai->maxFilhos; i++)
	{
		pai->filhos[i] = -1;
	}
	pai->TotalElementoNo = 1;
	pai->totalFilhos = 2;
	pai->elementos[0] = valores[meio];
	pai->indexElemento[0] = datas[meio];
	pai->filhos[0] = posA;
	pai->filhos[1] = posB;
	escrita_disco (arvore, pai->posAtual, pai);
	return 1;
}

// SEPARA O NÓ E RETORNA O ELEMENTO COM O FILHO À DIREITA
int explodir (ArvoreB* arvore, NoB* folha, double valor, int objeto, int idfilho2)
{
	int indice, i, j, meio, dataAux, pos, datas[folha->maxElementos+1];
	double valAux, valores[folha->maxElementos+1];
	NoB* pai;
	NoB* filho1;
	NoB* filho2;
	if (folha->TotalElementoNo < folha->maxElementos)
	{
		adicionar_elemento (arvore, folha, valor, objeto);
		indice = busca_indice (arvore, folha, valor, objeto);
		folha->filhos[indice+1] = idfilho2;
		escrita_disco (arvore, folha->posAtual, folha);
		return 1;
	}
	if (folha->pai == -1)
	{
		return separa (arvore, folha, valor, objeto);
	}
	for (i=0; i<folha->maxElementos; i++)
	{
		valores[i] = folha->elementos[i];
		datas[i] = folha->indexElemento[i];
	}
	valores[folha->maxElementos] = valor;
	datas[folha->maxElementos] = objeto;
	for (i=0; i<=folha->maxElementos; i++)
	{
		for (j=i; j<=folha->maxElementos; j++)
		{
			if (valores[i] > valores[j])
			{
				valAux = valores[i];
				dataAux = datas[i];
				valores[i] = valores[j];
				datas[i] = datas[j];
				valores[j] = valAux;
				datas[j] = dataAux;
			}
		}
	}
	meio = folha->maxElementos / 2;
	filho1 = inicializa_folha (arvore->tamBloco);	
	filho2 = inicializa_folha (arvore->tamBloco);
	filho1->TotalElementoNo = 0;
	for (i=0; i<meio; i++)
	{
		filho1->elementos[i] = valores[i];
		filho1->indexElemento[i] = datas[i];
		filho1->TotalElementoNo++;
	}
	filho2->TotalElementoNo = 0;
	for (i=meio+1; i<=folha->maxElementos; i++)
	{
		filho2->elementos[i-(meio+1)] = valores[i];
		filho2->indexElemento[i-(meio+1)] = datas[i];
		filho2->TotalElementoNo++;
	}
	for (i=0; i<meio; i++)
	{
		filho1->filhos[i] = folha->filhos[i];
	}
	for(i=meio+1; i<folha->maxFilhos; i++)
	{
		filho2->filhos[i-(meio+1)] = folha->filhos[i];
	}
	filho1->pai = folha->pai;
	filho1->posAtual = folha->posAtual;
	escrita_disco (arvore, filho1->posAtual, filho1);
	fseek (arvore->arq, 0, SEEK_END);
	pos = ftell (arvore->arq);
	escrita_disco (arvore, pos, filho2);
	pai = inicializa_folha (arvore->tamBloco);
	leitura_disco (arvore, folha->pai, pai);
	explodir (arvore, pai, valores[meio], datas[meio], pos);
	return 1;
}

// ORDENA OS ELEMENTOS DA FOLHA
void ordena (NoB* folha) 
{
	int i, j, aData, aFilho;
	double aChave;
	for (i=0; i<folha->maxElementos; i++)
	{
		for (j=i; j<folha->maxElementos; j++)
		{
			if ((folha->elementos[i] > folha->elementos[j] && folha->elementos[j] != -1) || (folha->elementos[i] == -1 && folha->elementos[j] != -1))
			{
				aChave = folha->elementos[i];
				aData = folha->indexElemento[i];
				aFilho = folha->filhos[i];
				folha->elementos[i] = folha->elementos[j];
				folha->indexElemento[i] = folha->indexElemento[j];
				folha->filhos[i] = folha->filhos[j];
				folha->elementos[j] = aChave;
				folha->indexElemento[j] = aData;
				folha->filhos[j] = aFilho;
			}
		}
	}
	for (i=0; i<folha->maxFilhos; i++)
	{
		if (folha->filhos[i] == -1)
		{
			for (j=i+1; j<folha->maxFilhos; j++)
			{
				if (folha->filhos[j] == -1)
				{
					folha->filhos[i] = folha->filhos[j];
					folha->filhos[j] = -1;
					break;
				}
			}
		}
	}
	return;
}

// INSERE UM ITEM EM UM FILHO NA ÁRVORE B
int inserir_filho_arvoreB (ArvoreB* arvore, NoB* folha, double valor, double objeto) 
{
	int i;
	NoB* temp;
	temp = inicializa_folha (arvore->tamBloco);
	if (folha->filhos[0] != -1)  
	{
		for (i=0; i<folha->maxElementos; i++)
		{
			if (valor<folha->elementos[i] || folha->elementos[i] == -1) break;
		}
		leitura_disco (arvore, folha->filhos[i], temp);
		if (total_elemento_no (temp) > 0)
		{
				if (total_elemento_no (temp) == temp->maxElementos) 
				{
					explodir (arvore, temp, valor, objeto, -1);
					leitura_disco (arvore, arvore->raiz->posAtual, arvore->raiz);
					return 1;
				}
				adicionar_elemento (arvore, temp, valor, objeto);
				ordena (temp);
				escrita_disco (arvore, temp->posAtual, temp);
		}
		else 
		{
			adicionar_elemento (arvore, temp, valor, objeto);
			ordena (temp);
			escrita_disco (arvore, temp->posAtual, temp);
		}
	}
	return 1;
}

// INSERE UM ITEM NA ÁRVORE B
int insere_arvoreB (TreeB* arvr, double valor, void* objeto)
{
	int data, pos;
	NoB* folha;
	ArvoreB *arvore;
	arvore = (ArvoreB *) arvr;
	data = adicionar_objeto_arquivo (objeto, arvore->caminho, arvore->escritor);
	if (arvore->raiz == NULL) 
	{
		arvore->raiz = inicializa_folha (arvore->tamBloco);
		folha = arvore->raiz;
		adicionar_elemento (arvore, folha, valor, data);
		fseek (arvore->arq, 0, SEEK_END);	
		pos = ftell (arvore->arq);
		folha->posAtual = pos;
		escrita_disco (arvore, pos, folha);
		leitura_disco (arvore, pos, folha);
		rewind (arvore->arq);
		fseek (arvore->arq, sizeof (int), SEEK_SET);
		fwrite (&pos, sizeof (int), 1, arvore->arq);
	}
	else 
	{
		folha = arvore->raiz;
		if (folha->filhos[0] != -1) {
			inserir_filho_arvoreB (arvore, folha, valor, data);
		}
		else 
		{
			if (total_elemento_no (folha) == folha->maxElementos) 
			{
				separa (arvore, folha, valor, data);
			}
			else 
			{
				adicionar_elemento (arvore, folha, valor, data);
				escrita_disco (arvore, folha->posAtual, arvore->raiz);
			}
		}
	}
	return 0;
}

///// FIM DAS FUNÇÕES NECESSÁRIAS PARA A FUNÇÃO INSERE_ARVOREB

///// FUNÇÕES NECESSÁRIAS PARA A FUNÇÃO DELETE_ARVOREB

//FUNDE DOIS NÓS EM UM SÓ
void fusao (ArvoreB* arvore, NoB* folha)
{
	int i, j, k, m, n, meio, dAux, data[folha->maxElementos*2];
	double eAux, elem[folha->maxElementos*2];
	NoB* pai;
	NoB* dir;
	NoB* esq;
	if (folha->TotalElementoNo >= folha->maxElementos / 2) return;
	if (folha->pai == -1) return;
	pai = inicializa_folha (arvore->tamBloco);
	leitura_disco (arvore, folha->pai, pai);
	for (i=0; i<pai->maxFilhos; i++)
	{
		if (pai->filhos[i] == folha->posAtual) break;
	}
	dir = inicializa_folha (arvore->tamBloco);
	if (i+i < pai->maxFilhos && pai->filhos[i+1] != -1)
	{
		leitura_disco (arvore, pai->filhos[i+1], dir);
	}
	else
	{
		free (dir);
		dir = NULL;
	}
	esq = inicializa_folha (arvore->tamBloco);
	if (i-1 >=0 && pai->filhos[i-1] != -1)
	{
		leitura_disco (arvore, pai->filhos[i-1], esq);
	}
	else
	{
		free (esq);
		esq = NULL;
	}
	if (dir == NULL && esq == NULL)
	{
		k = 0;
		for (j=0; j<folha->maxElementos; j++)
		{
			if (folha->elementos[j] == -1) break;
			elem[k] = folha->elementos[j];
			data[k] = folha->indexElemento[j];
			k++;
		}
		for (j=0; j<pai->maxElementos; j++)
		{
			elem[k] = pai->elementos[j];
			data[k] = pai->elementos[j];
			k++;
		}
		if (k+1 < pai->maxElementos)
		{
			pai->filhos[i] = -1;
			for (i=0; i<k+1; i++)
			{
				pai->elementos[i] = elem[i];
				pai->indexElemento[i] = data[i];
			}
			pai->TotalElementoNo = k;
			pai->totalFilhos = 0;
		}
		else
		{
			pai->filhos[i] = -1;
			for (i=0; i<k+1; i++)
			{
				pai->elementos[i] = -1;
				pai->indexElemento[i] = -1;
			}
			pai->TotalElementoNo = 0;
			pai->totalFilhos = 0;
			for (i=0; i < k+1; i++)
			{
				adicionar_elemento (arvore, pai, elem[i], data[i]);
			}
		}
	}
	if (dir == NULL && esq != NULL)
	{
		k = 0;
		for (j=0; j<folha->maxElementos; j++)
		{
			if(folha->elementos[j] == -1) break;
			elem[k] = folha->elementos[j];
			data[k] = folha->indexElemento[j];
			k++;
		}
		for (j=0; j<esq->maxElementos; j++)
		{
			if(esq->elementos[j] == -1) break;
			elem[k] = esq->elementos[j];
			data[k] = esq->indexElemento[j];
			k++;
		}
		elem[k] = pai->elementos[i-1];
		data[k] = pai->indexElemento[i-1];
		if (k+1 < esq->maxElementos)
		{
			for (j=0; j<esq->maxElementos; j++)
			{
				esq->elementos[j] = -1;
				esq->indexElemento[j] = -1;
			}
			for (j=0; j<=k; j++)
			{
				esq->elementos[j] = elem[j];
				esq->indexElemento[j] = data[j];
			}
			esq->TotalElementoNo = k;
			ordena (esq);
			pai->elementos[i-1] = -1;
			pai->indexElemento[i-1] = -1;
			pai->filhos[i] = -1;
			pai->TotalElementoNo--;
			if (pai->TotalElementoNo == 0) esq->posAtual = pai->posAtual;
			ordena (pai);
			ordena (esq);
			escrita_disco (arvore, pai->posAtual, pai);
			escrita_disco (arvore, esq->posAtual, esq);
			free (pai);
			free (esq);
		}
		else
		{
			for (m=0; m<=k; m++)
			{
				for (n=m; n<=k; n++)
				{
					if (elem[m] > elem[n])
					{
						eAux = elem[m];
						dAux = data[m];
						elem[m] = elem[n];
						data[m] = data[n];
						elem[n] = eAux;
						data[n] = dAux;
					}
				}
			}
			meio = k / 2;
			pai->elementos[i-1] = elem[meio];
			pai->indexElemento[i-1] = data[meio];
			for (j=0; j<esq->maxElementos; j++)
			{
				esq->elementos[j] = -1;
				esq->indexElemento[j] = -1;
			}
			for (j=0; j<meio; j++)
			{
				esq->elementos[j] = elem[j];
				esq->indexElemento[j] = data[j];
			}
			esq->TotalElementoNo = meio;
			for(j=(meio+1); j<=k; j++)
			{
				folha->elementos[j-(meio+1)] = elem[j];
				folha->indexElemento[j-(meio+1)] = data[j];
			}
			folha->TotalElementoNo = k-(meio);
			ordena (pai);
			ordena (esq);
			ordena (folha);
			escrita_disco (arvore, pai->posAtual, pai);
			escrita_disco (arvore, esq->posAtual, esq);
			escrita_disco (arvore, folha->posAtual, folha);
		}
		return;
	}
	if (esq == NULL && dir != NULL)
	{
		k = 0;
		for (j=0; j<folha->maxElementos; j++)
		{
			if (folha->elementos[j] == -1) break;
			elem[k] = folha->elementos[j];
			data[k] = folha->indexElemento[j];
			k++;
		}
		for (j=0; j<dir->maxElementos; j++)
		{
			if (dir->elementos[j] == -1) break;
			elem[k] = dir->elementos[j];
			data[k] = dir->indexElemento[j];
			k++;
		}
		elem[k] = pai->elementos[i];
		data[k] = pai->indexElemento[i];
		if (k+1 < dir->maxElementos)
		{
			for (j=0; j<dir->maxElementos; j++)
			{
				dir->elementos[j] = -1;
				dir->indexElemento[j] = -1;
			}
			for (j=0; j<=k; j++)
			{
				dir->elementos[j] = elem[j];
				dir->indexElemento[j] = data[j];
			}
			dir->TotalElementoNo = k;
			ordena (dir);
			pai->elementos[i] = -1;
			pai->indexElemento[i] = -1;
			pai->filhos[i+1] = -1;
			pai->TotalElementoNo--;
			if (pai->TotalElementoNo == 0)
			{
				dir->posAtual = pai->posAtual;
			}
			ordena (pai);
			ordena (dir);
			escrita_disco (arvore, pai->posAtual, pai);
			escrita_disco (arvore, dir->posAtual, dir);
			free (pai);
			free (dir);
		}
		else
		{
			for (m=0; m<=k; m++)
			{
				for (n=m; n<=k; n++)
				{
					if (elem[m] > elem[n])
					{
						eAux = elem[m];
						dAux = data[m];
						elem[m] = elem[n];
						data[m] = data[n];
						elem[n] = eAux;
						data[n] = dAux;
					}
				}
			}
			meio = k / 2;
			pai->elementos[i] = elem[meio];
			pai->indexElemento[i] = data[meio];
			for (j=0; j<meio; j++)
			{
				folha->elementos[j] = elem[j];
				folha->indexElemento[j] = data[j];
			}
			folha->TotalElementoNo = meio;
			for (j=0; j<dir->maxElementos; j++)
			{
				dir->elementos[j] = -1;
				dir->indexElemento[j] = -1;
			}
			for (j=(meio+1); j<=k; j++)
			{
				dir->elementos[j-(meio+1)] = elem[j];
				dir->indexElemento[j-(meio+1)] = data[j];
			}
			dir->TotalElementoNo = k-(meio);
			ordena (pai);
			ordena (folha);
			ordena (dir);
			escrita_disco (arvore, pai->posAtual, pai);
			escrita_disco (arvore, folha->posAtual, folha);
			escrita_disco (arvore, dir->posAtual, dir);
		}
		return;
	}
}

// RETORNA O ÍNDICE DO OBJETO QUE ESTÁ NA FOLHA (VERIFICA SE ESTÁ DENTRO DO NÓ)
int busca_elemento (ArvoreB* arvore, NoB* folha, double valor, void* objeto)
{
	int i;
	void* obj;
	for (i=0; i<folha->maxElementos; i++)
	{
		if (folha->elementos[i] == valor)
		{
            obj = get_objeto_arquivo (arvore->caminho, folha->indexElemento[i], arvore->leitor, arvore->alloc);
            if (arvore->compare (obj, objeto) == 0)
			return folha->indexElemento[i];
		}
	}
	return -1;
}

//REMOVE UM ELEMENTO E RETORNA SEU ÍNDICE
int retira_elemento (ArvoreB* arvore, NoB* folha, double elem, void* objeto)
{
	int i;
	void* obj;
	for (i=0; i<folha->maxElementos; i++)
	{
		if (folha->elementos[i] == elem)
		{
            obj = get_objeto_arquivo (arvore->caminho, folha->indexElemento[i], arvore->leitor, arvore->alloc);
            if (arvore->compare (obj, objeto) == 0)
			{
                folha->elementos[i] = -1;
                deletar_objeto_arquivo (arvore->caminho, folha->indexElemento[i]);
                folha->indexElemento[i] = -1;
				folha->TotalElementoNo--;
                return i;
            }
		}
	}
	return -1;
}

// FUNÇÃO QUE PROCURA O VALOR MAIS À DIREITA DO NÓ
Info* procura_direita (ArvoreB* arvore, NoB* folha)
{
	int i;
	NoB* no;
	Info* result;
	for (i=folha->maxElementos-1; i>=0; i--)
	{
		if (folha->elementos[i] != -1)
		{
			if (folha->filhos[i+1] != -1){
				no = inicializa_folha (arvore->tamBloco);
				leitura_disco (arvore, folha->filhos[i+1], no);
				return procura_direita (arvore, no);
			}
			result = (Info*) malloc (sizeof (Info));
			result->chave = folha->elementos[i];
			result->data = folha->indexElemento[i];
			folha->elementos[i] = -1;
			folha->elementos[i] = -1;
			escrita_disco (arvore, folha->posAtual, folha);
			return result;
		}
	}
}

// FUNÇÃO AUXILIAR DO DELETE_ARVOREB
int delete_secundario (ArvoreB* arvore, NoB* folha, double valor, void* objeto)
{
	int res, ctr, i;
	NoB* no;
	NoB* temp;
	Info* infoData;
	if (busca_elemento (arvore, folha, valor, objeto) != -1)
	{
		ctr = retira_elemento (arvore, folha, valor, objeto);
		if (ctr >= 0)
		{
			if (folha->filhos[ctr] != -1)
			{
				no = inicializa_folha (arvore->tamBloco);
				leitura_disco (arvore, folha->filhos[ctr], no);
				infoData = procura_direita (arvore, no);
				folha->elementos[ctr] = infoData->chave;
				folha->indexElemento[ctr] = infoData->data;
				escrita_disco (arvore, folha->posAtual, folha);
			}
			return folha->posAtual;
		}
	}
	else 
	{
		for (i=0; i<folha->maxElementos; i++)
		{
			if (folha->elementos[i] == -1) break;
			if (folha->filhos[i] != -1 && valor <= folha->elementos[i])
			{
				temp = inicializa_folha (arvore->tamBloco);
				leitura_disco (arvore, folha->filhos[i], temp);
                res = busca_elemento (arvore, temp, valor, objeto);
				if (res >= 0) 
				{
					ctr = retira_elemento (arvore, temp, valor, objeto);
					if (ctr >= 0)
					{
						if (temp->filhos[ctr] != -1)
						{
							no = inicializa_folha (arvore->tamBloco);
							leitura_disco (arvore, temp->filhos[ctr], no);
							infoData = procura_direita (arvore, no);
							temp->elementos[ctr] = infoData->chave;
							temp->indexElemento[ctr] = infoData->data;
						}
						escrita_disco (arvore, temp->posAtual, temp);
						return temp->posAtual;
					}
				}
                return delete_secundario (arvore, temp, valor, objeto);
			}
		}	
		if (folha->filhos[i] != -1)
		{
				temp = inicializa_folha (arvore->tamBloco);
				leitura_disco (arvore, folha->filhos[i], temp);
                res = busca_elemento (arvore, temp, valor, objeto);
				if (res >= 0) 
				{
					ctr = retira_elemento (arvore, temp, valor, objeto);
					if (ctr >= 0)
					{
						if (temp->filhos[ctr] != -1)
						{
							no = inicializa_folha (arvore->tamBloco);
							leitura_disco (arvore, temp->filhos[ctr], no);
							infoData = procura_direita (arvore, no);
							temp->elementos[ctr] = infoData->chave;
							temp->indexElemento[ctr] = infoData->data;
						}
						escrita_disco (arvore, temp->posAtual, temp);
						return temp->posAtual;
					}
				}
                return delete_secundario (arvore, temp, valor, objeto);
		}
	}
	return -1;
}

// DELETA UM ITEM DA ÁRVORE B
int delete_arvoreB (TreeB* arvr, double valor, void* objeto)
{
	int i;
	NoB* no;
	ArvoreB *arvore;
	arvore = (ArvoreB *) arvr;
	i = delete_secundario (arvore, arvore->raiz, valor, objeto);
	no = inicializa_folha (arvore->tamBloco);
	leitura_disco (arvore, i, no);
	ordena (no);
	fusao (arvore, no);
	if (no->pai == arvore->raiz->posAtual)
	{
		leitura_disco (arvore, arvore->raiz->posAtual, arvore->raiz);
	}
	escrita_disco (arvore, i, no);
	return i;
}

///// FIM DAS FUNÇÕES NECESSÁRIAS PARA A FUNÇÃO DELETE_ARVOREB

///// FUNÇÕES NECESSÁRIAS PARA A FUNÇÃO BUSCA_ARVOREB

// FUNÇÃO SECUNDÁRIA DE BUSCA NA ÁRVORE B
void* busca_secundario (ArvoreB* arvore, NoB* folha, double valor, void* objeto)
{	
	int indice, i, res;
	NoB* temp;
	indice = busca_elemento (arvore, folha, valor, objeto);
    if (indice >= 0)
	{
		return get_objeto_arquivo (arvore->caminho, folha->indexElemento[indice], arvore->leitor, arvore->alloc);
	}
	else 
	{
		for (i=0; i<folha->maxElementos; i++)
		{
			if (folha->elementos[i] == -1) break;
			if (folha->filhos[i] != -1 && valor <= folha->elementos[i])
			{
				temp = inicializa_folha (arvore->tamBloco);
				leitura_disco (arvore, folha->filhos[i], temp);
                res = busca_elemento (arvore, temp, valor, objeto);
				if (res >= 0) 
				{
					free (temp);
					return get_objeto_arquivo (arvore->caminho, res, arvore->leitor, arvore->alloc);
				}
                return busca_secundario (arvore, temp, valor, objeto);
				free (temp);
			}
		}
		if (folha->filhos[i] != -1)
		{
				temp = inicializa_folha (arvore->tamBloco);
				leitura_disco (arvore, folha->filhos[i], temp);
                res = busca_elemento (arvore, temp, valor, objeto);
				if (res >= 0) 
				{
					free (temp);
					return get_objeto_arquivo (arvore->caminho, res, arvore->leitor, arvore->alloc);
				}
                return busca_secundario (arvore, temp, valor, objeto);
				free (temp);
		}
	}
	return NULL;
}

// BUSCA UM ITEM NA ÁRVORE B
void* busca_arvoreB (TreeB* arvr, double valor, void* objeto)
{
	ArvoreB *arvore;
	arvore = (ArvoreB *) arvr;
	return busca_secundario (arvore, arvore->raiz, valor, objeto);
}

///// FIM DAS FUNÇÕES NECESSÁRIAS PARA A FUNÇÃO BUSCA_ARVOREB

///// FUNÇÕES NECESSÁRIAS PARA A FUNÇÃO VIZINHO_PROXIMO_ARVOREB

// FUNÇÃO SECUNDÁRIA DO VIZINHO_PROXIMO
void vizinho_proximo_secundario (ArvoreB* arvore, NoB* no, double ref, void* referencia, int ctr, double* minDist, void** minDistObj)
{
	int i;
	double dist;
	void* objeto;
	NoB* folha;
	for(i=0; i<no->maxElementos; i++)
	{
		if (no->elementos[i] != -1)
		{
			objeto = get_objeto_arquivo (arvore->caminho, arvore->raiz->indexElemento[i], arvore->leitor, arvore->alloc);
			dist = abs (arvore->compare (objeto, minDistObj));
			if (dist < 0) dist = -dist;
			if (dist < *minDist)
			{
				if (ctr != 0 || minDist != 0)
				{
					*minDist = dist;
					*minDistObj = objeto;
				}
			}
		}
	}
	for (i=0; i<no->maxElementos; i++)
	{
		if (abs (ref - no->elementos[i]) < *minDist)
		{
			if (ref - no->elementos[i] <= 0)
			{
				if (no->filhos[i] != -1)
				{
					folha = inicializa_folha (arvore->tamBloco);
					leitura_disco (arvore, no->filhos[i], folha);
					vizinho_proximo_secundario (arvore, folha, ref, referencia, ctr, minDist, minDistObj);
				}
				if (ref - no->elementos[i+1] >= 0)
				{
					if (no->filhos[i+1] != -1)
					{
						folha = inicializa_folha (arvore->tamBloco);
						leitura_disco (arvore, no->filhos[i+1], folha);
						vizinho_proximo_secundario (arvore, folha, ref, referencia, ctr, minDist, minDistObj);
					}
				}
			}
			else
			{
				if (no->filhos[i+1] != -1)
				{
					folha = inicializa_folha (arvore->tamBloco);
					leitura_disco (arvore, no->filhos[i+1], folha);
					vizinho_proximo_secundario (arvore, folha, ref, referencia, ctr, minDist, minDistObj);
				}
			}
		}
	}
}

// RETORNA O ITEM MAIS PRÓXIMO À REFERÊNCIA
// SE CTR != 0, PERMITE O RETORNO DE UM ITEM COM DISTÂNCIA = 0
void* vizinho_proximo_arvoreB (TreeB* arvr, double ref, void* referencia, int ctr)
{
	int i;
	double* minDist;
	void** minDistObj;
	NoB* folha;
	ArvoreB *arvore;
	arvore = (ArvoreB *) arvr;
	if (arvore->raiz == NULL) return NULL;
	if(arvore->raiz->elementos[0] == -1) return NULL;
	minDist = (double*) malloc (sizeof (double));
	minDistObj = (void**) malloc (sizeof (void*));
	*minDist = 0;
	i = 0;
	do
	{
		if (i >= arvore->raiz->maxElementos) return NULL;
		if (arvore->raiz->elementos[i] != -1)
		{
			*minDistObj = get_objeto_arquivo (arvore->caminho, arvore->raiz->indexElemento[i], arvore->leitor, arvore->alloc);
			*minDist = abs (arvore->compare (referencia, minDistObj));
		}
		i++;
	}
	while (*minDist==0 || ctr);
	folha = inicializa_folha (arvore->tamBloco);
	leitura_disco (arvore, arvore->raiz->posAtual, folha);
	vizinho_proximo_secundario (arvore, folha, ref, referencia, ctr, minDist, minDistObj);
	return *minDistObj;
}

///// FIM DAS FUNÇÕES NECESSÁRIAS PARA A FUNÇÃO VIZINHO_PROXIMO_ARVOREB

///// FUNÇÕES NECESSÁRIAS PARA A FUNÇÃO FREE_ARVOREB

// LIBERA A MEMÓRIA ALOCADA DA ÁRVORE B
void free_arvoreB (TreeB* arvr)
{
	ArvoreB *arvore;
	arvore = (ArvoreB *) arvr;
	fclose (arvore->arq);
	free (arvore->caminho);
	if (arvore->raiz != NULL)
	{	
		free (arvore->raiz);
	}
	free (arvore);
}

///// FIM DAS FUNÇÕES NECESSÁRIAS PARA A FUNÇÃO FREE_ARVOREB

///// FUNÇÕES NECESSÁRIAS PARA A FUNÇÃO GET_TODOS_ARVOREB

// RETORNA TODOS OS ITENS DA ÁRVORE B
Lista* get_todos_arvoreB (TreeB* arvr)
{
	ArvoreB *arvore;
	arvore = (ArvoreB *) arvr;
	return get_todos_arquivo (arvore->caminho, arvore->leitor, arvore->alloc);
}

///// FIM DAS FUNÇÕES NECESSÁRIAS PARA A FUNÇÃO GET_TODOS_ARVOREB

///// FUNÇÕES NECESSÁRIAS PARA A FUNÇÃO IMPRIME_ARVOREB

// IMPRIME UM NÓ DA ÁRVORE B
void print_no_arvoreB (ArvoreB* arvore, NoB* no)
{
	int i;
	NoB* noAux;
	printf ("\nLocal: %d", no->posAtual);
	printf ("\nElementos: \n");
	for (i=0; i<no->maxElementos; i++) printf ("| %lf |", no->elementos[i]);
	printf ("\nElementoData: \n");
	for (i=0; i<no->maxElementos; i++) printf ("| %d |", no->indexElemento[i]);
	printf("\nFilhos: \n");
	for (i=0; i<no->maxFilhos; i++) printf ("| %d |", no->filhos[i]);
	for (i=0; i<no->maxFilhos; i++)
	{
		if (no->filhos[i] != -1)
		{
			noAux = inicializa_folha (arvore->tamBloco);
			leitura_disco (arvore, no->filhos[i], noAux);
			print_no_arvoreB (arvore, noAux);
		}
	}
}

// IMPRIME A ÁRVORE B
void imprime_arvoreB (TreeB* arvr)
{
	ArvoreB *arvore;
	arvore = (ArvoreB *) arvr;
	if (arvore->raiz!=NULL)
	{
		print_no_arvoreB (arvore, arvore->raiz);
	}
}

///// FIM DAS FUNÇÕES NECESSÁRIAS PARA A FUNÇÃO IMPRIME_ARVOREB

//FUNÇÕES NECESSÁRIAS PARA A FUNÇÃO GET_TODOS_DENTRO_AREA_ARVOREB

void secundario_dentro_arvoreB (ArvoreB* arvore, NoB* folha, double valorInicial, void* refInicial, double valorFinal, void* refFinal, Lista lista)
{
	int i;
	double esq, dir;
	void* objeto;
	NoB* no;
	for (i=0; i<folha->maxElementos; i++)
	{
		if (folha->elementos[i] == -1) break;
		objeto = get_objeto_arquivo (arvore->caminho, folha->indexElemento[i], arvore->leitor, arvore->alloc);
		esq = arvore->compare (refInicial, objeto);
		dir = arvore->compare (objeto, refFinal);
		if (esq >= 0 && dir>=0)
		{
			insere_lista (lista, objeto);
		}
	}
	for (i=0; i<folha->maxElementos; i++)
	{
		if (folha->elementos[i] == -1 || folha->filhos[i] == -1) break;
		if (valorInicial <= folha->elementos[i] && folha->elementos[i] <= valorFinal)
		{
			no = inicializa_folha (arvore->tamBloco);
			leitura_disco (arvore, folha->filhos[i], no);
			secundario_dentro_arvoreB (arvore, no, valorInicial, refInicial, valorFinal, refFinal, lista);
		}
	}
	if (folha->elementos[i-1] <= valorFinal && folha->filhos[i] != -1)
	{
			no = inicializa_folha (arvore->tamBloco);
			leitura_disco(arvore, folha->filhos[i], no);
			secundario_dentro_arvoreB (arvore, no, valorInicial, refInicial, valorFinal, refFinal, lista);
	}
}

//RETORNA UMA LISTA COM TODOS OS ITENS DA ÁRVORE B DENTRO DE UMA ÁREA
Lista get_todos_dentro_area_arvoreB (TreeB* arvr, double valorInicial, void* refInicial, double valorFinal, void* refFinal)
{
	ArvoreB *arvore;
	arvore = (ArvoreB *) arvr;
	Lista lista = cria_lista();
	secundario_dentro_arvoreB (arvore, arvore->raiz, valorInicial, refInicial, valorFinal, refFinal, lista);
	return lista;
}
