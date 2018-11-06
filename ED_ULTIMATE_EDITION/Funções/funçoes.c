#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Estruturas/Fila/fila.h"
#include "../Estruturas/Lista/lista.h"
#include "../Formas/Círculo/circulo.h"
#include "../Formas/Retângulo/retangulo.h"
#include "../Objetos/Quadra/quadra.h"
#include "../Objetos/Hidrante/hidrante.h"
#include "../Objetos/Semáforo/semaforo.h"
#include "../Objetos/Rádiobase/radiobase.h"
#include "funçoes.h"

#define C "circulo"
#define R "retangulo"
#define A "anotaçao"

//DECLARAÇÃO DA STRUCT DE VARIÁVEIS
typedef struct params {
    char* caminho_GEO;
    char* caminho_TXT;
    char* caminho_SVG;
    char* caminho_QRY;
    char* caminho_EC;
    char* caminho_PM;
    char* diretorio_entrada;
    char* arquivo_entrada;
    char* diretorio_saida;
    char* arquivo_entrada_qry;
    char* arquivo_entrada_ec;
    char* arquivo_entrada_pm;
    char* cor_borda_quadra;
    char* cor_preenche_quadra;
    char* cor_borda_hidrante;
    char* cor_preenche_hidrante;
    char* cor_borda_semaforo;
    char* cor_preenche_semaforo;
    char* cor_borda_radiobase;
    char* cor_preenche_radiobase;
    char** comando_vetor;
    long int max_figuras;
    int contador_figuras;
    Item* figuras;
    Fila* anotaçoes;
    Fila* resultado;
    Lista quadras;
    Lista hidrantes;
    Lista semaforos;
    Lista radiobases;
} Parametros;

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
    for (i=0; !feof (entrada); i++)
    {
        linha = (char*) calloc (200, sizeof(char));
        if (fgets(linha, 200, entrada) == NULL)
        {
            continue;
        }
        if (linha[strlen(linha)-1] == '\n')
        {
            linha[strlen(linha)-1] = '\0';
        }
        if (linha[strlen(linha)-2] == '\n')
        {
            linha[strlen(linha)-2] = '\0';
        }
        linha[strlen(linha)] = '\0';
        insere_fila (aux, (void*) linha);
        continue;
    }
    return aux;
}

