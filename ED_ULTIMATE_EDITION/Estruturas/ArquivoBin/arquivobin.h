#ifndef ARQUIVOBIN_H
#define ARQUIVOBIN_H
#include <stdio.h>

//CRIA UM NOVO ARQUIVO BINÁRIO
void cria_arquivo (char* caminho, int tam);

//ADICIONA UM OBJETO NO ARQUIVO E RETORNA SEU ÍNDICE
int adicionar_objeto_arquivo (char* caminho, void* objeto, void (*escritor)(void* obj, int procura, FILE* arq));
 
//DELETA UM OBJETO NO ARQUIVO, ESPECIFICADO PELO ÍNDICE
void deletar_objeto_arquivo (char* caminho, int ind);

//RETORNA UM OBJETO DO ARQUIVO, ESPECIFICADO PELO ÍNDICE
void* get_objeto_arquivo (char* caminho, int ind, void (*leitor)(void* obj, int procura, FILE* arq), void* (*alloc)());

//RETORNA UM VETOR COM TODOS OS OBJETOS DO ARQUIVO
void* get_todos_arquivo (char* caminho, void (*leitor)(void* obj, int procura, FILE* arq), void* (*alloc)());


#endif