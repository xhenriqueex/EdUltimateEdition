//BIBLIOTECA PARA FUNÇÕES DO OBJETO PESSOA

#ifndef PESSOA_H
#define PESSOA_H
#include "../../Parâmetros/parametros.h"

//DEFINE O TIPO PESSOA
typedef void* Pessoa;
typedef void* Endereco;

//CRIA E RETORNA UMA PESSOA COM OS VALORES PASSADOS
Pessoa cria_pessoa (char* cpf, char* nome, char* sobrenome, char* sexo, char* nasc);

//ATRIBUI UM ENDEREÇO A UMA DETERMINADA PESSOA
Endereco set_endereco_pessoa (Pessoa pes, char* cep, char* face, char* num, char* comp);

//RETORNA O ENDEREÇO DE UMA PESSOA
Endereco get_endereco_pessoa (Pessoa pes);

//LIBERA A MEMÓRIA ALOCADA A UMA PESSOA
void free_pessoa (Pessoa pes);

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

#endif