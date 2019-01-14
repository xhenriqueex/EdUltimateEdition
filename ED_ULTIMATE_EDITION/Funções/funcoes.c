#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../Parâmetros/parametros.h"
#include "../Estruturas/Fila/fila.h"
#include "../Estruturas/Lista/lista.h"
#include "../Formas/Círculo/circulo.h"
#include "../Formas/Retângulo/retangulo.h"
#include "../Formas/Anotação/anotacao.h"
#include "../Objetos/Quadra/quadra.h"
#include "../Objetos/Hidrante/hidrante.h"
#include "../Objetos/Semáforo/semaforo.h"
#include "../Objetos/Rádiobase/radiobase.h"
#include "../Objetos/Comércio/comercio.h"
#include "../Objetos/Carro/carro.h"

#define C "circulo"
#define R "retangulo"
#define A "anotacao"

//TRATA OS CAMINHOS
void altera_caminho (char** caminho)
{
    int size;
    size = strlen(*caminho);
    if((*caminho)[size-1] == '/')
    {
        (*caminho)[size-1] = '\0';
    }
}

//PEGA TODOS OS COMANDOS DE ENTRADA E OS COLOCA EM UMA FILA
Fila coloca_comandos_arquivo_fila (FILE* entrada)
{
    Fila aux;
    char* linha;
    int i;
    aux = cria_fila ();
    while (!feof (entrada))
    {
        linha = (char*) calloc (200, sizeof (char));
        if (fgets(linha, 200, entrada) == NULL)
        {
            free(linha);
            linha = NULL;
            break;
        }
        if (linha[strlen(linha)-1] == '\n')
        {
            linha[strlen(linha)-1] = '\0';
        }
        if(linha[0] == '#')
        {
            insere_fila (aux, (void*) linha);
            break;
        }
        if (linha[strlen(linha)-2] == '\n')
        {
            linha[strlen(linha)-2] = '\0';
        }
        insere_fila (aux, (void*) linha);
    }
    return aux;
}

//RETORNA O TAMANHO DO VETOR DE COMANDOS
int tamanho_strings (char** strings)
{
    int n = -1;
    do 
    {
		n++;
	} 
    while(strings[n] != NULL);
	return n;
}

//LIBERA AS STRINGS DO VETOR DE COMANDOS
void free_strings (char** strings)
{
    int i = 0;
	for (i = 0; i < tamanho_strings (strings); i++)
    {
		free (strings[i]);
        strings[i] = NULL;
	}
	free (strings);
    strings = NULL;
}

//VERIFICA E RETORNA O MAIOR VALOR
double maior (double x1, double x2)
{
    if (x1 > x2)
    {
        return x1;
    }
    return x2;
}

//VERIFICA E RETORNA O MENOR VALOR
double menor_overlap (double x1, double x2)
{
    if (x1 < x2)
    {
        return x1;
    }
    return x2;
}

