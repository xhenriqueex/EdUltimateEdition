//BIBLIOTECA DE FUNÇÕES PARA UTILIZAÇÃO DURANTE O PROGRAMA

#ifndef FUNCOES_H
#define FUNCOES_H
#include <stdio.h>
#include "../Estruturas/Fila/fila.h"
#include "../Estruturas/Lista/lista.h"
#include "../Parametros/parametros.h"
#include "../Estruturas/Grafo/grafo.h"
#include "../Formas/Retangulo/retangulo.h"

//TRATA OS CAMINHOS
void altera_caminho (char** caminho);

//PEGA TODOS OS COMANDOS DE ENTRADA E OS COLOCA EM UMA FILA
Fila coloca_comandos_arquivo_fila (FILE* entrada);

//VERIFICA SE DUAS FIGURAS SE SOBREPÕEM
int sobrepoe (void* fig1, void* fig2);

//IDENTIFICA TODOS OS PARAMETROS DO COMANDO LIDO E RETORNA UM VETOR DE PARAMETROS
char** trata_comando (char* leitura);

//RETORNA O TAMANHO DO VETOR DE COMANDOS
int tamanho_strings (char** strings);

//LIBERA AS STRINGS DO VETOR DE COMANDOS
void free_strings (char** strings);

//VERIFICA E RETORNA O MAIOR VALOR
double maior (double x1, double x2);

//VERIFICA E RETORNA O MENOR VALOR
double menor_overlap (double x1, double x2);

//REPORTA TODOS OS ITENS DENTRO DO RETÂNGULO
void reporta_dentro_retangulo (Fila resultado, void* quadras, void* hidrantes, void* semaforos, void* radiobases, double x, double y, double w, double h);

//REPORTA TODAS AS QUADRAS DENTRO DO RETÂNGULO
Lista reporta_quadra_dentro_retangulo (void* quadras, double w, double h, double x, double y);

//REPORTA TODOS OS ITENS DENTRO DO CÍRCULO
void reporta_dentro_circulo (Fila resultado, void* quadras, void* hidrantes, void* semaforos, void* radiobases, double x, double y, double r);

//DELETA TODAS AS QUADRAS DENTRO DO RETÂNGULO
void delete_quadra_dentro_retangulo (Fila resultado, void* quadras, double x, double y, double w, double h);

//DELETA TODOS OS EQUIPAMENTOS DENTRO DO RETÂNGULO
void delete_equipamento_dentro_retangulo (Fila resultado, char* tipo, void* hidrantes, void* semaforos, void* radiobases, double x, double y, double w, double h);

//DELETA TODAS AS QUADRAS DENTRO DO CÍRCULO
void delete_quadra_dentro_circulo (Fila resultado, void* quadras, double x, double y, double r);

//DELETA TODOS OS EQUIPAMENTOS DENTRO DO CÍRCULO
void delete_equipamento_dentro_circulo (Fila resultado, char* tipo, void* hidrantes, void* semaforos, void* radiobases, double x, double y, double r);

//ESCREVE AS INFORMAÇÕES DO CEP ESPECIFICADO (QUADRA) NO .TXT
void escreve_crd_quadra (Fila* resultado, void* quadra);
 
//ESCREVE AS INFORMAÇÕES DO ID ESPECIFICADO (HIDRANTE) NO .TXT
void escreve_crd_hidrante (Fila* resultado, void* hidrante);

//ESCREVE AS INFORMAÇÕES DO ID ESPECIFICADO (SEMÁFORO) NO .TXT
void escreve_crd_semaforo (Fila* resultado, void* semaforo);

//ESCREVE AS INFORMAÇÕES DO ID ESPECIFICADO (RÁDIO-BASE) NO .TXT
void escreve_crd_radiobase (Fila* resultado, void* radiobase);

//IMPRIME POR TIPO TODOS OS ESTABELECIMENTOS NAQUELA QUADRA
char* imprime_tipos_comercios_quadra (Lista comercios);

//IMPRIME TODOS OS TIPOS NAQUELA QUADRA
char* imprime_tipos_quadra (Lista comercios);

//FUNÇÃO QUE GERA O SVG DO CAMINHO
void fecha_caminho (Parametros* par, Grafo_forma gf);

//FUNÇÃO PARA FECHAR O ARQUIVO .QRY E GERAR OS ARQUIVOS
void fecha_qry (Parametros* par);

//FUNÇÃO QUE ENCONTRA O COMÉRCIO MAIS PRÓXIMO DA COORDENADA QUE SEJA DAQUELE TIPO
void* comercio_proximo_coordenada (double* coord, char* tipo, Parametros* par);

//FUNÇÃO QUE VERIFICA SE DOIS RETÂNGULOS SE SOBREPÕEM
int sobrepoe_ret (Retangulo ret1, Retangulo ret2);

//FUNÇÃO QUE DETECTA TODAS AS COLISÕES ENTRE OS CARROS
char** detectar_colisoes (Lista carros);

//FUNÇÃO QUE GERA O SVG DAS COLISÕES
void fecha_colisao (Parametros* par, char* sufixo);

//FUNCÃO QUE CALCULA A DISTÂNCIA ENTRE DOIS PONTOS
double distancia (double* pos1, double* pos2);

//FUNÇÃO QUE CALCULA O MELHOR TRAJETO ENTRE DOIS REGISTROS
char **melhor_trajeto_registradores(Registrador *regis, char *r1, char *r2, Grafo G, char def);

#endif