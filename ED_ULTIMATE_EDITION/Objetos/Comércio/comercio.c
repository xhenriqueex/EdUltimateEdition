#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Quadra/quadra.h"
#include "../../Formas/Retângulo/retangulo.h"
#include "../../Parâmetros/parametros.h"
#include "../../Estruturas/Hash/hashtable.h"

//DEFINE A STRUCT TIPO
typedef struct {
    char* cod;
    char* info;
} Tip;

//DEFINE A STRUCT ENDEREÇO
typedef struct e{
    int tipo;
    char* cep;
    char* face;
    char* num;
    char* comp;
    void* comercio;
} Endereco;

//DEFINE A STRUCT COMÉRCIO
typedef struct c{
    char* cnpj;
    Tip* tipo;
    Endereco* endereco;
    char* nome;
} Com;

//CRIA UM COMÉRCIO
void* cria_comercio (char* cnpj, void* tip, char* cep, char* face, char* num, char* nome)
{
    Com* result;
    result = (Com*) calloc (1, sizeof (Com));

    Endereco* end;
    end = (Endereco*) calloc (1, sizeof (Endereco));
    end->tipo = 0;
    end->cep = (char*) calloc (strlen (cep) + 2, sizeof (char*));
    end->face = (char*) calloc (strlen (face) + 2, sizeof (char*));
    end->num = (char*) calloc (strlen (num) + 2, sizeof (char*));
    end->comp = NULL;
    Tip* tipo;
    tipo = (Tip*) tip;
    result->cnpj = (char*) calloc (strlen (cnpj) + 2, sizeof (char*));
    result->nome = (char*) calloc (strlen (nome) + 2, sizeof (char*));
    strcpy(result->cnpj, cnpj);
    strcpy(end->cep, cep);
    strcpy(end->face, face);
    strcpy(end->num, num);
    strcpy(result->nome, nome);
    result->tipo = tipo;
    result->endereco = end;
    result->endereco->comercio = result;
    return (void*) result;
}

//DEFINE O TIPO DO COMÉRCIO
void* cria_tipo_comercio (char* cod, char* info)
{
    Tip* tipo;
    tipo = (Tip*) calloc (1, sizeof (Tip));
    tipo->cod = (char*) calloc (strlen (cod) + 2, sizeof (char));
    tipo->info = (char*) calloc (strlen (info) + 2, sizeof (char));
    strcpy (tipo->cod, cod);
    strcpy (tipo->info, info);
    return (void*) tipo;
}

//RETORNA UM ENDEREÇO CORRESPONDENTE À UMA MUDANÇA DE ENDEREÇO
void* set_endereco_comercio (void* com,  char* cep, char* face, char* num)
{
    Com* result;
    result = (Com*) com;
    free (result->endereco->cep);
    result->endereco->cep = NULL;
    free (result->endereco->face);
    result->endereco->face = NULL;
    free (result->endereco->num);
    result->endereco->num = NULL;
    result->endereco->cep = (char*) calloc (strlen (cep) + 2 , sizeof (char*));
    result->endereco->face = (char*) calloc (strlen (face) + 2 , sizeof (char*));
    result->endereco->num = (char*) calloc (strlen (num) + 2  , sizeof (char*));
    strcpy (result->endereco->cep, cep);
    strcpy (result->endereco->face, face);
    strcpy (result->endereco->num, num);
    return (void*) result->endereco;
}

//RETORNA O ENDEREÇO DO COMÉRCIO
void* get_endereco_comercio (void* com)
{
    Com* result;
    result = (Com*) com;
    return (void*) result->endereco;
}

//LIBERA A MEMÓRIA ALOCADA DO COMÉRCIO
void free_comercio (void* com)
{
    Com* result;
    result = (Com*) com;
    free (result->nome);
    result->nome = NULL;
    free (result->cnpj);
    result->cnpj = NULL;
    if (result->endereco != NULL) 
    {
        free (result->endereco->cep);
        result->endereco->cep = NULL;
        free (result->endereco->face);
        result->endereco->face = NULL;
        free (result->endereco->num);
        result->endereco->num = NULL;
        free (result->endereco);
        result->endereco = NULL;
    }
    free (result);
    result = NULL;
}

