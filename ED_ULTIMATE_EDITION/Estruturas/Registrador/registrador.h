#ifndef REGISTRADOR_H
#define REGISTRADOR_H

typedef void* Registrador;


Registrador criar_registrador();

void inserir_pos_registrador(Registrador r, double *pos);

void inserir_tipo_registrador(Registrador r, void *tipo);

void inserir_nome_registrador(Registrador r, char *nome);

double *get_pos_registrador(Registrador r);

void *get_tipo_registrador(Registrador r);

char *get_nome_registrador(Registrador r);

int busca_registrador(Registrador *registradores, char *regis);

#endif
