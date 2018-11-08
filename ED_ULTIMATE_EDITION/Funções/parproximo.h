//BIBLIOTECA DE FUNÇÕES PARA DETERMINAR AS DUAS RÁDIO-BASES MAIS PRÓXIMAS

#ifndef PARPROXIMO_H
#define PARPROXIMO_H

//DEFINE O TIPO DO PONTO
typedef struct ponto
{
    char* id;
    int x;
    int y;
}Ponto;

//FUNÇÃO NECESSÁRIA PARA ORDENAR OS PONTOS DE ACORDO COM X
int compare_x (void* a, void* b);

//FUNÇÃO NECESSÁRIA PARA ORDENAR OS PONTOS DE ACORDO COM Y
int compare_y (void* a, void* b);

//FUNÇÃO PARA ACHAR A DISTÂNCIA ENTRE DOIS PONTOS
float dist_points (Ponto p1, Ponto p2);

//RETORNA A MENOR DISTÂNCIA ENTRE DOIS PONTOS EM P[] DE TAMANHO N
float brute_force (Ponto P[], int n);

//FUNÇÃO PARA ACHAR O MENOR VALOR ENTRE DOIS FLOATS
float menor (float x, float y);

//FUNÇÃO PARA ENCONTRAR O PAR MAIS PRÓXIMO
float closest_pair (Ponto** vetor, int size, char* saida);

//FUNÇÃO PARA RETORNAR A DISTÂNCIA DO PAR
float closest_dist (Ponto** vetor, int inicial, int final, char* saida);

//PERCORRE O VETOR PROCURANDO OS PONTOS NA STRIP E VERIFICA SE EXISTE DISTÂNCIA MENOR QUE A MÍNIMA
double strip_closest (Ponto** vetor, int inicial, int final, float mindist, char* result);

#endif