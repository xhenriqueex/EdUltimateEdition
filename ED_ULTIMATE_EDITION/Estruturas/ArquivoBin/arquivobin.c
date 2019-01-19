#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista/lista.h"

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
int adicionar_objeto_arquivo (char* caminho, void* objeto)
{
    FILE* arq;
    int tam, header, i, offset;
    long int indice;
    marca temp;
    arq = fopen (caminho, "r+b");
    fread (&indice, sizeof (long int), 1, arq);
    fread (&tam, sizeof (int), 1, arq);
    header = sizeof (long int) + sizeof (int);
    for (i=0; i<indice; i++)
    {
        offset = header + (i * (sizeof (marca) + tam));
        fseek (arq, offset, SEEK_SET);
        fread (&temp, sizeof (marca), 1, arq);
        if (temp==0) break;
    }
    offset = header + (i * (sizeof (marca) + tam));
    fseek (arq, offset, SEEK_SET);
    fwrite (&cheio, sizeof (marca), 1, arq);
    fwrite (objeto, tam, 1, arq);
    if (i == indice)
    {
        indice++;
        fwrite (&vazio, sizeof (marca), 1, arq);
        rewind (arq);
        fwrite (&indice, sizeof (long int), 1, arq);
    }
    fflush (arq);
    fclose (arq);
    return i;
}

//DELETA UM OBJETO NO ARQUIVO, ESPECIFICADO PELO ÍNDICE
void deletar_objeto_arquivo (char* caminho, int ind)
{
    FILE* arq;
    int tam, header, i, offset;
    long int indice;
    arq = fopen (caminho, "r+b");
    fread (&indice, sizeof (long int), 1, arq);
    fread (&tam, sizeof (int), 1, arq);
    header = sizeof (long int) + sizeof (int);
    if (ind >= indice || ind < 0) return;
    offset = header + (ind * (sizeof (marca) + tam));
    fseek (arq, offset, SEEK_SET);
    fwrite (&vazio, sizeof (marca), 1, arq);
    fflush (arq);
    fclose (arq);
}

//RETORNA UM OBJETO DO ARQUIVO, ESPECIFICADO PELO ÍNDICE
void* get_objeto_arquivo (char* caminho, int ind)
{
    FILE* arq;
    int tam, header, i, offset;
    long int indice;
    void* result;
    marca temp;
    arq = fopen (caminho, "r+b");
    fread (&indice, sizeof (long int), 1, arq);
    fread (&tam, sizeof (int), 1, arq);
    header = sizeof (long int) + sizeof (int);
    if (ind >= indice || ind < 0) return NULL;
    offset = header + (ind * (sizeof (marca) + tam));
    fseek (arq, offset, SEEK_SET);
    fread (&temp, sizeof (marca), 1, arq);
    if (temp == vazio) return NULL;
    result = malloc (tam);
    fread (result, tam, 1, arq);
    fflush (arq);
    fclose (arq);
    return result;
}

//RETORNA UMA LISTA COM TODOS OS OBJETOS DO ARQUIVO
Lista get_todos_arquivo (char* caminho)
{
    FILE* arq;
    int tam, header, i, offset;
    long int indice;
    void* objeto;
    Lista result;
    marca temp;
    arq = fopen (caminho, "r+b");
    fread (&indice, sizeof (long int), 1, arq);
    fread (&tam, sizeof (int), 1, arq);
    header = sizeof (long int) + sizeof (int);
    result = cria_lista ();
    for (i = 0; i<indice; i++)
    {
        offset = header + (i *(tam + sizeof (marca)));
        fseek (arq, offset, SEEK_SET);
        fread (&temp, sizeof (marca), 1, arq);
        if (temp == vazio) continue;
        objeto = malloc (tam);
        fread (objeto, tam, 1, arq);
        insere_lista (result, objeto);
    }
    fflush (arq);
    fclose (arq);
    return result;
}
