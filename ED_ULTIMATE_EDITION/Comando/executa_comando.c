#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funçoes.h"
#include "retangulo.h"
#include "circulo.h"
#include "anotaçao.h"
#include "item.h"
#include "fila.h"

#define C "circulo"
#define R "retangulo"
#define A "anotaçao"

typedef struct params {
    char* caminho_GEO;
    char* caminho_TXT;
    char* caminho_SVG;
    char* diretorio_entrada;
    char* arquivo_entrada;
    char* diretorio_saida;
    char** comando_vetor;
    long int max_figuras;
    int contador_figuras;
    Item* figuras;
    Fila* anotaçoes;
    Fila* resultado;
} Parametros;

void executa_comando (void* p)
{
    Parametros* par;
    par = (Parametros*) p;
    //ALTERA O NÚMERO MÁXIMO DE FIGURAS
    if (!strcmp (*(par->comando_vetor), "nx"))
    {
        caso_nx (par);
    }
    //CRIAR UM CÍRCULO
    if (!strcmp (*(par->comando_vetor), "c"))
    {
        caso_c (par);
    }
    //CRIAR UM RETÂNGULO
    if (!strcmp (*(par->comando_vetor), "r"))
    {
        caso_r (par);
        return;
    }
    //VERIFICAR SE DUAS FIGURAS SE SOBREPOEM
    if (!strcmp (*(par->comando_vetor), "o"))
    {
        caso_o (par);
        return;
    }
    //VERIFICAR SE UM PONTO É INTERNO A FIGURA
    if (!strcmp (*(par->comando_vetor), "i"))
    {
        caso_i (par);
        return;
    }
    //CALCULAR A DISTÂNCIA ENTRE OS CENTROS DE MASSA DE DUAS FIGURAS
    if (!strcmp (*(par->comando_vetor), "d"))
    {
        caso_d (par);
        return;
    }
    //CRIA O ARQUIVO SVG COM O SUFIXO
    if (!strcmp (*(par->comando_vetor), "a"))
    {
        caso_a (par);
        return;
    }
    //FINALIZA O ARQUIVO
    if (!strcmp (*(par->comando_vetor), "#"))
    {
        caso_hashtag (par);
        return;
    }
}

