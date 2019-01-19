#ifndef ARQUIVOBIN_H
#define ARQUIVOBIN_H

//CRIA UM NOVO ARQUIVO BINÁRIO
void cria_arquivo (char* caminho, int tam);

//ADICIONA UM OBJETO NO ARQUIVO E RETORNA SEU ÍNDICE
int adicionar_objeto_arquivo (char* caminho, void* objeto);

//DELETA UM OBJETO NO ARQUIVO, ESPECIFICADO PELO ÍNDICE
void deletar_objeto_arquivo (char* caminho, int ind);

//RETORNA UM OBJETO DO ARQUIVO, ESPECIFICADO PELO ÍNDICE
void* get_objeto_arquivo (char* caminho, int ind);

//RETORNA UM VETOR COM TODOS OS OBJETOS DO ARQUIVO
void* get_todos_arquivo (char* caminho);


#endif