//BIBLIOTECA UTILIZADA PARA REALIZAR AS FUNÇÕES DO CIRCULO

#ifndef CIRCULO_H
#define CIRCULO_H

//INICIALIZANDO STRUCT CIRCULO
typedef void* Circulo;

//RETORNA UM PONTEIRO PARA VOID COM AS INFORMAÇÕES DO CÍRCULO
void* cria_circulo (long int id, char* cor1, char* cor2, double r, double x, double y);

//RETORNA UMA STRING COM AS INFORMAÇÕES PARA IMPRIMIR O CÍRCULO NO SVG
char* cria_svg_circulo (void* circle);

//RETORNA 0 SE UMA COORDENADA(X,Y) NÃO ESTIVER CONTIDA NO CÍRCULO, OU 1 CASO CONTRÁRIO
int dentro_circulo (void* circle, double x, double y);

//RETORNA 0 SE UMA COORDENADA(X,Y) NÃO ESTIVER CONTIDA NO CÍRCULO OU NA BORDA DO MESMO, OU 1 CASO CONTRÁRIO
int dentro_borda_circulo (void* circle, double x, double y);

//RETORNA UM DOUBLE POINTER COM AS COORDENADAS DO CENTRO DE MASSA DO CÍRCULO
double* centro_massa_circulo (void* circle);

//PEGA O ID DO CÍRCULO
long int get_id_circulo (void* circle);

//PEGA O RAIO DO CÍRCULO
double get_r_circulo (void* circle);

//PEGA O X DO CÍRCULO
double get_x_circulo (void* circle);

//PEGA O Y DO CÍRCULO
double get_y_circulo (void* circle);

//PEGA A COR1 DO CÍRCULO
char* get_cor1_circulo (void* circle);

//PEGA A COR2 DO CÍRCULO
char* get_cor2_circulo (void* circle);

//FUNÇÃO PARA DAR FREE NA MEMÓRIA ALOCADA DO CÍRCULO
void free_circulo (void* circle);

#endif