void caso_nx (Parametros* par)
{
    sscanf(*(par->comando_vetor + 1), "%ld", par->max_figuras);
    return;
}
void caso_c (Parametros* par)
{
    int id, r, x, y;
    char* cor1;
    char* cor2;
    void* fig;
    Item it;
    if (par->contador_figuras >= par->max_figuras)
    {
        printf ("\nERRO: LIMITE DE FIGURAS ATINGIDO!");
        return;
    }
    id = *(par->comando_vetor + 1);
    sscanf (*(par->comando_vetor + 2), "%s", cor1);
    sscanf (*(par->comando_vetor + 3), "%s", cor2);
    r = *(par->comando_vetor + 4);
    x = *(par->comando_vetor + 5);
    y = *(par->comando_vetor + 6);
    fig = cria_circulo (id, cor1, cor2, r, x, y);
    it = cria_item (fig, C);
    par->figuras[par->contador_figuras] = it;
    par->contador_figuras++;
    return;
}
void caso_r (Parametros* par)
{
    int id, w, h, x, y;
    char* cor1;
    char* cor2;
    void* fig;
    Item it;
    if (par->contador_figuras >= par->max_figuras)
    {
        printf ("\nERRO: LIMITE DE FIGURAS ATINGIDO!");
        return;
    }
    id = *(par->comando_vetor + 1);
    sscanf (*(par->comando_vetor + 2), "%s", cor1);
    sscanf (*(par->comando_vetor + 3), "%s", cor2);
    w = *(par->comando_vetor + 4);
    h = *(par->comando_vetor + 5);
    x = *(par->comando_vetor + 6);
    y = *(par->comando_vetor + 7);
    fig = cria_retangulo (id, cor1, cor2, w, h, x, y);
    it = cria_item (fig, R);
    par->figuras[par->contador_figuras] = it;
    par->contador_figuras++;
    return;
}
void caso_o (Parametros* par)
{
    double* centro1;
    double* centro2;
    double valor1, valor2, valor3, valor4, dist;
    int dentro, id1, id2, i;
    char* string;
    Item fig1 = NULL;
    Item fig2 = NULL;
    Anotaçao anotacao;
    id1 = *(par->comando_vetor + 1);
    id2 = *(par->comando_vetor + 2);
    string = (char*) calloc (strlen(par->comando_vetor) + 1 + strlen(par->comando_vetor + 1) + 1 + strlen(par->comando_vetor + 2) + 1, sizeof(char));
    strcpy (string, *(par->comando_vetor));
    strcat (string, " ");
    strcat (string, *(par->comando_vetor + 1));
    strcat (string, " ");
    strcat (string, *(par->comando_vetor + 2));
    insere_fila(par->resultado, string);
    for (i=0; i<par->contador_figuras; i++)
    {
        if (fig1 && fig2 != NULL)
        {
            break;
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), R))
        {
            if (get_id_retangulo (get_valor_item (par->figuras[i])) == id1)
            {
                fig1 = par->figuras[i];
                continue;
            }
            if (get_id_retangulo (get_valor_item (par->figuras[i])) == id2)
            {
                fig2 = par->figuras[i];
                continue;
            }
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), C))
        {
            if (get_id_circulo (get_valor_item (par->figuras[i])) == id1)
            {
                fig1 = par->figuras[i];
                continue;
            }
            if (get_id_circulo (get_valor_item (par->figuras[i])) == id2)
            {
                fig2 = par->figuras[i];
                continue;
            }
        }
    }
    if (fig1 == NULL)
    {
        if (fig2 == NULL)
        {
            printf ("\nERRO: AS FIGURAS NAO FORAM ENCONTRADAS!");
            return;
        }
        printf ("\nERRO: UMA DAS FIGURAS NAO FORAM ENCONTRADAS!");
        return;
    }
    if (fig2 == NULL)
    {
        printf ("\nERRO: UMA DAS FIGURAS NAO FORAM ENCONTRADAS!");
        return;
    }
    if (!strcmp (get_tipo_item (fig1), C) && !strcmp (get_tipo_item (fig2), C))
    {
        centro1 = centro_massa_circulo (get_valor_item (fig1));
        centro2 = centro_massa_circulo (get_valor_item (fig2));
        valor1 = (*centro2 - *centro1);
        valor2 = (*(centro2+1) - *(centro1+1));
        free (centro1);
        free (centro2);
        dist = sqrt ((valor1 * valor1) + (valor2 * valor2));
        if (dist <= get_r_circulo (get_valor_item (fig1)) + get_r_circulo (get_valor_item (fig2)))
        {
            insere_fila (par->resultado, (Valor*) "\nSIM\n");
            if (get_x_circulo (get_valor_item (fig1)) > get_x_circulo (get_valor_item (fig2)))
            {
                valor1 = get_x_circulo (get_valor_item (fig2)) - get_r_circulo (get_valor_item (fig2));
                valor3 = get_x_circulo (get_valor_item (fig1)) + get_r_circulo (get_valor_item (fig1));
            }
            else 
            {
                valor1 = get_x_circulo (get_valor_item(fig1)) - get_r_circulo (get_valor_item (fig1));
                valor3 = get_x_circulo (get_valor_item(fig2)) + get_r_circulo (get_valor_item (fig2));
            }
            if (get_y_circulo (get_valor_item (fig1)) > get_y_circulo (get_valor_item (fig2)))
            {
                valor2 = get_y_circulo (get_valor_item (fig2)) - get_r_circulo (get_valor_item (fig2));
                valor4 = get_y_circulo (get_valor_item (fig1)) + get_r_circulo (get_valor_item(fig1));
            }
            else 
            {
                valor2 = get_y_circulo (get_valor_item(fig1)) - get_r_circulo (get_valor_item(fig1));
                valor4 = get_y_circulo (get_valor_item(fig2)) + get_r_circulo (get_valor_item(fig2));
            }
            anotacao = cria_anotacao (abs (valor1 - valor3), abs (valor2 - valor4), valor1, valor2, "SOBREPOE");
            insere_fila(par->anotaçoes, (Valor*) anotacao);
            return;
        }
        insere_fila (par->resultado, (Valor*) "\nNAO\n");
        return;
    }
    else if (!strcmp (get_tipo_item (fig1), R) && !strcmp (get_tipo_item (fig2), R) == 0)
    {
        dentro = 1;
        valor1 = get_x_retangulo (get_valor_item (fig1)) + get_w_retangulo (get_valor_item (fig1));
        valor2 = get_x_retangulo (get_valor_item (fig2));
        if (valor1 < valor2 && dentro)
        {
            dentro = 0;
        }
        valor1 = get_x_retangulo (get_valor_item (fig1));
        valor2 = get_x_retangulo (get_valor_item (fig2)) + get_w_retangulo (get_valor_item (fig2));
        if (valor1 > valor2 && dentro)
        {
            dentro = 0;
        }
        valor1 = get_y_retangulo (get_valor_item (fig1)) + get_h_retangulo (get_valor_item(fig1));
        valor2 = get_y_retangulo (get_valor_item (fig2));
        if (valor1 < valor2 && dentro)
        {
            dentro = 0;
        }
        valor1 = get_y_retangulo (get_valor_item (fig1));
        valor2 = get_y_retangulo (get_valor_item (fig2)) + get_h_retangulo (get_valor_item (fig2));
        if (valor1 > valor2 && dentro)
        {
            dentro = 0;
        }
        if (dentro == 1)
        {
            insere_fila (par->resultado, (Valor*) "\nSIM\n");
            if (get_x_retangulo (get_valor_item (fig1)) > get_x_retangulo (get_valor_item (fig2)))
            {
                valor1 = get_x_retangulo (get_valor_item (fig2));
            }
            else 
            {
                valor1 = get_x_retangulo (get_valor_item (fig1));
            }
            if (get_x_retangulo (get_valor_item (fig1)) + get_w_retangulo (get_valor_item(fig1)) > get_x_retangulo (get_valor_item (fig2)) + get_w_retangulo (get_valor_item (fig2)))
            {
                valor3 = get_x_retangulo (get_valor_item (fig1)) + get_w_retangulo (get_valor_item (fig1));
            }
            else
            {
                valor3 = get_x_retangulo (get_valor_item (fig2)) + get_w_retangulo (get_valor_item (fig2));
            }
            if (get_y_retangulo (get_valor_item (fig1)) > get_y_retangulo (get_valor_item (fig2)))
            {
                valor2 = get_y_retangulo (get_valor_item (fig2));
            }
            else 
            {
                valor2 = get_y_retangulo (get_valor_item (fig1));
            }
            if (get_y_retangulo (get_valor_item (fig1)) + get_h_retangulo (get_valor_item (fig1)) > get_y_retangulo (get_valor_item (fig2)) + get_h_retangulo (get_valor_item (fig2)))
            {
                valor4 = get_y_retangulo (get_valor_item (fig1)) + get_h_retangulo (get_valor_item (fig1));
            }
            else
            {
                valor4 = get_y_retangulo (get_valor_item (fig2)) + get_h_retangulo (get_valor_item (fig2));
            }
            anotacao = cria_anotacao (abs (valor1 - valor3), abs (valor2 - valor4), valor1, valor2, "SOBREPOE");
            insere_fila (par->anotaçoes, anotacao);
            return;
        }
        insere_fila (par->resultado, (Valor*) "\nNAO\n");
        return;
    }
    else if (!strcmp (get_tipo_item (fig1), R))
    {
        valor1 = max (get_x_retangulo (get_valor_item (fig1)), min (get_x_circulo (get_valor_item (fig2)), get_x_retangulo (get_valor_item (fig1)) + get_w_retangulo (get_valor_item (fig1))));
        valor2 = max (get_y_retangulo (get_valor_item (fig1)), min (get_y_circulo (get_valor_item (fig2)), get_y_retangulo (get_valor_item (fig1)) + get_h_retangulo (get_valor_item (fig1))));
        dentro = dentro_borda_circulo (get_valor_item (fig2), valor1, valor2);
        if (dentro == 1)
        {
            insere_fila (par->resultado, (Valor*) "\nSIM\n");
            if (get_x_retangulo (get_valor_item (fig1)) > get_x_circulo (get_valor_item (fig2)) - get_r_circulo (get_valor_item (fig2)))
            {
                valor1 = get_x_circulo (get_valor_item (fig2)) - get_r_circulo (get_valor_item (fig2));
                valor3 = get_x_retangulo (get_valor_item (fig1));
            }
            else
            {
                valor1 = get_x_retangulo (get_valor_item (fig1));
                valor3 = get_x_circulo (get_valor_item (fig2)) + get_r_circulo (get_valor_item (fig2));
            }
            if (get_y_retangulo (get_valor_item (fig1)) > get_y_circulo (get_valor_item (fig2)) - get_r_circulo (get_valor_item (fig2)))
            {
                valor2 = get_y_circulo (get_valor_item (fig2)) - get_r_circulo (get_valor_item (fig2));
                valor4 = get_y_retangulo (get_valor_item (fig1));
            }
            else
            {
                valor2 = get_y_retangulo (get_valor_item (fig1));
                valor4 = get_y_circulo (get_valor_item (fig2)) + get_r_circulo (get_valor_item (fig2));
            }
            anotacao = cria_anotacao (abs (valor1 - valor3), abs (valor2 - valor4), valor1, valor2, "SOBREPOE");
            insere_fila(par->anotaçoes, (Valor*) anotacao);
            return;
        }
        insert_fila (par->resultado, (Valor*) "\nNAO\n");
        return;
    }
    else if (!strcmp (get_tipo_item ((fig1)), C))
    {
        valor1 = max (get_x_retangulo (get_valor_item (fig2)), min (get_x_circulo (get_valor_item (fig1)), get_x_retangulo (get_valor_item (fig2)) + get_w_retangulo(get_valor_item(fig2))));
        valor2 = max (get_y_retangulo (get_valor_item (fig2)), min (get_y_circulo (get_valor_item (fig1)), get_y_retangulo (get_valor_item (fig2)) + get_h_retangulo(get_valor_item(fig2))));
        dentro = dentro_borda_circle (get_valor_item (fig1), valor1, valor2);
        if (dentro == 1)
        {
            insere_fila (par->resultado, (Valor*) "\nSIM\n");
            if (get_x_retangulo (get_valor_item (fig2)) > get_x_circulo (get_valor_item (fig1)) - get_r_circulo (get_valor_item (fig1)))
            {
                valor1 = get_x_circulo (get_valor_item (fig1)) - get_r_circulo (get_valor_item (fig1));
                valor3 = get_x_retangulo (get_valor_item (fig2));
            }
            else
            {
                valor1 = get_x_retangulo (get_valor_item (fig2));
                valor3 = get_x_circulo (get_valor_item (fig1)) + get_r_circulo (get_valor_item (fig1));
            }
            if (get_y_retangulo (get_valor_item (fig2)) > get_y_circulo (get_valor_item (fig1)) - get_r_circulo (get_valor_item (fig1)))
            {
                valor2 = get_y_circulo (get_valor_item (fig1)) - get_r_circulo (get_valor_item (fig1));
                valor4 = get_y_retangulo (get_valor_item (fig2));
            }
            else
            {
                valor2 = get_y_retangulo (get_valor_item (fig2));
                valor4 = get_y_circulo (get_valor_item (fig1)) + get_r_circulo (get_valor_item (fig1));
            }
            anotacao = cria_anotacao(abs (valor1 - valor3), abs (valor2 - valor4), valor1, valor2, "SOBREPOE");
            insere_fila(par->anotaçoes, (Valor*) anotacao);                   
            return;
        }
        insere_fila (par->resultado, (Valor*) "\nNAO\n");
        return;
    }
}
void caso_i (Parametros* par)
{
    int id, x, y, i, in1, in2;
    char* string;
    string = (char*) calloc (strlen(par->comando_vetor) + 1 + strlen(par->comando_vetor + 1) + 1 + strlen(par->comando_vetor + 2) + 1 + strlen(par->comando_vetor + 3) + 1, sizeof(char));
    strcpy (string, *(par->comando_vetor));
    strcat (string, " ");
    strcat (string, *(par->comando_vetor + 1));
    strcat (string, " ");
    strcat (string, *(par->comando_vetor + 2));
    strcat (string, " ");
    strcat (string, *(par->comando_vetor + 3));
    insert_fila (par->resultado, string);
    Item fig = NULL;
    id = *(par->comando_vetor + 1);
    x = *(par->comando_vetor + 2);
    y = *(par->comando_vetor + 3);
    for (i=0; i<par->contador_figuras; i++)
    {
        if (fig != NULL)
        {
            break;
        }
        if (!strcmp (get_valor_item (par->figuras[i]), R))
        {
            if (get_id_retangulo (get_valor_item (par->figuras[i])) == id)
            {
                fig = par->figuras[i];
                continue;
            }
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), C))
        {
            if (get_id_circulo (get_valor_item (par->figuras[i])) == id)
            {
                fig = par->figuras[i];
                continue;
            }
        }
    }
    if (fig == NULL)
    {
        printf ("\nERRO: FIGURA NAO ENCONTRADA!");
        return;
    }
    if (!strcmp (get_tipo_item (fig), R))
    {
        in1 = dentro_retangulo (get_valor_item (fig), x, y);
        if (in1 == 1)
        {
            insere_fila (par->resultado, (Valor*) "\nSIM\n");    
            return;
        }
        insere_fila (par->resultado, (Valor*) "\nNAO\n");
        return;
    }
    if (!strcmp (get_tipo_item (fig), C))
    {
        in1 = dentro_circulo (get_valor_item (fig), x, y);
        if (in1 == 1)
        {
            insert_fila(par->resultado, (Valor*) "\nSIM\n");
            return;
        }
        insert_fila(par->resultado, (Valor*) "\nNAO\n");
        return;
    }
}

