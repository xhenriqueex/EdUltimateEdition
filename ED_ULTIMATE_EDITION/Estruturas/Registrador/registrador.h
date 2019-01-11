#ifndef REGISTRADOR_H
#define REGISTRADOR_H

typedef void* Registrador;


Registrador cria_registrador();

void insere_pos_registrador(Registrador r, double *pos);

void insere_tipo_registrador(Registrador r, void *tipo);

void insere_nome_registrador(Registrador r, char *nome);

double *get_pos_registrador(Registrador r);

void *get_tipo_registrador(Registrador r);

char *get_nome_registrador(Registrador r);

int busca_registrador(Registrador *registradores, char *regis);

#endif
