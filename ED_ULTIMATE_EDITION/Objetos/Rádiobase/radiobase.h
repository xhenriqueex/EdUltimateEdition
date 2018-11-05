//BIBLIOTECA DE FUNÇÕES DA FIGURA RÁDIO BASE

#ifndef RADIOBASE_H
#define RADIOBASE_H

//DEFINE O TIPO SEMÁFORO
typedef void* Radiobase;

//RETORNA UM PONTEIRO PARA VOID COM AS INFORMAÇÕES DA RÁDIO-BASE
void* cria_radiobase (char* id, double r, double x, double y, char* cor_borda, char* cor_preenche);

//RETORNA UMA STRING COM AS INFORMAÇÕES PARA IMPRIMIR O SEMÁFORO NO SVG
char* cria_svg_radiobase (void* radiobase);

//PEGA O ID DA RÁDIO BASE
char* get_id_radiobase (void* radiobase);

//PEGA O RAIO DA RÁDIO BASE
double get_r_radiobase (void* radiobase);

//PEGA O X DA RÁDIO BASE
double get_x_radiobase (void* radiobase);

//PEGA O Y DA RÁDIO BASE
double get_y_radiobase (void* radiobase);

//ALTERA AS CORES DA BORDA E DO PREENCHIMENTO DA RÁDIO BASE
void* troca_cor_radiobase (void* radiobase, char* cor_borda, char* cor_preenche);

//PEGA A COR1 DA RÁDIO BASE
char* get_cor1_radiobase (void* radiobase);

//PEGA A COR2 DA RÁDIO BASE
char* get_cor2_radiobase (void* radiobase);

#endif