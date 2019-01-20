//BIBLIOTECA DE FUNÇÕES DA FIGURA SEMÁFORO

#ifndef SEMAFORO_H
#define SEMAFORO_H

//DEFINE O TIPO SEMÁFORO
typedef void* Semaforo;

//RETORNA UM PONTEIRO PARA VOID COM AS INFORMAÇÕES DO SEMÁFORO
void* cria_semaforo (char* id, double r, double x, double y, char* cor_borda, char* cor_preenche);

//RETORNA UMA STRING COM AS INFORMAÇÕES PARA IMPRIMIR O SEMÁFORO NO SVG
char* cria_svg_semaforo (void* semaforo);

//PEGA O ID DO SEMÁFORO
char* get_id_semaforo (void* semaforo);

//PEGA O RAIO DO SEMÁFORO
double get_r_semaforo (void* semaforo);

//PEGA O X DO SEMÁFORO
double get_x_semaforo (void* semaforo);

//PEGA O Y DO SEMÁFORO
double get_y_semaforo (void* semaforo);

//ALTERA AS CORES DA BORDA E DO PREENCHIMENTO DO SEMÁFORO
void* muda_cor_semaforo (void* semaforo, char* cor_borda, char* cor_preenche);

//PEGA A COR1 DO SEMÁFORO
char* get_cor1_semaforo (void* semaforo);

//PEGA A COR2 DO SEMÁFORO
char* get_cor2_semaforo (void* semaforo);

//FUNÇÃO DE COMPARAÇÃO DE ID DE SEMÁFORO
int compare_semaforo (void* sem1, void* sem2, int dim);

//RETORNA O CÓDIGO HASH DO SEMÁFORO
int hashcode_semaforo (void* sem, int modulo);

//COMPARADOR DE CEP DO SEMÁFORO PARA HASHTABLE
int compare_hash_semaforo (void* sem, void* id);

//FUNÇÃO QUE RETORNA UM CÍRCULO COM AS INFORMAÇÕES DO SEMÁFORO
void* get_circulo_semaforo (void* semaforo);

//LIBERA A MEMÓRIA ALOCADA DO SEMÁFORO
void free_semaforo(void *semaforo);

//ESCREVE O SEMÁFORO NO ARQUIVO
void escreve_arquivo_semaforo (void* semaforo, int procura, FILE* arq);

//LE O SEMÁFORO DO ARQUIVO
void ler_arquivo_semaforo (void* semaforo, int procura, FILE* arq);

//RETORNA O TAMANHO DO SEMÁFORO
int get_tamanho_semaforo ();

//FUNÇÃO DE COMPARAÇÃO DA ÁRVORE B DO SEMÁFORO
double compare_semaforo_arvoreB (void* objA, void* objB);

//ALOCA A MEMÓRIA NECESSÁRIA PARA O SEMÁFORO
void* alloc_semaforo ();

#endif