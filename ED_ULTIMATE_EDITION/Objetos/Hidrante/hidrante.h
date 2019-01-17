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

//FUNÇÃO DE COMPARAÇÃO DE ID DE HIDRANTE
int compare_hidrante (void* hid1, void* hid2, int dim);

//RETORNA O CÓDIGO HASH DO HIDRANTE
int hashcode_hidrante (void* hid, int modulo);

//COMPARADOR DE CEP DO HIDRANTE PARA HASHTABLE
int compare_hash_hidrante (void* hid, void* id);

//FUNÇÃO QUE RETORNA UM CÍRCULO COM AS INFORMAÇÕES DO HIDRANTE
void* get_circulo_hidrante (void* hidrante);

void free_hidrante(void *hidrante);

#endif