//IDENTIFICA TODOS OS PARAMETROS DO COMANDO LIDO E RETORNA UM VETOR DE PARAMETROS
char** trata_comando (char *leitura)
{
    char** string = NULL;
	char* aux = NULL;
    char* aux2 = NULL;
    char* auxR = NULL;
	int i = 0;
	int n = 0;
	aux = (char *) calloc (strlen (leitura) + 1, sizeof (char));
	string = (char**) calloc (1, sizeof (char*));
	strcpy (aux, leitura);
	auxR = aux;
	if (aux[0] == 32) 
    {
		aux++;
	}
	if (aux[strlen (aux) - 1] == '\n') 
    {
		aux[strlen (aux) - 1] = '\0';
	}
    do 
    {
		string = (char**) realloc (string, (1 + i) * sizeof (char*));
		string[i] = NULL;
		n = strcspn (aux, " ");
		aux2 = strtok (aux, " ");
		if (aux2 == NULL) 
        {
            break;
		}
		string[i] = (char*) calloc (strlen (aux2) + 1, sizeof (char));
		strcpy (string[i], aux2);
		aux[n] = ' ';
		aux += n + 1;
		i++;
	} 
    while (string[i-1] != NULL);
    free (auxR);
	return string;
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
	for (i = 0; i < tamanhoStrings (strings); i++)
    {
		free (strings[i]);
	}
	free (strings);
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
double menor (double x1, double x2)
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
        aux = get_valor_lista (quadras, primeiro);
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
        aux = get_valor_lista (hidrantes, primeiro);
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
        aux = get_valor_lista (semaforos, primeiro);
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
        aux = get_valor_lista (radiobases, primeiro);
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
        aux = get_valor_lista (quadras, primeiro);
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
        aux = get_valor_lista (hidrantes, primeiro);
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
        aux = get_valor_lista (semaforos, primeiro);
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
            insert_fila (reporta_circulo, info);
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
        aux = get_valor_lista (radiobases, primeiro);
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
            insert_fila (reporta_circulo, info);
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
        aux = get_valor_lista (quadras, primeiro);
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
        aux = get_valor_lista (hidrantes, primeiro);
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
        aux = get_valor_lista (semaforos, primeiro);
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
        aux = get_valor_lista (radiobases, primeiro);
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
        aux = get_valor_lista (quadras, primeiro);
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
        aux = get_valor_lista (hidrantes, primeiro);
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
        aux = get_valor_lista (semaforos, primeiro);
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
        aux = get_valor_lista (radiobases, primeiro);
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

//FUNÇÃO PARA FECHAR O ARQUIVO .QRY E GERAR OS ARQUIVOS
void fecha_qry (Parametros* par)
{
    int i;
    char* caminho;
    char* percorre;
    char* conteudo_svg;
    char* remove_ext;
    FILE* saida_SVG;
    FILE* saida_QRY;
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
            free_retangulo (get_valor_item (*(par->figuras + i)));
            continue;
        }
        else
        {
            conteudo_svg = cria_svg_circulo (get_valor_item (*(par->figuras + i)));
            fprintf (saida_SVG, conteudo_svg);
            free_circulo (get_valor_item (*(par->figuras + i)));
            continue;
        }
        free_item (*(par->figuras + i));
        free (conteudo_svg);
    }
    void* primeiro;
    primeiro = get_primeiro_lista (par->quadras);
    do
    {
        if (get_valor_lista (par->quadras, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (par->quadras, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_quadra (get_valor_lista (par->quadras, primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">%s</text>", get_x_quadra (get_valor_lista (par->quadras, primeiro)) + 3, get_y_quadra (get_valor_lista (par->quadras, primeiro)) + get_h_quadra (get_valor_lista (par->quadras, primeiro)) - 3, get_cep_quadra (get_valor_lista (par->quadras, primeiro)));
        primeiro = get_proximo_lista (par->quadras, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (par->hidrantes);
    do
    {
        if (get_valor_lista (par->hidrantes, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (par->hidrantes, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_hidrante(get_valor_lista(par->hidrantes, primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">H</text>", get_x_hidrante(get_valor_lista(par->hidrantes, primeiro)), get_y_hidrante(get_valor_lista(par->hidrantes, primeiro)));
        primeiro = get_proximo_lista (par->hidrantes, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (par->semaforos);
    do
    {
        if (get_valor_lista(par->semaforos, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (par->semaforos, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_semaforo (get_valor_lista (par->semaforos, primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">S</text>", get_x_semaforo (get_valor_lista (par->semaforos, primeiro)), get_y_semaforo (get_valor_lista (par->semaforos, primeiro)));
        primeiro = get_proximo_lista (par->semaforos, primeiro);
    }
    while (primeiro != NULL);
    primeiro = get_primeiro_lista (par->radiobases);
    do
    {
        if (get_valor_lista (par->radiobases, primeiro) == NULL)
        {
            primeiro = get_proximo_lista (par->radiobases, primeiro);
            continue;
        }
        conteudo_svg = cria_svg_radiobase (get_valor_lista (par->radiobases, primeiro));
        fprintf (saida_SVG, conteudo_svg);
        fprintf (saida_SVG, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">R</text>", get_x_radiobase (get_valor_lista (par->radiobases, primeiro)), get_y_radiobase (get_valor_lista (par->radiobases, primeiro)));
        primeiro = get_proximo_lista (par->radiobases, primeiro);
    }
    while (primeiro != NULL);
    free(conteudo_svg);
    while (!empty_fila(par->anotaçoes))
    {
        conteudo_svg = cria_anotacao_svg (remove_fila (par->anotaçoes));
        fprintf (saida_SVG, conteudo_svg);
        free (conteudo_svg);
        continue;
    }
    free (par->anotaçoes);
    fprintf (saida_SVG, "\n</svg>");
    fclose (saida_SVG);
    remove_ext = par->arquivo_entrada;
    //percorre = remove_ext;
    //while (*percorre != '.')
    //{
        //percorre++;
    //}
    //*percorre = '\0';
    caminho = (char*) calloc (255, sizeof(char));
    strcpy(caminho, par->diretorio_saida);
    strcat(caminho, "/");
    strcat (caminho, remove_ext);
    //strcat (caminho, "-");
    //remove_ext = arquivo_entrada_qry;
    //percorre = remove_ext + strlen(remove_ext)-1;
    //while (*percorre != '/')
    //{
        //percorre--;
    //}
    //remove_ext = percorre+1;
    //percorre = remove_ext + strlen(remove_ext)-1;
    //while (*percorre != '.')
    //{
        //percorre--;
    //}
    //*percorre = '\0';
    //strcat (caminho, remove_ext);
    strcat (caminho, ".txt");

    /*
    percorre = caminho + strlen(caminho)-1;
    while (*percorre != '-')
    {
        percorre--;
    }
    strcpy(percorre, ".txt");
    */
    saida_QRY = fopen (caminho, "a");
    free (caminho);
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
        continue;
    }
    free (par->resultado);
    //free(conteudo_svg);
    fclose (saida_QRY);
    printf ("\n"); 
}