#ifndef REGISTRADOR_H
#define REGISTRADOR_H

typedef void* Registrador;

//CRIA E RETORNA UM REGISTRADOR
Registrador cria_registrador (char *nome);

//INSERE A COORDENADA NO REGISTRADOR
void insere_pos_registrador (Registrador r, double* pos);

//INSERE O TIPO NO REGISTRADOR
void insere_tipo_registrador (Registrador r, void* tipo);

//INSERE O NOME NO REGISTRADOR
void insere_nome_registrador (Registrador r, char* nome);

//RETORNA A COORDENADA PRESENTE NO REGISTRADOR
double* get_pos_registrador (Registrador r);

//RETORNA O TIPO PRESENTE NO REGISTRADOR
void* get_tipo_registrador (Registrador r);

//RETORNA O NOME PRESENTE NO REGISTRADOR
char* get_nome_registrador (Registrador r);

//BUSCA UM REGISTRADOR ESPECÍFICADO PELO NOME
int busca_registrador (Registrador* registradores, char* regis);

#endif