void caso_d (Parametros* par)
{
    int i, id1, id2;
    char* string;
    char* result_string;
    double* centro1;
    double* centro2;
    double dx, dy, result;
    string = (char*) calloc (strlen(par->comando_vetor) + 1 + strlen(par->comando_vetor + 1) + 1 + strlen(par->comando_vetor + 2) + 1, sizeof(char));
    strcpy (string, *(par->comando_vetor));
    strcat (string, " ");
    strcat (string, *(par->comando_vetor + 1));
    strcat (string, " ");
    strcat (string, *(par->comando_vetor + 2));
    insere_fila(par->resultado, string);
    Item fig1 = NULL;
    Item fig2 = NULL;
    for (i=0; i<=par->contador_figuras; i++)
    {
        if (fig2 && fig2 != NULL)
        {
            break;
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), R))
        {
            if (get_id_retangulo (get_valor_item (par->figuras[i])) == id1)
            {
                fig1 = par->figuras[i];
                continue;
            }
            if (get_id_retangulo (get_valor_item (par->figuras[i])) == id2)
            {
                fig2 = par->figuras[i];
                continue;
            }
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), C))
        {
            if (get_id_circulo (get_valor_item (par->figuras[i])) == id1)
            {
                fig1 = par->figuras[i];
                continue;
            }
            if (get_id_circulo (get_valor_item (par->figuras[i])) == id2)
            {
                fig2 = par->figuras[i];
                continue;
            }
        }
    }
    if ((fig1) == NULL)
    {
        if ((fig2) == NULL)
        {
            printf ("\nERRO: AS FIGURAS NAO FORAM ENCONTRADAS!");
            return;
        }
        printf ("\nERRO: UMA DAS FIGURAS NAO FORAM ENCONTRADAS!");
        return;
    }
    if ((fig2) == NULL)
    {
        printf ("\nERRO: UMA DAS FIGURAS NAO FORAM ENCONTRADAS!");
        return;
    }
    if(!strcmp(get_tipo_item (fig1), R))
    {
        centro1 = centro_massa_retangulo (get_valor_item (fig1));
        if (!strcmp (get_tipo_item (fig2), R))
        {
            centro2 = centro_massa_retangulo (get_valor_item (fig2));
        }
        else
        {
            centro2 = centro_massa_circulo (get_valor_item (fig1));
        }
    }
    else
    {
        centro1 = centro_massa_circulo (get_valor_item (fig1));
        if (!strcmp (get_tipo_item (fig2), R))
        {
            centro2 = centro_massa_retangulo (get_valor_item (fig2));
        }
        else
        {
            centro2 = centro_massa_circulo (get_valor_item (fig2));
        }
    }
    dx = *centro1 - *centro2;
    dy = *(centro1 + 1) - *(centro2 +1);
    free (centro1);
    free (centro2);
    result = sqrt ((dx*dx) + (dy*dy));
    result_string = (char*) calloc (1, sizeof(result));
    sprintf (result_string, "\n%f\n", result);
    insere_fila (par->resultado, (Valor*) result_string);
    return;
}

