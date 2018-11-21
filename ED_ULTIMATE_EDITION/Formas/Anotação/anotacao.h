//BIBLIOTECA UTILIZADA PARA REALIZAR AS FUNÇÕES DA ANOTAÇÃO

#ifndef ANOTACAO_H
#define ANOTACAO_H

//INICIALIZANDO STRUCT ANOTAÇÃO
typedef void* Anotacao;

//RETORNA UM PONTEIRO PARA VOID COM AS INFORMAÇÕES DA ANOTAÇÃO
void* cria_anotacao (double w, double h, double x, double y, char* text);

//RETORNA UMA STRING COM AS INFORMAÇÕES PARA IMPRIMIR A ANOTAÇÃO NO SVG
char* cria_svg_anotacao (void* anotation);

#endif