//FUNÇÃO DE COMPARAÇÃO DE CNPJ DE COMÉRCIO
int compare_comercio (void* com1, void* com2, int dim)
{
    Com* comA;
    Com* comB;    
    comA = (Com*) com1;
    comB = (Com*) com2;
    return strcmp (comA->cnpj, comB->cnpj);
}

//RETORNA O CÓDIGO HASH DO COMÉRCIO
int hashcode_comercio (void* com, int modulo)
{
    Com* result;
    result = (Com*) com;
    int x = strlen (result->cnpj);
    int hash = 0;
    char* aux = result->cnpj;
    while (*aux != 0)
    {
        hash += x*(*aux);
        aux++;
        x--;
    }
    return modulo < 0 ? hash : hash % modulo;
}

//COMPARADOR DE CNPJ DO COMÉRCIO
int compare_cnpj_comercio (void* com, void* cnpj)
{
    Com* com1;
    Com* com2;
    com1 = (Com*) com;
    com2 = (Com*) cnpj;
    return strcmp (com1->cnpj, com2->cnpj);
}

//COMPARADOR DE ENDEREÇOS DO COMÉRCIO
int compare_endereco_comercio (void* end1, void* end2, int dim)
{
    Endereco* endereco1;
    Endereco* endereco2;    
    endereco1 = (Endereco*) end1;
    endereco2 = (Endereco*) end2;
    return strcmp (endereco1->cep, endereco2->cep);
}

//RETORNA O CÓDIGO HASH DO TIPO DO COMÉRCIO
int hashcode_tipo_comercio (void* tip, int modulo)
{
    Tip *tipo;
    tipo = (Tip*) tip;
    int x = strlen (tipo->cod);
    int hash = 0;
    char *aux = tipo->cod;
    while(*aux != 0)
    {
        hash += x*(*aux);
        aux++;
        x--;
    }
    return modulo < 0 ? hash : hash % modulo;
}

//COMPARADOR DE HASH DO TIPO DO COMÉRCIO
int compare_hash_tipo_comercio (void* tip, void* cod)
{
    Tip *tp, *id;
    tp = (Tip*) tip;
    id = (Tip*) cod;
    return strcmp (tp->cod, id->cod);
}

//RETORNA O COMÉRCIO PRESENTE NO ENDEREÇO ESPECÍFICO
void* get_comercio_endereco (void* endereco)
{
    Endereco* end;
    end = (Endereco*) endereco;
    if(end->tipo == 1)
    {
        return NULL;
    } 
    return end->comercio;
}

//RETORNA O CÓDIGO HASH DO ENDEREÇO DO COMÉRCIO
int hashcode_endereco_comercio (void* endereco, int modulo)
{
    Endereco *end;
    end = (Endereco*) endereco;
    int x = strlen (end->cep);
    int hash = 0;
    char *aux = end->cep;
    while(*aux != 0)
    {
        hash += x*(*aux);
        aux++;
        x--;
    }
    return modulo < 0 ? hash : hash % modulo;
}

//COMPARADOR DE HASH DO ENDEREÇO DO COMÉRCIO
int compare_hash_endereco_comercio (void* endereco1, void* endereco2)
{
    Endereco* end1;
    Endereco *end2;
    end1 = (Endereco*) endereco1;
    end2 = (Endereco*) endereco2;
    return strcmp (end1->cep, end2->cep);
}

