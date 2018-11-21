//BIBLIOTECA DE FUNÇÕES DO OBJETO CARRO

#ifndef CARRO_H
#define CARRO_H

typedef void* Carro;

//CRIA UM RETÂNGULO COM AS INFORMAÇÕES PASSADAS
Carro cria_carro (char* placa, double x, double y, double w, double h);

//GERA UMA STRING COM AS INFORMAÇÕES DO CARRO EM SVG
char* cria_svg_carro (Carro car);

//PEGA A PLACA DO CARRO
char* get_placa_carro (Carro car);

//RETORNA UM RETÂNGULO
void* get_retangulo_carro (Carro car);

//LIBERA A MEMÓRIA ALOCADA DO CARRO
void free_carro (Carro car);

//GERA UM RELATÓRIO DO CARRO
char* relatorio_carro (Carro car);

//COMPARA DOIS CARROS
int compare_carro (void* carA, void* carB, int dim);

//CRIA UM CÓDIGO HASH REFERENTE AO OBJETO CARRO
int hashcode_carro (void* car, int mod);

//COMPARADOR DE HASH DO OBJETO CARRO
int compare_hash_carro (void* carA, void* carB);

#endif