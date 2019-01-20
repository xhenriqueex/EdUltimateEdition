#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Lista/lista.h"

typedef short int marca;
static marca cheio = 1;
static marca vazio = 0;

//CRIA UM NOVO ARQUIVO BINÁRIO
void cria_arquivo (char* caminho, int tam)
{
    FILE* arq;
    int qte;
    long int zero = 0;
    arq = fopen (caminho, "wb");
    qte = fwrite (&zero, sizeof (long int), 1, arq); // último índice do vetor 
    qte = fwrite (&tam, sizeof (int), 1, arq); // tamanho do objeto
    qte = fwrite (&vazio, sizeof (marca), 1, arq); // marca de vazio
    fflush (arq);
    fclose (arq);
}

//ADICIONA UM OBJETO NO ARQUIVO E RETORNA SEU ÍNDICE
int adicionar_objeto_arquivo (char* caminho, void* objeto, void (*escritor)(void* obj, int procura, FILE* arq))
{
    FILE* arq;
    int bloco, primeiro, i, qte;
    long int indice, offset, prox;
    marca temp;
    arq = fopen (caminho, "r+b");
    fread (&indice, sizeof (long int), 1, arq);
    fread (&bloco, sizeof (int), 1, arq);
    primeiro = ftell (arq);
    rewind (arq);
    i = 0;
    while (1)
    {
        qte = fseek (arq, (primeiro + (i * (bloco + sizeof (marca)))), SEEK_SET);
        fread (&temp, sizeof (marca), 1, arq);
        if (temp == 0) break;
        if (i == indice) break;
        i++;
    }
    offset = (primeiro + (i * (bloco + sizeof (marca))));
    qte = fseek (arq, offset, SEEK_SET);
    qte = fwrite (&cheio, sizeof (marca), 1, arq);
    escritor (objeto, ftell (arq), arq);
    if (i == indice)
    {
        prox = indice + 1;
        qte = fwrite (&vazio, sizeof (marca), 1,arq);
        rewind (arq);
        fwrite (&prox, sizeof (long int), 1, arq);
    }
    fflush (arq);
    fclose (arq);
    return i;
}

//DELETA UM OBJETO NO ARQUIVO, ESPECIFICADO PELO ÍNDICE
void deletar_objeto_arquivo (char* caminho, int ind)
{
    FILE* arq;
    int bloco, primeiro;
    long int qte, offset;
    arq = fopen (caminho, "r+b");
    fread (&qte, sizeof (long int), 1, arq);
    fread (&bloco, sizeof (int), 1, arq);
    primeiro = ftell (arq);
    if (ind >= qte || ind < 0) return;
    offset = (primeiro + (ind * (bloco + sizeof (marca))));
    fseek (arq, offset, SEEK_SET);
    fwrite (&vazio, sizeof (marca), 1, arq);
    fflush (arq);
    fclose (arq);
}

//RETORNA UM OBJETO DO ARQUIVO, ESPECIFICADO PELO ÍNDICE
void* get_objeto_arquivo (char* caminho, int ind, void (*leitor)(void* obj, int procura, FILE* arq), void* (*alloc)())
{
    FILE* arq;
    int bloco, primeiro, pos;
    long int qte;
    void* result;
    marca temp;
    arq = fopen (caminho, "r+b");
    fread (&qte, sizeof (long int), 1, arq);
    fread (&bloco, sizeof (int), 1, arq);
    primeiro = ftell (arq);
    rewind (arq);
    pos = fseek (arq, primeiro, SEEK_SET);
    qte = fseek (arq, (primeiro + (ind * (bloco + sizeof (marca)))), SEEK_SET);
    fread (&temp, sizeof (marca), 1, arq);
    if (temp == vazio) return NULL;
    result = alloc ();
    leitor (result, ftell (arq), arq);
    fflush (arq);
    fclose (arq);
    return result;
}

//RETORNA UMA LISTA COM TODOS OS OBJETOS DO ARQUIVO
Lista get_todos_arquivo (char* caminho, void (*leitor)(void* obj, int procura, FILE* arq), void* (*alloc)())
{
    FILE* arq;
    int bloco, primeiro, pos, i;
    long int qte;
    void* objeto;
    Lista result;
    marca temp;
    result = cria_lista ();
    arq = fopen (caminho, "r+b");
    fread (&qte, sizeof (long int), 1, arq);
    fread (&bloco, sizeof (int), 1, arq);
    primeiro = ftell (arq);
    rewind (arq);
    pos = fseek (arq, primeiro, SEEK_SET);
    for (i=0; i<qte; i++)
    {
        fseek (arq, (primeiro + (i * (bloco + sizeof (marca)))), SEEK_SET);
        fread (&temp, sizeof (marca), 1, arq);
        if (temp == vazio) continue;
        objeto = alloc ();
        leitor (objeto, ftell (arq), arq);
        insere_lista (result, objeto);
    }
    fflush (arq);
    fclose (arq);
    return result;
}
