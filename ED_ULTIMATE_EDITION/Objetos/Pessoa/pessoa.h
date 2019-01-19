//BIBLIOTECA PARA FUNÇÕES DO OBJETO PESSOA

#ifndef PESSOA_H
#define PESSOA_H
#include "../../Parametros/parametros.h"

//DEFINE O TIPO PESSOA
typedef void* Pessoa;
typedef void* Endereco;

//CRIA E RETORNA UMA PESSOA COM OS VALORES PASSADOS
Pessoa cria_pessoa (char* cpf, char* nome, char* sobrenome, char* sexo, char* nasc);

//LIBERA A MEMÓRIA ALOCADA A UMA PESSOA
void free_pessoa (Pessoa pes);

void free_endereco(void *endereco);

//ATRIBUI UM ENDEREÇO A UMA DETERMINADA PESSOA
Endereco set_endereco_pessoa (Pessoa pes, char* cep, char* face, char* num, char* comp);

//RETORNA O ENDEREÇO DE UMA PESSOA
Endereco get_endereco_pessoa (Pessoa pes);

//FUNÇÃO QUE RETORNA O CÓDIGO HASH REFERENTE À PESSOA
int hashcode_pessoa (Pessoa pes, int modulo);

//COMPARA O CPF DE UMA PESSOA COM O CPF DESEJADO
int compare_cpf_pessoa (Pessoa pes, void* cpf);

//RETORNA A PESSOA QUE MORA EM UM RESPECTIVO ENDEREÇO
void* get_pessoa_endereco (Endereco endereco);

//FUNÇÃO QUE RETORNA O CÓDIGO HASH REFERENTE AO ENDEREÇO
int hashcode_endereco_pessoa (Endereco endereco, int modulo);

//COMPARADOR PARA HASHTABLE DE ENDEREÇO DA PESSOA
int compare_cep_endereco_pessoa (Endereco endereco1, Endereco endereco2);

//ESTRUTURA DE ENDEREÇO NECESSÁRIA PARA ENCONTRAR A PESSOA NA ÁRVORE
void* identificador_endereco_pessoa (char* cep);

//GERA UMA STRING COM AS INFORMAÇÕES DA PESSOA
char* relatorio_endereco_pessoa (Pessoa pessoa);

//RETORNA AS COORDENADAS DA PESSOA
double* get_xy_pessoa (Pessoa pessoa, Parametros* par);

//GERA UMA STRING COM O RELATÓRIO DA MORTE DA PESSOA
char* relatorio_morte_pessoa (Pessoa pessoa);

//GERA UMA STRING COM O RELATÓRIO DA MUDANÇA DA PESSOA
char* relatorio_mud_pessoa (Pessoa pessoa, void* end1, void* end2);

//ESCREVE A PESSOA NO ARQUIVO
void escreve_arquivo_pessoa (void* morador, int procura, FILE* arq);

//LE A PESSOA DO ARQUIVO
void ler_arquivo_pessoa (void* morador, int procura, FILE* arq);

//RETORNA O TAMANHO DA PESSOA
int get_tamanho_pessoa ();

//FUNÇÃO DE COMPARAÇÃO DA ÁRVORE B DA PESSOA
double compare_pessoa_arvoreB (void* objA, void* objB);

//ESCREVE O ENDEREÇO DA PESSOA NO ARQUIVO
void escreve_arquivo_endereco_pessoa (void* pessoa, int procura, FILE* arq);

//LE O ENDEREÇO DA PESSOA DO ARQUIVO
void ler_arquivo_endereco_pessoa (void* pessoa, int procura, FILE* arq);

//RETORNA O TAMANHO DO ENDEREÇO DA PESSOA
int get_tamanho_endereco_pessoa ();

#endif