void caso_a (Parametros* par)
{
    int id, i;
    char* percorre;
    char* svg_content;
    char* sufixo;
    char* corB;
    char* saida_svg;
    double* centro1;
    double* centro2;
    void* fila_linha;
    double x1, x2, y1, y2, dx, dy, result;
    Fila aux;
    FILE* saida_SVG;
    Item fig;
    id = *(par->comando_vetor + 1);
    fig = NULL;
    for (i=0; i<=par->contador_figuras; i++)
    {
        if (fig != NULL)
        {
            break;
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), R))
        {
            if (get_id_retangulo (get_valor_item (par->figuras[i])) == id)
            {
                fig = par->figuras[i];
                continue;
            }
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), C))
        {
            if (get_id_circulo (get_valor_item (par->figuras[i])) == id)
            {
                fig = par->figuras[i];
                continue;
            }
        }
    }
    if (fig == NULL)
    {
        printf ("\nERRO: FIGURA NAO ENCONTRADA!");
        return;
    }
    sufixo = (char*) calloc (255, sizeof(char));
    strcpy (sufixo, *(par->comando_vetor + 2));
    par->caminho_SVG = (char*) calloc (255, sizeof(char));
    strcpy(par->caminho_SVG, par->diretorio_saida);
    strcat(par->caminho_SVG, "/");
    strcat (par->caminho_SVG, par->arquivo_entrada);
    percorre = par->caminho_SVG + strlen (par->caminho_SVG) - 1;
    while (*percorre != '.')
    {
        percorre--;
    }
    strcpy(percorre, "-");
    strcat(percorre, sufixo);
    strcat(percorre, ".svg");
    saida_svg = fopen (par->caminho_SVG, "w");
    free (par->caminho_SVG);
    fprintf (saida_svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"100000\" height=\"100000\">");
    for (i=0; i<=par->contador_figuras; i++)
    {
        if (par->figuras[i] == NULL)
        {
            continue;
        }
        if (!strcmp (get_tipo_item (par->figuras[i]), R))
        {
            svg_content = cria_svg_retangulo (get_valor_item (par->figuras[i]));
            fprintf (saida_svg, svg_content);
            continue;
        }
        else
        {
            svg_content = cria_svg_circulo (get_valor_item (par->figuras[i]));
            fprintf (saida_svg, svg_content);
            continue;
        }
    }
    aux = cria_fila();
    while (!fila_vazia (par->anotaçoes))
    {
        fila_linha = remove_fila (par->anotaçoes);
        svg_content = cria_anotacao_svg (fila_linha);
        fprintf (saida_svg, svg_content);
        insere_fila (aux, fila_linha);
        continue;
    }
    while (!fila_vazia(aux))
    {
        insere_fila (par->anotaçoes, remove_fila(aux));
    }
    free (aux);
    if(!strcmp (get_tipo_item (fig), R))
    {
        centro1 = centro_massa_retangulo (get_valor_item (fig));
        corB = get_cor1_retangulo (get_valor_item (fig));
    }
    else
    {
        centro1 = centro_massa_circulo (get_valor_item (fig));
        corB = get_cor1_circulo (get_valor_item (fig));
    }
    x1 = *centro1;
    y1 = *(centro1 + 1);
    free (centro1);
    for (i=0; i<=par->contador_figuras; i++)
    {
        if (par->figuras[i] == NULL || i == id)
        {
            continue;
        }
        if (!strcmp (get_tipo_item(par->figuras[i]), R))
        {
            centro2 = centro_massa_retangulo (get_valor_item (par->figuras[i]));
        }
        else
        {
            centro2 = centro_massa_circulo (get_valor_item(par->figuras[i]));
        }
        x2 = *centro2;
        y2 =*(centro2 + 1);
        dx = x2 - x1;
        dy = y2 - y1;
        free (centro2);
        result = sqrt ((dx*dx) + (dy*dy));
        fprintf (saida_svg, "\n<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke=\"%s\" stroke-width=\"2\"/>", x1, y1, x2, y2, corB);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">%.2f</text>", (x1 + dx/2), (y1+dy/2), result);
    }
    fprintf (saida_svg, "\n</svg>");
    fclose (saida_svg);
    return;
    /*
    void* first;
    first = get_first_lista (quad_list);
    do
    {
        if (get_value_lista(quad_list, first) == NULL)
        {
            first = get_next_lista (quad_list, first);
            continue;
        }
        svg_content = generate_svg_quadra(get_value_lista(quad_list, first));
        fprintf (saida_svg, svg_content);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">%s</text>", get_x_quadra(get_value_lista(quad_list, first)), get_y_quadra(get_value_lista(quad_list, first)), get_cep_quadra(get_value_lista(quad_list, first)));
        first = get_next_lista (quad_list, first);
    }
    while (first != NULL);
    first = get_first_lista (hid_list);
    do
    {
        if (get_value_lista(hid_list, first) == NULL)
        {
            first = get_next_lista (hid_list, first);
            continue;
        }
        svg_content = generate_svg_hidrante(get_value_lista(hid_list, first));
        fprintf (saida_svg, svg_content);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">H</text>", get_x_hidrante(get_value_lista(hid_list, first)), get_y_hidrante(get_value_lista(hid_list, first)));
        first = get_next_lista (hid_list, first);
    }
    while (first != NULL);
    first = get_first_lista (sem_list);
    do
    {
        if (get_value_lista(sem_list, first) == NULL)
        {
            first = get_next_lista (sem_list, first);
            continue;
        }
        svg_content = generate_svg_semaforo(get_value_lista(sem_list, first));
        fprintf (saida_svg, svg_content);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">S</text>", get_x_semaforo(get_value_lista(sem_list, first)), get_y_semaforo(get_value_lista(sem_list, first)));
        first = get_next_lista (sem_list, first);
    }
    while (first != NULL);
    first = get_first_lista (rb_list);
    do
    {
        if (get_value_lista(rb_list, first) == NULL)
        {
            first = get_next_lista (rb_list, first);
            continue;
        }
        svg_content = generate_svg_radiobase(get_value_lista(rb_list, first));
        fprintf (saida_svg, svg_content);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">R</text>", get_x_radiobase(get_value_lista(rb_list, first)), get_y_radiobase(get_value_lista(rb_list, first)));
        first = get_next_lista (rb_list, first);
    }
    while (first != NULL);
    free(svg_content);
    fprintf (saida_svg, "\n</svg>");
    fclose (saida_svg);
    break;
    */
}