//RETORNA AS COORDENADAS DO COMÉRCIO
double* get_xy_comercio (void* comercio, Parametros* par)
{
    Com* com;
    double num;
    com = (Com*) comercio;
    double* result;
    if(com->endereco == NULL)
    {
        return NULL;
    }
    Quadra temp = cria_quadra (com->endereco->cep, 0, 0, 0, 0, "", "");
    Quadra quad = get_hashtable (par->hash_quadras, temp);
    sscanf (com->endereco->num, "%lf", &num);
    result = (double*) calloc (2, sizeof (double));
    result[0] = get_x_retangulo (get_retangulo_quadra (quad));
    result[1] = get_y_retangulo (get_retangulo_quadra (quad));
    if(!strcmp (com->endereco->face, "N"))
    {
        result[0] += num;
        result[1] += get_h_retangulo (get_retangulo_quadra (quad));
    }
    if(!strcmp(com->endereco->face, "S"))
    {
        result[0] += num;
    }
    if(!strcmp(com->endereco->face, "L"))
    {
        result[1] += num;
    }
    if(!strcmp(com->endereco->face, "O"))
    {
        result[1] += num;
        result[0] += get_w_retangulo (get_retangulo_quadra (quad));
    }
    return result;
}

//GERA UMA STRING COM AS INFORMAÇÕES DO COMÉRCIO 
char* relatorio_comercio (void* comercio)
{
    Com* com;
    com = (Com*) comercio;
    char* result;
    result = (char*) calloc (555, sizeof (char));
    if(com->endereco == NULL)
    {
        sprintf (result, "\nNome: %s \nTipo: %s\n", com->nome, com->tipo->info);
    }
    else
    {
        sprintf (result, "\nNome: %s \nTipo: %s \nEndereço: CEP = %s,   Face = %s   Número = %s\n", com->nome, com->tipo->info, com->endereco->cep, com->endereco->face, com->endereco->num);
    }
    return result;
}

//ESTRUTURA DE ENDEREÇO NECESSÁRIA PARA ENCONTRAR O COMÉRCIO NA ÁRVORE
void* identificador_endereco_comercio (char* cep)
{
    Endereco* end;
    end = (Endereco*) calloc (1, sizeof(Endereco));
    end->tipo = 0;
    end->cep = (char*) calloc (strlen (cep) + 2, sizeof (char));
    strcpy (end->cep,cep);
    end->face= NULL;
    end->num = NULL;
    end->comp= NULL;
    end->comercio = NULL;
    return (void*) end;
}

//RETORNA O CÓDIGO DO TIPO DO COMÉRCIO
char* get_codigo_tipo_comercio (void* comercio)
{
    Com* com;
    com = (Com*) comercio;
    return com->tipo->cod;
}

//RETORNA O TIPO DO COMÉRCIO
char* get_tipo_comercio (Com* comercio)
{
    Com* com;
    com = (Com*) comercio;
    return com->tipo->info;
}

//RETORNA O NOME DO COMÉRCIO
char* get_nome_comercio (Com* comercio)
{
    Com* com;
    com = (Com*) comercio;
    return com->nome;
}

//RETORNA O CNPJ DO COMÉRCIO
char* get_cnpj_comercio (Com* comercio)
{
    Com* com;
    com = (Com*) comercio;
    return com->cnpj;
}

//GERA UMA STRING COM O RELATÓRIO DA MUDANÇA DA PESSOA
char* relatorio_mud_comercio (void* comercio, void* end1, void* end2)
{
    char* relatorio;
    Com* com;
    Endereco* endA;
    Endereco* endB;
    com = (Com*) comercio;
    endA = (Endereco*) end1;
    endB = (Endereco*) end2;
    relatorio = (char*) calloc (555, sizeof (char));
    if (end1 == NULL)
    {
        sprintf (relatorio, "\nEndereço novo : %s/%s/%s\n", endB->cep, endB->face, endB->num);
    }
    if (end2 == NULL)
    {
        sprintf (relatorio, "\nNome: %s Tipo: %s\nEndereço antigo: %s/%s/%s", com->nome, com->tipo->info, endA->cep, endA->face, endA->num);
    }
    return relatorio;
}