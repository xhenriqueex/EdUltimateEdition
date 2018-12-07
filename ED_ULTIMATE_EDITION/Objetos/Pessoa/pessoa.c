#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Parâmetros/parametros.h"
#include "../Quadra/quadra.h"
#include "../../Estruturas/Hash/hashtable.h"

//DEFINE A STRUCT ENDEREÇO
typedef struct e{
    int tipo;
    char* cep;
    char* face;
    char* num;
    char* comp;
    void* pessoa;
} Endereco;

//DEFINE A STRUCT PESSOA
typedef struct p{
    char* nome;
    char* sobrenome;
    char* cpf;
    char* sexo;
    char* nascimento;
    Endereco* endereco;
} Pessoa;

//CRIA E RETORNA UMA PESSOA COM OS VALORES PASSADOS
void* cria_pessoa (char* nome, char* sobrenome, char* cpf, char* sexo, char* nascimento)
{
    Pessoa* result;
    result = (Pessoa*) calloc (1, sizeof (Pessoa));
    result->nome = (char*) calloc (strlen (nome) + 1, sizeof(char));
    result->sobrenome = (char*) calloc (strlen (sobrenome) + 1, sizeof(char));
    result->cpf = (char*) calloc (strlen (cpf) + 1, sizeof(char));
    result->sexo = (char*) calloc (strlen (sexo) + 1, sizeof(char));
    result->nascimento = (char*) calloc (strlen (nascimento) + 1, sizeof(char));
    result->endereco = NULL;
    strcpy (result->nome, nome);
    strcpy (result->sobrenome, sobrenome);
    strcpy (result->cpf, cpf);
    strcpy (result->sexo, sexo);
    strcpy (result->nascimento, nascimento);
    return (void*) result;  
}

//ATRIBUI UM ENDEREÇO A UMA DETERMINADA PESSOA E O RETORNA
void* set_endereco_pessoa (void* pes, char* cep, char* face, char* num, char* comp)
{
    Pessoa* pessoa;
    pessoa = (Pessoa*) pes;
    if (pessoa->endereco == NULL)
    {
        Endereco* end;
        end = (Endereco*) calloc (1, sizeof (Endereco));
        end->tipo = 1;
        end->cep = (char*) calloc (strlen (cep) + 2, sizeof (char));
        end->face= (char*) calloc (strlen (face) + 2, sizeof (char));
        end->num = (char*) calloc (strlen (num) + 2, sizeof (char));
        end->comp= (char*) calloc (strlen (comp) + 2, sizeof (char));
        end->pessoa = pessoa;
        strcpy (end->cep, cep);
        strcpy (end->face, face);
        strcpy (end->num, num);
        strcpy (end->comp, comp);
        pessoa->endereco = end;
        return (void*) end;
    }
    else
    {
        free (pessoa->endereco->cep);
        pessoa->endereco->cep = NULL;
        free (pessoa->endereco->face);
        pessoa->endereco->face = NULL;
        free (pessoa->endereco->num);
        pessoa->endereco->num = NULL;
        free (pessoa->endereco->comp);
        pessoa->endereco->comp = NULL;
        pessoa->endereco->cep = (char*) calloc (strlen (cep) + 2, sizeof (char));
        strcpy (pessoa->endereco->cep, cep);
        pessoa->endereco->face = (char*) calloc (strlen (face) + 2, sizeof (char));
        strcpy (pessoa->endereco->face, face);
        pessoa->endereco->num = (char*) calloc (strlen (num) + 2, sizeof (char));
        strcpy (pessoa->endereco->num, num);
        pessoa->endereco->comp = (char*) calloc (strlen (comp) + 2, sizeof (char));
        strcpy (pessoa->endereco->comp, comp);
        return (void*) pessoa->endereco;
    }
}

//RETORNA O ENDEREÇO DE UMA PESSOA
void* get_endereco_pessoa (void* pes)
{
    Pessoa* pessoa;
    pessoa = (Pessoa*) pes;
    return (void*) pessoa->endereco;
}

//LIBERA A MEMÓRIA ALOCADA A UMA PESSOA
void free_pessoa (void* pes)
{
    Pessoa* pessoa;
    pessoa = (Pessoa*) pes;
    free(pessoa->cpf);
    pessoa->cpf = NULL;
    free(pessoa->nome);
    pessoa->nome = NULL;
    free(pessoa->sobrenome);
    pessoa->sobrenome = NULL;
    free(pessoa->sexo);
    pessoa->sexo = NULL;
    free(pessoa->nascimento);
    pessoa->nascimento = NULL;
    if(pessoa->endereco != NULL)
    {
        free(pessoa->endereco->cep);
        pessoa->endereco->cep = NULL;
        free(pessoa->endereco->face);
        pessoa->endereco->face = NULL;
        free(pessoa->endereco->num);
        pessoa->endereco->num = NULL;
        free(pessoa->endereco->comp);
        pessoa->endereco->comp = NULL;
        free(pessoa->endereco);
        pessoa->endereco = NULL;
    }
    free(pessoa);
    pessoa = NULL;
}

//FUNÇÃO QUE RETORNA O CÓDIGO HASH REFERENTE À PESSOA
int hashcode_pessoa (void* pes, int modulo)
{
    Pessoa* pessoa;
    pessoa = (Pessoa*) pes;
    int x = strlen (pessoa->cpf);
    int hash = 0;
    char *aux = pessoa->cpf;
    while (*aux != 0)
    {
        hash += x*(*aux);
        aux++;
        x--;
    }
    return modulo < 0 ? hash : hash % modulo;
}