void caso_hashtag (Parametros* par)
{
    int i;
    char* percorre;
    char* svg_content;
    void* fila_linha;
    Fila aux;
    FILE* saida_svg;
    FILE* saida_txt;
    par->caminho_SVG = (char*) calloc (255, sizeof(char));
    strcpy(par->caminho_SVG, par->diretorio_saida);
    strcat(par->caminho_SVG, "/");
    strcat (par->caminho_SVG, par->arquivo_entrada);
    percorre = par->caminho_SVG + strlen(par->caminho_SVG)-1;
    while (*percorre != '.')
    {
        percorre--;
    }
    strcpy (percorre, ".svg");
    saida_svg = fopen (par->caminho_SVG, "w");
    fprintf (saida_svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"100000\" height=\"100000\">");
    for (i=0; i<=par->contador_figuras; i++)
    {
        if (par->figuras[i] == NULL)
        {
            continue;
        }
        if (!strcmp(get_tipo_item (par->figuras[i]), R))
        {

            svg_content = cria_svg_retangulo (get_valor_item (par->figuras[i]));
            fprintf (saida_svg, svg_content);
            continue;
        }
        else
        {
            svg_content = cria_svg_circulo (get_valor_item (par->figuras[i]));
            fprintf (saida_svg, svg_content);
            continue;
        }
        free (svg_content);
    }
    /*
    void* first;
    first = get_first_lista (quad_list);
    do
    {
        if (get_value_lista(quad_list, first) == NULL)
        {
            first = get_next_lista (quad_list, first);
            continue;
        }
        svg_content = generate_svg_quadra(get_value_lista(quad_list, first));
        fprintf (saida_svg, svg_content);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">%s</text>", get_x_quadra(get_value_lista(quad_list, first)) + 3, get_y_quadra(get_value_lista(quad_list, first)) + (get_h_quadra(get_value_lista(quad_list, first))) - 3, get_cep_quadra(get_value_lista(quad_list, first)));
        first = get_next_lista (quad_list, first);
    }
    while (first != NULL);
    first = get_first_lista (hid_list);
    do
    {
        if (get_value_lista(hid_list, first) == NULL)
        {
            first = get_next_lista (hid_list, first);
            continue;
        }
        svg_content = generate_svg_hidrante(get_value_lista(hid_list, first));
        fprintf (saida_svg, svg_content);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">H</text>", get_x_hidrante(get_value_lista(hid_list, first)), get_y_hidrante(get_value_lista(hid_list, first)));
        first = get_next_lista (hid_list, first);
    }
    while (first != NULL);
    first = get_first_lista (sem_list);
    do
    {
        if (get_value_lista(sem_list, first) == NULL)
        {
            first = get_next_lista (sem_list, first);
            continue;
        }
        svg_content = generate_svg_semaforo(get_value_lista(sem_list, first));
        fprintf (saida_svg, svg_content);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">S</text>", get_x_semaforo(get_value_lista(sem_list, first)), get_y_semaforo(get_value_lista(sem_list, first)));
        first = get_next_lista (sem_list, first);
    }
    while (first != NULL);
    first = get_first_lista (rb_list);
    do
    {
        if (get_value_lista(rb_list, first) == NULL)
        {
            first = get_next_lista (rb_list, first);
            continue;
        }
        svg_content = generate_svg_radiobase(get_value_lista(rb_list, first));
        fprintf (saida_svg, svg_content);
        fprintf (saida_svg, "\n<text x=\"%f\" y=\"%f\" fill=\"black\">R</text>", get_x_radiobase(get_value_lista(rb_list, first)), get_y_radiobase(get_value_lista(rb_list, first)));
        first = get_next_lista (rb_list, first);
    }
    while (first != NULL);
    free(svg_content);
    */
    aux = cria_fila ();
    while (!fila_vazia (par->anotaçoes))
    {
        fila_linha = remove_fila (par->anotaçoes);
        svg_content = cria_svg_anotacao (fila_linha);
        fprintf (saida_svg, svg_content);
        insere_fila (aux, fila_linha);
        continue;
    }
    while(!fila_vazia (aux))
    {
        insere_fila (par->anotaçoes, remove_fila (aux));
    }
    free (aux);
    fprintf (saida_svg, "\n</svg>");
    fclose (saida_svg);
    strcpy (par->caminho_TXT, par->caminho_SVG);
    percorre = par->caminho_TXT + strlen(par->caminho_TXT) - 1;
    while (*percorre != '.')
    {
        percorre--;
    }
    strcpy (percorre, ".txt");
    saida_txt = fopen (par->caminho_TXT, "a");
    free (par->caminho_TXT);
    fprintf (saida_txt, "\nARQUIVO: %s\n\n", par->arquivo_entrada);
    while (!fila_vazia (par->resultado))
    {
        svg_content = remove_fila (par->resultado);
        fprintf (saida_txt, svg_content);
        continue;
    }
    fclose (saida_txt);
    printf ("\n");
    return;
}