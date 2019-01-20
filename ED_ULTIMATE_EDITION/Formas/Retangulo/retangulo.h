//BIBLIOTECA UTILIZADA PARA REALIZAR AS FUNÇÕES DO RETÂNGULO

#ifndef RETANGULO_H
#define RETANGULO_H

//INICIALIZANDO STRUCT RETÂNGULO
typedef void* Retangulo;

//RETORNA UM PONTEIRO PARA VOID COM AS INFORMAÇÕES DO RETÂNGULO
void* cria_retangulo (long int id, char* cor1, char* cor2, double w, double h, double x, double y);

//RETORNA UMA STRING COM AS INFORMAÇÕES PARA IMPRIMIR O RETÂNGULO NO SVG
char* cria_svg_retangulo (void* rectangle);

//RETORNA 0 SE UMA COORDENADA(X,Y) NÃO ESTIVER CONTIDA NO RETÂNGULO, OU 1 CASO CONTRÁRIO
int dentro_retangulo (void* rectangle, double x, double y);

//RETORNA 0 SE UMA COORDENADA(X,Y) NÃO ESTIVER CONTIDA NO RETÂNGULO OU NA BORDA DO MESMO, OU 1 CASO CONTRÁRIO
int dentro_borda_retangulo (void* rectangle, double x, double y);

//RETORNA UM DOUBLE POINTER COM AS COORDENADAS DO CENTRO DE MASSA DO RETÂNGULO
double* centro_massa_retangulo (void* rectangle);

//PEGA O ID DO RETÂNGULO
long int get_id_retangulo (void* rectangle);

//PEGA O W DO RETÂNGULO
double get_w_retangulo (void* rectangle);

//PEGA O H DO RETÂNGULO
double get_h_retangulo (void* rectangle);

//PEGA O X DO RETÂNGULO
double get_x_retangulo (void* rectangle);

//PEGA O Y DO RETÂNGULO
double get_y_retangulo (void* rectangle);

//PEGA A COR1 DO RETÂNGULO
char* get_cor1_retangulo (void* rectangle);

//PEGA A COR2 DO RETÂNGULO
char* get_cor2_retangulo (void* rectangle);

//FUNÇÃO PARA DAR FREE NA MEMÓRIA ALOCADA DO RETÂNGULO
void free_retangulo (void* rectangle);

//ESCREVE O RETÂNGULO NO ARQUIVO
void escreve_arquivo_retangulo (void* retangulo, int procura, FILE* arq);

//LE O RETÂNGULO DO ARQUIVO
void ler_arquivo_retangulo (void* retangulo, int procura, FILE* arq);

//RETORNA O TAMANHO DO RETÂNGULO
int get_tamanho_retangulo ();

//FUNÇÃO DE COMPARAÇÃO DA ÁRVORE B DO RETÂNGULO
double compare_retangulo (void* objA, void* objB);

//ALOCA A MEMÓRIA NECESSÁRIA DO RETÂNGULO
void* alloc_retangulo ();

#endif