//REPORTA TODOS OS ITENS DENTRO DO RETÂNGULO
void reporta_dentro_retangulo (Fila resultado, void* quadras, void* hidrantes, void* semaforos, void* radiobases, double x, double y, double w, double h)
{
    double xi, xf, yi, yf;
    char* info;
    char* id;
    Fila* reporta_retangulo;
    reporta_retangulo = resultado;
    void* primeiro;
    primeiro = get_primeiro_lista (quadras);
    do
    {     
        if (primeiro == NULL)
        {
            continue;
        }
        Quadra* aux;
        aux = get_valor_lista (primeiro);
        xi = get_x_quadra (aux);
        xf = xi + get_w_quadra (aux);
        yi = get_y_quadra (aux);
        yf = yi + get_h_quadra (aux);
        if (xi >= x && xf <= (x + w) && yi >= y && yf <= (y + h))
        {
            id = (char*) calloc (strlen (get_cep_quadra (aux)) + 2, sizeof (char));
            strcpy (id, get_cep_quadra (aux));
            info = (char*) calloc (155, sizeof (char));
            sprintf (info, "\nQuad - CEP = %s X = %lf Y = %lf", id, xi, yi);
            insere_fila (reporta_retangulo, info);
        }
        primeiro = get_proximo_lista (quadras, primeiro);
    }
    while(primeiro != NULL);
    primeiro = get_primeiro_lista (hidrantes);
    do
    {
        if (primeiro == NULL)
        {
            continue;
        }
        Hidrante* aux;
        aux = get_valor_lista (primeiro);
        xi = get_x_hidrante (aux) - get_r_hidrante (aux);
        xf = get_x_hidrante (aux) + get_r_hidrante (aux);
        yi = get_y_hidrante (aux) - get_r_hidrante (aux);
        yf = get_y_hidrante (aux) + get_r_hidrante (aux);
        if (xi >= x && xf <= (x + w) && yi >= y && yf <= (y + h))
        {
            id = (char*) calloc (strlen (get_id_hidrante (aux)) + 2, sizeof (char));
            strcpy (id, get_id_hidrante (aux));
            info = (char*) calloc (155, sizeof (char));
            sprintf (info, "\nHid - ID = %s X = %lf Y = %lf", id, get_x_hidrante (aux), get_y_hidrante (aux));
            insere_fila (reporta_retangulo, info);
        }
        primeiro = get_proximo_lista (hidrantes, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (semaforos);
    do
    {
        if (primeiro == NULL)
        {
            continue;
        }
        Semaforo* aux;
        aux = get_valor_lista (primeiro);
        xi = get_x_semaforo (aux) - get_r_semaforo (aux);
        xf = get_x_semaforo (aux) + get_r_semaforo (aux);
        yi = get_y_semaforo (aux) - get_r_semaforo (aux);
        yf = get_y_semaforo (aux) + get_r_semaforo (aux);
        if (xi >= x && xf <= (x + w) && yi >= y && yf <= (y + h))
        {
            id = (char*) calloc (strlen (get_id_semaforo (aux)) + 2, sizeof (char));
            strcpy (id, get_id_semaforo (aux));
            info = (char*) calloc (155, sizeof (char));
            sprintf (info, "\nSem - ID = %s X = %lf Y = %lf", id, get_x_semaforo (aux), get_y_semaforo (aux));
            insere_fila (reporta_retangulo, info);
        }
        primeiro = get_proximo_lista (semaforos, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (radiobases);
    do
    {
        if (primeiro == NULL)
        {
            continue;
        }
        Radiobase* aux;
        aux = get_valor_lista (primeiro);
        xi = get_x_radiobase (aux) - get_r_radiobase (aux);
        xf = get_x_radiobase (aux) + get_r_radiobase (aux);
        yi = get_y_radiobase (aux) - get_r_radiobase (aux);
        yf = get_y_radiobase (aux) + get_r_radiobase (aux);
        if (xi >= x && xf <= (x + w) && yi >= y && yf <= (y + h))
        {
            id = (char*) calloc (strlen (get_id_radiobase (aux)) + 2, sizeof (char));
            strcpy (id, get_id_radiobase (aux));
            info = (char*) calloc (155, sizeof (char));
            sprintf (info, "\nRbs - ID = %s X = %lf Y = %lf", id, get_x_radiobase (aux), get_y_radiobase (aux));
            insere_fila (reporta_retangulo, info);
        }
        primeiro = get_proximo_lista (radiobases, primeiro);
    }
    while (primeiro != NULL);
    return;
}

Lista reporta_quadra_dentro_retangulo (Lista quadras, double w, double h, double x, double y)
{
    double xi, xf, yi, yf;
    char* info;
    char* id;
    Lista reporta_retangulo;
    reporta_retangulo = cria_lista ();
    void* primeiro;
    primeiro = get_primeiro_lista (quadras);
    do
    {     
        if (primeiro == NULL)
        {
            continue;
        }
        Quadra* aux;
        aux = get_valor_lista (primeiro);
        xi = get_x_quadra (aux);
        xf = xi + get_w_quadra (aux);
        yi = get_y_quadra (aux);
        yf = yi + get_h_quadra (aux);
        if (xi >= x && xf <= (x + w) && yi >= y && yf <= (y + h))
        {
            insere_lista (reporta_retangulo, aux);
        }
        primeiro = get_proximo_lista (quadras, primeiro);
    }
    while(primeiro != NULL);
    return reporta_retangulo;
}

void reporta_dentro_circulo (Fila resultado, void* quadras, void* hidrantes, void* semaforos, void* radiobases, double x, double y, double r)
{
    int result = 0;
    char* info;
    char* id;
    double dist, value1, value2;
    Fila* reporta_circulo;
    reporta_circulo = resultado;
    void* circulo;
    circulo = cria_circulo (-1, "black", "black", r, x, y);
    void* primeiro;
    primeiro = get_primeiro_lista (quadras);
    do
    {
        if (primeiro == NULL)
        {
            continue;
        }
        Quadra* aux;
        aux = get_valor_lista (primeiro);
        result += dentro_borda_circulo (circulo, (get_x_quadra(aux)), (get_y_quadra(aux)));
        result += dentro_borda_circulo (circulo, (get_x_quadra(aux) + get_w_quadra(aux)), (get_y_quadra(aux)));
        result += dentro_borda_circulo (circulo, (get_x_quadra(aux)), (get_y_quadra(aux) + get_h_quadra(aux)));
        result += dentro_borda_circulo (circulo, (get_x_quadra(aux) + get_w_quadra(aux)), (get_y_quadra(aux) + get_h_quadra(aux)));
        if (result == 4)
        {
            id = (char*) calloc (strlen (get_cep_quadra (aux)) + 2, sizeof (char));
            strcpy (id, get_cep_quadra (aux));
            info = (char*) calloc (155, sizeof (char));
            sprintf (info, "\nQuad - CEP = %s X = %lf Y = %lf", id, get_x_quadra (aux), get_y_quadra (aux));
            insere_fila (reporta_circulo, info);
        }
        primeiro = get_proximo_lista (quadras, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (hidrantes);
    do
    {
        if (primeiro == NULL)
        {
            continue;
        }
        Hidrante* aux;
        aux = get_valor_lista (primeiro);
        value1 = get_x_hidrante (aux) - x;
        value2 = get_y_hidrante (aux) - y;
        value1 *= value1;
        value2 *= value2;
        dist = sqrt (value1 + value2);
        if ((dist + get_r_hidrante (aux)) <= r)
        {
            id = (char*) calloc (strlen (get_id_hidrante (aux)) + 2, sizeof (char));
            strcpy (id, get_id_hidrante (aux));
            info = (char*) calloc (155, sizeof (char));
            sprintf (info, "\nHid - ID = %s X = %lf Y = %lf", id, get_x_hidrante (aux), get_y_hidrante (aux));
            insere_fila (reporta_circulo, info);
        }
        primeiro = get_proximo_lista(hidrantes, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (semaforos);
    do
    {
        if (primeiro == NULL)
        {
            continue;
        }
        Semaforo* aux;
        aux = get_valor_lista (primeiro);
        value1 = get_x_semaforo (aux) - x;
        value2 = get_y_semaforo (aux) - y;
        value1 *= value1;
        value2 *= value2;
        dist = sqrt (value1 + value2);
        if ((dist + get_r_semaforo(aux)) <= r)
        {
            id = (char*) calloc (strlen (get_id_semaforo (aux)) + 2, sizeof (char));
            strcpy(id, get_id_semaforo (aux));
            info = (char*) calloc (155, sizeof (char));
            sprintf (info, "\nSem - ID = %s X = %lf Y = %lf", id, get_x_semaforo (aux), get_y_semaforo (aux));
            insere_fila (reporta_circulo, info);
        }
        primeiro = get_proximo_lista(semaforos, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (radiobases);
    do
    {
        if (primeiro == NULL)
        {
            continue;
        }
        Radiobase* aux;
        aux = get_valor_lista (primeiro);
        value1 = get_x_radiobase (aux) - x;
        value2 = get_y_radiobase (aux) - y;
        value1 *= value1;
        value2 *= value2;
        dist = sqrt (value1 + value2);
        if ((dist + get_r_radiobase (aux)) <= r)
        {
            id = (char*) calloc (strlen (get_id_radiobase (aux)) + 2, sizeof (char));
            strcpy (id, get_id_radiobase (aux));
            info = (char*) calloc (155, sizeof (char));
            sprintf (info, "\nRbs - ID = %s X = %lf Y = %lf", id, get_x_radiobase (aux), get_y_radiobase (aux));
            insere_fila (reporta_circulo, info);
        }
        primeiro = get_proximo_lista(radiobases, primeiro);
    }
    while (primeiro != NULL);
    return;
}

//DELETA TODOS OS ITENS DENTRO DO RETÂNGULO
void delete_quadra_dentro_retangulo (Fila resultado, void* quadras, double x, double y, double w, double h)
{
    double xi, xf, yi, yf;
    char* info;
    char* id;
    Fila* deleta_quadra_retangulo;
    deleta_quadra_retangulo = resultado;
    void* primeiro;
    primeiro = get_primeiro_lista (quadras);
    void* auxiliar;
    do
    {     
        if (primeiro == NULL)
        {
            continue;
        }
        Quadra* aux;
        aux = get_valor_lista (primeiro);
        xi = get_x_quadra (aux);
        xf = xi + get_w_quadra (aux);
        yi = get_y_quadra (aux);
        yf = yi + get_h_quadra (aux);
        if (xi >= x && xf <= (x + w) && yi >= y && yf <= (y + h))
        {
            id = (char*) calloc (strlen (get_cep_quadra (aux)) + 2, sizeof (char));
            strcpy (id, get_cep_quadra (aux));
            info = (char*) calloc (155, sizeof (char));
            sprintf (info, "\nQuad - CEP = %s", id);
            insere_fila (deleta_quadra_retangulo, info);
            auxiliar = primeiro;
            primeiro = get_proximo_lista (quadras, primeiro);
            remove_lista (quadras, auxiliar);
            continue;
        }
        primeiro = get_proximo_lista (quadras, primeiro);
    }
    while(primeiro != NULL);
    return;
}

//DELETA TODOS OS ITENS DENTRO DO RETÂNGULO
void delete_equipamento_dentro_retangulo (Fila resultado, char* tipo, void* hidrantes, void* semaforos, void* radiobases, double x, double y, double w, double h)
{
    double xi, xf, yi, yf;
    char* info;
    char* id;
    Fila* deleta_equipamento_retangulo;
    deleta_equipamento_retangulo = resultado;
    void* primeiro;
    primeiro = get_primeiro_lista (hidrantes);
    void* auxiliar;
    int c1 = 0, c2 = 0, c3 = 0;
    while (*tipo != '\0')
    {
        if (*tipo == 'h')
        {
            c1 = 1;
        }
        if (*tipo == 's')
        {
            c2 = 1;
        }
        if (*tipo == 'r')
        {
            c3 = 1;
        }
        tipo++;
    }
    do
    {
        if (!c1)
        {
            break;
        }
        if (primeiro == NULL)
        {
            continue;
        }
        Hidrante* aux;
        aux = get_valor_lista (primeiro);
        xi = get_x_hidrante (aux) - get_r_hidrante (aux);
        xf = get_x_hidrante (aux) + get_r_hidrante (aux);
        yi = get_y_hidrante (aux) - get_r_hidrante (aux);
        yf = get_y_hidrante (aux) + get_r_hidrante (aux);
        if (xi >= x && xf <= (x + w) && yi >= y && yf <= (y + h))
        {
            id = (char*) calloc (strlen (get_id_hidrante (aux)) + 2, sizeof (char));
            strcpy (id, get_id_hidrante (aux));
            info = (char*) calloc (155, sizeof (char));
            sprintf (info, "\nHid - ID = %s", id);
            insere_fila (deleta_equipamento_retangulo, info);
            auxiliar = primeiro;
            primeiro = get_proximo_lista (hidrantes, primeiro);
            remove_lista (hidrantes, auxiliar);
            continue;
        }
        primeiro = get_proximo_lista (hidrantes, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (semaforos);
    do
    {
        if (!c2)
        {
            break;
        }
        if (primeiro == NULL)
        {
            continue;
        }
        Semaforo* aux;
        aux = get_valor_lista (primeiro);
        xi = get_x_semaforo (aux) - get_r_semaforo (aux);
        xf = get_x_semaforo (aux) + get_r_semaforo (aux);
        yi = get_y_semaforo (aux) - get_r_semaforo (aux);
        yf = get_y_semaforo (aux) + get_r_semaforo (aux);
        if (xi >= x && xf <= (x + w) && yi >= y && yf <= (y + h))
        {
            id = (char*) calloc (strlen (get_id_semaforo (aux)) + 2, sizeof (char));
            strcpy (id, get_id_semaforo (aux));
            info = (char*) calloc (155, sizeof (char));
            sprintf (info, "\nSem - ID = %s", id);
            insere_fila (deleta_equipamento_retangulo, info);
            auxiliar = primeiro;
            primeiro = get_proximo_lista (semaforos, primeiro);
            remove_lista (semaforos, auxiliar);
            continue;
        }
        primeiro = get_proximo_lista (semaforos, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (radiobases);
    do
    {
        if (!c3)
        {
            break;
        }
        if (primeiro == NULL)
        {
            continue;
        }
        Radiobase* aux;
        aux = get_valor_lista (primeiro);
        xi = get_x_radiobase (aux) - get_r_radiobase (aux);
        xf = get_x_radiobase (aux) + get_r_radiobase (aux);
        yi = get_y_radiobase (aux) - get_r_radiobase (aux);
        yf = get_y_radiobase (aux) + get_r_radiobase (aux);
        if (xi >= x && xf <= (x + w) && yi >= y && yf <= (y + h))
        {
            id = (char*) calloc (strlen (get_id_radiobase (aux)) + 2, sizeof (char));
            strcpy (id, get_id_radiobase (aux));
            info = (char*) calloc (155, sizeof (char));
            sprintf (info, "\nRbs - ID = %s", id);
            insere_fila (deleta_equipamento_retangulo, info);
            auxiliar = primeiro;
            primeiro = get_proximo_lista (radiobases, primeiro);
            remove_lista (radiobases, auxiliar);
            continue;
        }
        primeiro = get_proximo_lista (radiobases, primeiro);
    }
    while (primeiro != NULL);
    return;
}

//DELETA TODOS OS ITENS DENTRO DO CÍRCULO
void delete_quadra_dentro_circulo (Fila resultado, void* quadras, double x, double y, double r)
{
    int result;
    char* info;
    char* id;
    Fila* deleta_quadra_circulo;
    deleta_quadra_circulo = resultado;
    void* circulo;
    circulo = cria_circulo (-1, "black", "black", r, x, y);
    void* primeiro;
    primeiro = get_primeiro_lista (quadras);
    void* auxiliar;
    do
    {
        result = 0;
        if (primeiro == NULL)
        {
            continue;
        }
        Quadra* aux;
        aux = get_valor_lista (primeiro);
        result += dentro_borda_circulo (circulo, (get_x_quadra(aux)), (get_y_quadra(aux)));
        result += dentro_borda_circulo (circulo, (get_x_quadra(aux) + get_w_quadra(aux)), (get_y_quadra(aux)));
        result += dentro_borda_circulo (circulo, (get_x_quadra(aux)), (get_y_quadra(aux) + get_h_quadra(aux)));
        result += dentro_borda_circulo (circulo, (get_x_quadra(aux) + get_w_quadra(aux)), (get_y_quadra(aux) + get_h_quadra(aux)));
        if (result == 4)
        {
            id = (char*) calloc (strlen (get_cep_quadra(aux)) + 2, sizeof (char));
            strcpy (id, get_cep_quadra (aux));
            info = (char*) calloc (55, sizeof (char));
            sprintf (info, "\nQuad - CEP = %s", id);
            insere_fila (deleta_quadra_circulo, info);
            auxiliar = primeiro;
            primeiro = get_proximo_lista (quadras, primeiro);
            remove_lista (quadras, auxiliar);
            continue;
        }
        primeiro = get_proximo_lista (quadras, primeiro);
    }
    while (primeiro != NULL);
    return;
}

//DELETA TODOS OS EQUIPAMENTOS DENTRO DO CÍRCULO
void delete_equipamento_dentro_circulo (Fila resultado, char* tipo, void* hidrantes, void* semaforos, void* radiobases, double x, double y, double r)
{
    int result = 0;
    char* info;
    char* id;
    int c1 = 0, c2 = 0, c3 = 0;
    while (*tipo != '\0')
    {
        if (*tipo == 'h')
        {
            c1 = 1;
        }
        if (*tipo == 's')
        {
            c2 = 1;
        }
        if (*tipo == 'r')
        {
            c3 = 1;
        }
        tipo ++;
    }
    double dist;
    double value1, value2;
    Fila* deleta_equipamento_circulo;
    deleta_equipamento_circulo = resultado;
    void* circulo;
    circulo = cria_circulo (-1, "black", "black", r, x, y);
    void* primeiro;
    primeiro = get_primeiro_lista (hidrantes);
    void* auxiliar;
    do
    {
        if (!c1)
        {
            break;
        }
        if (primeiro == NULL)
        {
            continue;
        }
        Hidrante* aux;
        aux = get_valor_lista (primeiro);
        value1 = get_x_hidrante (aux) - x;
        value2 = get_y_hidrante (aux) - y;
        value1 *= value1;
        value2 *= value2;
        dist = sqrt (value1 + value2);
        if ((dist + get_r_hidrante(aux)) <= r)
        {
            id = (char*) calloc (strlen (get_id_hidrante (aux)) + 2, sizeof (char));
            strcpy (id, get_id_hidrante (aux));
            info = (char*) calloc (155, sizeof (char));
            sprintf (info, "\nHid - ID = %s", id);
            insere_fila (deleta_equipamento_circulo, info);
            auxiliar = primeiro;
            primeiro = get_proximo_lista (hidrantes, primeiro);
            remove_lista (hidrantes, auxiliar);
            continue;
        }
        primeiro = get_proximo_lista (hidrantes, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (semaforos);
    do
    {
        if (!c2)
        {
            break;
        }
        if (primeiro == NULL)
        {
            continue;
        }
        Semaforo* aux;
        aux = get_valor_lista (primeiro);
        value1 = get_x_semaforo (aux) - x;
        value2 = get_y_semaforo (aux) - y;
        value1 *= value1;
        value2 *= value2;
        dist = sqrt(value1 + value2);
        if ((dist + get_r_semaforo (aux)) <= r)
        {
            id = (char*) calloc (strlen (get_id_semaforo (aux)) + 2, sizeof(char));
            strcpy(id, get_id_semaforo(aux));
            info = (char*) calloc (155, sizeof(char));
            sprintf (info, "\nSem - ID = %s", id);
            insere_fila (deleta_equipamento_circulo, info);
            auxiliar = primeiro;
            primeiro = get_proximo_lista (semaforos, primeiro);
            remove_lista (semaforos, auxiliar);
            continue;
        }
        primeiro = get_proximo_lista (semaforos, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (radiobases);
    do
    {
        if (!c3)
        {
            break;
        }
        if (primeiro == NULL)
        {
            continue;
        }
        Radiobase* aux;
        aux = get_valor_lista (primeiro);
        value1 = get_x_radiobase (aux) - x;
        value2 = get_y_radiobase (aux) - y;
        value1 *= value1;
        value2 *= value2;
        dist = sqrt (value1 + value2);
        if ((dist + get_r_radiobase (aux)) <= r)
        {
            id = (char*) calloc (strlen (get_id_radiobase (aux)) + 2, sizeof (char));
            strcpy (id, get_id_radiobase (aux));
            info = (char*) calloc (155, sizeof (char));
            sprintf (info, "\nRbs - ID = %s", id);
            insere_fila (deleta_equipamento_circulo, info);
            auxiliar = primeiro;
            primeiro = get_proximo_lista (radiobases, primeiro);
            remove_lista (radiobases, auxiliar);
            continue;
        }
        primeiro = get_proximo_lista(radiobases, primeiro);
    }
    while (primeiro != NULL);
    return;
}

//ESCREVE AS INFORMAÇÕES DO CEP ESPECIFICADO (QUADRA) NO .TXT
void escreve_crd_quadra (Fila* resultado, void* quadra)
{
    Quadra* aux;
    aux = (Quadra*) quadra;
    Fila* retorno;
    retorno = (Fila*) resultado;
    char* info;
    char* id;
    double x, y;
    id = (char*) calloc (strlen (get_cep_quadra (aux)) + 2, sizeof (char));
    info = (char*) calloc (155, sizeof (char));
    strcpy (id, get_cep_quadra (aux));
    x = get_x_quadra (aux);
    y = get_y_quadra (aux);
    sprintf (info, "\nQuad - ID = %s X = %lf Y = %lf", id, x, y);
    insere_fila (retorno, info);
    insere_fila (retorno, "\n");
    return;
}

//ESCREVE AS INFORMAÇÕES DO ID ESPECIFICADO (HIDRANTE) NO .TXT
void escreve_crd_hidrante (Fila* resultado, void* hidrante)
{
    Hidrante* aux;
    aux = (Hidrante*) hidrante;
    Fila* retorno;
    retorno = (Fila*) resultado;
    char* info;
    char* id;
    double x, y;
    id = (char*) calloc (strlen (get_id_hidrante (aux)) + 2, sizeof (char));
    info = (char*) calloc (155, sizeof (char));
    strcpy (id, get_id_hidrante (aux));
    x = get_x_hidrante (aux);
    y = get_y_hidrante (aux);
    sprintf (info, "\nHid - ID = %s X = %lf Y = %lf", id, x, y);
    insere_fila (retorno, info);
    insere_fila (retorno, "\n");
    return;
}

//ESCREVE AS INFORMAÇÕES DO ID ESPECIFICADO (SEMÁFORO) NO .TXT
void escreve_crd_semaforo (Fila* resultado, void* semaforo)
{
    Semaforo* aux;
    aux = (Semaforo*) semaforo;
    Fila* retorno;
    retorno = (Fila*) resultado;
    char* info;
    char* id;
    double x, y;
    id = (char*) calloc (strlen (get_id_semaforo (aux)) + 2, sizeof (char));
    info = (char*) calloc (155, sizeof (char));
    strcpy(id, get_id_semaforo (aux));
    x = get_x_semaforo (aux);
    y = get_y_semaforo (aux);
    sprintf (info, "\nSem - ID = %s X = %lf Y = %lf", id, x, y);
    insere_fila (retorno, info);
    insere_fila (retorno, "\n");
    return;
}

//ESCREVE AS INFORMAÇÕES DO ID ESPECIFICADO (RÁDIO-BASE) NO .TXT
void escreve_crd_radiobase (Fila* resultado, void* radiobase)
{
    Radiobase* aux;
    aux = (Radiobase*) radiobase;
    Fila* retorno;
    retorno = (Fila*) resultado;
    char* info;
    char* id;
    double x, y;
    id = (char*) calloc (strlen (get_id_radiobase (aux)) + 2, sizeof (char));
    info = (char*) calloc (155, sizeof (char));
    strcpy (id, get_id_radiobase (aux));
    x = get_x_radiobase (aux);
    y = get_y_radiobase (aux);
    sprintf (info, "\nRbs - ID = %s X = %lf Y = %lf", id, x, y);
    insere_fila (retorno, info);
    insere_fila (retorno, "\n");
    return;
}

//IMPRIME POR TIPO TODOS OS ESTABELECIMENTOS NAQUELA QUADRA
char* imprime_tipos_comercios_quadra (Lista comercios)
{
    char* result;
    char* tipo;
    char* aux;
    char* nome;
    char* charAux;
    void* primeiro;
    void* prox;
    void* comercio;
    void* comercioAux;
    result = (char*) calloc (largura_lista (comercios) * 155, sizeof (char));
    //tipo = (char*) calloc (155, sizeof (char));
    //aux = (char*) calloc (155, sizeof (char));
    //nome = (char*) calloc (155, sizeof (char));
    while (largura_lista (comercios) != 0)
    {
        primeiro = get_primeiro_lista (comercios);
        comercio = get_valor_lista (primeiro);
        tipo = get_tipo_comercio (comercio);
        charAux = (char*) calloc (55, sizeof (char));
        sprintf (charAux, "\nTipo: %s", tipo);
        strcat (result, charAux);
        free (charAux);
        charAux = NULL;
        do
        {
            comercioAux = get_valor_lista (primeiro);
            aux = get_tipo_comercio (comercioAux);
            if (!strcmp (tipo, aux))
            {
                nome = get_nome_comercio (comercio);
                charAux = (char*) calloc (55, sizeof (char));
                sprintf (charAux, "\n   Nome: %s", nome);
                strcat (result, charAux);
                free (charAux);
                charAux = NULL;
                prox = get_proximo_lista (comercios, primeiro);
                remove_lista (comercios, primeiro);
                primeiro = prox;
            }
            else
            {
                primeiro = get_proximo_lista (comercios, primeiro);
            }
        }
        while (primeiro != NULL);
    }
    strcat (result, "\n");
    return result;
}

//IMPRIME TODOS OS TIPOS NAQUELA QUADRA
char* imprime_tipos_quadra (Lista comercios)
{
    char* result;
    char* tipo;
    char* aux;
    char* charAux;
    void* primeiro;
    void* prox;
    void* comercio;
    void* comercioAux;
    result = (char*) calloc (largura_lista (comercios) * 55, sizeof (char));
    while (largura_lista (comercios) != 0)
    {
        primeiro = get_primeiro_lista (comercios);
        comercio = get_valor_lista (primeiro);
        tipo = get_tipo_comercio (comercio);
        charAux = (char*) calloc (55, sizeof (char));
        sprintf (charAux, "\n   Tipo: %s", tipo);
        strcat (result, charAux);
        free (charAux);
        charAux = NULL;
        do
        {
            comercioAux = get_valor_lista (primeiro);
            aux = get_tipo_comercio (comercioAux);
            if (!strcmp (tipo, aux))
            {
                prox = get_proximo_lista (comercios, primeiro);
                remove_lista (comercios, primeiro);
                primeiro = prox;
            }
            else
            {
                primeiro = get_proximo_lista (comercios, primeiro);
            }
        }
        while (primeiro != NULL);
    }
    strcat (result, "\n");
    return result;
}

//FUNÇÃO PARA FECHAR O ARQUIVO .QRY E GERAR OS ARQUIVOS
void fecha_qry (Parametros* par)
{
    int i;
    double* coord;
    char* caminho;
    char* percorre;
    char* conteudo_svg;
    char* remove_ext;
    void* primeiro;
    FILE* saida_SVG;
    FILE* saida_QRY;
    Lista quadras;
    Lista hidrantes;
    Lista semaforos;
    Lista radiobases;
    remove_ext = par->arquivo_entrada;
    percorre = remove_ext;
    while (*percorre != '.')
    {
        percorre++;
    }
    *percorre = '\0';
    caminho = (char*) calloc (255, sizeof(char));
    strcpy (caminho, par->diretorio_saida);
    strcat (caminho, "/");
    strcat (caminho, remove_ext);
    strcat (caminho, "-");
    remove_ext = par->arquivo_entrada_qry;
    percorre = remove_ext + strlen (remove_ext) - 1;
    while (*percorre != '/')
    {
        percorre--;
    }
    remove_ext = percorre + 1;
    percorre = remove_ext + strlen (remove_ext) - 1;
    while (*percorre != '.')
    {
        percorre--;
    }
    *percorre = '\0';
    strcat (caminho, remove_ext);
    strcat (caminho, ".svg");
    saida_SVG = fopen (caminho, "w");
    free (caminho);
    caminho = NULL;
    fprintf (saida_SVG, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"100000\" height=\"100000\">");
    for (i=0; i<par->max_figuras; i++)
    {
        if (*(par->figuras + i) == NULL)
        {
            continue;
        }
        if (!strcmp (get_tipo_item (*(par->figuras + i)), R))
        {
            conteudo_svg = cria_svg_retangulo (get_valor_item (*(par->figuras + i)));
            fprintf (saida_SVG, conteudo_svg);
            free (conteudo_svg);
            conteudo_svg = NULL;
            free_retangulo (get_valor_item (*(par->figuras + i)));
            continue;
        }
        if (!strcmp (get_tipo_item (*(par->figuras + i)), C))
        {
            conteudo_svg = cria_svg_circulo (get_valor_item (*(par->figuras + i)));
            fprintf (saida_SVG, conteudo_svg);
            free (conteudo_svg);
            conteudo_svg = NULL;
            free_circulo (get_valor_item (*(par->figuras + i)));
            continue;
        }
        free_item (*(par->figuras + i));
    }
    quadras = get_todos_arvore (par->tree_quadras);
    primeiro = get_primeiro_lista (quadras);
    do
    {
        if (get_valor_lista (primeiro) == NULL)
        {
            primeiro = get_proximo_lista (quadras, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_quadra (get_valor_lista (primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">%s</text>", get_x_quadra (get_valor_lista (primeiro)) + 3, get_y_quadra (get_valor_lista (primeiro)) + get_h_quadra (get_valor_lista (primeiro)) - 3, get_cep_quadra (get_valor_lista (primeiro)));
        free (conteudo_svg);
        conteudo_svg = NULL;
        primeiro = get_proximo_lista (quadras, primeiro);
    }
    while (primeiro != NULL);
    
    for(size_t i = 0; i < largura_lista(quadras); i++)
    {
        remove_lista(quadras, get_primeiro_lista(quadras));
    }
    free(quadras);
    quadras = NULL;
    
    hidrantes = get_todos_arvore (par->tree_hidrantes);
    primeiro = get_primeiro_lista (hidrantes);
    do
    {
        if (get_valor_lista (primeiro) == NULL)
        {
            primeiro = get_proximo_lista (hidrantes, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_hidrante(get_valor_lista(primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">H</text>", get_x_hidrante(get_valor_lista(primeiro)), get_y_hidrante(get_valor_lista(primeiro)));
        free (conteudo_svg);
        conteudo_svg = NULL;
        primeiro = get_proximo_lista (hidrantes, primeiro);
    }
    while (primeiro != NULL);

    for(size_t i = 0; i < largura_lista(hidrantes); i++)
    {
        remove_lista(hidrantes, get_primeiro_lista(hidrantes));
    }
    free(hidrantes);
    hidrantes = NULL;
    
    semaforos = get_todos_arvore (par->tree_semaforos);
    primeiro = get_primeiro_lista (semaforos);
    do
    {
        if (get_valor_lista(primeiro) == NULL)
        {
            primeiro = get_proximo_lista (semaforos, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_semaforo (get_valor_lista (primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">S</text>", get_x_semaforo (get_valor_lista (primeiro)), get_y_semaforo (get_valor_lista (primeiro)));
        free (conteudo_svg);
        conteudo_svg = NULL;
        primeiro = get_proximo_lista (semaforos, primeiro);
    }
    while (primeiro != NULL);
    
    for(size_t i = 0; i < largura_lista(semaforos); i++)
    {
        remove_lista(semaforos, get_primeiro_lista(semaforos));
    }
    free(semaforos);
    semaforos = NULL;
    
    radiobases = get_todos_arvore (par->tree_radiobases);
    primeiro = get_primeiro_lista (radiobases);
    do
    {
        if (get_valor_lista (primeiro) == NULL)
        {
            primeiro = get_proximo_lista (radiobases, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_radiobase (get_valor_lista (primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">R</text>", get_x_radiobase (get_valor_lista (primeiro)), get_y_radiobase (get_valor_lista (primeiro)));
        free (conteudo_svg);
        conteudo_svg = NULL;
        primeiro = get_proximo_lista (radiobases, primeiro);
    }
    while (primeiro != NULL);

    for(size_t i = 0; i < largura_lista(radiobases); i++)
    {
        remove_lista(radiobases, get_primeiro_lista(radiobases));
    }
    free(radiobases);
    radiobases = NULL;
    
    while (!fila_vazia (par->anotacoes))
    {
        conteudo_svg = cria_svg_anotacao (remove_fila (par->anotacoes));
        fprintf (saida_SVG, conteudo_svg);
        free (conteudo_svg);
        conteudo_svg = NULL;
        continue;
    }
    ///////////escreve_grafo(par->grafo_via, par->vertices, saida_SVG, )

    fprintf (saida_SVG, "\n</svg>");
    fclose (saida_SVG);
    remove_ext = par->arquivo_entrada;
    caminho = (char*) calloc (255, sizeof(char));
    strcpy(caminho, par->diretorio_saida);
    strcat(caminho, "/");
    strcat (caminho, remove_ext);
    strcat (caminho, ".txt");
    saida_QRY = fopen (caminho, "a");
    free (caminho);
    caminho = NULL;
    percorre = par->arquivo_entrada_qry + strlen (par->arquivo_entrada_qry) - 1;
    while (*percorre != '/')
    {
        percorre--;
    }
    percorre++;
    strcat (percorre, ".qry");
    fprintf (saida_QRY, "\nARQUIVO: %s\n\n", percorre);
    while (!fila_vazia (par->resultado))
    {
        conteudo_svg = remove_fila (par->resultado);
        fprintf (saida_QRY, conteudo_svg);
        free (conteudo_svg);
        conteudo_svg = NULL;
        continue;
    }
    fclose (saida_QRY);
    printf ("\n"); 
}

void escreve_grafo (Grafo G, char **vertices, FILE *arquivo, char *cor1, char *cor2)
{
    void *vert1 = NULL, *vert2 = NULL;
    double *pos1 = NULL, *pos2 = NULL;
    char *auxCor = NULL;

    for(size_t i = 0; i < qtd_vertices(G)-1; i++)
    {
        vert1 = get_vertice(G, vertices[i]);
        vert2 = get_vertice(G, vertices[i+1]);

        pos1 = get_pos_vertice(vert1);
        pos2 = get_pos_vertice(vert2);

        if(i%2 == 0) {
            auxCor = cor1;
        }
        else {
            auxCor = cor2;
        }

        fprintf (arquivo,
            "\n<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"2\"/>",
            pos1[0], pos1[1], pos2[0], pos2[1], auxCor);
    }
}

double distancia(double *pos1, double *pos2)
{
    double result = 0;

    result = pow(pos1[0]-pos2[0], 2) + pow(pos1[1]-pos2[1], 2);
    result = sqrt(result);

    return result;
}

char **melhor_trajeto_registradores(Registrador *regis, char *r1, char *r2, Grafo G)
{
    int reg1 = 0, reg2 = 0;
    double *pos1 = NULL, *pos2 = NULL;
    void *v1 = NULL, *v2 = NULL;
    Lista l = NULL;
    char **vertices = NULL;

    reg1 = busca_registrador(regis, r1);
    reg2 = busca_registrador(regis, r2);

    pos1 = get_pos_registrador(regis[reg1]);
    pos2 = get_pos_registrador(regis[reg2]);

    v1 = vertice_mais_proximo(G, pos1);
    v2 = vertice_mais_proximo(G, pos2);

    fixa_primeiro_lista(G, get_posic_vertice(G, get_id_vertice(v1)));
    l = divide_lista(G, get_posic_vertice(G, get_id_vertice(v1)));

    vertices = dijkstra((Grafo) l, get_id_vertice(v1));

    return vertices;
//FUNÇÃO QUE ENCONTRA O COMÉRCIO MAIS PRÓXIMO DA COORDENADA QUE SEJA DAQUELE TIPO
void* comercio_proximo_coordenada (double* coord, char* tipo, Parametros* par)
{
    double dist;
    double minDist;
    double distX;
    double distY;
    double distAux;
    double* coordAux;
    void* primeiro;
    void* comercio;
    void* comProx;
    Lista comercios;
    comercios = get_todos_hashtable (par->hash_comercios);
    primeiro = get_primeiro_lista (comercios);
    if (primeiro != NULL)
    {
        comProx = get_valor_lista (primeiro);
        coordAux = get_xy_comercio (comProx, par);
        distX = *coord + *coordAux;
        distY = *(coord+1) + *(coordAux+1);
        distX = distX * distX;
        distY = distY * distY;
        minDist = sqrt (distX + distY);
    }
    primeiro = get_proximo_lista (comercios, primeiro);
    do
    {
        comercio = get_valor_lista (primeiro);
        coordAux = get_xy_comercio (comercio, par);
        distX = *coord + *coordAux;
        distY = *(coord+1) + *(coordAux+1);
        distX = distX * distX;
        distY = distY * distY;
        distAux = sqrt (distX + distY);
        if (distAux < minDist)
        {
            minDist = distAux;
            comProx = comercio;
        }
        primeiro = get_proximo_lista (comercios, primeiro);
    }
    while (primeiro != NULL);
    return comProx;
}

//FUNÇÃO QUE VERIFICA SE DOIS RETÂNGULOS SE SOBREPÕEM
int sobrepoe_ret (Retangulo ret1, Retangulo ret2)
{
    int dentro;
    double valor1, valor2;
    dentro = 1;
    valor1 = get_x_retangulo (ret1) + get_w_retangulo (ret1);
    valor2 = get_x_retangulo (ret2);
    if (valor1 <= valor2 && dentro)
    {
        dentro = 0;
    }
    valor1 = get_x_retangulo (ret1);
    valor2 = get_x_retangulo (ret2) + get_w_retangulo (ret2);
    if (valor1 >= valor2 && dentro)
    {
        dentro = 0;
    }
    valor1 = get_y_retangulo (ret1) + get_h_retangulo (ret1);
    valor2 = get_y_retangulo (ret2);
    if (valor1 <= valor2 && dentro)
    {
        dentro = 0;
    }
    valor1 = get_y_retangulo (ret1);
    valor2 = get_y_retangulo (ret2) + get_h_retangulo (ret2);
    if (valor1 >= valor2 && dentro)
    {
        dentro = 0;
    }
    return dentro;
}

//FUNÇÃO QUE DETECTA TODAS AS COLISÕES ENTRE OS CARROS
char** detectar_colisoes (Lista carros)
{
    char** colisoes;
    char* placa1;
    char* placa2;
    char* colisao;
    void* primeiro;
    void* percorre;
    void* carro1;
    void* carro2;
    int i, j;
    Lista list1;
    Retangulo* ret1;
    Retangulo* ret2;
    list1 = carros;
    i = largura_lista (list1);
    j = 0;
    colisoes = (char**) calloc (i/2, sizeof (char*));
    *colisoes = (char*) calloc (55, sizeof (char));
    primeiro = get_primeiro_lista (list1);
    do
    {
        if (primeiro == NULL)
        {
            continue;
        }
        carro1 = get_valor_lista (primeiro);
        ret1 = get_retangulo_carro (carro1);
        percorre = get_proximo_lista (list1, primeiro);
        do
        {
            if (percorre == NULL)
            {
                continue;
            }
            carro2 = get_valor_lista (percorre);
            ret2 = get_retangulo_carro (carro2);
            i = sobrepoe_ret (ret1, ret2);
            if (i == 1)
            {
                placa1 = get_placa_carro (carro1);
                placa2 = get_placa_carro (carro2);
                strcat ( *(colisoes+j), placa1);
                strcat ( *(colisoes+j), "+");
                strcat ( *(colisoes+j), placa2);
                strcat ( *(colisoes+j), "\0");
                j++;
            }
        }
        while (percorre != NULL);
    }
    while (primeiro != NULL);
}

//FUNÇÃO QUE GERA O SVG DAS COLISÕES
void fecha_colisao (Parametros* par, char* sufixo)
{
    int i;
    double* coord;
    char* caminho;
    char* percorre;
    char* conteudo_svg;
    char* remove_ext;
    void* primeiro;
    void* fila_linha;
    FILE* saida_SVG;
    FILE* saida_QRY;
    Fila aux;
    Lista quadras;
    Lista hidrantes;
    Lista semaforos;
    Lista radiobases;
    remove_ext = par->arquivo_entrada;
    percorre = remove_ext;
    while (*percorre != '.')
    {
        percorre++;
    }
    *percorre = '\0';
    caminho = (char*) calloc (255, sizeof(char));
    strcpy (caminho, par->diretorio_saida);
    strcat (caminho, "/");
    strcat (caminho, remove_ext);
    strcat (caminho, "-");
    remove_ext = par->arquivo_entrada_qry;
    percorre = remove_ext + strlen (remove_ext) - 1;
    while (*percorre != '/')
    {
        percorre--;
    }
    remove_ext = percorre + 1;
    percorre = remove_ext + strlen (remove_ext) - 1;
    while (*percorre != '.')
    {
        percorre--;
    }
    *percorre = '\0';
    strcat (caminho, remove_ext);
    strcat (caminho, "-");
    strcat (caminho, sufixo);
    strcat (caminho, ".svg");
    saida_SVG = fopen (caminho, "w");
    free (caminho);
    caminho = NULL;
    fprintf (saida_SVG, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"100000\" height=\"100000\">");
    for (i=0; i<par->max_figuras; i++)
    {
        if (*(par->figuras + i) == NULL)
        {
            continue;
        }
        if (!strcmp (get_tipo_item (*(par->figuras + i)), R))
        {
            conteudo_svg = cria_svg_retangulo (get_valor_item (*(par->figuras + i)));
            fprintf (saida_SVG, conteudo_svg);
            free (conteudo_svg);
            conteudo_svg = NULL;
            continue;
        }
        if (!strcmp (get_tipo_item (*(par->figuras + i)), C))
        {
            conteudo_svg = cria_svg_circulo (get_valor_item (*(par->figuras + i)));
            fprintf (saida_SVG, conteudo_svg);
            free (conteudo_svg);
            conteudo_svg = NULL;
            continue;
        }
    }
    quadras = get_todos_arvore (par->tree_quadras);
    primeiro = get_primeiro_lista (quadras);
    do
    {
        if (get_valor_lista (primeiro) == NULL)
        {
            primeiro = get_proximo_lista (quadras, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_quadra (get_valor_lista (primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">%s</text>", get_x_quadra (get_valor_lista (primeiro)) + 3, get_y_quadra (get_valor_lista (primeiro)) + get_h_quadra (get_valor_lista (primeiro)) - 3, get_cep_quadra (get_valor_lista (primeiro)));
        free (conteudo_svg);
        conteudo_svg = NULL;
        primeiro = get_proximo_lista (quadras, primeiro);
    }
    while (primeiro != NULL);
    hidrantes = get_todos_arvore (par->tree_hidrantes);
    primeiro = get_primeiro_lista (hidrantes);
    do
    {
        if (get_valor_lista (primeiro) == NULL)
        {
            primeiro = get_proximo_lista (hidrantes, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_hidrante(get_valor_lista(primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">H</text>", get_x_hidrante(get_valor_lista(primeiro)), get_y_hidrante(get_valor_lista(primeiro)));
        free (conteudo_svg);
        conteudo_svg = NULL;
        primeiro = get_proximo_lista (hidrantes, primeiro);
    }
    while (primeiro != NULL);
    semaforos = get_todos_arvore (par->tree_semaforos);
    primeiro = get_primeiro_lista (semaforos);
    do
    {
        if (get_valor_lista(primeiro) == NULL)
        {
            primeiro = get_proximo_lista (semaforos, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_semaforo (get_valor_lista (primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">S</text>", get_x_semaforo (get_valor_lista (primeiro)), get_y_semaforo (get_valor_lista (primeiro)));
        free (conteudo_svg);
        conteudo_svg = NULL;
        primeiro = get_proximo_lista (semaforos, primeiro);
    }
    while (primeiro != NULL);
    radiobases = get_todos_arvore (par->tree_radiobases);
    primeiro = get_primeiro_lista (radiobases);
    do
    {
        if (get_valor_lista (primeiro) == NULL)
        {
            primeiro = get_proximo_lista (radiobases, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_radiobase (get_valor_lista (primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">R</text>", get_x_radiobase (get_valor_lista (primeiro)), get_y_radiobase (get_valor_lista (primeiro)));
        free (conteudo_svg);
        conteudo_svg = NULL;
        primeiro = get_proximo_lista (radiobases, primeiro);
    }
    while (primeiro != NULL);
    aux = cria_fila();
    while (!fila_vazia (par->anotacoes))
    {
        fila_linha = remove_fila (par->anotacoes);
        conteudo_svg = cria_svg_anotacao (fila_linha);
        fprintf (saida_SVG, conteudo_svg);
        free (conteudo_svg);
        conteudo_svg = NULL;
        insere_fila (aux, fila_linha);
        continue;
    }
    while (!fila_vazia(aux))
    {
        insere_fila (par->anotacoes, remove_fila(aux));
    }
    free (aux);
    aux = NULL;
    ///////////escreve_grafo(par->grafo_via, par->vertices, saida_SVG, )
    fprintf (saida_SVG, "\n</svg>");
    fclose (saida_SVG);
}