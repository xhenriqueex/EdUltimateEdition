//BIBLIOTECA DE FUNÇÕES DA FIGURA QUADRA

#ifndef QUADRA_H
#define QUADRA_H
#include "../../Formas/Retângulo/retangulo.h"

//DEFINE O TIPO QUADRA
typedef void* Quadra;

//RETORNA UM PONTEIRO PARA VOID COM AS INFORMAÇÕES DA QUADRA
void* cria_quadra (char* cep, double x, double y, double w, double h, char* cor_preenche, char* cor_borda);

//RETORNA UMA STRING COM AS INFORMAÇÕES PARA IMPRIMIR A QUADRA NO SVG
char* cria_svg_quadra (void* quadra);

//PEGA O CEP DA QUADRA
char* get_cep_quadra (void* quadra);

//PEGA A LARGURA DA QUADRA
double get_w_quadra (void* quadra);

//PEGA A ALTURA DA QUADRA
double get_h_quadra (void* quadra);

//PEGA O X DA QUADRA
double get_x_quadra (void* quadra);

//PEGA O Y DA QUADRA
double get_y_quadra (void* quadra);

//ALTERA AS CORES DA BORDA E DO PREENCHIMENTO DA QUADRA
void* muda_cor_quadra (void* quadra, char* cor_borda, char* cor_preenche);

//PEGA A COR1 DA QUADRA
char* get_cor1_quadra (void* quadra);

//PEGA A COR2 DA QUADRA
char* get_cor2_quadra (void* quadra);

//RETORNA UM RETÂNGULO COM AS INFORMAÇÕES DA QUADRA
Retangulo get_retangulo_quadra (void* quadra);

//FUNÇÃO DE COMPARAÇÃO DE CEP DE QUADRA
int compare_quadra (void* quad1, void* quad2, int dim);

//RETORNA O CÓDIGO HASH DA QUADRA
int hashcode_quadra (void* quad, int modulo);

#endif