//COMPARA O CPF DE UMA PESSOA COM O CPF DESEJADO
int compare_cpf_pessoa (void* pes, void* cpf)
{
    Pessoa* pessoa;
    Pessoa* id;
    pessoa = (Pessoa*) pes;
    id = (Pessoa*) cpf;
    return strcmp (pessoa->cpf, id->cpf);
}

//RETORNA A PESSOA QUE MORA EM UM RESPECTIVO ENDEREÇO
void* get_pessoa_endereco (void* endereco)
{
    Endereco * end;
    end = (Endereco*) endereco;
    if (end->tipo == 0)
    {
        return NULL;
    }
    return end->pessoa;
}

//FUNÇÃO QUE RETORNA O CÓDIGO HASH REFERENTE AO ENDEREÇO
int hashcode_endereco_pessoa (void* endereco, int modulo)
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

//COMPARADOR DE CEP DE DOIS ENDEREÇOS
int compare_cep_endereco_pessoa (void* endereco1, void* endereco2)
{
    Endereco* est1;
    Endereco* est2;
    est1 = (Endereco*) endereco1;
    est2 = (Endereco*) endereco2;
    if (est1->cep == NULL)
    {
        return 1;
    }
    return strcmp (est1->cep, est2->cep);
}

//ESTRUTURA DE ENDEREÇO NECESSÁRIA PARA ENCONTRAR A PESSOA NA ÁRVORE
void* identificador_endereco_pessoa (char* cep)
{
    Endereco* end;
    end = (Endereco*) calloc (1, sizeof (Endereco));
    end->tipo = 1;
    end->cep = (char*) calloc (strlen (cep) + 1, sizeof (char));
    strcpy (end->cep, cep);
    end->face= NULL;
    end->num = NULL;
    end->comp= NULL;
    end->pessoa = NULL;
    return (void*) end;
}

//GERA UMA STRING COM AS INFORMAÇÕES DO ENDEREÇO DA PESSOA
char* relatorio_endereco_pessoa (void* pessoa)
{
    Pessoa* pes;
    char* result;
    result = (char*) calloc (555, sizeof (char));
    pes = (Pessoa*) pessoa;
    if (pes->endereco == NULL)
    {
        sprintf (result, "\nNome: %s %s\n", pes->nome, pes->sobrenome);
    }
    else
    {
        sprintf (result, "\nNome: %s %s \nEndereço: CEP = %s, Face = %s   Número = %s   Complemento = %s\n", pes->nome, pes->sobrenome, pes->endereco->cep, pes->endereco->face, pes->endereco->num, pes->endereco->comp);
    }
    return result;
}

//RETORNA AS COORDENADAS DA PESSOA
double* get_xy_pessoa (void* pessoa, Parametros* par)
{
    Pessoa* pes;
    double num;
    pes = (Pessoa*) pessoa;
    double* result;
    void *ret = NULL;
    if (pes->endereco == NULL)
    {
        return NULL;
    }
    Quadra temp = cria_quadra (pes->endereco->cep, 0, 0, 0, 0, "", "");
    Quadra quad = get_hashtable (par->hash_quadras, temp);
    sscanf (pes->endereco->num, "%lf", &num);
    result = (double*) calloc (2, sizeof (double));
    ret = get_retangulo_quadra(quad);
    result[0] = get_x_retangulo (ret);
    result[1] = get_y_retangulo (ret);

    if (!strcmp (pes->endereco->face, "N"))
    {
        result[0] += num;
        result[1] += get_h_retangulo (ret);
    }
    if (!strcmp (pes->endereco->face, "S"))
    {
        result[0] += num;
    }
    if (!strcmp (pes->endereco->face, "L"))
    {
        result[1] += num;
    }
    if(!strcmp(pes->endereco->face, "O"))
    {
        result[1] += num;
        result[0] += get_w_retangulo (ret);
    }
    free(ret);
    return result;
}

//GERA UMA STRING COM O RELATÓRIO DA MORTE DA PESSOA
char* relatorio_morte_pessoa (void* pessoa)
{
    char* relatorio;
    Pessoa* pes;
    pes = (Pessoa*) pessoa;
    relatorio = (char*) calloc (555, sizeof (char));
    sprintf (relatorio, "\n%s %s, portador do CPF %s, do sexo %s, nascido em %s, residia no endereço %s/%s/%s/%s, falecido!\n", pes->nome, pes->sobrenome, pes->cpf, pes->sexo, pes->nascimento, pes->endereco->cep, pes->endereco->face, pes->endereco->num, pes->endereco->comp);
    return relatorio;
}

//GERA UMA STRING COM O RELATÓRIO DA MUDANÇA DA PESSOA
char* relatorio_mud_pessoa (void* pessoa, void* end1, void* end2)
{
    char* relatorio;
    Pessoa* pes;
    Endereco* endA;
    Endereco* endB;
    pes = (Pessoa*) pessoa;
    endA = (Endereco*) end1;
    endB = (Endereco*) end2;
    relatorio = (char*) calloc (555, sizeof (char));
    if (end1 == NULL)
    {
        sprintf (relatorio, "\nEndereço novo: %s/%s/%s/%s\n", endB->cep, endB->face, endB->num, endB->comp);
    }
    if (end2 == NULL)
    {
        sprintf (relatorio, "\nNome: %s %s\nEndereço antigo: %s/%s/%s/%s", pes->nome, pes->sobrenome, endA->cep, endA->face, endA->num, endA->comp);
    }
    return relatorio;
}