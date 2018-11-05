//BIBLIOTECA DE FUNÇÕES DA FIGURA HIDRANTE

#ifndef HIDRANTE_H
#define HIDRANTE_H

//DEFINE O TIPO HIDRANTE
typedef void* Hidrante;

//RETORNA UM PONTEIRO PARA VOID COM AS INFORMAÇÕES DO HIDRANTE
void* cria_hidrante (char* id, double r, double x, double y, char* cor_borda, char* cor_preenche);

//RETORNA UMA STRING COM AS INFORMAÇÕES PARA IMPRIMIR O HIDRANTE NO SVG
char* cria_svg_hidrante (void* hidrante);

//PEGA O ID DO HIDRANTE
char* get_id_hidrante (void* hidrante);

//PEGA O RAIO DO HIDRANTE
double get_r_hidrante (void* hidrante);

//PEGA O X DO HIDRANTE
double get_x_hidrante (void* hidrante);

//PEGA O Y DO HIDRANTE
double get_y_hidrante (void* hidrante);

//PEGA A COR1 DO HIDRANTE
char* get_cor1_hidrante (void* hidrante);

//PEGA A COR2 DO HIDRANTE
char* get_cor2_hidrante (void* hidrante);

//ALTERA AS CORES DA BORDA E DO PREENCHIMENTO DO HIDRANTE
void* muda_cor_hidrante (void* hidrante, char* cor_borda, char* cor_preenche);

#endif